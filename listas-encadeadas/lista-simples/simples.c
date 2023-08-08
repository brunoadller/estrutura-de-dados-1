#include "simples.h"
#include <stdlib.h>
#include <stdio.h>

struct lista{
  int info;
  Lista *prox;
};

Lista *inicializa(void){
  return NULL;
  
}
//Função para liberar espaço da lista
void libera(Lista *l){
  Lista *p = l;
  while(p != NULL){
    Lista *t = p->prox;//guarda referencia para o proximo elemento
    free(p);//libera a memoria apontada po p
    p = t;//faz p apontar para o proximo
  }
}

Lista *insere(Lista *l, int i){
  Lista *novo = (Lista *) malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = l;
  return novo;
}
void imprime(Lista *l){
  Lista *p;//variavel auxiliar para percorrer a lista
  for(p = l; p != NULL; p = p->prox){
    printf("info = %d\n", p->info);
  }
}
//função vazia: retorna 1 se vazia ou zero se não vazia
int vazia (Lista *l){
  if(l == NULL){
    return 1;
  }else{
    return 0;
  }
}
//função de busca: busca um elemento na lista
Lista *busca(Lista *l, int v){
  Lista *p;
  for(p = l; p != NULL; p = p->prox){
    if(p->info == v){
      return p;
    }
  }
  return NULL;
}
//função que retira elemento da lista
Lista *retira (Lista*l, int v){
  Lista *ant = NULL; // ponteiro para elemento anterior
  Lista *p = l; //ponteiro para percorrer a lista

  //procura elemento na lista, guardando anterior
  while(p != NULL && p->info != v){
    ant = p;
    p = p->prox;
  }
   //verifica se achou elemento
   if(p == NULL){
     return l; //nao achou retorna lista original
   }
   //retira elemento
   if(ant == NULL){
    //RETIRA O ELEMENTO DO INICIO;
    l = p->prox;
   }else{
    //retira elemento do meio da lista
    ant->prox = p->prox;
   }
   free(p);
   return l;
}