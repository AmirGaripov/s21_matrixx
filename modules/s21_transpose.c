#include "../s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  int error_code = OK;
  error_code = s21_create_matrix(A->columns, A->rows, result);
  if (error_code) {
    error_code = CREATION_FAIL;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return error_code;
}