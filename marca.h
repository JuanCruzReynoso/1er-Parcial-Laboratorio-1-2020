#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct
{
    char nombre[20];///Ford FIAT VW
    char pais[20];///eeuu italia alemania
    int estado;
    int idMarca;///300 301 302
} eMarca;

void inicializarMarcas(eMarca listado[], int tam);
void hardCodearMarcas(eMarca listado[], int tam);
eMarca buscarMarca(eMarca listado[], int tam, int id);
void mostrarMarcas(eMarca listadoMarcas[], int tMarca);
void mostrarMarca(eMarca pMarca);

#endif // MARCA_H_INCLUDED
