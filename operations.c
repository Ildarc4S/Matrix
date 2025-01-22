#include "operations.h"
#include "utils.h"
#include "memory.h"

int s21_operator_sum(int a, int b) {
  return a+b;
}

int s21_operator_sub(int a, int b) {
  return a-b;
}

int s21_apply_operation(matrix_t *A, matrix_t *B, matrix_t *result,
                        int (*s21_operator)(int, int)) {
  if (A == NULL || B == NULL) {
    return kCodeIncorrect;
  }
  if (!s21_size_eq(A, B)) { 
    return kCodeCalcError;
  }

  S21OperationsResultCode result_code = kCodeOK;

  if(s21_create_matrix(A->rows, A->columns, result) != 1) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; i++) {
        result->matrix[i][j] = s21_operator(A->matrix[i][j], B->matrix[i][j]);
      }
    }
  } else {
    result_code = kCodeIncorrect;
  }
  return result_code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_apply_operation(A, B, result, s21_operator_sum); 
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_apply_operation(A, B, result, s21_operator_sub); 
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL) {
    return kCodeIncorrect;
  }

  S21OperationsResultCode result_code = kCodeOK;
  if (s21_create_matrix(A->rows, A->columns, result) != 1) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; i++) {
        result->matrix[i][j] = A->matrix[i][j]*number;
      }
    }
  } else {
    result_code = kCodeIncorrect;
  }

  return result_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL) {
    return kCodeIncorrect;
  }
  if ( A->columns != B->rows) {
    return kCodeCalcError;
  }

  S21OperationsResultCode result_code = kCodeOK;

  if(s21_create_matrix(A->rows, A->columns, result) != 1) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < B->columns; i++) {
        for (int k = 0; k < result->rows;i++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  } else {
    result_code = kCodeIncorrect;
  }

  return result_code;
}

