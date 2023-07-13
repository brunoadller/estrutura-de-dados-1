#include <stdio.h>
#include <stdlib.h>

int soma(int vet[], int tam){
  if(tam == 0){
    return 0;
  }else{
    return vet[tam - 1] + soma(vet, tam - 1);
  }
}

int main(){
  int vet[10] = {1,2,3,4,5,6,7,8,9,10};
  int tam = 10;
  printf("Resultado da soma e: %d",soma(vet, tam));
  return 0;
}