#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include "./../s21_matrix.h"

#define S21_EPS 1e-7
enum work_res { OK, INCORRECT_MATRIX, CALC_ERROR };

Suite *det_suite(void);
Suite *sum_suite(void);
Suite *sub_suite(void);
Suite *transp_suite(void);
Suite *inverse_suite(void);
Suite *mul_num_suite(void);

#endif