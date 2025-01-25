#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "Rocha.h"

typedef int Apontador_R;


typedef struct
{
    rochamineral *ROOchas;
    Apontador_R pPrimeiro;
    Apontador_R pUltimo;
} L_Compart;

void FLVazia_R(L_Compart *pLista, int n);
int LEhVazia_R(L_Compart *pLista);
void LImprime_R(L_Compart *pLista);

int LTamanho_R(L_Compart *pLista);
int LInsere_R(L_Compart *pLista, rochamineral pRocha,int x);
void selection(rochamineral *pLista, int n,int* comp, int* tro);
void Shellsort(rochamineral* pLista, int, int* comp, int* troc);
#endif