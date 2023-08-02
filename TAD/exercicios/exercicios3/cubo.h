typedef struct cubo Cubo;

Cubo *cubo_create();
void cubo_destroy(Cubo *cubo);
float cubo_get_comprimento(const Cubo *cubo);
float cubo_get_largura(const Cubo *cubo);
float cubo_get_altura(const Cubo *cubo);
void cubo_set(Cubo *cubo, float comprimento, float largura, float altura);
float cubo_calcula_volume(Cubo *cubo);
float cubo_calcula_area(float volume);
void cubo_print(Cubo *cubo);