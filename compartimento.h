#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "Rocha.h"
#define MAX 100000

typedef struct
{
    rochamineral vetor[MAX];
    int tamanho;
} L_Compart;

void Inicializar_L_compart(L_Compart* pLista);
void LImprime_R(L_Compart *pLista);
void LTroca_R(rochamineral *a, rochamineral*b);
void LInsere_R(L_Compart *pLista, rochamineral pRocha);
void LRetira_R(L_Compart *pLista, int indice);

void selection(rochamineral* pRochas, int n, int* comparacoes, int *trocas);
void Shellsort (rochamineral* rocha, int n);

#endif