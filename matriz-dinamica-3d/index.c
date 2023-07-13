#include <stdio.h>
#include <stdlib.h>

int main(){
  int n_slices = 2;
  int n_rows = 2;
  int n_cols = 3;

  int ***m = (int***) calloc(n_slices, sizeof(int**));
  if(m == NULL){
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < n_rows; i++){
    m[i] = (int**) calloc(n_rows, sizeof(int*));
    if(m[i] == NULL){
      exit(EXIT_FAILURE);
    }
    for(int j = 0; j < n_cols; j++){
      m[i][j] = (int*) calloc(n_cols, sizeof(int));
      if(m[i][j] == NULL){
        (EXIT_FAILURE);
      }
    }
  }

  
  printf("&m = %p, m = %p\n\n", &m, m);
  int cont = 0;
  for(int k = 0; k < n_slices; k++ ){
    //imprimindo a fatia
    printf("&m[%d] = %p, m[%d] = %p\n",k, &m[k], k, m[k]);
    for(int i = 0; i< n_rows; i++){
      //imprimindo a linha
      printf("&m[%d][%d] = %p, m[%d][%d] = %p\n",k,i, &m[k][i], k,i, m[k][i]);

      for(int j= 0; j < n_cols; j++){
        printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", 
          k,i,j, &m[k][i][j], k,i,j, m[k][i][j]
        );
      }
      puts("");
    }
    puts("");
  }
  //para cada fatia
  for(int k = 0; k < n_slices; k++){


    for(int i = 0; i < n_rows; i++){
      //deu um free na primeira e segunda linha linha
      //isso desaloca as colunas
      free(m[k][i]);
    }
    //desaloca as linhas
    free(m[k]);
  }
  //desaloca o m
  free(m);
  m = NULL;
  return 0;
}

