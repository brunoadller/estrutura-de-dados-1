#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no{
  struct no *proximo;
  struct no *anterior;
  int valor;
}No;
typedef struct lista{
  No *inicio;
  No *fim;
  int tamanho;
}Lista;
/*LISTA DUPLAMENTE ENCADEADA COM AS FUNÇÕES PARA MANIPULAR A FILA*/
No * cria_no(int val){
  No *novo_no = (No*) calloc(1, sizeof(No));
  
  novo_no->anterior = NULL;
  novo_no->proximo = NULL;
  novo_no->valor = val;

  return novo_no;
}

Lista * cria_lista(){
  Lista *lista_nova = (Lista*) calloc(1, sizeof(Lista));

  lista_nova->inicio = NULL;
  lista_nova->fim = NULL;
  lista_nova->tamanho = 0;

  return lista_nova;
}

void destroi_lista(Lista **lista){
  Lista *l = *lista;

  No *p = l->inicio;
  No *aux = NULL;

  while( p != NULL){
    aux =p;
    p = p->proximo;
    free(aux);
  }
  free(l);
  *lista = NULL;
}
bool lista_vazia(Lista *l){
  return l->tamanho == 0;
}

int tamanho(Lista *l){
  return l->tamanho;

}

void adiciona_inicio(Lista *l, int val){
  No *p = cria_no(val);

  p->proximo = l->inicio;
  if(lista_vazia(l)){
    l->fim =p;
  }else{
    l->inicio->anterior = p;
  }
  l->inicio = p;
  l->tamanho++;
}
void adiciona_final(Lista *l, int val){
  No *p = cria_no(val);
  p->anterior = l->fim;
  if(lista_vazia(l)){
    l->inicio = p;

  }else{
    l->fim->proximo = p;
  }
  l->fim =p;
  l->tamanho++;
}
void imprimir(Lista *l){
  No *p = l->inicio;

  while(p != NULL){
    printf("%d -> ", p->valor);
    p =p->proximo;
  }
  printf("NULL\n");

  if(l->fim == NULL){
    printf("L->FIM = NULL");
  }else{
    printf("L->FIM = %d", l->fim->valor);
  }
  printf("Tamanho: %lu\n", l->tamanho);
  puts("");
}
void remove_inicio(Lista *l){
  if(!lista_vazia(l)){
    No *p = l->inicio;

    if(l->inicio == l->fim){
      l->inicio = NULL;
      l->fim = NULL;

    }
   else{
    l->inicio = l->inicio->proximo;
    l->inicio->anterior = NULL;
   }
   free(p);
   l->tamanho--;
  }
}
int pega_primeiro_valor(Lista *l){
  if(lista_vazia(l)){
      fprintf(stderr, "ERROR in 'List_get_first_val'\n");
      fprintf(stderr, "A lista está vazia\n");
      exit(EXIT_FAILURE); // termina o programa com um código de erro
        // EXIT_FAILURE ==> stdlib.h
  }
  return l->inicio->valor;
}

/*FUNÇÕES DA FILA*/
typedef struct fila{
  Lista *dados;
}Fila;

Fila *cria_fila(){
  Fila *f = (Fila *) calloc(1, sizeof(Fila));
  f->dados = cria_lista();
  return f;
}
void destroi_fila(Fila **fila_referencia){
  Fila *f = *fila_referencia;

  destroi_lista(f->dados);
  free(f);
  *fila_referencia = NULL;
}

bool fila_vazia(Fila *f){
  return lista_vazia(f->dados);
}

long tamanho_fila(Fila *f){
  return tamanho(f->dados);
}

int consultar_fila(Fila *f){
  return pega_primeiro_valor(f->dados);
}
void enfileirar(Fila *f,int val){
  adiciona_final(f->dados, val);
}
int desenfileirar(Fila *f){
  int val = pega_primeiro_valor(f);
  remove_inicio(f->dados);
  return val;
}
void imprimir_fila(Fila *f){
  imprimir(f->dados);
}