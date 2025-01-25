#include "compartimento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    clock_t start, stop;

    L_Compart L_rochas;

    int N_rochas;
    int comparacoes = 0;
    int trocas = 0;
    float latitude, longitude;
    float peso_r;
    char linha[300];

    printf("Digite o nome do arquivo: ");

    char nomearq[100];
    scanf("%32s", nomearq);
    FILE *arq = fopen(nomearq, "r");

    if (arq == NULL)
    {
        perror("ERRO!!\n");
        return 1;
    }

    fscanf(arq, "%d", &N_rochas);
    FLVazia_R(&L_rochas, N_rochas);
    start = clock();
    for (int i = 0; i < N_rochas; i++)
    {
        rochamineral rochas;
        Mineral mineral;

        fscanf(arq, "%f %f %f", &latitude, &longitude, &peso_r);

        FLVazia_L(&rochas.L_Mineral);
        fgets(linha, sizeof(linha), arq);

        if (linha[strlen(linha) - 1] == '\n')
        {
            linha[strlen(linha) - 1] = '\0';
        }

        const char delim[] = " ";
        char *parteMinerais = strtok(linha, delim);

        while (parteMinerais != NULL)
        {
            strcpy(mineral.nome, parteMinerais);
            LInsere_L(&rochas.L_Mineral, mineral);
            parteMinerais = strtok(NULL, delim);
        }
        InicializaRocha(&rochas, peso_r, Categoria(&rochas), latitude, longitude);
        LInsere_R(&L_rochas, rochas, N_rochas);
    }
    fclose(arq);

    L_Compart copiaVetor = L_rochas;
    int caso;
    printf("insira (1) para selectionSort ou (2) para shellSort\n");
    scanf("%d",&caso);
    while(caso!=1 && caso!=2){
        printf("Digito errado!!\nInsira 1-SelectionSort 2-ShellSort\n");
        scanf("%d",&caso);
    }
    switch (caso)
    {
    case 1:{
        start = clock();
        selection(copiaVetor.ROOchas, LTamanho_R(&copiaVetor), &comparacoes,&trocas);
        LImprime_R(&copiaVetor);
        printf("\nComparacoes: %d\n",comparacoes);
        printf("Trocas: %d\n",trocas);
        printf("Algoritmo: SelectionSort");
        stop = clock();
    }
        break;
    case 2:{
        start = clock();
        Shellsort(copiaVetor.ROOchas, LTamanho_R(&copiaVetor), &comparacoes,&trocas);
        LImprime_R(&copiaVetor);
        printf("\nComparacoes: %d\n",comparacoes);
        printf("Trocas: %d\n",trocas);
        printf("Algoritmo: ShellSort");
        stop = clock();
    }
    
    default:
        break;
    }


    double timep = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("\nTempo: %.5lf \n\n", timep);
    

}