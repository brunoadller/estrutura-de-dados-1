typedef struct celula Celula;
typedef struct matriz Matriz;

//Funcoes

Matriz *matrix_create(int m, int n);
int iniciaCabecasDaMatriz(Matriz *mat);
int insereCabecaDaLinha(Matriz *mat);
int insereCabecaDaColuna(Matriz *mat);

float matrix_getelem(Matriz *mat, int linha, int coluna);
void matrix_setelem(Matriz *mat, int linha, int coluna, float valor);
void matrix_print(Matriz *mat);
void matrix_destroy(Matriz *mat);
Matriz *matrix_add(Matriz *matA, Matriz *matB);
Matriz *matrix_multiply(Matriz *matA, Matriz *matB);
Matriz *matrix_transpose(Matriz *matA);
Matriz *matrix_create_for_test(unsigned int m);
void matrix_print_for_test(Matriz *mat);


float **cria_matriz_forca_bruta(unsigned int m);
void insere_matriz_forca_bruta(float **matriz, unsigned int m);
void destroi_matriz_forca_bruta(float **matriz, unsigned int m);
void imprimi_matriz_forca_bruta(float **matriz, unsigned int m);
void multiplica_matriz_forca_bruta(float **matrizA,float **matrizB, float **matrizC, unsigned int m);