#include "circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


int main(){

    Lista *l = cria_lista();

    adicioona_no_inicio(l, 2);
    adicioona_no_inicio(l, 5);
    adicioona_no_inicio(l, 10);
    adicioona_no_inicio(l, 7);
    adicioona_no_inicio(l, 9);
    adicioona_no_inicio(l, 25);
    
    print(l);
    destroi_lista(&l);
    return 0;
}