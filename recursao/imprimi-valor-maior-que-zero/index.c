#include <stdio.h>
#include <stdlib.h>

void imprimir_crescente(int x){
  if(x == 0){
    printf(" %d ", x);
  }else{
    imprimir_crescente(x - 1);
    printf(" %d ", x);
  }
}
void imprimir_decrescente(int x){
  if(x == 0){
    printf(" %d ", x);
  }else{
    printf(" %d ", x);
    imprimir_decrescente(x - 1);
  }
}
int main(){
  int n;
  printf("Digite um valor maior que 0: ");
  scanf("%d", &n);
  imprimir_crescente(n);
  return 0;
}