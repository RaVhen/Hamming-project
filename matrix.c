#include "matrix.h"

void print_matrix(int r, int c, int m[r][c]){
  int x, y;
  for(x = 0; x < r; x++){
    for(y = 0; y < c; y++){
      printf("%d", (m[x][y]));
    }
    printf("\n");
  }
}
