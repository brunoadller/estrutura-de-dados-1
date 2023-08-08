#include "duplamente.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
  int valor;
  struct no *proximo;
  struct no *anterior;
}No;

struct lista{
  No *inicio;
  No *final;
  int size;
}Lista;


No *no_create(int num){
  No *novo = (No*) calloc(1, sizeof(No));
  novo->proximo = NULL;
  novo->anterior = NULL;
  novo->valor = num;

  return novo;
}
Lista *list_create(){
  Lista *L = (Lista*) calloc(1, sizeof(Lista));
  L->inicio = NULL;
  L->final = NULL;
  L->size = 0;
  return L;
}
void list_destroy(Lista **list_ref){
  Lista *L = *list_ref;
  No *p = L->inicio;
  No *aux = NULL;
  while (p != NULL)
  {
    /* code */
    aux = p;
    p = p->proximo;
    free(aux);
  }
  
}