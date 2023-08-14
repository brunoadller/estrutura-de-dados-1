#include "fila.h"
#include <stdio.h>
int main(){
  Fila *f = cria_fila();

  enfileirar(f, 2);
  enfileirar(f, 3);
  enfileirar(f, 8);
  enfileirar(f, 9);
  enfileirar(f, 77);
  enfileirar(f, 50);
  enfileirar(f, 21);
  
  imprimir_fila(f);
  destroi_fila(f);
  return 0;

}