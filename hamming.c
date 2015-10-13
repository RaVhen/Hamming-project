#include "matrix.h"

int main(int argc, char* argv[]){

  Matrix lucien = CreateNewMatrix(4,7);
  init_Hamming(lucien);
  printm(lucien);
  return 0;
}
