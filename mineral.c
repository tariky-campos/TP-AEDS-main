#include "Mineral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Mineral_L Inicializa_mineral(Mineral_L* mineral, char *nomeM, float dureza, float reatividade, char *cor) {
    set_nomeM(mineral, nomeM);
    set_dureza(mineral, dureza);
    set_reatividade(mineral, reatividade);
    set_cor(mineral, cor);

    return *mineral; 
}
Mineral_L Inicializa_mineral2(Mineral_L*mineral, char *nomeM) {
    set_nomeM(mineral, nomeM);

    return *mineral;
}

char* get_nomeM(Mineral_L* mineral) {
    return mineral->nomeM;
}

float get_dureza(Mineral_L* mineral) {
    return mineral->dureza;
}

float get_reatividade(Mineral_L* mineral) {
    return mineral->reatividade;
}

char* get_cor(Mineral_L* mineral) {
    return mineral->cor;
}

void set_nomeM(Mineral_L* mineral, char *nomeM) {
    strcpy(mineral->nomeM, nomeM);
}

void set_dureza(Mineral_L* mineral, float dureza) {
    mineral->dureza = dureza;
}

void set_reatividade(Mineral_L* mineral, float reatividade) {
    mineral->reatividade = reatividade;
}

void set_cor(Mineral_L* mineral, char *cor) {
    strcpy(mineral->cor, cor);
}