#include "simples.h"
#include <stdio.h>


int main(){
  Lista *l; //declara uma lista não iniciada
  l = inicializa();//inicia lista vazia
  l = insere(l, 23);//inseres o elemento 23
  l = insere(l, 45);//insere o elemento 45
  l = insere(l, 56);//insere o elemento 56
  l = insere(l, 78);//insere o elemento 78
  imprime(l); //imprimirá: 78 56 45 23
  l = retira(l, 78);
  imprime(l);//imprimira 56, 45, 23
  l = retira(l, 45);
  imprime(l);//imprimirá: 56, 23
  libera(l);
  return 0;
}