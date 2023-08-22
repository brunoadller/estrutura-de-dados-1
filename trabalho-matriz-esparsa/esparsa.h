

typedef struct celula Celula;
typedef struct matrizEsparca Matriz;

//Funcoes

Matriz *matrix_create(int m, int n);
int iniciaCabecas(Matriz *mat);
int insereCabecaLinha(Matriz *mat);
int insereCabecaColuna(Matriz *mat);

float matrix_getelem(Matriz *mat, int linha, int coluna);
void matrix_setelem(Matriz *mat, int linha, int coluna, float valor);
void matrix_print(Matriz *mat);
void matrix_destroy(Matriz *mat);
Matriz *matrix_add(Matriz *matA, Matriz *matB);
Matriz *matrix_multiply(Matriz *matA, Matriz *matB);
Matriz *matrix_transpose(Matriz *matA);
Matriz *matrix_create_for_test(int m);
void matrix_print_for_test(Matriz *mat);

