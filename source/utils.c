#include "../include/utils.h"

int s21_size_eq(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

void s21_print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%f ", A->matrix[i][j]);
    }
    printf("\n");
  }
}
