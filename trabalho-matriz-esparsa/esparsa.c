#include "esparsa.h"
#include <stdlib.h>
#include <stdio.h>

struct celula{
  Celula *direita;
  Celula *abaixo;
  int linha;
  int coluna;
  float valor;
};
struct matrizEsparca{
   int m, n;
   Celula *inicio;
   Celula *fimLinha;
   Celula *fimColuna;
};

//m = linha e n = colunas
Matriz *matrix_create(int m, int n){
  Matriz *mat = (Matriz*) calloc(1, sizeof(Matriz));

  if(!mat || m <= 0 || n <=0){
    return 0;
  }
  //inicia as variaveis da struct
  mat->inicio = NULL;
  mat->fimLinha = NULL;
  mat->fimColuna = NULL;
  mat->m = m;
  mat->n = n;

  iniciaCabecas(mat);

  return mat;

}

int iniciaCabecas(Matriz *mat){
  int i = 0;
  //aloca para uma cabeca que sao do tipo celula
  Celula *cabeca = (Celula *) calloc(1, sizeof(Celula));
  if(!cabeca){
    return 0;
  }

  //celula principal recebe -1 pois representam as celulas cabeças
  cabeca->coluna = -1;
  cabeca->linha = -1;

  //matriz que entrou para inicializar as cabeças recebe a cabeca para poder inicializar
  //as linhas e as colunas
  mat->inicio = cabeca;
  mat->fimLinha = cabeca;
  mat->fimColuna = cabeca;

  for(i = 1; i <= mat->n; i++){
    insereCabecaColuna(mat);
  }
  for(i = 1; i <= mat->m; i++){
    insereCabecaLinha(mat);
  }
  return 1;
}
int insereCabecaColuna(Matriz *mat){
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
int insereCabecaLinha(Matriz *mat){
  Celula *cabeca = (Celula*) calloc(1, sizeof(Celula));

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

  Celula *pCelula; //ponteiro para uma celula temporaria
  Celula *pCelulaColuna;//ponteiro para uma celula para coluna temporaria
  Celula *pCelulaLinha;//ponteiro para uma celula para linha temporaria

  pCelula = (Celula *) calloc(1, sizeof(Celula));

  if(!pCelula){
   exit(EXIT_FAILURE);
  }
  pCelula->linha = linha;
  pCelula->coluna = coluna;
  pCelula->valor = valor;

  pCelulaLinha = mat->inicio->abaixo;//LINHA APONTA PARA A PRIMEIRA CABECA SO DE LINHA
  pCelulaColuna = mat->inicio->direita;//COLUNA APONTA PARA PRIMEIRA CABECA SO DE COLUNA

  //PERCORRE ATE A LINHA DO ELEMENTO, PERCORRE NAS CABECAS ATE A INFORMADA
  for(i = 0; i < linha - 1; i++){//-1 pq ja ta na primeira
    pCelulaLinha = pCelulaLinha->abaixo;//percorre para baixo(linhas) ate achar a correta

  }
  i=0;
  while(i < coluna && pCelulaLinha->direita->linha != -1){
    if (pCelulaLinha->direita->coluna > pCelula->coluna){ //se a celula inserida esta a esquerda
      pCelula->direita = pCelulaLinha->direita;
      pCelulaLinha->direita = pCelula;
    }else{
      pCelulaLinha = pCelulaLinha->direita;//anda pelas celulas a direita
    }
    i++;
  }
  if(pCelulaLinha->direita->linha == -1){//a celula esta mais a direita
    pCelula->direita = pCelulaLinha->direita;//aponta para a cabeca
    pCelulaLinha->direita = pCelula;//ultima celula ou cabeca, senao tiver celulas, aponta para celulula
  }
  //linha encontrada e apontada

  //agora tera de encontrar a coluna
  //percorre ate a coluna do elemento, percorre nas cabecas ate a informada
  for(i = 0; i < coluna - 1; i++){//-1 pq ja ta na primeira
    pCelulaColuna = pCelulaColuna->direita;//percorre a direita colunas ate achar a correta
  }
  i = 0;
  while(i < linha && pCelulaColuna->abaixo->coluna != -1){
    if(pCelulaColuna->abaixo->linha > pCelula->linha){
      pCelula->abaixo = pCelulaColuna->abaixo;
      pCelulaColuna->abaixo = pCelula;
    }else{
      pCelulaColuna = pCelulaColuna->abaixo;//anda pelas celulas abaixo
    }
    i++;
  }
  if(pCelulaColuna->abaixo->coluna == -1){
    pCelula->abaixo = pCelulaColuna->abaixo;//aponta para a cabeca
    pCelulaColuna->abaixo = pCelula;//ultima celula ou cabeca, senao tiver celulas, aponta para a celula
  }
  
}
void matrix_print(Matriz *mat){
    int i, j;
    Celula *pCelula;

    if (!mat || !mat->m || !mat->n){
       exit(EXIT_FAILURE);
    }

    pCelula = mat->inicio->abaixo;

    printf("\n");

    for (i = 1; i <= mat->m; i++){
        for (j = 1; j <= mat->n; j++){
            if (pCelula->direita->linha == i && pCelula->direita->coluna == j){
                pCelula = pCelula->direita;
                printf("  \t%0.2f   ", pCelula->valor);
            }
            else{
                printf("  \t%0.2f   ", 0.0F);
            }
        }
        printf("\n");
        pCelula = pCelula->direita->abaixo;
    }

}
void matrix_destroy(Matriz *mat){
    int i = 1;
    int j = 1;
    Celula *pCelula, *aux;

    if (!mat || !mat->m || !mat->n){
      exit(EXIT_FAILURE);
    }

    pCelula = mat->inicio->abaixo;
    pCelula = pCelula->direita;

    for (i = 1; i <= mat->m; i++){
        for (j = 1; j <= mat->n; j++){
            if (pCelula->linha == i && pCelula->coluna == j){
                aux = pCelula;
                pCelula = pCelula->direita;
                free(aux);
            }
        }
        pCelula = pCelula->abaixo->direita;
    }

    //apaga cabecas
    pCelula = mat->inicio->direita;

    for (i = 0; i < mat->n; i++){ //cabecas coluna
        aux = pCelula;
        pCelula = pCelula->direita;
        free(aux);
    }

    pCelula = mat->inicio->abaixo;
    for (i = 0; i < mat->m; i++){ //cabecas linha
        aux = pCelula;
        pCelula = pCelula->abaixo;
        free(aux);
    }

    pCelula = mat->inicio;
    free(pCelula);

    mat->fimColuna = mat->fimLinha = mat->inicio = NULL;
    mat->m = mat->n = 0;
    mat = NULL;
}
float matrix_getelem(Matriz *mat, int linha, int coluna){
  Celula *pCelula;
  int i = 0;

  pCelula = mat->inicio->direita;

  for(i = 0; i < coluna-1; i++){
    pCelula = pCelula->direita;
  }
  do{
    pCelula = pCelula->abaixo;
    if(pCelula->linha == linha){
      return pCelula->valor;
    }
  }while(pCelula->coluna != -1);

  return 0; //elemento não encontrado
}
Matriz *matrix_add(Matriz *matA, Matriz *matB){
    int i, j;
    float soma;
    Matriz *matC;
    Celula *pCelulaA, *pCelulaB;

    if (matA->m != matB->m || matA->n != matB->n){ //soma de matrizes so é possivel qndo as duas forem de mesma ordem
        printf("\nMatrizes de Ordem diferente.\nSo eh possivel somar matrizes de mesma ordem\n");
        return NULL;
    }

    if (!matA || !matB || !matA->m || !matA->n){
        return NULL;
    }

    matC = matrix_create(matA->m, matB->n);

    pCelulaA = matA->inicio->abaixo;
    pCelulaB = matB->inicio->abaixo;

    for (i = 1; i <= matA->m; i++){
        for (j = 1; j <= matA->n; j++){
            if (j == pCelulaA->direita->coluna && j == pCelulaB->direita->coluna){
                soma = pCelulaA->direita->valor + pCelulaB->direita->valor;
                if (soma){
                    matrix_setelem(matC, i, j, soma);
                }
                pCelulaA = pCelulaA->direita;
                pCelulaB = pCelulaB->direita;
            }
            else if (j == pCelulaA->direita->coluna){
                matrix_setelem(matC, i, j, pCelulaA->direita->valor);
                pCelulaA = pCelulaA->direita;
            }
            else if (j == pCelulaB->direita->coluna){
                matrix_setelem(matC, i, j, pCelulaB->direita->valor);
                pCelulaB = pCelulaB->direita;
            }
        }
        pCelulaA = pCelulaA->direita->abaixo;
        pCelulaB = pCelulaB->direita->abaixo;
    }

    return matC;
}
Matriz *matrix_multiply(Matriz *matA, Matriz *matB){
    int i=0, j=0, k=0;
    float total;
    Matriz *matC;

    if (matA->n != matB->m){ //so pode multiplicar se o numero de colunas de A eh igual ao numero de linhas de B
        printf("\nNao foi possivel multiplicar as matrizes\nnumero de colunas de A eh diferente do numero de linhas de B\n");
        return NULL;
    }

    if (!matA || !matB || !matA->m || !matA->n || !matB->n){
        return NULL;
    }

    matC = matrix_create(matA->m, matB->n); //C é formada pelo numero de linhas de A e de colunas de B

    for (i = 1; i <= matA->m; i++){
        for (j = 1; j <= matB->n; j++){
            total = 0;
            for (k = 1; k <= matA->n; k++){
                total += matrix_getelem(matA,i,k) * matrix_getelem(matB,k,j);
            }
            if (total){
                matrix_setelem(matC,i,j,total);
            }
        }
    }
    return matC;
}