#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno{
  char nome[100];
  int idade;
}Aluno;

int main(){
  
  Aluno *ted = (Aluno*) calloc(1, sizeof(Aluno));

  strcpy(ted->nome, "Ted");
  ted->idade = 10;

  return 0;
}