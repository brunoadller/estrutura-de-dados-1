#include <stdbool.h>
typedef struct no No;
typedef struct lista Lista;
typedef struct fila Fila;

/*LISTA DUPLAMENTE ENCADEADA COM AS FUNÇÕES PARA MANIPULAR A FILA*/
No * cria_no(int val);
Lista * cria_lista();

void destroi_lista(Lista **lista);
bool lista_vazia(Lista *l);
int tamanho(Lista *l);
void adiciona_inicio(Lista *l, int val);
void adiciona_final(Lista *l, int val);
void imprimir(Lista *l);
void remove_inicio(Lista *l);
int pega_primeiro_valor(Lista *l);

/*FUNÇÕES DA FILA*/


Fila *cria_fila();
void destroi_fila(Fila **fila_referencia);
bool fila_vazia(Fila *f);
long tamanho_fila(Fila *f);
int consultar_fila(Fila *f);
void enfileirar(Fila *f,int val);
int desenfileirar(Fila *f);
void imprimir_fila(Fila *f);