#include "matrix.h"

int main(int argc, char* argv[]){

  Matrix lucien = CreateNewMatrix(4,7);
  init_Hamming(lucien);
  
  int tmat[1][4] = {1, 0, 0, 1};
  int hmat[3][7] = {
    {0,0,0,1,1,1,1},
    {0,1,1,0,0,1,1},
    {1,0,1,0,1,0,1}
  };
  Matrix puissant = convert(1, 4, tmat);
  Matrix hmatrix = convert(3, 7, hmat);
  Matrix result = times_Matrix(puissant, lucien);
  Matrix decod = decode(result);
  Matrix error = correct(result, hmatrix);
  
  printm(lucien);
  printf("\n");
  printm(puissant);
  printf("\n");
  printm(result);
  printf("\n");
  printm(decod);
  printf("\n");
  printm(error);
  printf("\n");

  return 0;
}