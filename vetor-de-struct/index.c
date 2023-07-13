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

//forma mais bem estruturada para criar uma estrutura de vetor e dentro dela colocar os dados para o tamanho
//e dentro dela receberá um vetor de struct de dados
typedef struct _vetor_livros{
  Livro **vet;
  int size;//numero de elementos do vetor
}vetorLivros;

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

bool livros_sao_iguais(const Livro *livro_1, const Livro *livro_2){
  if(strcmp(livro_1->titulo, livro_2->titulo) == 0){
    return true;
  }else{
    return false;
  }
}
int main(){
  //criando um vetor de livros
  Livro **vet = (Livro *) calloc(3, sizeof(Livro*));
  //inserindo os dados para cada struct de livro e criando-as
  vet[0] = create_livro("Harry Potter 1", 200, 25.00);
  vet[1] = create_livro("A batalha do Apocallipse", 600, 40);
  vet[2] = create_livro("O senhor dos Anéis", 500, 15);
  for(int i = 0; i < 3; i++){
    print_livro(vet[i]);
  }
  //destruindo um vetor de struct de livro
  for(int i = 0; i < 3; i++){
    destroy_livro(&vet[i]);
  }
  free(vet);
  vet = NULL;
  return 0;
}