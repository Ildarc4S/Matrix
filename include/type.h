#ifndef MATRIX_TYPE_H
#define MATRIX_TYPE_H

#include <stdlib.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

typedef enum {
  kCodeOK = 0,
  kCodeIncorrect = 1,
  kCodeCalcError = 2,
} S21OperationsResultCode;
#endif
