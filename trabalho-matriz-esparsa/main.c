#include "esparsa.h"
#include <stdio.h>

int main(){
  //criando matriz A
  Matriz *A = matrix_create(4,4);
  matrix_setelem(A, 1, 1,50.0);
  matrix_setelem(A, 2, 1,10.0);
  matrix_setelem(A, 2, 3, 20.0);
  matrix_setelem(A, 4, 1,-30.0);
  matrix_setelem(A, 4, 3,-60.0);
  matrix_setelem(A, 4, 4,5.0);
  printf("Matriz A: \n");
  matrix_print(A);
  printf("\n");

  Matriz *B = matrix_create(4,4);
  matrix_setelem(B, 1, 1,50.0);
  matrix_setelem(B, 1, 2,30.0);
  matrix_setelem(B, 2, 1,10.0);
  matrix_setelem(B, 2, 3,-20.0);
  matrix_setelem(B, 4, 4,-5.0);
  printf("Matriz B: \n");
  matrix_print(B);
  printf("\n");

  Matriz *C = matrix_add(A,B);
  printf("Matriz C: \n");
  matrix_print(C);
  matrix_destroy(C);
  printf("\n");


  C = matrix_multiply(A,B);
  printf("Multiplicacao de A e C: \n");
  matrix_print(C);
  matrix_destroy(C);
  printf("\n");

  
  C = matrix_transpose(A);
  printf("Transposta de A: \n");
  matrix_print(C);
  printf("\n");
  
  matrix_destroy(C);
  matrix_destroy(A);
  matrix_destroy(B);
  return 0;
}