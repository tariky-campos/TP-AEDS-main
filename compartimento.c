#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compartimento.h"

void FLVazia_R(L_Compart *pLista, int n)
{
    pLista->ROOchas = (rochamineral*)malloc(sizeof(rochamineral)*n);
    pLista->pPrimeiro = 0;
    pLista->pUltimo =pLista->pPrimeiro;
}

int LEhVazia_R(L_Compart *pLista)
{
    return (pLista->pPrimeiro == pLista->pUltimo);
}

int LInsere_R(L_Compart *pLista, rochamineral pRocha, int x)
{
    if(pLista->pUltimo == x){
        return 0;
    }
    pLista->ROOchas[pLista->pUltimo++] = pRocha;
    return 1;
}

void LImprime_R(L_Compart *pLista)
{
    
    for(int i = pLista->pPrimeiro; i< pLista->pUltimo; i++){
        printf("%s %.1f\n",pLista->ROOchas[i].categoria, pLista->ROOchas[i].peso);
    }
}


int LTamanho_R(L_Compart *pLista)
{
    if(pLista->pPrimeiro == pLista->pUltimo){
        return 0;
    }
    return pLista->pUltimo - pLista->pPrimeiro;

}
void selection(rochamineral *pLista, int n,int *comparacoes, int* trocas)
{
    int i, j, Min;
    
    rochamineral Aux;

    for (i = 0; i < n - 1; i++)
    {
        Min = i;
        for (j = i + 1; j < n; j++){
            (*comparacoes)++;
            if (pLista[j].peso < pLista[Min].peso)
            {
                Min = j;  
            }
        }

        Aux = pLista[Min];
        pLista[Min] = pLista[i];
        pLista[i] = Aux;
        (*trocas)+=3;
    }
}
void Shellsort(rochamineral *pLista, int n, int *comp, int *troc) {
    int i, j;
    int h = 1;
    rochamineral aux;

    *comp = 0;  // Inicializa o contador de comparações
    *troc = 0;  // Inicializa o contador de trocas

    // Define o intervalo inicial (h)
    do h = h * 3 + 1; while (h < n);
    do {
        h = h / 3;
        for (i = h; i < n; i++) {
            aux = pLista[i];
            j = i;

            // Comparações e trocas no while
            while (j >= h && pLista[j - h].peso > aux.peso) {
                (*comp)++;  // Incrementa comparações
                pLista[j] = pLista[j - h];
                j -= h;
                (*troc)++;  // Incrementa trocas
            }
            (*comp)++;  // Conta a última comparação do while que falhou

            // Troca final, apenas se o índice mudou
            if (j != i) (*troc)++;  
            pLista[j] = aux;  // Insere o elemento na posição correta
        }
    } while (h != 1);
}
