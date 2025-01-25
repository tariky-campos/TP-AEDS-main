#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rocha.h"
#define zero 0
#define um 1
#define dois 2
#define tres 3

rochamineral InicializaRocha(rochamineral* rocha, float lat_rocha, float long_rocha, float peso, L_Minerais* lista_mineral) {
     //inicia lista mineral na rocha
    set_listaminerais(rocha, lista_mineral);
   
    setPeso(rocha, peso);
    set_latRocha(rocha, lat_rocha);
    set_longRocha(rocha, long_rocha);
    char* classificacao = classificar(lista_mineral);
    set_categoria(rocha, classificacao);
    return *rocha;
}

void set_listaminerais(rochamineral* rocha, L_Minerais* lista_mineral) {
    rocha->L_Mineral = lista_mineral;
}


char* classificar(L_Minerais *pLista)
{
    int aux = TMListaM(pLista);
    if (aux == 0) {
        printf("Nao tem mineral\n");
        return "0";
    }
    
    if (aux == 1)
    {
        {
            if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Ferrolita") == 0)
            {
                return "Ferrom";
            }
            else if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Solarium") == 0)
            {
                return "Solaris";
            }
        }
    }
    if (aux == 2)
    {
        if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Terranita") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Terranita")) == 0)
        {
            if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Calaris") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Calaris")) == 0){
                return "Terrolis";
            }
            else if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Solarium") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Solarium")) == 0){
                return "Terrasol";
            }
            else if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Aquavitae") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Aquavitae")) == 0){
                return "Aquaterra";
            }
            else if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Ferrolita") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Ferrolita")) == 0){
                return "Terralis";
            }
        }
        if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Aquavitae") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Aquavitae") == 0)){
            if(strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Calaris") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Calaris")) == 0){
                return "Calquer";
            }
        }
        if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Ferrolita") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Ferrolita")) == 0){
            if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Solarium") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Solarium")) == 0){
                return "Solarisfer";
            }
            else if (strcmp(pLista->ListaMINERAIS[0].Chave.nomeM, "Aquavitae") == 0 || (strcmp(pLista->ListaMINERAIS[1].Chave.nomeM, "Aquavitae")) == 0){
                return "Aquaferro";
            }
        }   
    }
    if (aux == 3) {
        return "Aquacalis";
    }
    return NULL;
}
void setPeso(rochamineral *rocha, float peso)
{
    rocha->peso = peso;
}
void set_categoria(rochamineral *rocha, char *categoria)
{
    strcpy(rocha->categoria, categoria);
}

void set_latRocha(rochamineral *rocha, float lat_rocha){
    rocha->latitude = lat_rocha;
}
void set_longRocha(rochamineral *rocha, float long_rocha){
    rocha->longitude = long_rocha;
}


float getPeso(rochamineral *rocha)
{
    return rocha->peso;
}

