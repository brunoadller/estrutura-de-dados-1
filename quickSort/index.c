#include <stdio.h>

//particiona o algoritmo
int particiona(int *v, int inicio, int final){
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = final;
  pivo = v[inicio];
  while(esq < dir){
    while(v[esq] <= pivo)
      esq++;
    while(v[esq] > pivo)
      dir--;
    if(esq < dir){
      aux=v[esq];
      v[esq] = v[dir];
      v[dir] = aux;
    }
  }
}
void quickSort(int *v, int inicio, int fim){
  int pivo;
  if(fim > inicio){
    pivo = particiona(v, inicio, fim);
    quickSort(v, inicio, pivo-1);
    quickSort(v, pivo + 1, fim);
  }
}
int main(){
  int v[10] = {4,6,7,2,8,9,10,44,1,0};
  quickSort(v, 0, 9);
  for(int i = 0; i < 10; i++){
    printf(" %d ", v[i]);
  }
  return 0;
}