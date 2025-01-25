#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"


void Inicializar_L_compart(L_Compart* pLista){
    pLista->tamanho = 0;
}


void LInsere_R(L_Compart *pLista, rochamineral pRocha)
{
    if(pLista->tamanho >= MAX){
        printf("Vetor sem espaco!\n");
        return;
    }
    pLista->vetor[pLista->tamanho] = pRocha;
    pLista->tamanho++;
    return;

}


void LImprime_R(L_Compart *pLista)
{
    if(pLista->tamanho ==0){
        printf("vetor vazio!\n");
        return;
    }
    printf("Lista de rochas:\n");
    for(int i = 0; i<pLista->tamanho; i++){
        printf("%s %1.f\n", pLista->vetor[i].categoria, pLista->vetor[i].peso);
    }
}

void LRetira_R(L_Compart* pLista, int indice) {
    if (indice < 0 || indice >= pLista->tamanho) {
        printf("Sem rocha\n");
        return;
    }
    for (int i = indice; i < pLista->tamanho - 1; i++) {
        pLista->vetor[i] = pLista->vetor[i + 1];
    }
    pLista->tamanho--;
    return;
}

void LTroca_R(rochamineral *A, rochamineral*B)
{
    rochamineral aux = *A;
    *A = *B;
    *B = aux;
}

void selection(rochamineral *pRochas, int n, int*comparacoes, int *trocas){
    for(int i =0; i<n-1; i++){
        int menorIndice =i;
        for(int j=i+1; j<n;j++){
            (*comparacoes)++;
            if(pRochas[j].peso < pRochas[menorIndice].peso){
                menorIndice = j;
            }
        }
        if(menorIndice != i){
            LTroca_R(&pRochas[i], &pRochas[menorIndice]);
            (*trocas)++;
        }
    }
}
void Shellsort (rochamineral* rocha, int n){
    int i, j;
    int h = 1;
    rochamineral aux;

    do h = h * 3 + 1; while (h < n);
    do
    {
        h = h/3;
        for( i = h ; i < n ; i++ )
        {
            aux = rocha[i]; j = i;
            while (rocha[j - h].peso > aux.peso)
            {
                rocha[j] = rocha[j - h]; j -= h;
                if (j < h) break;
            }
            rocha[j] = aux;
        }
    } while (h != 1);
}