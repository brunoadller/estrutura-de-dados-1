#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _livro{
  char titulo[100];
  unsigned int num_paginas;
  float preco;
} Livro;

//STRUCT lIVRO
typedef struct _aluno{
  char nome[100];
  int idade;
  Livro * livro_fav;

}Aluno;

//forma de representar o vetor titulo com ponteiro, é uma constante pois não será modificado
Livro *create_livro(const char *titulo, unsigned int num_paginas, float preco){
  //aloca pra mim na heap um tipo de dado do tamanho de Livro
  Livro *livro = (Livro*) calloc(1, sizeof(Livro));

  //atribuição dos valores no livro-> titulo, num_pagina, preco;
  strcpy(livro->titulo, titulo);
  livro->num_paginas = num_paginas;
  livro->preco = preco;
  return livro;
}
//como é um ponteiro e a impressão é só para leitura coloca-se const
void print_livro(const Livro *livro){
  printf("Titulo: %s\n", livro->titulo);
  printf("Num paginas: %d\n", livro->num_paginas);
  printf("Preco: R$  %.2f\n", livro->preco);
}
//forma para desalocar o ponteiro da struct
void destroy_livro(Livro **livro_ref){
  Livro *livro = *livro_ref;
  free(livro);
  *livro_ref = NULL;
}
Livro *copy_livro(const Livro *livro){
  return create_livro(livro->titulo, livro->num_paginas, livro->preco);
}

Aluno *create_aluno(const char *nome, int idade, const Livro *livro){
  Aluno *aluno = (Aluno *) calloc(1, sizeof(Aluno));

  strcpy(aluno->nome, nome);
  aluno->idade = idade;
  aluno->livro_fav = copy_livro(livro);
}
void print_aluno(const Aluno *aluno){
  printf("Nome: %s\n", aluno->nome);
  printf("Idade: %d\n", aluno->idade);
  printf("Livro Favorito");
  puts("---------");
  print_livro(aluno->livro_fav);

}

void destroy_aluno(Aluno **aluno_ref){
  Aluno *aluno = *aluno_ref;
  destroy_livro(&aluno->livro_fav);//pega a regiao de memoria onde esta o livro do aluno
  free(aluno);
  *aluno_ref = NULL;
}
bool livros_sao_iguais(const Livro *livro_1, const Livro *livro_2){
  if(strcmp(livro_1->titulo, livro_2->titulo) == 0){
    return true;
  }else{
    return false;
  }
}
int main(){
 
  Livro *livro_harry = create_livro("Harry Potter 1", 200, 25.00);
  print_livro(livro_harry);
  livro_harry->preco = 39;
  print_livro(livro_harry);

  Aluno *ted = create_aluno("Ted", 20, livro_harry);
  print_aluno(ted);

  puts("\nLivros sao iguais"); 
  if(livros_sao_iguais(ted->livro_fav, livro_harry)){
    puts("TRUE");
  }else{
    puts("False");
  } 
  //destruindo o livro
  destroy_livro(&livro_harry);

  print_aluno(ted);

  destroy_aluno(&ted);
  return 0;
}