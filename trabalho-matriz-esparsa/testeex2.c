#include "esparsa.h"
#include <stdio.h>
#include <time.h>       

int main(){
  //Testando Matriz grande
  double time = 0.0;
 
  clock_t inicio = clock();
  printf("Matriz A: \n");
  Matriz *mA = matrix_create_for_test(5);
  matrix_print_for_test( mA );
  
  printf("Matriz B: \n");
  Matriz *mB = matrix_create_for_test(5);
  matrix_print_for_test( mB );

  printf("Soma da Matriz A e B: \n");
  Matriz *mC = matrix_add(mA, mB);
  matrix_print_for_test(mC);
  
  matrix_destroy( mC );
  
  printf("Multiplicacao de A e B");
  mC = matrix_multiply(mA, mB);
  matrix_print_for_test(mC);
  matrix_destroy( mC );
  
  printf("Trasposta de A");
  mC = matrix_transpose(mA);
  matrix_print_for_test(mC);

  matrix_destroy( mC );
  matrix_destroy( mB );
  matrix_destroy( mA );
  clock_t fim = clock();
  time += (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo de  %f segundos", time);
  return 0;
}