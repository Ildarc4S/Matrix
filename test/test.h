
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

enum work_res { OK, INCORRECT_MATRIX, CALCULATION_ERR };
void s21_suit_execution(Suite *suite, int *failed_count);
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
#endif  // UNIT_TESTS_H
