#include <stdio.h>
#include <stdlib.h>


int main(){
  int a = 10;
  int *p1 = NULL;
  int *p2 = NULL; 

  printf("&a = %p, a = %d\n", &a, a);
  printf("&p1 = %p, p1 = %d\n", &p1, p1);
  printf("&p2 = %p, p2 = %d\n", &p2, p2);

  p1 = &a;
  p2 = p1;
  *p2 = 4;

  printf("\n\n");
  //pi = &p2 não pode armazenar o endereco de p2 por 
  //que p1 teria q ser um ponteiro de ponteiro

  printf("&a = %p, a = %d\n", &a, a);
  printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
  printf("&p2 = %p, p2 = %p, *p2 = %d\n", &p2, p2, *p2);

  return 0;
}