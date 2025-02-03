#include "s21_test.h"

void s21_initialize_matrix(matrix_t* A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}

START_TEST(det_1) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 2;
  a.matrix[2][0] = 5;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 1;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, -40, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_2) {
  matrix_t a = {0};
  s21_create_matrix(4, 4, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a.matrix[i][j] = c++;
    }
  }
  a.matrix[0][0] = 3;
  a.matrix[1][1] = 14;
  a.matrix[2][2] = 5;
  a.matrix[3][3] = 7;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 1688, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_3) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  double result = 0.0;
  a.matrix[0][0] = 5;
  a.matrix[0][1] = 7;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 3;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 1, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_4) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  }

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_5) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 1;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 1;
  a.matrix[2][2] = 1;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_6) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  double result = 0.0;
  a.matrix[0][0] = 4;
  a.matrix[0][1] = 6;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 3;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_7) {
  matrix_t a = {0};
  s21_create_matrix(4, 4, &a);
  double result = 0.0;
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 3;
  a.matrix[0][2] = 5;
  a.matrix[0][3] = 7;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 6;
  a.matrix[1][3] = 8;
  a.matrix[2][0] = 3;
  a.matrix[2][1] = 5;
  a.matrix[2][2] = 7;
  a.matrix[2][3] = 9;
  a.matrix[3][0] = 4;
  a.matrix[3][1] = 6;
  a.matrix[3][2] = 8;
  a.matrix[3][3] = 10;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_8) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 0;
  a.matrix[0][2] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 0;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 3;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 6, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_9) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  double result = 0.0;
  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, 0, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_10) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  a.matrix[0][0] = 7;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 4;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 3;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  ck_assert_int_eq(0, s21_determinant(&a, &result));
  ck_assert_double_eq_tol(result, -80, S21_EPS);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(transp_1) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(3, 2, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;

  check_result.matrix[0][0] = 1;
  check_result.matrix[0][1] = 4;
  check_result.matrix[1][0] = 2;
  check_result.matrix[1][1] = 5;
  check_result.matrix[2][0] = 3;
  check_result.matrix[2][1] = 6;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_2) {
  matrix_t a = {0};
  s21_create_matrix(3, 2, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  
  s21_create_matrix(2, 3, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 4;
  a.matrix[1][0] = 2;
  a.matrix[1][1] = 5;
  a.matrix[2][0] = 3;
  a.matrix[2][1] = 6;

  check_result.matrix[0][0] = 1;
  check_result.matrix[0][1] = 2;
  check_result.matrix[0][2] = 3;
  check_result.matrix[1][0] = 4;
  check_result.matrix[1][1] = 5;
  check_result.matrix[1][2] = 6;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_3) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(3, 3, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 9;

  check_result.matrix[0][0] = 1;
  check_result.matrix[0][1] = 4;
  check_result.matrix[0][2] = 7;
  check_result.matrix[1][0] = 2;
  check_result.matrix[1][1] = 5;
  check_result.matrix[1][2] = 8;
  check_result.matrix[2][0] = 3;
  check_result.matrix[2][1] = 6;
  check_result.matrix[2][2] = 9;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_4) {
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(2, 2, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 3;
  a.matrix[1][1] = 4;

  check_result.matrix[0][0] = 1;
  check_result.matrix[0][1] = 3;
  check_result.matrix[1][0] = 2;
  check_result.matrix[1][1] = 4;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transp_5) {
  matrix_t a = {0};
  s21_create_matrix(1, 2, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(2, 1, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;

  check_result.matrix[0][0] = 1;
  check_result.matrix[1][0] = 2;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_6) {
  matrix_t a = {0};
  s21_create_matrix(3, 1, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 3, &check_result);
  a.matrix[0][0] = 5;
  a.matrix[1][0] = 6;
  a.matrix[2][0] = 7;

  check_result.matrix[0][0] = 5;
  check_result.matrix[0][1] = 6;
  check_result.matrix[0][2] = 7;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_7) {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(3, 2, &check_result);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 1;
  a.matrix[0][2] = 1;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 1;
  a.matrix[1][2] = 1;

  check_result.matrix[0][0] = 1;
  check_result.matrix[0][1] = 1;
  check_result.matrix[1][0] = 1;
  check_result.matrix[1][1] = 1;
  check_result.matrix[2][0] = 1;
  check_result.matrix[2][1] = 1;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_8) {
  matrix_t a = {0};
  s21_create_matrix(2, 1, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 2, &check_result);
  a.matrix[0][0] = 2;
  a.matrix[1][0] = 3;

  check_result.matrix[0][0] = 2;
  check_result.matrix[0][1] = 3;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_9) {
  matrix_t a = {0};
  s21_create_matrix(1, 1, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 1, &check_result);
  a.matrix[0][0] = 3;

  check_result.matrix[0][0] = 3;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(transp_10) {
  matrix_t a = {0};
  s21_create_matrix(1, 3, &a);
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(3, 1, &check_result);
  a.matrix[0][0] = 4;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 6;

  check_result.matrix[0][0] = 4;
  check_result.matrix[1][0] = 5;
  check_result.matrix[2][0] = 6;

  ck_assert_int_eq(0, s21_transpose(&a, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &check_result));
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

Suite *det_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Determinant");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, det_1);
    tcase_add_test(tc_core, det_2);
    tcase_add_test(tc_core, det_3);
    tcase_add_test(tc_core, det_4);
    tcase_add_test(tc_core, det_5);
    tcase_add_test(tc_core, det_6);
    tcase_add_test(tc_core, det_7);
    tcase_add_test(tc_core, det_8);
    tcase_add_test(tc_core, det_9);
    tcase_add_test(tc_core, det_10);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite *transp_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Transposition");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, transp_1);
    tcase_add_test(tc_core, transp_2);
    tcase_add_test(tc_core, transp_3);
    tcase_add_test(tc_core, transp_4);
    tcase_add_test(tc_core, transp_5);
    tcase_add_test(tc_core, transp_6);
    tcase_add_test(tc_core, transp_7);
    tcase_add_test(tc_core, transp_8);
    tcase_add_test(tc_core, transp_9);
    tcase_add_test(tc_core, transp_10);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite *inverse_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Matrix Inversion");

    tc_core = tcase_create("Core");

    // tcase_add_test(tc_core, inverse_1);
    // tcase_add_test(tc_core, inverse_2);
    // tcase_add_test(tc_core, inverse_3);
    // tcase_add_test(tc_core, inverse_4);
    // tcase_add_test(tc_core, inverse_5);
    // tcase_add_test(tc_core, inverse_6);
    // tcase_add_test(tc_core, inverse_7);
    // tcase_add_test(tc_core, inverse_8);
    // tcase_add_test(tc_core, inverse_9);
    // tcase_add_test(tc_core, inverse_10);

    suite_add_tcase(s, tc_core);

    return s;
}