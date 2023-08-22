#include "esparsa.h"
#include <stdio.h>
#include <time.h>       

int main(){
  //Testando Matriz grande
  double time = 0.0;
 
  clock_t inicio = clock();
  printf("Matriz A: \n");
  Matriz *mA = matrix_create_for_test(10);
  matrix_print_for_test( mA );
  
  printf("Matriz B: \n");
  Matriz *mB = matrix_create_for_test(10);
  matrix_print_for_test( mB );

  printf("Matriz A e B somadas: \n");
  Matriz *mC = matrix_add( mA, mB );
  matrix_print_for_test( mC );
  matrix_destroy( mC );

  printf("Matriz A e B multiplicadas: \n");
  mC = matrix_multiply( mA, mB );
  matrix_print_for_test( mC );
  matrix_destroy( mC );

  printf("Transposta de A: \n");
  mC = matrix_transpose( mA );
  matrix_print_for_test( mC );
  matrix_destroy( mC );
 
  matrix_destroy( mA );
  matrix_destroy( mB );

  clock_t fim = clock();
  time += (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo de  %f segundos", time);
  return 0;
}