#include "../s21_matrix.h"
#include <check.h>

int main() {
      matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t result = {0};
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  int c = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c++;
    }
  true_result.matrix[0][0] = -2;
  true_result.matrix[0][1] = 1;
  true_result.matrix[1][0] = 1.5;
  true_result.matrix[1][1] = -0.5;
  s21_inverse_matrix(&a, &result);
//   ck_assert_int_eq(0, );
//   ck_assert_int_eq(1, s21_eq_matrix(&result, &true_result));
  
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}