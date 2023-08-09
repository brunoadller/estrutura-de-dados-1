#include "circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//RESPONSÁVEL POR REPRESENTAR OS NÓS QUE APONTARAM APARA OUTROS VALORES DA LISTA
typedef struct no_circular{
  int val;
  NoCircular *prev;
  NoCircular *next;
}NoCircular;
//LISTA QUE TERÁ UM NÓ APONTADO PARA O INICIO E O FINAL DA LISTA
typedef struct lista_circular{
  NoCircular *begin;
  NoCircular *end;
  size_t size;
}ListaCircular;

NoCircular *criando_no(int val){
  NoCircular  *no = (NoCircular*) calloc(1, sizeof(NoCircular));
  /*
    Isso representa a estrutura no criando apontando para ela mesma enquanto 
    não tem mais valores adicionados
    ________
    |  10  |-------/     
    |_______|-----|
  */
  no->val = val;
  no->prev = no;
  no->next = no;

  return no;
}

void destruindo_no(NoCircular ** no_referencia){
  NoCircular *no = *no_referencia;
  free(no);
  *no_referencia = NULL;
}

ListaCircular *criando_lista_circular(){
  ListaCircular *L = (ListaCircular *) calloc(1, sizeof(ListaCircular));
  /*
    lista apontando para Null
    para seu inicio e fim
  */
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;

  return L;
}
void add_inicio_lista(ListaCircular *L, int val){
  //cria um nó p que ira apontar para o 
  //inicio da lista que terá o primeiro valor
  NoCircular *p = criando_no(val);
  if(lista_esta_vazia(L)){
    L->end = p;
  }else{
    //se p sera o novo cabeça da lista p será o L->BEGIN
    p->next = L->begin;
    L->begin->prev = p;
    p->prev = L->end;
    L->end->next = p;
  }
  L->begin = p;
  //aumentando o tamanho da lista
  L->size++;
}
void destruindo_lista_circular(ListaCircular **lista_referencia){
  ListaCircular *L = *lista_referencia;

  NoCircular *p = L->begin;
  NoCircular *aux = NULL;
  /*
    PERCORRE DO INICIO DESALOCANDO O PONTEIRO P PARA CADA VALOR 
    DA LISTA E QUANDO CHEGAR NO ULTMIMO ELE SERÁ DESALOCADO POR FORA DO LAÇO
    PARA PODER N]AO PERDER O ENDERECO DA LISTA
  */
 /*
  enquanto p for diferente do no final, cria-se um auxiliar para destruir o anterior
  e o p apontar para o proximo
 */
 while(p != L->end){
  aux = p;
  p = p->next;
  destruindo_no(&aux);
 }
 /*Se o p é igual ao nó final depois do laco preciso desalocar ess nó*/
 destruindo_no(&p);
 free(L);

  *lista_referencia = NULL;

}
//outra maneira de destruir a lista
void destruindo_lista_circular_2(ListaCircular **lista_referencia){
  ListaCircular *L = *lista_referencia;

  NoCircular *p = L->begin;
  NoCircular *aux = NULL;
  for(int i = 0; i < L->size; i++){
    aux = p;
    p = p->next;
    destruindo_no(&aux);
  }
  free(L);

  *lista_referencia = NULL;
}

bool lista_esta_vazia(const ListaCircular *L){
  return L->size == 0;
}

