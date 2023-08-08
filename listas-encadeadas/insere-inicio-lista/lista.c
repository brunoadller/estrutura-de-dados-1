#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct list{
  int num;
  List *next;
};

List *list_insert(List *l, int num){
  List *novo = (List*) calloc(1, sizeof(List));
  novo->num = num;
  novo->next = l;
  return novo;
}

void list_print(List *l){
  List *p;
  for(p = l; p != NULL; p = p->next){
    printf("%d \n", p->num);
  }
}