#include <stdio.h>
#include <stdlib.h>

int  fatorial(int x){
  if(x == 0 || x == 1){
    return 1;
  }else{
    return x * fatorial(x - 1);
  }
}

int main(){
  int n;
  printf("Digite um valor maior que 0: ");
  scanf("%d", &n);
  printf("Fatorial de %d e: %d", n, fatorial(n));
  return 0;
}