#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-6

#define SUCCESS 0
#define FAILURE 1

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALCULATION_FAIL = 2,
  CREATION_FAIL = 2
} matrix_status_t;

int s21_create_matrix(int rows, int columns, matrix_t* result);
int s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
void calcMinor(double** A, double** aux, int skipRow, int skipCol, int size);
double calcDeterminant(matrix_t* A, int size);
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

#endif