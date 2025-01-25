#ifndef MINERAL_H
#define MINERAL_H

typedef struct 
{
    char nomeM[50], cor[50];
    float dureza, reatividade;
} Mineral_L;

Mineral_L Inicializa_mineral(Mineral_L* mineral, char *nomeM, float dureza, float reatividade, char *cor);
Mineral_L Inicializa_mineral2(Mineral_L*mineral, char *nomeM);

char* get_nomeM(Mineral_L* mineral);
float get_dureza(Mineral_L* mineral);
float get_reatividade(Mineral_L* mineral);
char* get_cor(Mineral_L* mineral);

void set_nomeM(Mineral_L* mineral, char *nomeM);
void set_dureza(Mineral_L* mineral, float dureza);
void set_reatividade(Mineral_L* mineral, float reatividade);
void set_cor(Mineral_L* mineral, char *cor);

#endif // MINERAL_H