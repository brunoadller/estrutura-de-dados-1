#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    {
    {2, "Andre", 9.5, 7.8,8.5},
    {4, "Ricardo", 7.5, 8.7,6.8},
    {1, "Bianca", 9.7, 6.7,8.4},
    {3, "Ana", 5.7, 6.1,7.4},
    };
  */
 //terei uma struct do tipo aluno
typedef struct aluno{
  int mat;
  char nome[30];
  float n1, n2, n3;
}Aluno;
void insertionSortNome(Aluno *v, int N){
  int i, j;
  Aluno aux;
  for(i = 1; i < N; i++){
    aux = v[i];
    for(j = i;(j > 0) && (strcmp(aux.nome, v[j-1].nome) < 0); j--){
      v[j] = v[j-1];
    }
    v[j] = aux;
  }
}
int main(){
  
  int i;
  //vou ter um vetor de ponteiros que irá apontar para 
  //um ponteiro do tipo aluno dentro da heap
  //que ira armazenar 4 tipos de dados do tipo aluno
  //nos endereços de memoria alocados
  Aluno *vetorAlunos = (Aluno*) calloc(4, sizeof(Aluno));
  if(vetorAlunos == NULL){
    exit(EXIT_FAILURE);
  }
  printf("\n--------Preencha os dados dos Alunos--------\n");
  for(i = 0; i < 4; i++){
    printf("\nMatricula.....: ");scanf("%d", &vetorAlunos[i].mat);
    printf("\nNome..........: ");scanf("%s",vetorAlunos[i].nome);
    printf("\nNota 1........: ");scanf("%f", &vetorAlunos[i].n1);
    printf("\nNota 2........: ");scanf("%f", &vetorAlunos[i].n2);
    printf("\nNota 3........: ");scanf("%f", &vetorAlunos[i].n3);

  }
  insertionSortNome(vetorAlunos, 4);
  printf("\n--------Resultado--------\n");
  for(i = 0; i < 4; i++){
    printf("\nMatricula.....: %d", vetorAlunos[i].mat);
    printf("\nNome..........: %s",vetorAlunos[i].nome);
    printf("\nNota 1........: %.2f", vetorAlunos[i].n1);
    printf("\nNota 2........: %.2f", vetorAlunos[i].n2);
    printf("\nNota 3........: %.2f", vetorAlunos[i].n3);

  }

  
  free(vetorAlunos);
  system("pause");
  return 0;
}