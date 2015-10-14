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

void free_matrix(Matrix mat){
  int i;
  for(i = 0; i < mat.row; i++){
    free(mat.matrix[i]);
  }
  free(mat.matrix);
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

Matrix encode(Matrix mat){
  Matrix hamming = CreateNewMatrix(4,7);
  init_Hamming(hamming);
  Matrix result = times_Matrix(mat, hamming);
  free_matrix(hamming);
  return (result);
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
  int i,j;
  for(i = 0; i < mat.row; i++){
    for(j = 0; j < mat.col; j++){
      result.matrix[j][i] = mat.matrix[i][j];
    }
  }
  return result;
}

void copy_Matrix(Matrix mat1, Matrix mat2){
  int i,j;
  for(i = 0; i < mat1.row; i++){
    for(j = 0; j < mat1.col; j++){
      mat2.matrix[i][j] = mat1.matrix[i][j];
    }
  }
}

Matrix correct(Matrix mat, Matrix hmat){
  Matrix error = times_Matrix(hmat, transpose(mat));
  Matrix result = CreateNewMatrix(mat.row, mat.col);
  copy_Matrix(mat, result);
  if(error.matrix[0][0] == 0
     && error.matrix[1][0] == 0
     && error.matrix[2][0] == 0){
    /*printf("No error(s) found in the message\n");*/
  }
  else{
    /*printf("Error(s) found in message, correcting ...\n");*/
    int pos = (error.matrix[0][0] * 4) +
      (error.matrix[1][0] * 2) +
      (error.matrix[2][0] * 1) - 1;
    result.matrix[0][pos] = (result.matrix[0][pos] + 1) % 2;  
  }
  free_matrix(error);
  return result;
}

Matrix random_Matrix(int r, int c){
  Matrix result = CreateNewMatrix(r,c);
  int i,j;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      result.matrix[i][j] = rand() % 2;
    }
  }
  return result;
}

int are_equals(Matrix mat1, Matrix mat2){
  int i,j;
  for(i = 0; i < mat1.row; i++){
    for(j = 0; j < mat1.col; j++){
      if(mat1.matrix[i][j] != mat2.matrix[i][j])
	return 0;
    }
  }
  return 1;
}

Matrix noise(Matrix mat, double d){
  Matrix result = CreateNewMatrix(mat.row, mat.col);
  copy_Matrix(mat, result);
  int i,j,count;
  count = 0;
  for(i = 0; i < result.row; i++){
    for(j = 0; j < result.col; j++){
      double r = (double)rand() / (double)RAND_MAX;
      if(r < d){
	result.matrix[i][j] = (result.matrix[i][j] + 1) % 2;
	count++;
      }
    }
  }
  /*printf("Alterate %d bits in message\n", count);*/
  return result;
}
