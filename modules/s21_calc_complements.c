#include "../s21_matrix.h"

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  if (A->rows != A->columns) {
    return INCORRECT_MATRIX;
  }
  int error_code = s21_create_matrix(A->rows, A->columns, result);
  if (error_code != OK) {
    return CREATION_FAIL;
  }
  s21_create_matrix(A->columns, A->rows, result);
  if (A->rows != 1) {
    matrix_t minor = {0};

    s21_create_matrix(A->rows, A->rows, &minor);
    for (int sign = 0, x = 0; x < A->rows; x++) {
      for (int y = 0; y < A->columns; y++) {
        calcMinor(A->matrix, minor.matrix, x, y, A->rows);
        sign = ((x + y) % 2 == 0) ? 1 : (-1);
        result->matrix[x][y] = sign * calcDeterminant(&minor, A->rows - 1);
      }
    }

    s21_remove_matrix(&minor);
  } else {
    result->matrix[0][0] = 1;
  }

  return OK;
}
