#include "s21_test.h"

START_TEST(sum_normal) {
  matrix_t a = {0}, b = {0}, result = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = 1.5;
  b.matrix[0][0] = 2.5;
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_diff_sizes) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), CALC_ERROR);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_null_input) {
  matrix_t result;
  ck_assert_int_eq(s21_sum_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_result_not_init) {
  matrix_t a, b, result = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_self) {
  matrix_t a, result;
  s21_create_matrix(3, 3, &a);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      a.matrix[i][j] = i + j;
  
  ck_assert_int_eq(s21_sum_matrix(&a, &a, &result), OK);
  ck_assert_double_eq_tol(result.matrix[1][1], 4.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_zero_matrix) {
  matrix_t a, b, result;
  s21_create_matrix(4, 4, &a);
  s21_create_matrix(4, 4, &b);
  
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      a.matrix[i][j] = 0.0;
      b.matrix[i][j] = 0.0;
    }
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[2][2], 0.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_negative_values) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = -1.5;
  b.matrix[0][0] = -2.5;
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -4.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_mixed_signs) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = 5.0;
  b.matrix[0][0] = -3.0;
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_single_element) {
  matrix_t a, b, result;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  
  a.matrix[0][0] = 0.0001;
  b.matrix[0][0] = 0.0002;
  
  ck_assert_int_eq(s21_sum_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.0003, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_normal) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = 5.0;
  b.matrix[0][0] = 3.0;
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_diff_sizes) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), CALC_ERROR);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_null_input) {
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_negative_result) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = 1.0;
  b.matrix[0][0] = 2.0;
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -1.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_zero_matrix) {
  matrix_t a, b, result;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 0.0;
      b.matrix[i][j] = 0.0;
    }
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[1][1], 0.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_self) {
  matrix_t a, result;
  s21_create_matrix(2, 2, &a);
  
  a.matrix[0][0] = 5.0;
  
  ck_assert_int_eq(s21_sub_matrix(&a, &a, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_large_values) {
  matrix_t a, b, result;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(10, 10, &b);
  
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      a.matrix[i][j] = 1e308;
      b.matrix[i][j] = 1e308;
    }
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[5][5], 0.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_mixed_signs) {
  matrix_t a, b, result;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  a.matrix[0][0] = -5.0;
  b.matrix[0][0] = 3.0;
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -8.0, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_single_element) {
  matrix_t a, b, result;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  
  a.matrix[0][0] = 0.0001;
  b.matrix[0][0] = 0.0002;
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -0.0001, S21_EPS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_result_not_init) {
  matrix_t a, b, result = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  
  ck_assert_int_eq(s21_sub_matrix(&a, &b, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_1) {
  matrix_t a, result;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 2.0; a.matrix[0][1] = 4.0;
  s21_mult_number(&a, 3.0, &result);
  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, S21_EPS);
  s21_remove_matrix(&a); s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_2) {
  matrix_t a, result;
  s21_create_matrix(1, 1, &a);
  a.matrix[0][0] = 5.0;
  s21_mult_number(&a, 0.0, &result);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.0, S21_EPS);
  s21_remove_matrix(&a); s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_3) {
  matrix_t a = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 1, &a);

  a.matrix[0][0] = -3.0;
  s21_mult_number(&a, -2.0, &result);
  
  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, S21_EPS);
 
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_4) {
  matrix_t result;
  ck_assert_int_eq(s21_mult_number(NULL, 5.0, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(mul_num_5) {
  matrix_t a, result;
  s21_create_matrix(2, 2, &a);
  a.matrix[0][0] = 1e301;
  s21_mult_number(&a, 1.0, &result);
  ck_assert_double_eq_tol(result.matrix[0][0], 1e301, S21_EPS);
  s21_remove_matrix(&a); s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_6) {
  matrix_t a, result;
  s21_create_matrix(1, 3, &a);
  a.matrix[0][0] = 0.5; a.matrix[0][1] = 1.5; a.matrix[0][2] = 2.5;
  s21_mult_number(&a, 0.4, &result);
  ck_assert_double_eq_tol(result.matrix[0][1], 0.6, S21_EPS);
  s21_remove_matrix(&a); s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_7) {
  matrix_t a, result;
  s21_create_matrix(3, 2, &a);
  for (int i = 0; i < 3; i++) 
    for (int j = 0; j < 2; j++) a.matrix[i][j] = -i-j;
  s21_mult_number(&a, -1.0, &result);
  ck_assert_double_eq_tol(result.matrix[2][1], 3.0, S21_EPS);
  s21_remove_matrix(&a); s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_num_8) {
  matrix_t src, result, expected;
  s21_create_matrix(2, 2, &src);
  s21_create_matrix(2, 2, &expected);
  
  src.matrix[0][0] = 2.0; src.matrix[0][1] = 4.0;
  src.matrix[1][0] = 6.0; src.matrix[1][1] = 8.0;
  
  expected.matrix[0][0] = 6.0;  expected.matrix[0][1] = 12.0;
  expected.matrix[1][0] = 18.0; expected.matrix[1][1] = 24.0;
  
  s21_mult_number(&src, 3.0, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&src);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_num_9) {
  matrix_t src, result, expected;
  s21_create_matrix(1, 1, &src);
  s21_create_matrix(1, 1, &expected);
  
  src.matrix[0][0] = 5.0;
  expected.matrix[0][0] = 0.0;
  
  s21_mult_number(&src, 0.0, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&src);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_num_10) {
  matrix_t src, result, expected;
  s21_create_matrix(1, 3, &src);
  s21_create_matrix(1, 3, &expected);
  
  src.matrix[0][0] = -3.0; src.matrix[0][1] = 6.0; src.matrix[0][2] = -9.0;
  expected.matrix[0][0] = 6.0; expected.matrix[0][1] = -12.0; expected.matrix[0][2] = 18.0;
  
  s21_mult_number(&src, -2.0, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&src);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_1) { 
  matrix_t a, b, result, expected;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &b);
  s21_create_matrix(2, 2, &expected);
  
  a.matrix[0][0] = 1; a.matrix[0][1] = 2; a.matrix[0][2] = 3;
  a.matrix[1][0] = 4; a.matrix[1][1] = 5; a.matrix[1][2] = 6;
  
  b.matrix[0][0] = 7; b.matrix[0][1] = 8;
  b.matrix[1][0] = 9; b.matrix[1][1] = 10;
  b.matrix[2][0] = 11; b.matrix[2][1] = 12;
  

  expected.matrix[0][0] = 58;  expected.matrix[0][1] = 64;
  expected.matrix[1][0] = 139; expected.matrix[1][1] = 154;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_2) {
  matrix_t a, b, result, expected;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &expected);
  
  a.matrix[0][0] = -2; a.matrix[0][1] = 1;
  a.matrix[1][0] = 5;  a.matrix[1][1] = 4;
  
  b.matrix[0][0] = 3;  b.matrix[0][1] = -1;
  b.matrix[1][0] = 7;  b.matrix[1][1] = 2;
  
  expected.matrix[0][0] = 1;  expected.matrix[0][1] = 4;
  expected.matrix[1][0] = 43; expected.matrix[1][1] = 3;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_3) {
  matrix_t a = {0}, b = {0}, result = {0}, expected = {0};
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(3, 3, &expected);
  
  for (int i = 0; i < 3; i++) b.matrix[i][i] = 1.0;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_4) {
  matrix_t a, b, result, expected;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &expected);
  

  expected.matrix[0][0] = 0; expected.matrix[0][1] = 0;
  expected.matrix[1][0] = 0; expected.matrix[1][1] = 0;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_5) {
  matrix_t a, b, result;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 3, &b);
  
  ck_assert_int_eq(s21_mult_matrix(&a, &b, &result), CALC_ERROR);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(mul_6) {
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(mul_7) {
  matrix_t a, b, result, expected;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(10, 10, &b);
  s21_create_matrix(10, 10, &expected);
  
  a.matrix[9][9] = 2.0;
  b.matrix[9][9] = 3.0;
  expected.matrix[9][9] = 6.0;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_8) {
  matrix_t a, b, result, expected;
  s21_create_matrix(3, 2, &a);
  s21_create_matrix(2, 3, &b);
  s21_create_matrix(3, 3, &expected);
  
  for (int i = 0; i < 6; i++) {
    a.matrix[i/2][i%2] = i+1;
    b.matrix[i%2][i/2] = i+1;
  }
  

  expected.matrix[0][0] = 5.0;
  expected.matrix[0][1] = 11.0;
  expected.matrix[0][2] = 17.0;
  expected.matrix[1][0] = 11.0;
  expected.matrix[1][1] = 25.0;
  expected.matrix[1][2] = 39.0;
  expected.matrix[2][0] = 17.0;
  expected.matrix[2][1] = 39.0;
  expected.matrix[2][2] = 61.0;
  
  s21_mult_matrix(&a, &b, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_9) {
  matrix_t a, b, result, expected;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &expected);
  
  a.matrix[0][0] = -2; a.matrix[0][1] = 1;
  b.matrix[0][0] = 3;  b.matrix[0][1] = -1;
  
  expected.matrix[0][0] = -6; expected.matrix[0][1] = 2;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mul_10) { // Матрица 1x1
  matrix_t a, b, result, expected;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &expected);
  
  a.matrix[0][0] = 5.0;
  b.matrix[0][0] = 4.0;
  expected.matrix[0][0] = 20.0;
  
  s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST
Suite *sub_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Subtraction");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, sub_normal);
    tcase_add_test(tc_core, sub_diff_sizes);
    tcase_add_test(tc_core, sub_null_input);
    tcase_add_test(tc_core, sub_negative_result);
    tcase_add_test(tc_core, sub_zero_matrix);
    tcase_add_test(tc_core, sub_self);
    tcase_add_test(tc_core, sub_large_values);
    tcase_add_test(tc_core, sub_mixed_signs);
    tcase_add_test(tc_core, sub_single_element);
    tcase_add_test(tc_core, sub_result_not_init);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite *sum_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Addition");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, sum_normal);
    tcase_add_test(tc_core, sum_diff_sizes);
    tcase_add_test(tc_core, sum_null_input);
    tcase_add_test(tc_core, sum_result_not_init);
    tcase_add_test(tc_core, sum_self);
    tcase_add_test(tc_core, sum_zero_matrix);
    tcase_add_test(tc_core, sum_negative_values);
    tcase_add_test(tc_core, sum_mixed_signs);
    tcase_add_test(tc_core, sum_single_element);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite *mul_num_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Multiplication to number");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, mul_num_1);
    tcase_add_test(tc_core, mul_num_2);
    tcase_add_test(tc_core, mul_num_3);
    tcase_add_test(tc_core, mul_num_4);
    tcase_add_test(tc_core, mul_num_5);
    tcase_add_test(tc_core, mul_num_6);
    tcase_add_test(tc_core, mul_num_7);
    tcase_add_test(tc_core, mul_num_8);
    tcase_add_test(tc_core, mul_num_9);
    tcase_add_test(tc_core, mul_num_10);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite *mul_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Multiplication");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, mul_1);
    tcase_add_test(tc_core, mul_2);
    tcase_add_test(tc_core, mul_3);
    tcase_add_test(tc_core, mul_4);
    tcase_add_test(tc_core, mul_5);
    tcase_add_test(tc_core, mul_6);
    tcase_add_test(tc_core, mul_7);
    tcase_add_test(tc_core, mul_8);
    tcase_add_test(tc_core, mul_9);
    tcase_add_test(tc_core, mul_10);

    suite_add_tcase(s, tc_core);

    return s;
}