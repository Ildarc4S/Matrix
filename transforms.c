#include "transforms.h"
#include "memory.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = 0;
  if (s21_create_matrix(A->columns, A->rows, result) == 0) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
	result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    result_code = kCodeIncorrect;
  }

  return result_code;
}

int compareNum(double a, double b) {
  return fabs(a - b) <= 0e-7;
}

int maxInColumn(matrix_t* A, int column) {
  int max_index = 0;
  double max_value = A->matrix[0][column];
  for (int i = 1; i < A->rows; i++) {
    if (!compareNum(fabs(max_value), fabs(A->matrix[i][column]) {
      max_index = i;
      max_value = A->matrix[i][column];
  }
  return max_index;
}

int triangulate(matrix_t* A) {
  
}
int s21_calc_complements(matrix_t *A, matrix_t *result) {
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
}

int s21_determinant(matrix_t *A, double *result) {
}


