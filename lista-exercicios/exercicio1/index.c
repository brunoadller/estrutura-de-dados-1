#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criaVetor(int tam);
void preencheVetor(int tam, int *v);
void encontraValor(int tam, int *v);
void imprimeVetor(int tam, int *v);
void produtoDosElementosDoVetor(int tam, int *v);
void procuraContaValorV(int tam, int *v);
int verificaSeOrdenado(int tam, int *v);
void ordenaVetor(int tam, int *v);
void mostraVetorVerificadoEOrdenado(int tam, int *v);
void menu(int tam, int *v, int op);
int main(){
  int tam= 25;
  int *v = criaVetor(tam);
  preencheVetor(tam, v);
  imprimeVetor(tam, v);
  printf("\n\n");
  
  free(v);
  return 0;
}
void menu(int tam, int *v, int op){

  printf("#########->MENU<-#########\n\n");
  
}

void mostraVetorVerificadoEOrdenado(int tam, int *v){
  int valor = verificaSeOrdenado(tam, v);
  if(valor == 1){
    printf("Esta ordenado!");
  }else{
    ordenaVetor(tam, v);
  }
}
void ordenaVetor(int tam, int *v){
  int aux;
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
      if(v[i] <= v[j]){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }
    }
  }
  imprimeVetor(tam, v);
}

int verificaSeOrdenado(int tam, int *v){
   for(int i = 0; i < tam; i++){
    
    if(v[i - 1] > v[i]){
      return 0;
    }else{
      return 1;
    }
    
  }
}
void procuraContaValorV(int tam, int *v){
  int valor;
  int cont = 0;
  printf("Informe um valor para procura: ");
  scanf("%d", &valor);
  printf("Valor = %d\n", valor);
  for(int i = 0; i < tam; i++){
    if(v[i] == valor){
      cont++;
    }
  }
  printf("O valor aparece %d vezes no vetor", cont);
}

void produtoDosElementosDoVetor(int tam, int *v){
  unsigned int prod = 1;
  for(int i = 0; i < tam; i++){
    prod *= v[i];
  }
  printf("O produto de todos elementos do vetor e: %d",prod);
}


void encontraValor(int tam, int *v){
  int valor;
  printf("Informe um valor para procura: ");
  scanf("%d", &valor);
  printf("Valor = %d\n", valor);
  for(int i = 0; i < tam; i++){
    if(v[i] == valor){
      printf("Esta na posicao: %d\n",i);
    }
  }
}
int *criaVetor(int tam){
  int *v = (int*) calloc(tam, sizeof(int));
  if(v == NULL){
    exit(EXIT_FAILURE);
  }
}
void preencheVetor(int tam, int *v){
  srand(time(NULL));
  for(int i = 0; i < tam; i++){
    v[i] = rand() % 50;
  }
}
void imprimeVetor(int tam, int *v){
  for(int i = 0; i < tam; i++){
    printf("v[%d] = %d\n",i, v[i]); 
  }
}


