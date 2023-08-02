typedef struct cilindro Cilindro;

Cilindro *cilindro_create();
void cilindro_destroy(Cilindro *cilindro);
float cilindro_get_altura(Cilindro *cilindro);
float cilindro_get_raio(Cilindro *cilindro);
float cilindro_get_pi(Cilindro *cilindro);
void cilindro_set(Cilindro *cilindro, float altura, float raio, float pi);
float cilindro_area(Cilindro *cilindro);
float cilindro_volume(Cilindro *cilindro);
void cilindro_print(Cilindro *cilindro);