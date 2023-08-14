#include <stddef.h>
#include <stdbool.h>

typedef struct no No;
typedef struct lista Lista;

No *cria_no(int val);
void destroi_no(No **no_ref);

Lista *cria_lista();
void destroi_lista(Lista **lista_ref);

bool lista_esta_vazia(Lista *L);

void adicioona_no_inicio(Lista *L, int val);
void adiciona_no_fim(Lista *L, int val);
void print(Lista *L);
void remove_da_lista(Lista *L, int val);