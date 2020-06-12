#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
#include "camiones.h"

#define LIBRE 0
#define OCUPADO 1


void inicializarMarcas(eMarca listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;
    }
}

void hardCodearMarcas(eMarca listado[], int tam)
{
    char nombre[3][20]= {"Ford","FIAT","VW"};
    char pais[3][20]= {"eeuu","italia","alemania"};
    int idMarca[3]= {300,301,302};

    int i;

    for(i=0; i<3; i++)
    {
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].pais,pais[i]);
        listado[i].idMarca = idMarca[i];
        listado[i].estado = OCUPADO;
    }
}

eMarca buscarMarca(eMarca listado[], int tam, int id)
{
    int i;
    eMarca auxMarca = {000,"no existe",LIBRE};
    for(i=0; i<tam; i++)
    {
        if(listado[i].idMarca == id)
        {
            auxMarca = listado[i];

        }
    }
    return auxMarca;

}

void mostrarMarcas(eMarca listadoMarcas[], int tMarca)
{
    int i;

    printf("   Nombre:    Pais de origen: \t id Marca:\n");

    for(i=0; i<tMarca; i++)
    {
        if(listadoMarcas[i].estado==OCUPADO)
        {
            mostrarMarca(listadoMarcas[i]);
        }
    }
}


void mostrarMarca(eMarca pMarca)
{
    if(pMarca.estado==OCUPADO)
    {
        printf("%8s \t %8s \t %8d\n",pMarca.nombre, pMarca.pais, pMarca.idMarca);
    }
}


