#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livros{
  char titulo[100];
  unsigned int num_pag;
  float preco;
}Livro;
Livro *create_livro(const char *titulo, int num_pag, int preco){
  Livro *livro = (Livro*) calloc(1, sizeof(Livro));

  strcpy(livro->titulo, titulo);
  livro->num_pag = num_pag;
  livro->preco = preco;

  return livro;
}
void destroy_livro(Livro **livro_ref){
  //PEGA O ENDERECO DO LIVRO CRIADO
  Livro *livro = *livro_ref;
  //APAGA ESSE ENDERECO
  free(livro);
  //MANDA O ENDERECO FICAR NULO
  *livro_ref = NULL;

}

typedef struct _dados_vetor{
  Livro **vet;
  int size_vet;
}StructDadosVetor;

StructDadosVetor *create_vetor(const Livro **vet, int size){
  StructDadosVetor *dvt = (StructDadosVetor*) calloc(size, sizeof(StructDadosVetor));
  dvt->size_vet = size;
  dvt->vet = vet;
  return dvt;
}

void destroy_dados_vetor(StructDadosVetor **structDadosVetor_ref){
  StructDadosVetor *dadosVetor = *structDadosVetor_ref;
  free(dadosVetor);
  *structDadosVetor_ref = NULL;
}

int main(){
  
  return 0;
}