#ifndef MATRIX_TRANSFORMS_H
#define MATRIX_TRANSFORMS_H

#include "type.h"
#include "memory.h"
#include "operations.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);

int triangulate(matrix_t* A);

#endif // MATRIX_TRANSFORMS_H

