#include "s21_test.h"

START_TEST(compare_1) {
  matrix_t a = {0}, b = {0};
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  ck_assert_int_eq(1, s21_eq_matrix(&a, &b));

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_2) {
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  ck_assert_int_eq(0, s21_eq_matrix(NULL, &b));
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_3) {
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  ck_assert_int_eq(0, s21_eq_matrix(&b, NULL));
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_4) {
  matrix_t a = {0}, b = {0};
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 2, &b);

  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(compare_5) {
  matrix_t a = {0}, b = {0};
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(2, 3, &b);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2;
      b.matrix[i][j] = 3;
    }

  ck_assert_int_eq(0, s21_eq_matrix(&a, &b));

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

Suite *compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Matrix compare");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, compare_1);
  tcase_add_test(tc_core, compare_2);
  tcase_add_test(tc_core, compare_3);
  tcase_add_test(tc_core, compare_4);
  tcase_add_test(tc_core, compare_5);
  suite_add_tcase(s, tc_core);

  return s;
}
