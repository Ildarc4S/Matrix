#include "../include/memory.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  S21OperationsResultCode result_code = CODE_OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return CODE_INCORRECT;
  }

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->columns = columns;
    result->rows = rows;
  } else {
    result_code = CODE_INCORRECT;
  }

  return result_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->columns > 0 && A->rows > 0 && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}
