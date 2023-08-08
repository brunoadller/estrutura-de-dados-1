typedef struct no No;
typedef struct lista Lista;

No *no_create(int num);
Lista *list_create();
void list_destroy(Lista **list_ref);