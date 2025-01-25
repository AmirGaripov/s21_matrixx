#include "../s21_matrix.h"

void calcMinor(double** A, double** minor, int skipRow, int skipCol, int size) {
  for (int row = 0, x = 0; row < size; row++) {
    for (int col = 0, y = 0; col < size; col++) {
      if (row != skipRow && col != skipCol) {
        minor[x][y++] = A[row][col];
        if (y == size - 1) {
          y = 0;
          x++;
        }
      }
    }
  }
}

double calcDeterminant(matrix_t* A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t aux = {0};
  double result = 0;
  s21_create_matrix(size, size, &aux);
  for (int sign = 1, x = 0; x < size; x++, sign *= (-1)) {
    calcMinor(A->matrix, aux.matrix, 0, x, size);
    result += sign * A->matrix[0][x] * calcDeterminant(&aux, size - 1);
  }

  s21_remove_matrix(&aux);
  return result;
}
