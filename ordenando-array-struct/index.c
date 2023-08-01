#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
  int mat;
  char nome[30];
  float n1, n2, n3;
};

void insertionSortMatricula(struct aluno *v, int N){
  int i, j;
  struct aluno aux;
  for(i = 1; i < N; i++){
    aux = v[i];
    for(j = i; (j > 0) && (aux.mat < v[j - 1].mat); j--){
      v[j] = v[j-1];
    }
    v[j] = aux;
  }
}
void insertionSortNome(struct aluno *v, int N){
  int i, j;
  struct aluno aux;
  for(i = 1; i < N; i++){
    aux = v[i];
    for(j = i; (j > 0) && (strcmp(aux.nome, v[j-1].nome) < 0); j--){
      v[j] = v[j-1];
    }
    v[j] = aux;
  }
}
int main(){
  int i;
  struct aluno v[4] = {
    {2, "Andre", 9.5, 7.8,8.5},
    {4, "Ricardo", 7.5, 8.7,6.8},
    {1, "Bianca", 9.7, 6.7,8.4},
    {3, "Ana", 5.7, 6.1,7.4},
  };
  insertionSortMatricula(v,4);
  for(i = 0; i < 4; i++){
    printf("Matricula:  %d\tNome: %s\n",v[i].mat, v[i].nome);
  }
  system("pause");
  return 0;
}