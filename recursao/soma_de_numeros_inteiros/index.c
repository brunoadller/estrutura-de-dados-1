#include <stdio.h>
#include <stdlib.h>


int soma(int n){
  if(n == 0){
    return 0;
  }else{
    return (n) + soma(n - 1);
  }
}
int main(){
  int n;
  printf("Digite N: ");
  scanf("%d", &n);
  printf("Resultado da soma  1 ate %d e: %d", n, soma(n));
  return 0;
}