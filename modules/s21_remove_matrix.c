#include "../s21_matrix.h"

int s21_remove_matrix(matrix_t* A) {
  int status = OK;
  if (A) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
  return status;
}