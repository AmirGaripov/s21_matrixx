#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int status = OK;
  if (rows <= 0 || columns <= 0 || !result) {
    status = INCORRECT_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double**)calloc(rows, sizeof(double*));
  if (!result->matrix) {
    status = CALCULATION_FAIL;
  }
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double*)calloc(columns, sizeof(double));

    if (!result->matrix[i]) {
      status = CALCULATION_FAIL;
    }
  }
  if (status == CALCULATION_FAIL) {
    s21_remove_matrix(result);
  }
  return status;
}
