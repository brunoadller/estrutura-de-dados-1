#include "cilindro.h"
#include <stdio.h>
#include <stdlib.h>

struct cilindro{
  float altura;
  float raio;
  float pi;
};

Cilindro *cilindro_create(){
  Cilindro *cilindro = (Cilindro *) calloc(1, sizeof(Cilindro));

  cilindro->altura = 0.0;
  cilindro->raio = 0.0;

  return cilindro;
}

void cilindro_destroy(Cilindro *cilindro){
  free(cilindro);
}
void cilindro_set(Cilindro *cilindro, float altura, float raio, float pi){
  cilindro->altura = altura;
  cilindro->raio = raio;
  cilindro->pi = pi;
}
float cilindro_get_altura(Cilindro *cilindro){
  return cilindro->altura;
}
float cilindro_get_raio(Cilindro *cilindro){
  return cilindro->raio;
}
float cilindro_get_pi(Cilindro *cilindro){
  return cilindro->pi;
}
//At = 2(π.r2) + 2(π.r.h)
float cilindro_area(Cilindro *cilindro){
  float resultado = 2*(cilindro_get_pi(cilindro)*(cilindro_get_raio(cilindro)*cilindro_get_raio(cilindro))) +
  2*(cilindro_get_pi(cilindro)*cilindro_get_raio(cilindro) * cilindro_get_altura(cilindro));
  return resultado;
}
float cilindro_volume(Cilindro *cilindro){
  float resultado = cilindro_get_pi(cilindro) * (cilindro_get_raio(cilindro)*cilindro_get_raio(cilindro)) * cilindro_get_altura(cilindro);
  return resultado;
}
void cilindro_print(Cilindro *cilindro){
  printf("********************MEDIDAS*********************\n");
  printf("Altura........: %.2f\n", cilindro_get_altura(cilindro));
  printf("Raio...: %.2f\n", cilindro_get_raio(cilindro));
  printf("Pi.......: %.2f\n", cilindro_get_pi(cilindro));
  printf("********************RESULTADOS*********************\n");
  printf("Volume........: %.2f\n", cilindro_volume(cilindro));
  printf("Area..........: %.2f\n", cilindro_area(cilindro));
}