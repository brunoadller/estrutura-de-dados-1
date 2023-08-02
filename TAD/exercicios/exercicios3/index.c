#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
  Cubo *cubo = cubo_create();
  cubo_print(cubo);
  cubo_set(cubo, 5.8, 9.7, 3.4);
  cubo_print(cubo);
  cubo_destroy(cubo);
  return 0;
}