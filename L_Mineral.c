#include "L_Mineral.h"
#include <stdio.h>
#include <string.h>
#define MaxTam 5

void FLVazia_L(L_Minerais* pLista) {
    pLista->pPrimeiro = 0;
    pLista->pUltimo = pLista->pPrimeiro;
}

int LEhVazia_L(L_Minerais* pLista) {
    return pLista->pUltimo == pLista->pPrimeiro;
}

void LInsere_L(L_Minerais* pLista, Mineral_L x) {
    if (pLista->pUltimo >= MaxTam) {
        printf("ERRO DE INCERCAO\n");
        return;
    }
    pLista->ListaMINERAIS[pLista->pUltimo].Chave = x;
    pLista->pUltimo++; 
}

int LRetira_L(L_Minerais* pLista, char *nomeM, Mineral_L *pX) {
    int cont;
    
    if (LEhVazia_L(pLista)) {
        return 0;
    }
    for (cont = pLista->pPrimeiro; cont <= pLista->pUltimo; cont++) {
        if (strcmp(nomeM, pLista->ListaMINERAIS[cont].Chave.nomeM) == 0) {
            *pX = pLista->ListaMINERAIS[cont].Chave;
            for (cont += 1; cont < pLista->pUltimo; cont++) {
                pLista->ListaMINERAIS[cont - 1] = pLista->ListaMINERAIS[cont];
            }
            pLista->pUltimo--;
        }
    }
    return 1;
}

void LImprime_L(L_Minerais* pLista) {
    int i;
    for (i = pLista->pPrimeiro; i < pLista->pUltimo; i++) {
         printf("Nome: %s, Dureza: %.2f, Reatividade: %.2f, Cor: %s\n",
               pLista->ListaMINERAIS[i].Chave.nomeM,
               pLista->ListaMINERAIS[i].Chave.dureza,
               pLista->ListaMINERAIS[i].Chave.reatividade,
               pLista->ListaMINERAIS[i].Chave.cor);
    }
}

int TMListaM(L_Minerais *pLista)
{
    int count = 0;
    for (int cont = pLista->pPrimeiro; cont < pLista->pUltimo; cont++){
        count++;
    }
    
    return count;
}

void PListaMinerais(L_Minerais* pLista, Mineral_L* mineral) {
    FLVazia_L(pLista);

    Mineral_L Ferrolita = Inicializa_mineral(mineral, "Ferrolita", 0.5, 0.7, "Cinza");
    Mineral_L Solarium = Inicializa_mineral(mineral, "Solarium", 0.9, 0.2, "Amarelo");
    Mineral_L Aquavitae = Inicializa_mineral(mineral, "Aquavitae", 0.5, 0.8, "Azul");
    Mineral_L Terranita = Inicializa_mineral(mineral, "Terranita", 0.7, 0.6, "Marrom");
    Mineral_L Calaris = Inicializa_mineral(mineral, "Calaris", 0.6, 0.5, "Vermelho");

    LInsere_L(pLista, Ferrolita);
    LInsere_L(pLista, Solarium);
    LInsere_L(pLista, Aquavitae);
    LInsere_L(pLista, Terranita);
    LInsere_L(pLista, Calaris);
}