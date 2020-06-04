#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferesCamiones.h"

#define LIBRE 0
#define OCUPADO 1
#define TCHO 12
#define TCAM 25

void inicializarCamiones(eCamion listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;
    }
}

void hardCodearCamiones(eCamion listado[], int tam)
{
    char patente[10][10]= {"dog-368","ppt-234","atr-420","pbi-666","cat-223","mlp-234","mvp-733","boo-800","pte-669","ppp-444"};
    /// char marca[10][20]={"Ford","Ford","FIAT","FIAT","VW","Ford","Ford","Ford","Ford","Ford"};
    int anio[10]= {2000,2000,1998,2002,2010,2005,2015,2003,2012,2006};
    float peso[10]= {8.5,9.2,10.5,12.24,33.25,23.45,7.9,8.75,7.99,10.25};
    int ruedas[10]= {6,8,8,10,6,4,6,8,10,12};
    char tipo[10][20]= {"corta distancia","larga distancia","larga distancia","corta distancia","larga distancia","corta distancia","larga distancia","larga distancia","corta distancia","larga distancia"};
    int idMarca[10]= {300,300,301,301,302,300,300,300,300,300};
    int idCamion[10]= {200,201,202,203,204,205,206,207,208,209};
    int idChofer[10]= {100,100,101,101,102,103,103,104,104,104};

    int i;

    for(i=0; i<10; i++)
    {
        strcpy(listado[i].patente, patente[i]);
        listado[i].anio = anio[i];
        listado[i].peso = peso[i];
        listado[i].ruedas=ruedas[i];
        strcpy(listado[i].tipo,tipo[i]);
        listado[i].idMarca = idMarca[i];
        listado[i].idCamion = idCamion[i];
        listado[i].idChofer = idChofer[i];
        listado[i].estado = OCUPADO;
    }

}

void mostrarCamiones(eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{
    int i;
    int j;

    printf("Patente:    marca: \t     Anio: \t     Peso:    Ruedas: \t Tipo: \n");

    for(i=0; i<tCamion; i++)
    {
        for(j=0; j<tMarca; j++)
        {
            if(listadoCamiones[i].estado==OCUPADO)
            {
                mostrarCamion(listadoCamiones[i],listadoMarcas[j]);
            }
        }
    }
}


void mostrarCamion(eCamion pCamion,eMarca pMarca)
{
    if(pCamion.estado==OCUPADO)
    {
        printf("%8s %8s \t %8d \t %8.2f %8d \t %8s \n",pCamion.patente
               ,pMarca.nombre
               ,pCamion.anio
               ,pCamion.peso
               ,pCamion.ruedas
               ,pCamion.tipo);
    }
}

void mostrarCamionesConId(eCamion listadoCamiones[], int tCamion,eMarca listadoMarcas[], int tMarca)
{
    int i;

    printf("Patente:    marca: \t     Anio: \t     Peso:    Ruedas: \t Tipo: \t  \t        Id Camion:\t    Id Chofer:\n");

    for(i=0; i<tCamion; i++)
    {
        if(listadoCamiones[i].estado==OCUPADO)
        {
            mostrarCamionConId(listadoCamiones[i],listadoMarcas,tMarca);
        }
    }

}

void mostrarCamionConId(eCamion pCamion,eMarca listadoMarcas[], int tMarca)
{
    int i;

    if(pCamion.estado==OCUPADO)
    {
        for(i=0; i<tMarca; i++)
        {
            if (listadoMarcas[i].idMarca == pCamion.idMarca)
            {
                printf("%8s %8s \t %8d \t %8.2f %8d \t %8s \t %8d \t %8d \n",pCamion.patente
                       ,listadoMarcas[i].nombre
                       ,pCamion.anio
                       ,pCamion.peso
                       ,pCamion.ruedas
                       ,pCamion.tipo
                       ,pCamion.idCamion
                       ,pCamion.idChofer);
            }
        }
    }
}

int buscarCamionLibre(eCamion listado[], int tam)
{
    int i;
    int indice=-1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int generarIdCamion(eCamion listado[], int tam)
{
    int idAux= 199;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            if(listado[i].idCamion > idAux)
            {
                idAux = listado[i].idCamion;
            }
        }
    }

    return idAux+1;
}

eCamion buscarCamionPorId(eCamion listado[], int tam,int id)
{
    int i;
    eCamion aux;

    for(i=0; i<tam; i++)
    {
        if(listado[i].idCamion==id)
        {
            aux=listado[i];
            break;
        }
    }

    return aux;
}

void eliminarCamion(eCamion listadoCamiones[],int tCamion, eMarca listadoMarcas[], int tMarca)
{
    int i;
    int id;
    int flag = 0;
    eCamion aux;
    int respuesta;

    mostrarCamionesConId(listadoCamiones,tCamion,listadoMarcas,tMarca);
    printf("\nIngrese id del camion a eliminar: ");
    scanf("%d", &id);
    aux=buscarCamionPorId(listadoCamiones,tCamion,id);

    for(i=0; i<tCamion; i++)
    {
        if(aux.idCamion == listadoCamiones[i].idCamion)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        do
        {
            mostrarCamionConId(listadoCamiones[i],listadoMarcas,tMarca);
            printf("\nDesea confirmar eliminacion? (1 para confirmar - 2 para cancelar)\n");
            scanf("%d",&respuesta);

            switch(respuesta)
            {
            case 1:
                listadoCamiones[i].estado = LIBRE;
                printf("Eliminacion excitosa \n");
                break;
            case 2:
                printf("Eliminacion cancelada \n");
                break;
            default:
                printf("---------------------------------------------------Opcion incorrecta---------------------------------------------------");
                break;
            }
        }
        while(respuesta!=1 && respuesta!=2);

    }
    else
    {
        printf("---------------------------------------------------No existe---------------------------------------------------");
    }


}



void ordenarCamionesPorTipo(eCamion listado[],int tam)
{
    int i;
    int j;
    eCamion auxCamion;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].tipo,listado[j].tipo)>0)
            {
                auxCamion=listado[i];
                listado[i]=listado[j];
                listado[j]=auxCamion;
            }
        }
    }
}

void promedioAntiguedadCamiones(eCamion listado[], int tam)
{
    int i;
    int acumuladorAntiguedad = 0;
    int contadorAntiguedad = 0;
    float promedio;

    for(i = 0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            acumuladorAntiguedad = acumuladorAntiguedad + (2020 - listado[i].anio);
            contadorAntiguedad++;
        }

    }

    promedio = (float)acumuladorAntiguedad/contadorAntiguedad;


    printf("\nEl promedio de antiguedad de la flota de camiones es de %.2f\n",promedio);

}

