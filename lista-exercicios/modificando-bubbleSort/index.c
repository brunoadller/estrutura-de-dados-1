#include <stdio.h>
#include <string.h>

void bubbleSort(char *v, int N){
  int i, continua,fim = N;
  char aux[N];
  do{
    continua = 0;
    for(i = 0; i < fim -1; i++){
      if(strcmp(v[i], v[i+1]) > 0){
        aux[i] = v[i];
        v[i] = v[i+1];
        v[i+1] = aux[i];
        continua = i;
      }fim--;
    }
  }while(continua != 0);
}

//Modifique o algoritmo bubble sort. 
//O algoritmo deverá receber uma string e colocar as suas
//letras em ordem crescente.
int main(){

  char v[30];
  printf("Informe uma string: ");
  for(int i = 0; i <30; i++){
    scanf("%c", v[i]);
  }
  bubbleSort(v, 5);

  for(int i = 0; i <30; i++){
    printf("Nome: %c", v);
  }
  return 0;
}