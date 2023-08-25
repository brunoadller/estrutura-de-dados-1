#include "esparsa.h"
#include <stdio.h>
#include <time.h>       

int main(){
  //Testando Matriz grande
  double time = 0.0;
 
  clock_t inicio = clock();
  /*
    *****TESTE DA MATRIZ COM LISTA *********
  */
  printf("Matriz A: \n");
  Matriz *mA = matrix_create_for_test(100);
  matrix_print_for_test(mA);
  
  printf("Matriz B: \n");
  Matriz *mB = matrix_create_for_test(100);
  matrix_print_for_test(mB);

  printf("Multiplicacao de A e B");
  Matriz *mC = matrix_multiply(mA, mB);
  matrix_print_for_test(mC);
  
  matrix_destroy( mC );
  matrix_destroy( mB );
  matrix_destroy( mA );
  
 /*
  *****TESTE DA MATRIZ POR FORÇA BRUTA********
 */
  float **mA = cria_matriz_forca_bruta(5);
  float **mB = cria_matriz_forca_bruta(5);
  float **mC = cria_matriz_forca_bruta(5);

  insere_matriz_forca_bruta(mA, 5);
  insere_matriz_forca_bruta(mB, 5);
  multiplica_matriz_forca_bruta(mA,mB,mC,5);
  imprimi_matriz_forca_bruta(mC,5);
  destroi_matriz_forca_bruta(mA,5);
  destroi_matriz_forca_bruta(mB,5);
  destroi_matriz_forca_bruta(mC,5);
  clock_t fim = clock();
  time += (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo de  %f segundos", time);
  return 0;
}