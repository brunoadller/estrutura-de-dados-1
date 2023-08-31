#include "esparsa.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct celula{
  Celula *direita;
  Celula *abaixo;
  int linha;
  int coluna;
  float valor;
};

struct matriz{
  int m, n;
  Celula *inicio;
  Celula *fimLinha;
  Celula *fimColuna;
};

Matriz *matrix_create(int m, int n){
  Matriz *mat = (Matriz*) calloc(1, sizeof(Matriz));

  if(!mat || m<=0 || n <=0){
    return NULL;
  }

  mat->inicio = NULL;
  mat->fimLinha = NULL;
  mat->fimColuna = NULL;
  mat->m = m;
  mat->n = n;

  iniciaCabecasDaMatriz(mat);
  return mat;
}
int iniciaCabecasDaMatriz(Matriz *mat){
  int i=0;

  Celula *cabeca = (Celula*) calloc(1, sizeof(Celula));
  cabeca->coluna = -1;
  cabeca->linha = -1;

  mat->inicio = cabeca;
  mat->fimLinha = cabeca;
  mat->fimColuna = cabeca;

  for(i = 1; i<= mat->n; i++){
    insereCabecaDaColuna(mat);
  }
  for(i = 1; i <= mat->m; i++){
    insereCabecaDaLinha(mat);
  }
  return 1;
}

int insereCabecaDaColuna(Matriz *mat){
  Celula *cabeca = (Celula*) calloc(1, sizeof(Celula));

  if(!cabeca){
    return 0;
  }
  cabeca->coluna = -1;
  cabeca->linha = 0;

  mat->fimColuna->direita = cabeca;
  mat->fimColuna = cabeca;

  cabeca->direita = mat->inicio;
  cabeca->abaixo = cabeca;
  return 1;
}

int insereCabecaDaLinha(Matriz *mat){
  Celula *cabeca = (Celula *) calloc(1, sizeof(Celula));

  if(!cabeca){
    return 0;
  }
  cabeca->coluna = 0;
  cabeca->linha = -1;

  mat->fimLinha->abaixo = cabeca;
  mat->fimLinha = cabeca;

  cabeca->abaixo = mat->inicio;
  cabeca->direita = cabeca;

  return 1;
}
void matrix_setelem(Matriz *mat, int linha, int coluna, float valor){
  int i;
    if (!mat || mat->m <= 0 || mat->n <= 0 || !valor){ //esses testes sao feitos tbm na funcao lerMatriz
        exit(EXIT_FAILURE);
    }
    if (linha>mat->m || coluna>mat->n || !valor || linha < 1 || coluna < 1){
        exit(EXIT_FAILURE);
    }

  Celula *pCelula;
  Celula *pCelulaColuna;
  Celula *pCelulaLinha;

  pCelula = (Celula *) calloc(1, sizeof(Celula));

  if(!pCelula){
    exit(EXIT_FAILURE);
  }
  pCelula->linha = linha;
  pCelula->coluna = coluna;
  pCelula->valor = valor;

  pCelulaLinha = mat->inicio->abaixo;
  pCelulaColuna = mat->inicio->direita;

  for(i = 0; i < linha - 1; i++){
    pCelulaLinha= pCelulaLinha->abaixo;// até encontrar a linha informada
  }
  i = 0;
  while(i < coluna && pCelulaLinha->direita->linha != -1){
    if(pCelulaLinha->direita->coluna > pCelula->coluna){
      pCelula->direita = pCelulaLinha->direita;
      pCelulaLinha->direita = pCelula;
    }else{
      pCelulaLinha = pCelulaLinha->direita;
    }
    i++;
  }
  if(pCelulaLinha->direita->linha == -1){
    pCelula->direita = pCelulaLinha->direita;
    pCelulaLinha->direita = pCelula;
  }

  for(i = 0; i < coluna -1; i++){
    pCelulaColuna = pCelulaColuna->direita;
  }
  i = 0;
  while(i < linha && pCelulaColuna->abaixo->coluna != -1){
    if(pCelulaColuna->abaixo->linha > pCelulaLinha){
      pCelula->abaixo = pCelulaColuna->abaixo;
      pCelulaColuna->abaixo = pCelula;
    }else{
      pCelulaColuna = pCelulaColuna->abaixo;
    }
    i++;
  }

  if(pCelulaColuna->abaixo->coluna == -1){
    pCelula->abaixo = pCelulaColuna->abaixo;
    pCelulaColuna->abaixo = pCelula;
  }
}