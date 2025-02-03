#include "../include/utils.h"

int s21_size_eq(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}