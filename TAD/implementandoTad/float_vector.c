#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//chamando o arquivo de cabeçalho
/**************INTERFACE PRIVADA**************/
struct float_vector{
  int capacity; //nr maximo de elementos
  int size;//qtde de elementos armazenados atualmente
  float *data;//vetor de floats
};

bool isFull(const FloatVector *vec){
  return vec->size == vec->capacity;
}


/**************INTERFACE PÚBLICA**************/

/*
*@brief Cria, (aloca) um vetor de floats com uma dada capacidade
*
*@param capacity capacidade do vetor
*return FloatVector* um vetor de floats alocado/criado
*/
FloatVector *create(int capacity){
  FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
  //estipula o valor inicial do tamanho
  vec->size = 0;
  vec->capacity = capacity;
  vec->data = (float*) calloc(capacity, sizeof(float));

  return vec;
}
/*
* desalocando o floatVector
*/
void destroy(FloatVector **vec_ref){
  FloatVector *vec = *vec_ref;
  free(vec->data);
  free(vec);
  *vec_ref = NULL;
}
//
/*
*adiciona o valor na posicao do vetor e aumenta o tamanho do mesmo
*/
void append(FloatVector *vec, float val){
  //verifica se o vetor esta cheio
  if(isFull(vec)){
    fprintf(stderr,"ERROR in 'append'\n");
    fprintf(stderr,"Vector is full\n");
    exit(EXIT_FAILURE);

  }
  //implementa se não nao estiver cheio
  vec->data[vec->size] = val;
  vec->size++;
}
//IMPRIMINDO OS DADOS
void print(const FloatVector *vec){
  puts("--------------------------------------");
  printf("Size: %d\n", vec->size);
  printf("Capacity: %d\n", vec->capacity);
  puts("---");
  for(int i = 0; i < vec->size; i++){
    printf("[%d] = %.3f\n", i, vec->data[i]);
  }
}
//retorna capacidade
int capacity(const FloatVector *vec){
  return vec->capacity;
}
//retotna tamanho
int size(const FloatVector *vec){
  return vec->size;
}
//retorna um dado valor do vetor
float at(const FloatVector *vec, int index){
  if(index < 0 || index >= vec->size){
     fprintf(stderr,"ERROR in 'at'\n");
    fprintf(stderr,"Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
    exit(EXIT_FAILURE);
  }
  return vec->data[index];
}

float get(const FloatVector *vec, int index){
  return vec->data[index];
}
void set(FloatVector *vec, int index, float Val){
  if(index < 0 || index >= vec->size){
     fprintf(stderr,"ERROR in 'at'\n");
    fprintf(stderr,"Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
    exit(EXIT_FAILURE);
  }
  vec->data[index] = Val;
}