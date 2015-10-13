#include "matrix.h"

Matrix CreateNewMatrix(int r, int c){
  Matrix mat;
  mat.row = r;
  mat.col = c;
  mat.matrix = (int**)malloc(r * sizeof(int*));
  int i;
  for(i = 0; i < r; i++){
    mat.matrix[i] = (int*)calloc(c, sizeof(int));
  }
  int j;
  for(i=0; i < r; i++){
    for(j=0; j< c; j++){
      mat.matrix[i][j] = j;
    }
  }
  
  return mat;
}

void printm(Matrix mat){
  int x, y;
  for(x = 0; x < mat.row; x++){
    for(y = 0; y < mat.col; y++){
      printf("%d", (mat.matrix[x][y]));
    }
    printf("\n");
  }
}

void init_Hamming(Matrix mat){
  int gmatrix[4][7] = {
    {1,0,0,0,0,1,1},
    {0,1,0,0,1,0,1},
    {0,0,1,0,1,1,0},
    {0,0,0,1,1,1,1}
  };
  int i,j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 7; j++){
      mat.matrix[i][j] = gmatrix[i][j];
    }
  }
}

Matrix times_Matrix(Matrix mat1, Matrix mat2){
  Matrix result = CreateNewMatrix(mat1.row, mat2.col);
  int i,j;
  int n,k,sum;
  for(i = 0; i < result.row; i++){
    for(j = 0; j < result.col; j++){
      sum = 0;
      for(n = 0; n < mat1.col; n++){
	sum += mat1.matrix[i][n] * mat2.matrix[n][j];
      }
      result.matrix[i][j] = sum % 2;
    }
  }
  
  return result;
}


Matrix convert(int r, int c, int mat[r][c]){
  Matrix result = CreateNewMatrix(r,c);
  int i,j;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      result.matrix[i][j] = mat[i][j];
    }
  }
  return result;
}

Matrix decode(Matrix mat){
  Matrix result = CreateNewMatrix(mat.row, mat.col - 3);
  int i,j;
  for(i = 0; i < result.row; i++){
    for(j = 0; j < result.col; j++){
      result.matrix[i][j] = mat.matrix[i][j];
    }
  }
  return result;
}

Matrix transpose(Matrix mat){
  Matrix result = CreateNewMatrix(mat.col, mat.row);
  printm(result);
  int i,j;
  for(i = 0; i < mat.row; i++){
    for(j = 0; j < mat.col; j++){
      result.matrix[j][i] = mat.matrix[i][j];
    }
  }
  return result;
}

Matrix correct(Matrix mat, Matrix hmat){
  Matrix error = times_Matrix(hmat, transpose(mat));
  return error;
}
