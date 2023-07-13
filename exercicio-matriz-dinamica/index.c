#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int **criaMatrizDinamica(size_t n_rows, size_t n_cols);
void imprimiMatrizDinamica(size_t n_rows, size_t n_cols,int **m);
void colocaValoresNaMatriz(size_t n_rows, size_t n_cols,int **m);
void desalocaMemoriaDaMatriz(size_t n_rows, int **m);

int main(int argc, char *argv[]){
  int n_rows = 3, n_cols = 3;

  int **m = criaMatrizDinamica(n_rows, n_cols);
  colocaValoresNaMatriz(n_rows, n_cols, m);
  imprimiMatrizDinamica(n_rows,n_cols,m);
  desalocaMemoriaDaMatriz(n_rows, m);
  return 0;
}

int **criaMatrizDinamica(size_t n_rows, size_t n_cols){
  int **m = (int**) calloc(n_cols, sizeof(int*));
  if(m == NULL){
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < n_rows; i++){
    m[i] = (int*) calloc(n_cols, sizeof(int));
    if(m[i] == NULL){
      (EXIT_FAILURE);
    }
  }
  return m;
}
void colocaValoresNaMatriz(size_t n_rows, size_t n_cols,int **m){

 for(int i = 0; i < n_rows; i++){
    for(int j = 0; j < n_cols; j++){
      m[i][j] = rand() % 9;
    }
  }
}
void imprimiMatrizDinamica(size_t n_rows, size_t n_cols,int **m){

  printf("&m = %p, m = %p\n\n",&m, m);
  for(int i = 0; i < n_rows; i++){

    printf("&m[%d] = %p, m[%d] = %d\n", i, &m[i], i, m[i]);

    for(int j = 0; j < n_cols; j++){
      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]);
    }
    puts("");
  } 
}
void desalocaMemoriaDaMatriz(size_t n_rows, int **m){
    for(int i = 0; i < n_rows; i++){
      free(m[i]);
    }
    free(m);
    m = NULL;
}