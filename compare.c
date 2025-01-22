#include "compare.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || !s21_size_eq(A, B)) {
    return FAILURE;
  }

  int result_code = SUCCESS;

  int stop = 0;
  for (int i = 0; i < A->rows && !stop; i++) {
    for (int j = 0; j < A->columns && !stop; i++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        result_code = FAILURE;
        stop = 1;
      }
    }
  }

  return result_code;
}

