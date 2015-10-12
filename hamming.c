#include <stdlib.h>
#include <string.h>
#include "matrix.h"

/* For debug purpose only */
/*void print_matrix(int m[r][c], int r, int c){
  int x, y;
  for(x = 0; x < r; x++){
    for(y = 0; y < c; y++){
      printf("%d", (m[x][y]));
    }
    printf("\n");
  }
  }*/

int main(int argc, char* argv[]){
  int hmatrix[4][7] = {
    {1,0,0,0,0,1,1},
    {0,1,0,0,1,0,1},
    {0,0,1,0,1,1,0},
    {0,0,0,1,1,1,1}
  };

  print_matrix(4, 7, hmatrix);
  return 0;
}
