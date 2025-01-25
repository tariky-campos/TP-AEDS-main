#ifndef ROCHAMINERAL_H
#define ROCHAMINERAL_H
#include "L_Mineral.h"
#define MAXTAMR 50

typedef struct
{
    float peso;
    char categoria[MAXTAMR];
    float latitude;
    float longitude;
    L_Minerais *L_Mineral;

} rochamineral;

rochamineral InicializaRocha(rochamineral* rocha, float lat_rocha, float long_rocha, float peso, L_Minerais* lista_mineral);

void set_listaminerais(rochamineral* rocha, L_Minerais* lista_mineral);
float getPeso(rochamineral *rocha);


void setPeso(rochamineral *rocha, float peso);
char* classificar(L_Minerais *pLista);
void set_categoria(rochamineral *rocha, char *categoria);
void set_latRocha(rochamineral *rocha, float lat_rocha);
void set_longRocha(rochamineral *rocha, float long_rocha);
#endif