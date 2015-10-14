#include "matrix.h"

int main(int argc, char* argv[]){

  /*Matrix lucien = CreateNewMatrix(4,7);
  init_Hamming(lucien);
  
  int tmat[1][4] = {1, 0, 0, 1};*/
  int hmat[3][7] = {
    {0,0,0,1,1,1,1},
    {0,1,1,0,0,1,1},
    {1,0,1,0,1,0,1}
  };
  Matrix hmatrix = convert(3, 7, hmat);
  /*Matrix puissant = convert(1, 4, tmat);
  Matrix hmatrix = convert(3, 7, hmat);
  Matrix result = times_Matrix(puissant, lucien);
  Matrix decod = decode(result);
  Matrix error = correct(result, hmatrix);*/

  double p = 0.01;
  
  Matrix randMatrix = random_Matrix(1,4);
  printf("Random message is:\n");
  printm(randMatrix);
  
  Matrix c = encode (randMatrix);
  printf("Encoded message is:\n");
  printm(c);
  
  Matrix c2 = noise(c, p);
  printf("Noised message is:\n");
  printm(c2);
  
  Matrix cor = correct(c2, hmatrix);
  printf("Corrected message is:\n");
  printm(cor);

  Matrix deco = decode(cor);
  printf("Decoded message is:\n");
  printm(deco);

  if(are_equals(randMatrix, deco) == 1){
    printf(" M == M'\n");
  }
  else{
    printf(" M =\\= M'\n");
  }
  
  /*printm(lucien);
  printf("\n");
  printm(puissant);
  printf("\n");
  printm(result);
  printf("\n");
  printm(decod);
  printf("\n");
  printm(error);
  printf("\n");
  printm(randMatrix);
  printf("\n");

  free_matrix(lucien);
  free_matrix(puissant);
  free_matrix(hmatrix);
  free_matrix(result);
  free_matrix(decod);  
  free_matrix(error);
  free_matrix(randMatrix);*/
  
  return 0;
}
