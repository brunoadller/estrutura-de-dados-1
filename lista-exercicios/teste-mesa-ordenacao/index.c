#include <stdio.h>
#include <stdlib.h>

void verificaSeNull(int *v){
  if(v == NULL){
    exit(EXIT_FAILURE);
  }
}
void desaloca(int *v){
  free(v);
}

int main(){
  int *vet1 = (int*) calloc(6,sizeof(int));
  int *vet2 = (int*) calloc(6, sizeof(int));
  int *vet3 = (int*) calloc(6, sizeof(int));
  int *vet4 = (int*) calloc(12, sizeof(int));
  int *vet5 = (int*) calloc(12, sizeof(int));
  int *vet6 = (int*) calloc(10, sizeof(int));
  verificaSeNull(vet1);
  verificaSeNull(vet2);
  verificaSeNull(vet3);
  verificaSeNull(vet4);
  verificaSeNull(vet5);
  verificaSeNull(vet6);





  desaloca(vet1);
  desaloca(vet2);
  desaloca(vet3);
  desaloca(vet4);
  desaloca(vet5);
  desaloca(vet6);
  system("pause");
  return 0;
}