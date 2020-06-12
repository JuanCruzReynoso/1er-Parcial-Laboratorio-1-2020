#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nacionalidad.h"
#include "choferes.h"

#define LIBRE 0
#define OCUPADO 1


void inicializarNacionalidad(eNacion listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;
    }
}

void hardCodearNacionalidad(eNacion listado[], int tam)
{
    char pais[3][20]= {"Argentina","Italia","Uruguay"};
    char idioma[3][20]= {"Español","Italiano","Español"};
    char descripcion[3][20]= {"Argentino","Italiano","Uruguayo"};
    int idNacion[3]= {400,401,402};

    int i;

    for(i=0; i<3; i++)
    {
        strcpy(listado[i].pais,pais[i]);
        strcpy(listado[i].idioma,idioma[i]);
        strcpy(listado[i].descripcion,descripcion[i]);
        listado[i].idNacion = idNacion[i];
        listado[i].estado = OCUPADO;
    }
}

eNacion buscarNacionalidad(eNacion listado[], int tam, int id)
{
    int i;
    eNacion auxNacionalidad = {"no existe" ,"no existe","no existe",LIBRE,666};

    for(i=0; i<tam; i++)
    {
        if(listado[i].idNacion == id)
        {
            auxNacionalidad = listado[i];

        }
    }
    return auxNacionalidad;

}

void mostrarNacionalidades(eNacion listado[], int tam)
{
    int i;

    printf("   Pais:    Idioma: \t Descripcion: \t id Nacion:\n");

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarNacionalidad(listado[i]);
        }
    }
}


void mostrarNacionalidad(eNacion pNacion)
{
    if(pNacion.estado==OCUPADO)
    {
        printf("%8s \t %8s \t %8s \t %8d\n",pNacion.pais, pNacion.idioma, pNacion.descripcion, pNacion.idNacion);
    }
}

