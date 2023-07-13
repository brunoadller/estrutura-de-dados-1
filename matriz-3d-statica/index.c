#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_slices = 2;
  int n_rows = 2;
  int n_cols = 3;
  //matriz com 2 fatias 2 linhas e 3 colunas
  int m[2][2][3] = {
    //fatia [0]
    {
      {0,1,2},//linha [0]
      {4,5,6} //linha[1]
    },
    //fatia[1]
    {
      {7,8,9},//linha[0]
      {10,11,12}//linha[10]
    },
  };

  printf("&m = %p, m = %p\n\n", &m, m);

  for(int k = 0; k < n_slices; k++ ){
    for(int i = 0; i< n_rows; i++){
      for(int j= 0; j < n_cols; j++){
        printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", 
          k,i,j, &m[k][i][j], k,i,j, m[k][i][j]
        );
      }
    }
  }
  return 0;
}