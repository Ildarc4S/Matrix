#include "memory.h"
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  S21OperationsResultCode result_code = kCodeOK;
  result->matrix = (double**)calloc(rows, sizeof(double*));
}
void s21_remove_matrix(matrix_t *A);

