#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int N){
  int i, continua, aux, fim = N;
  int cont = 1;
  do{
    continua = 0;
    printf("\n%d iteracao.\n", cont);
    for(i = 0; i < fim -1; i++){
      if(v[i] > v[i+1]){
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
        continua = i;
      }
      
    }
    for(int i = 0; i < 10; i++){
      printf(" %d ",v[i]);
  };
    cont++;
    printf("\n");
    fim--;
  }while(continua != 0);
}
int main(){
  int vet[10] = {20,11,16,9,12,14,17,19,13,15};
  for(int i = 0; i < 10; i++){
    printf(" %d ",vet[i]);
  };
  printf("\n[ ");
  bubbleSort(vet,10);
  for(int i = 0; i < 10; i++){
    printf(" %d ",vet[i]);
  };
  printf(" ]\n");
  system("pause");
  return 0;
}