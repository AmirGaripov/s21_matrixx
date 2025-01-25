#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int error_code = OK;
  error_code = s21_create_matrix(A->rows, B->columns, result);
  if (error_code) {
    error_code = CREATION_FAIL;
  }
  if (A->columns == B->rows && !error_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int n = 0; n < A->columns; n++) {
          result->matrix[i][j] += A->matrix[i][n] * B->matrix[n][j];
        }
      }
    }
  } else {
    error_code = INCORRECT_MATRIX;
  }
  return error_code;
}