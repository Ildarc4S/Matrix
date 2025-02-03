#ifndef MATRIX_TRANSFORMS_H
#define MATRIX_TRANSFORMS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "operations.h"
#include "type.h"
#include "utils.h"

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);

int triangulate(matrix_t *A);

#endif  // MATRIX_TRANSFORMS_H
