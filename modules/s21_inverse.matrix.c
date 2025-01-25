#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int error_code = OK;
  error_code = s21_create_matrix(A->columns, A->rows, result);
  if (error_code) {
    error_code = CREATION_FAIL;
  }
  double determinant = 0.0;
  if (A->rows != A->columns) {
    error_code = INCORRECT_MATRIX;
  }
  s21_determinant(A, &determinant);
  if (determinant == 0) {
    error_code = INCORRECT_MATRIX;
  }
  matrix_t algeb_matrix;
  s21_calc_complements(A, &algeb_matrix);

  matrix_t trans_matrix;
  s21_transpose(&algeb_matrix, &trans_matrix);

  for (int i = 0; i < trans_matrix.rows; i++) {
    for (int j = 0; j < trans_matrix.columns; j++) {
      result->matrix[i][j] = 1.0 / determinant * trans_matrix.matrix[i][j];
    }
  }
  s21_remove_matrix(&algeb_matrix);
  s21_remove_matrix(&trans_matrix);

  return error_code;
}
