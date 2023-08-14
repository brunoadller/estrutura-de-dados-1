#include "circular.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct no{
    int val;
    No *anterior;
    No *proximo;
}No;
typedef struct lista{
    No *inicio;
    No *fim;
    size_t tamanho;
}Lista;

No *cria_no(int val){
    //aloca ponteiro do tipo no
    No *pno = (No*) calloc(1,sizeof(No));
    pno->val = val;
    pno->anterior = pno;
    pno->proximo = pno;
    return pno;
}
void destroi_no(No **no_ref){
    No *pno = *no_ref;
    free(pno);
    *no_ref = NULL;
}

Lista *cria_lista(){
    Lista *L = (Lista*)calloc(1, sizeof(Lista));

    L->inicio = NULL;
    L->fim = NULL;
    L->tamanho = 0;
    return L;

}
void destroi_lista(Lista **lista_ref){
    Lista *L = *lista_ref;
    No *p = L->inicio;
    No * aux = NULL;
    while (p != L->fim)
    {
        aux = p;
        p = p->proximo;
        destroi_no(&aux);
    }
    destroi_no(&p);
    free(L);
    *lista_ref = NULL;
}

bool lista_esta_vazia(Lista *L){
    return L->tamanho == 0;
}

void adicioona_no_inicio(Lista *L, int val){
    No *p = cria_no(val);
    
    if(lista_esta_vazia(L)){
        //se lista vazia p é igual ao nó criado
        L->fim = p;
    }else{
        //se ja tinha um valor na lista ele passa a ser o proximo
        //e o anterior passa a ser o novo nó do inicio
        p->proximo = L->inicio;
        L->inicio->anterior = p;

        p->anterior = L->fim;
        L->fim->proximo = p;
    }
    L->inicio = p;
    L->tamanho ++;
}
void adiciona_no_fim(Lista *L, int val){
    No *p = cria_no(val);
    if(lista_esta_vazia(L)){
        L->inicio = p;
    }else{
        L->fim->proximo = p;
        p->anterior = L->fim;
        L->inicio->anterior = p;
        p->proximo = L->inicio;
    }
    L->fim = p;
    L->tamanho++;
}
void print(Lista *L){
    if(lista_esta_vazia(L)){
        printf("L->NULL\n");
        printf("L->fim->NULL\n");
    }else{
        No *p = L->inicio;
        printf("L->");
        do{
            printf("%d -> ", p->val);
            p = p->proximo;
        }while(p != L->inicio);
        printf("\nL->fim->%d\n", L->fim->val);
    }
    printf("Tamanho: %lu\n\n", L->tamanho);
}
void remove_da_lista(Lista *L, int val){
    if(!lista_esta_vazia(L)){
        No *p = L->inicio;
        //caso 1: o elemento está na =cabeça da lista
        if(L->inicio->val == val){
            //a lista possui um unico elemento
            if(L->inicio == L->fim){
                L->inicio = NULL;
                L->fim = NULL;

            }else{
                L->inicio = p->proximo;
                L->inicio->anterior = L->fim;
                L->fim->proximo = L->inicio;
            }
            destroi_no(&p);
            L->tamanho--;
        }else{
            //caso 2 : O elemento está no meio da lista
            //caso 3 : Oelemento está no final da lista
            p = p->proximo;
            while (p != L->inicio)
            {
                if(p->val == val){
                    //elemento está no final da lista
                    if(L->fim == p){
                        L->fim = p->anterior;
                    }
                    p->anterior->proximo = p->proximo;
                    p->proximo->anterior = p->anterior;
                    destroi_no(&p);
                    L->tamanho--;
                    break;
                }else{
                    p = p->proximo;
                }
            }
            
        }
    }
}
