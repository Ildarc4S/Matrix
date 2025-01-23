#include "memory.h"
#include "type.h"
#include "transforms.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  matrix_t A;
  s21_create_matrix(4, 4, &A); 
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = rand() / (double)RAND_MAX;
    }
  }
  s21_print_matrix(&A);
  double res = 0.0;
  s21_determinant(&A, &res);
  printf("%f\n", res); 
  s21_print_matrix(&A);
  s21_remove_matrix(&A);
  return 0;
}
