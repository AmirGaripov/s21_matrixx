#include "../s21_matrix.h"

int s21_determinant(matrix_t* A, double* result) {
  int error_code = OK;
  if (A->rows != A->columns) {
    error_code = INCORRECT_MATRIX;
  }

  matrix_t complements;
  error_code = s21_calc_complements(A, &complements);
  if (error_code != OK) {
    error_code = CREATION_FAIL;
  }

  double det = 0.0;
  for (int i = 0; i < A->rows; i++) {
    det += A->matrix[0][i] * complements.matrix[0][i];
  }

  s21_remove_matrix(&complements);

  *result = det;
  return error_code;
}