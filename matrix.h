#ifndef MATRIX_HAMMING
#define MATRIX_HAMMING

#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix Matrix;
struct Matrix{
  int col;
  int row;
  int** matrix;
};

/* create Matrix r rows c columns */
Matrix CreateNewMatrix(int r, int c);

/* Print the matrix */
void printm(Matrix mat);

/* Init the hamming matrix */
void init_Hamming(Matrix mat);

/* Matrix multiplication */
Matrix times_Matrix(Matrix mat1, Matrix mat2);

/* Convert static matrix in Matrix format */
Matrix convert(int r, int c, int mat[r][c]);

/* Decode message */
Matrix decode(Matrix mat);

/* Transpose matrix */
Matrix transpose(Matrix mat);

/* Correct matrix */
Matrix correct(Matrix mat, Matrix hmat);
#endif
