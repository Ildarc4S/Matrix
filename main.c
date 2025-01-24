#include "memory.h"
#include "type.h"
#include "transforms.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "test.h"

int main() {
 // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
  eq_matrix.matrix[0][2] = 1;
  eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
  eq_matrix.matrix[1][2] = -34;
  eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
  eq_matrix.matrix[2][2] = 24;
  printf("%d\n", s21_inverse_matrix(&A, &result)); //, OK);
  printf("%d\n", s21_eq_matrix(&result, &eq_matrix)); // SUCCESS);
  s21_print_matrix(&result);
  printf("\n");
  s21_print_matrix(&eq_matrix);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
  return 0;
}
