
typedef struct lista Lista;

Lista *inicializa(void);
Lista *insere(Lista *l, int i);
void libera(Lista *l);
void imprime(Lista *l);
int vazia(Lista *l);
Lista *busca(Lista *l, int v);
Lista *retira (Lista*l, int v);

