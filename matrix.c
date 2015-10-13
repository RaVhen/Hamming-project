#include "matrix.h"

Matrix CreateNewMatrix(int r, int c){
  Matrix mat;
  mat.row = r;
  mat.col = c;
  mat.matrix = (int**)malloc(c * sizeof(int*));
  int i;
  for(i = 0; i < c; i++){
    mat.matrix[i] = (int*)calloc(r, sizeof(int));
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
  int hmatrix[4][7] = {
    {1,0,0,0,0,1,1},
    {0,1,0,0,1,0,1},
    {0,0,1,0,1,1,0},
    {0,0,0,1,1,1,1}
  };
  int i,j;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 7; j++){
      mat.matrix[i][j] = hmatrix[i][j];
    }
  }
}

Matrix times_Matrix(Matrix mat1, Matrix mat2){
  Matrix result = CreateNewMatrix(mat1.row, mat2.col);
  int i,j;
  int n,k;
  for(i = 0; i < result.row; i++){
    for(j = 0; j < result.col; j++){
      
    }
  }
  
  return result;
}

