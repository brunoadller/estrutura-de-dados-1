#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void insertionSort(int *v, int N);
void verificaAlocacao(int *v);
void colocaValoresNoVetor(int *v, int tam);
void imprimeValoresDoVetor(int *v, int tam);
void desalocaVetor(int *v);

int main(){
  //calculo do tempo
  double time = 0.0;
  clock_t inicio = clock();

  //realiza os procedimentos
  int tamanho = 1000000;
  int *vet = (int*) calloc(tamanho, sizeof(int));

  verificaAlocacao(vet);
  colocaValoresNoVetor(vet, tamanho);
  insertionSort(vet, tamanho);
  imprimeValoresDoVetor(vet, tamanho);
  desalocaVetor(vet);

  //final do tempo
  time_t fim = clock();
  time += (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("\n\ntempo decorrido: %f segundos.", time);
  return 0;
}
void insertionSort(int *v, int N){
  int i, j, atual;
  for(int i = 1; i < N; i++){
    atual = v[i];
    for(j = i; (j > 0) && (atual < v[j - 1]); j--){
      v[j] = v[j-1];
    }
    v[j] = atual;
  }
}
void selectionSort(int *v, int N){
  int i, j, troca, menor;
  for(i = 0; i< N-1; i++){
    menor = i;
    for(j = i + 1; j < N; j++){
      if(v[j] < v[menor]){
        menor = j;
      }
    }
    if(i != menor){
      troca = v[i];
      v[i] = v[menor];
      v[menor] = troca;
    }
  }
}
void verificaAlocacao(int *v){
  if(v == NULL){
    exit(EXIT_FAILURE);
  }
}
void colocaValoresNoVetor(int *v, int tam){
  srand(time(NULL));
  for(int i = 0; i < tam; i++){
    v[i] = rand() % 500000;
  }
}
void imprimeValoresDoVetor(int *v, int tam){
  for(int i = 0; i < tam; i++){
    printf(" %d ", v[i]);
  }
}
void desalocaVetor(int *v){
  free(v);
}