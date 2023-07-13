#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno{
  char nome[100];
  int idade;
}Aluno;

int main(){
  Aluno ted;
  strcpy(ted.nome, "Ted");
  ted.idade = 10;
  //atribuição de nomes de uma variável statica
  Aluno julio = {.nome = "Julio", .idade = 30};
  printf("sizeof(Aluno) = %lu bytes\n", sizeof(Aluno));

  return 0;
}