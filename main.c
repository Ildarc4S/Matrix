#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main() {

  matrix_t a = {0};
  s21_create_matrix(1, 1, &a);
  
  matrix_t result = {0};
  s21_create_matrix(1, 1, &result);
  
  matrix_t true_result = {0};
  s21_create_matrix(1, 1, &true_result);
  a.matrix[0][0] = 0.5;
  true_result.matrix[0][0] = 1.0 / 0.5;

  printf("%d\n", s21_inverse_matrix(&a, &result));
  printf("%d\n", s21_eq_matrix(&result, &true_result));

  s21_print_matrix(&result);
  s21_print_matrix(&true_result);
  return 0;
}
