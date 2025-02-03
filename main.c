#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

int main() {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);

  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);

  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);

  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      b.matrix[i][j] = 3.3431413598;
      true_result.matrix[i][j] = 2.13243422 - 3.3431413598;
  }
  printf("%d\n", s21_sub_matrix(&a, &b, &result));
  printf("%d\n",s21_eq_matrix(&result, &true_result));
  s21_print_matrix(&result);
  s21_print_matrix(&true_result);
  return 0;
}
