#include <stdio.h>
#include <stdlib.h>

int buscaBinariaRecursiva(int *vet, int chave, int inicio, int fim){
  int meio;
  if(inicio <= fim){
    meio = (inicio + fim)/2;
    if(chave == vet[meio]){
      return meio;
    }else{
      if(chave < vet[meio]){
        return buscaBinariaRecursiva(vet, chave, inicio, meio - 1);
      }else{
        return buscaBinariaRecursiva(vet, chave, meio + 1, fim);
      }
    }
  }
  return -1; //elemento não encontrado
}
int buscaBinariaIterativa(int *vet, int chave, int fim){
  int inicio = 0;
  int meio = (inicio + fim)/2;
  while(inicio <= fim){
    if(meio == vet[meio]){
      return meio;
    }else{
      if(chave < vet[meio]){
        fim = meio - 1;
      }else{
        inicio = meio + 1;
      }
      meio = (inicio + fim)/2;
    }
  }return -1;
}

int main(){
  int vet[16] = {1,2,3,12,14,15,21,24,45,46,47,53,86,90,98};
  int valor, op;
  do{
    printf("Digite um valor a ser buscado: ");
    scanf(" %d ", &valor);
    printf("\nResultado:  %d\n", buscaBinariaIterativa(vet, valor, 15));

    printf("\n0 - sair\n1 - Nova Busca\n");
    scanf(" %d ", &op);

  }while(op != 0);
  return 0;
}