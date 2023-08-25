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
  Matriz *mA = matrix_create_for_test(100);
  Matriz *mB = matrix_create_for_test(100);
  printf("Multiplicacao de A e B");
  Matriz *mC = matrix_multiply(mA, mB);
  matrix_print_for_test(mC);
  
  matrix_destroy( mA );
  matrix_destroy( mB );
  matrix_destroy( mC );

  
 /*
  *****TESTE DA MATRIZ POR FORÇA BRUTA********
 */
  /*
  unsigned int tamanho = 10000;
  float **mA = cria_matriz_forca_bruta(tamanho);
  float **mB = cria_matriz_forca_bruta(tamanho);
  float **mC = cria_matriz_forca_bruta(tamanho);

  insere_matriz_forca_bruta(mA, tamanho);
  insere_matriz_forca_bruta(mB, tamanho);
  multiplica_matriz_forca_bruta(mA,mB,mC,tamanho);
  imprimi_matriz_forca_bruta(mC,tamanho);
  destroi_matriz_forca_bruta(mA,tamanho);
  destroi_matriz_forca_bruta(mB,tamanho);
  destroi_matriz_forca_bruta(mC,tamanho);
  */
  clock_t fim = clock();
  time += (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("tempo de  %f segundos", time);
  return 0;
}