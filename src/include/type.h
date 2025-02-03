#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <stdlib.h>

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  CODE_OK = 0,
  CODE_INCORRECT = 1,
  CODE_CALC_ERROR = 2,
} S21OperationsResultCode;
#endif
