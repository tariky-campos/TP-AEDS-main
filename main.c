#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compartimento.h"
#include <math.h>
#include <time.h>
#define Maxtam 255
#define miner 50

// Função principal
int main() {
    printf("3333333\n");
    
    clock_t inicio = clock();

    int num_Operacoes;
    int comparacoes = 0;
    int trocas = 0;
    char nomearq[255];

    L_Compart compartimento;
    Inicializar_L_compart(&compartimento);

    FILE *arq;
    printf("Insira o nome do arquivo: \n");
    scanf("%49s", nomearq);
    arq = fopen(nomearq, "r");
        if(arq == NULL){
            printf("Falha no arquivo.\n");
            exit(0);
        }
    
    fscanf(arq, "%d", &num_Operacoes);

    for(int i=0;i<num_Operacoes;i++){
        rochamineral newRocha;
        float latitude, longitude, peso;
        char minerais[100];
        Mineral_L n;
        L_Minerais ListaMin;

        fscanf(arq, "%f %f %f", &latitude, &longitude, &peso);

        FLVazia_L(&ListaMin);
        fgets(minerais, 100, arq);

        if(minerais[strlen(minerais)-1] == '\n'){
            minerais[strlen(minerais)-1] = '\0';
        }
        else{
            minerais[strlen(minerais)] = '\0';
        }

        const char delim[] = " ";
        char *parte = strtok(minerais, delim);

        while(parte != NULL){
            strcpy(n.nomeM, parte);
            LInsere_L(&ListaMin, n);
            parte = strtok(NULL, delim);
        }

        newRocha = InicializaRocha(&newRocha, latitude, longitude, peso, &ListaMin);
        LInsere_R(&compartimento, newRocha);

        int caso;
        printf("Digite 1-SelectionSort\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:{
            selection(&compartimento, num_Operacoes,&comparacoes,&trocas);
            LImprime_R(&compartimento);
            printf("comparacoes: %d trocas: %d", comparacoes, trocas);
            fclose(arq);

            clock_t fim = clock();
            double tempo_decorrido = (double)(fim - inicio) / 10000000;
            printf("Tempo gasto: %f segundos\n", tempo_decorrido);
            printf("\n");
        }
            break;
        
        default:
            break;
        }
    }
    return 0;
}
