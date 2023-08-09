#include <stdbool.h>

typedef struct no_circular NoCircular;
typedef struct lista_circular ListaCircular;

NoCircular *criando_no(int val);
void destruindo_no(NoCircular ** no_referencia);

ListaCircular *criando_lista_circular();
void destruindo_lista_circular(ListaCircular **lista_referencia);
void destruindo_lista_circular_2(ListaCircular **lista_referencia);
void add_inicio_lista(ListaCircular *L, int val);

bool lista_esta_vazia(const ListaCircular *L);
