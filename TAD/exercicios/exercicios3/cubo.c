#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>

struct cubo{
  float altura;
  float largura;
  float comprimento;
};

Cubo * cubo_create(){
  Cubo *cubo = (Cubo *) calloc(1, sizeof(Cubo));

  cubo->altura = 0.0;
  cubo->comprimento = 0.0;
  cubo->largura = 0.0;

  return cubo;
}

void cubo_destroy(Cubo *cubo){
  free(cubo);
}

void cubo_set(Cubo *cubo, float comprimento, float largura, float altura){

  cubo->comprimento = comprimento;
  cubo->largura = largura;
  cubo->altura = altura;
}

float cubo_get_comprimento(const Cubo *cubo){
  return cubo->comprimento;
}
float cubo_get_largura(const Cubo *cubo){
  return cubo->largura;
}
float cubo_get_altura(const Cubo *cubo){
  return cubo->altura;
}

void cubo_print(Cubo *cubo){
  printf("********************MEDIDAS*********************\n");
  printf("Altura........: %.2f\n", cubo_get_altura(cubo));
  printf("Comprimento...: %.2f\n", cubo_get_comprimento(cubo));
  printf("Largura.......: %.2f\n", cubo_get_largura(cubo));
  printf("********************RESULTADOS*********************\n");
  printf("Volume........: %.2f\n", cubo_calcula_volume(cubo));
  printf("Area..........: %.2f\n", cubo_calcula_area(cubo_calcula_volume(cubo)));

}
float cubo_calcula_area(float volume){
  float resultado = 6 * (volume * volume);
  return resultado;
}
float cubo_calcula_volume(Cubo *cubo){
  float resultado = cubo_get_altura(cubo)*cubo_get_comprimento(cubo) * cubo_get_altura(cubo);
  return resultado;
}
