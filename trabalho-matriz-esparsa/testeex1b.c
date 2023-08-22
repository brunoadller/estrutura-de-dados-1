#include "esparsa.h"
#include <stdio.h>
#include <time.h>       


int main(){
  
  //Segunda matriz do primeiro teste
  Matriz *segundoA = matrix_create(5,5);
  matrix_setelem(segundoA, 1, 1, 1.0);
  matrix_setelem(segundoA, 1, 4, 6.0);
  matrix_setelem(segundoA, 2, 2, 10.5);
  matrix_setelem(segundoA, 3, 3, 0.015);
  matrix_setelem(segundoA, 4, 2,250.5);
  matrix_setelem(segundoA, 4, 4, -280.0);
  matrix_setelem(segundoA, 4, 5, 33.32);
  matrix_setelem(segundoA, 5, 5, 12.0);
  printf("Matriz Segunda A: \n");
  matrix_print(segundoA);
  printf("\n");

  Matriz *segundoB = matrix_create(5,5);
  matrix_setelem(segundoB, 1, 1, 1.0);
  matrix_setelem(segundoB, 2, 2, 10.5);
  matrix_setelem(segundoB, 3, 3, 0.3);
  matrix_setelem(segundoB, 4, 2, 100.0);
  matrix_setelem(segundoB, 4, 4, 30.0);
  matrix_setelem(segundoB, 5, 4, 1.0);
  printf("Matriz segunda B: \n");
  matrix_print(segundoB);
  printf("\n");

  Matriz *segundaC = matrix_add(segundoA, segundoB);
  printf("Matriz segundas A e B somadas: \n");
  matrix_print(segundaC);
  matrix_destroy(segundaC);
  printf("\n");


  segundaC = matrix_multiply(segundoA,segundoB);
  printf("Matrizes segundas A e B multiplicadas: \n");
  matrix_print(segundaC);
  matrix_destroy(segundaC);
  printf("\n");

  
  segundaC = matrix_transpose(segundoA);
  printf("Transposta de segunda A: \n");
  matrix_print(segundaC);
  printf("\n");
  
  matrix_destroy(segundaC);
  matrix_destroy(segundoA);
  matrix_destroy(segundoB);
  return 0;
}