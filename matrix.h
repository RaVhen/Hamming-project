#ifndef MATRIX_HAMMING
#define MATRIX_HAMMING

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Matrix Matrix;
struct Matrix{
  int col;
  int row;
  int** matrix;
};

/* create Matrix r rows c columns */
Matrix CreateNewMatrix(int r, int c);

/* Free the Matrix */
void free_matrix(Matrix mat);

/* Print the matrix */
void printm(Matrix mat);

/* Init the hamming matrix */
void init_Hamming(Matrix mat);

/* Matrix multiplication */
Matrix times_Matrix(Matrix mat1, Matrix mat2);

/* Convert static matrix in Matrix format */
Matrix convert(int r, int c, int mat[r][c]);

/* Encode message */
Matrix encode(Matrix mat);

/* Decode message */
Matrix decode(Matrix mat);

/* Transpose matrix */
Matrix transpose(Matrix mat);

/* Copy A into B */
void copy_Matrix(Matrix mat1, Matrix mat2);

/* Correct matrix */
Matrix correct(Matrix mat, Matrix hmat);

/* Generate random matrix */
Matrix random_Matrix(int r, int c);

/* Test if mat1 mat2 are equals */
int are_equals(Matrix mat1, Matrix mat2);

/* Create noise */
Matrix noise(Matrix mat, double d);
#endif
