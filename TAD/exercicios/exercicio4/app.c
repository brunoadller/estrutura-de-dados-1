#include "cilindro.h"
#include <stdio.h>

int main(){

  Cilindro *cilindro = cilindro_create();

  cilindro_print(cilindro);
  cilindro_set(cilindro, 5.0, 2.0, 3.14);
  cilindro_print(cilindro);
  cilindro_destroy(cilindro);
  return 0;
}