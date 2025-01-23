#include "transforms.h"
#include "memory.h"
#include <math.h>

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

int s21_max_in_column(matrix_t* A, int column) {
  int max_index = 0;
  for (int i = 1; i < A->rows; i++) {
    if (!compareNum(fabs(A->matrix[max_index][column]), fabs(A->matrix[i][column]))) {
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

int triangulate(matrix_t* A) {
  int swap_count = 0;
  for (int curr_column = 0; curr_column< A->rows; curr_column++) {

    int max_in_column = s21_max_in_column(A, curr_column); 

    if (fabs(A->matrix[max_in_column][curr_column]) < 1e-10) {
      break;
    }
    
    if (max_in_column != curr_column) {
      s21_swap_rows(A, max_in_column, curr_column);
      ++swap_count;
    }

    for (int j = curr_column+1; j < A->rows; j++) {
      double factor = A->matrix[j][curr_column]/A->matrix[curr_column][curr_column];
      for (int i = curr_column; i < A->rows; i++) {
        A->matrix[j][i] -= A->matrix[curr_column][i]*factor;
      }
    }
  }
  return swap_count;
}

/*int s21_calc_complements(matrix_t *A, matrix_t *result) {*/
/*}*/

/*int s21_inverse_matrix(matrix_t *A, matrix_t *result) {*/
/*}*/

int s21_determinant(matrix_t *A, double *result) {
  triangulate(A);
  double det = 1.0;
  for (int i = 0; i < A->rows; i++) {
    det *= A->matrix[i][i];
  }
  *result = det;
  return 0;
}


