#include "transforms.h"
#include "memory.h"
#include <math.h>
#include <stdlib.h>
#include "utils.h"
#include "operations.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) {
    return kCodeIncorrect;
  }
  if (A->rows <= 0 || A->columns <= 0) {
    return kCodeIncorrect; // kCodeCalcError
  }
  
  int result_code = 0;
  if (s21_create_matrix(A->columns, A->rows, result) != 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
	result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    result_code = kCodeIncorrect;
  }

  return result_code;
}

int compareNum(double a, double b) {
  return fabs(a - b) < 1e-7;
}

int s21_max_in_column(matrix_t* A, int column) {
  int max_index = column;
  for (int i = column+1; i < A->rows; i++) {
    if (fabs(A->matrix[max_index][column]) < fabs(A->matrix[i][column])) {
      max_index = i;
    }
  }
  return max_index;
}

void s21_swap_rows(matrix_t* A, int row_one, int row_two) {
  for (int i = 0; i < A->columns; i++) {
    double temp = A->matrix[row_one][i];
    A->matrix[row_one][i] = A->matrix[row_two][i];
    A->matrix[row_two][i] = temp;
  }
}

int s21_triangulate_matrix(matrix_t* A, int* swap_count) {
  int result_code = 0;
  for (int curr_column = 0; curr_column < A->rows && result_code == 0; curr_column++) {

    int max_in_column = s21_max_in_column(A, curr_column); 

    if (fabs(A->matrix[max_in_column][curr_column]) < 1e-12) {
      result_code = -1;
    } else {
      if (max_in_column != curr_column) {
        s21_swap_rows(A, max_in_column, curr_column);
        ++(*swap_count);
      }

      for (int j = curr_column+1; j < A->rows; j++) {
        double factor = A->matrix[j][curr_column]/A->matrix[curr_column][curr_column];
        for (int i = curr_column; i < A->columns; i++) {
          A->matrix[j][i] -= A->matrix[curr_column][i]*factor;
        }
      }
    }
  }
  return result_code;
}

void s21_create_minor(matrix_t* A, matrix_t* B, int skip_row, int skip_column) {
  for (int i = 0, row = 0; i < A->rows; i++) {
    if (i != skip_row) {
       for (int j = 0, column = 0; j < A->columns; j++) {
         if (j != skip_column) {
           B->matrix[row][column++] = A->matrix[i][j];
         }
       }
      row++; 
    } 
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows <= 0 || A->columns <= 0) {
    return kCodeIncorrect;
  }

  if (A->rows != A->columns) {
    return kCodeCalcError;
  }
  
  S21OperationsResultCode result_code = kCodeOK;

  matrix_t minor;
  if (A->rows == 1) {
    if (s21_create_matrix(A->rows, A->columns, result) != 1) {
       result->matrix[0][0] = A->matrix[0][0];
    }
  } else if (s21_create_matrix(A->rows, A->columns, result) != 1 && s21_create_matrix(A->rows-1, A->columns-1, &minor) != 1) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double det = 0.0;
      double factor = (i + j) % 2 != 0 ? -1.0 : 1.0;

      s21_create_minor(A, &minor, i, j);
      s21_determinant(&minor, &det);
      
      result->matrix[i][j] = det*factor;
    }
  }
  s21_remove_matrix(&minor);
 } else {
   result_code = kCodeIncorrect;
 }

  return result_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->rows == 0 || A->columns == 0) {
    return kCodeIncorrect;
  }

  if (A->rows != A->columns) {
    return kCodeCalcError;
  }

  S21OperationsResultCode result_code = kCodeOK;
  double det = 0.0;
  s21_determinant(A, &det);
  if (det == 0.0) {
    result_code = kCodeCalcError; 
  } else {
    det = 1.0 / det;
    matrix_t multiplier, complements;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &multiplier);
    s21_mult_number(&multiplier, det, result);     
    s21_remove_matrix(&multiplier);
    s21_remove_matrix(&complements);
  }
  return result_code;
}

void s21_copy_matrix(matrix_t* A, matrix_t* B) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
       B->matrix[i][j] = A->matrix[i][j];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  S21OperationsResultCode result_code = kCodeOK;
  if (A == NULL || result == NULL || A->rows == 0 || A->columns == 0) {
    return kCodeIncorrect;
  }

  if (A->rows != A->columns) {
    return kCodeCalcError;
  }

  matrix_t B;
  s21_create_matrix(A->rows, A->columns, &B);
  s21_copy_matrix(A, &B);

  int swap_count = 0;
  double det = 1.0;

  if (s21_triangulate_matrix(&B, &swap_count) == -1) {
    det = 0.0;
  } else {
    s21_print_matrix(&B);
    if (swap_count % 2 == 1) {
      det = -1.0;
    }
    for (int i = 0; i < B.rows; i++) {
      det *= B.matrix[i][i];
    }
  }
  *result = det;
  s21_remove_matrix(&B);
  return result_code;
}


