#include <stdio.h>
#include <stdlib.h>

int main(){

  int nrows = 2;
  int ncols = 3;

  int **m = (int**) calloc(nrows, sizeof(int*));
  if(m == NULL){
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < nrows; i++){
    m[i] = (int*) calloc(ncols, sizeof(int));
    if(m[i] == NULL){
      exit(EXIT_FAILURE);
    }
  }
  int cont = 0;

  printf("&m = %p, m = %p\n\n", &m, m);

  for(int i = 0; i < nrows; i++){
    printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
    for(int j = 0; j < ncols; j++){
      m[i][j] = cont++;

      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n"
      , i, j, &m[i][j], i, j, m[i][j]);
    }
  puts("");

  }

  for(int i = 0; i < nrows; i++){
    free(m[i]);
  }
  free(m);
  m = NULL;
  return 0;
}