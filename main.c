#include "memory.h"
#include "type.h"
#include "transforms.h"
#include "utils.h"

int main() {
  matrix_t A;
  s21_create_matrix(3, 4, &A); 
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i+j;
    }
  }
  triangulate(&A); 
  s21_print_matrix(&A);
  s21_remove_matrix(&A);
  return 0;
}
