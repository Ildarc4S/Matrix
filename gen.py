import numpy as np

SUCCESS = 1
FAILURE = 0

def generate_matrix_c_code(name, matrix):
    if not matrix or len(matrix) == 0:
        return f'matrix_t {name} = {{NULL, 0, 0}};'
    rows = len(matrix)
    cols = len(matrix[0]) if rows > 0 else 0
    code = []
    code.append(f'matrix_t {name};')
    code.append(f's21_create_matrix({rows}, {cols}, &{name});')
    for i in range(rows):
        for j in range(cols):
            val = matrix[i][j]
            code.append(f'{name}.matrix[{i}][{j}] = {val:.7f};')
    return '\n    '.join(code)

def generate_test_case(test_case, func_name):
    code = []
    test_name = test_case['name']
    code.append(f'START_TEST({test_name}) {{')
    
    # Generate input matrices
    for mat in ['A', 'B']:
        if mat in test_case:
            matrix = test_case[mat]
            code.append(f'    {generate_matrix_c_code(mat, matrix)}')
    
    # Generate result and expected matrices
    code.append('    matrix_t result;')
    if test_case.get('expected') is not None:
        code.append(f'    {generate_matrix_c_code("expected", test_case["expected"])}')
    
    # Function call
    func_call = f's21_{func_name}('
    args = []
    if 'A' in test_case:
        args.append('&A')
    if 'B' in test_case and func_name in ['sum_matrix', 'sub_matrix']:
        args.append('&B')
    args.append('&result')
    func_call += ', '.join(args) + ');'
    code.append(f'    int ret = {func_call}')
    
    # Check return code
    code.append(f'    ck_assert_int_eq(ret, {test_case["expected_return"]});')
    
    # Check result if applicable
    if test_case['expected_return'] == SUCCESS and 'expected' in test_case:
        code.append('    ck_assert(s21_eq_matrix(&result, &expected));')
    elif test_case['expected_return'] == FAILURE:
        code.append('    ck_assert_ptr_eq(result.matrix, NULL);')
        code.append('    ck_assert_int_eq(result.rows, 0);')
        code.append('    ck_assert_int_eq(result.columns, 0);')
    
    # Cleanup
    for mat in ['A', 'B', 'expected', 'result']:
        code.append(f'    s21_remove_matrix(&{mat});')
    
    code.append('}')
    code.append('END_TEST')
    return '\n'.join(code)

def generate_suite(test_cases, func_name):
    suite_name = f'suite_{func_name}'
    suite_code = []
    suite_code.append(f'Suite *{suite_name}(void) {{')
    suite_code.append(f'    Suite *s = suite_create("{suite_name}");')
    suite_code.append('    TCase *tc = tcase_create("core");')
    for test_case in test_cases:
        suite_code.append(f'    tcase_add_test(tc, {test_case["name"]});')
    suite_code.append('    suite_add_tcase(s, tc);')
    suite_code.append('    return s;')
    suite_code.append('}')
    return '\n'.join(suite_code)

# Пример тестового случая для сложения матриц
sum_test_cases = [
    {
        'name': 'test_sum_valid',
        'A': [[1.0, 2.0], [3.0, 4.0]],
        'B': [[5.0, 6.0], [7.0, 8.0]],
        'expected': [[6.0, 8.0], [10.0, 12.0]],
        'expected_return': SUCCESS,
    },
    {
        'name': 'test_sum_invalid_size',
        'A': [[1.0, 2.0], [3.0, 4.0]],
        'B': [[5.0, 6.0]],
        'expected_return': FAILURE,
    },
]

# Генерация кода тестов для суммы
test_code = []
for test_case in sum_test_cases:
    test_code.append(generate_test_case(test_case, 'sum_matrix'))

test_code.append(generate_suite(sum_test_cases, 'sum_matrix'))

# Сохранение в файл
with open('test_sum.c', 'w') as f:
    f.write('#include "check.h"\n#include "../s21_matrix.h"\n\n')
    f.write('\n\n'.join(test_code))