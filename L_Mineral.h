#ifndef LISTAMINERAIS_H
#define LISTAMINERAIS_H
#define MAXTAM 1000
#include "Mineral.h"

typedef int Apontador_L;

typedef struct 
{
    Mineral_L Chave;
}itemMineral;



typedef struct
{
    itemMineral ListaMINERAIS[MAXTAM];
    Apontador_L pPrimeiro, pUltimo;
}L_Minerais;

void FLVazia_L(L_Minerais *ListaMi);
int LEhVazia_L(L_Minerais *ListaMi);
void LInsere_L(L_Minerais *ListaMi, Mineral_L item);
int LRetira_L(L_Minerais *ListaMi, char *nome, Mineral_L *pX);
void LImprime_L(L_Minerais *ListaMi);




int TMListaM(L_Minerais *pLista);
void PListaMinerais(L_Minerais* pLista, Mineral_L* mineral);

#endif