#include <stdio.h>
#include <stdlib.h>

int  fibonacci(int n){
  if(n == 1){
    return 0;
  }else{
    if(n == 2){
      return 1;
    }else{
      return fibonacci(n - 1) + fibonacci(n - 2);
    }


  }
}

int main(){
  int n;
  printf("Digite um valor maior que 0: ");
  scanf("%d", &n);
  printf("Fibonacci de %d e: %d", n, fibonacci(n));
  return 0;
}