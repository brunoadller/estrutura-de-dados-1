#include "fila2.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no{
  int val;
  No *proximo;
  No *anterior;
}No;
typedef struct lista{
  int tamanho;
  No *inicio;
  No *final;
}Lista;
typedef struct fila{
  Lista *dados;
}Fila;

No *criar_no(int val){
  No *novo_no = (No *)calloc(1,sizeof(No));

  novo_no->val = val;
  novo_no->anterior = NULL;
  novo_no->proximo = NULL;

  return novo_no;
}
Lista *criar_lista(){
  Lista *nova_lista = (Lista *) calloc(1, sizeof(Lista));

  nova_lista->inicio = NULL;
  nova_lista->final = NULL;
  nova_lista->tamanho = 0;

  return nova_lista;
}
void destroi_lista(Lista **lista_ref){
  Lista *l = *lista_ref;

  No *p = l->inicio;
  No *aux = NULL;

  while(p != NULL){
    aux = p;
    p = p->proximo;
    free(aux);
  }

  free(l);
  *lista_ref = NULL;
}
bool lista_vazia(Lista *l){
  return l->tamanho == 0;
}
int tamanho_lista(Lista *l){
  return l->tamanho;
}

void adiciona_final(Lista *l, int val){
  No *novo_no = cria_no(val);

  novo_no->anterior = l->final;
  if(lista_vazia(l)){
    l->inicio = novo_no;
  }else{
    l->final->proximo = novo_no;
  }
  l->final = novo_no;
  l->tamanho ++;
}

void imprimir(Lista *l){
  No *p = l->inicio;

  while(p != NULL){
    printf(" %d -> ", p->val);
    p = p->proximo;
   
  }
   printf("NULL\n");
   if(l->final == NULL){
    printf("L->final = NULL");
   }else
   {
    printf("L->final = %d ", l->final->val);
   }
   printf(" Tamanho:  %lu\n",l->tamanho);
   puts("");
   
}
void remove_inicio(Lista *l){
  if(!lista_vazia(l)){
    No * p = l->inicio;
    if(l->inicio == l->final){
      l->inicio = NULL;
      l->final = NULL;
    }else{
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
  return l->inicio->val;
}
Fila *criar_fila(){
  Fila *f = (Fila *) calloc(1, sizeof(Fila));
  f->dados = cria_lista();

  return f;
}

void destroi_fila(Fila **fila_ref){
  Fila *f = *fila_ref;
  destroi_lista(&f->dados);
  free(f);
  *fila_ref = NULL;
}
bool fila_vazia(Fila *f){
  return lista_vazia(f->dados);
}
long tamanho_fila(Fila *f){
  return tamanho_lista(f->dados);
}
int consultar_fila(Fila *f){
  return pega_primeiro_valor(f->dados);
}
void enfileirar(Fila *f, int val){
  adiciona_final(f->dados, val);
}
int desenfileirar(Fila *f){
  int val = pega_primeiro_valor(f->dados);
  remove_inicio(f->dados);
  return val;
}
void imprimir_fila(Fila *f){
  imprimir(f->dados);
}