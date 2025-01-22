#include "memory.h"
#include "type.h"

int main() {
  matrix_t A;
  s21_create_matrix(3, 4, &A); 
  s21_remove_matrix(&A);
  return 0;
}
