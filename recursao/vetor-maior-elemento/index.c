#include <stdio.h>
#include <stdlib.h>

int maior(int vet[], int tam, int indice){
  if(tam == 0){
    return vet[indice];
  }else{
    if(vet[tam - 1 ] > vet[indice]){
      return maior(vet, tam - 1, tam - 1);
    }else{
      return maior(vet, tam - 1, indice);
    }
  }
}

int main(){
  int vet[10] = {11,258,13,445,58,67,7,800,9,10};
  int tam = 10;
  printf("O maior e: %d",maior(vet, tam, 0));
  return 0;
}