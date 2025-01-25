#include "../s21_matrix.h"

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int error_code = OK;
  error_code = s21_create_matrix(A->rows, A->columns, result);
  if (error_code) {
    error_code = CREATION_FAIL;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return error_code;
}