#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferes.h"
#include "camiones.h"
#include "marca.h"
#include "nacionalidad.h"

#define LIBRE 0
#define OCUPADO 1

int menu()
{
    int opcion;
    printf("\n 1- Mostrar lista de choferes"
           "\n 2- Mostrar lista de camiones"
           "\n 3- Mostrar lista de choferes con su camiones"
           "\n 4- Alta Camion"
           "\n 5- Baja Camion"
           "\n 6- Modificar Camion"
           "\n 7- Alta Chofer"
           "\n 8- Baja Chofer"
           "\n 9- Ordenar camiones por tipo"
           "\n 10- Modificar Chofer"
           "\n 11- Mostrar choferes con mas de un camion"
           "\n 12- Mostrar los camiones con mas de 10 años de antiguedad"
           "\n 13- Buscar camiones por marca"
           "\n 14- Ordenar choferes por cantidad de camiones"
           "\n 15- Ordenar choferes por cantidad de camiones alfabeticamente"
           "\n 16- Promediar edad entre choferes"
           "\n 17- Promediar antiguedad entre camiones"
           "\n 18- Porcentaje total de choferes varones"
           "\n 19- Buscar choferes por marca"
           "\n 20- Buscar choferes por nacionalidad"
           "\n 21- Ordenar choferes por nacionalidad"
           "\n 22- Salir"
           "\n Ingrese una opcion: ");
    scanf("%d",&opcion);
    return opcion;

}

void mostrarChoferesConCamiones(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion,eMarca listadoMarcas[],int tMarca,eNacion listadoNaciones[],int tNacion)
{
    int i;
    int j;
    int k;
    int l;
    char flag;

    for(i=0; i<tChofer; i++)
    {
        flag = 'n';
        for(l=0; l<tNacion; l++)
        {
            if(listadoNaciones[l].idNacion==listadoChoferes[i].idNacion)
            {
                mostrarChoferNacion(listadoChoferes[i],listadoNaciones,tNacion);
            }

        }
        for(j=0; j<tCamion; j++)
        {
            if(listadoChoferes[i].idChofer==listadoCamiones[j].idChofer)
            {
                flag='s';
                for (k=0; k<tMarca; k++)
                {
                    if(listadoMarcas[k].idMarca==listadoCamiones[j].idMarca)
                    {
                        mostrarCamion(listadoCamiones[j],listadoMarcas[k]);
                    }
                }
            }
        }
        if(flag=='n')
        {
            printf("---------------------------------------------------No tiene camiones---------------------------------------------------\n");
        }

    }

}

/*void mostrarCamionesConChofer(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{
    int i;
    int j;
    int k;

    printf("Patente:   \t     Anio: \t     Peso:    Ruedas: \t Tipo: \t           Chofer a cargo: \t   Marca:\n");

    for(i=0; i<tCamion; i++)
    {
        for(j=0; j<tChofer; j++)
        {
            for(k=0; k<tMarca; k++)
            {

                if(listadoCamiones[i].estado==OCUPADO)
                {
                    if(listadoCamiones[i].idChofer==listadoChoferes[j].idChofer && listadoCamiones[i].idCamion==listadoMarcas[k].idCamion)
                    {
                        printf("%8s \t %8d \t %8.2f %8d \t %8s \t %8s \n",listadoCamiones[i].patente
                               ,listadoCamiones[i].anio
                               ,listadoCamiones[i].peso
                               ,listadoCamiones[i].ruedas
                               ,listadoCamiones[i].tipo
                               ,listadoChoferes[j].nombre
                               ,listadoMarcas[k].nombre);
                    }
                }
            }
        }
    }
}*/

void cargarCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{
    eCamion miCamion;
    int i;
    int idAux;
    int id;
    int respuestaTipo;
    char corta[20]="corta distancia";
    char larga[20]="larga distancia";
    int respuestaMarca;

    i=buscarCamionLibre(listadoCamiones,tCamion);
    id=generarIdCamion(listadoCamiones,tCamion);
    ///  mostrarChoferes(listadoChoferes,tChofer);
    printf("Ingrese id del chofer a cargo del camion que desea dar de alta\n");
    scanf("%d",&idAux);

    if (i != -1)
    {
        printf("\nIngrese patente: ");
        fflush(stdin);
        gets(miCamion.patente);

        do
        {
            mostrarMarcas(listadoMarcas,tMarca);
            printf("\nIngrese id de marca: ");
            scanf("%d",&respuestaMarca);
            switch(respuestaMarca)
            {
            case 300:
                miCamion.idMarca=300;
                break;
            case 301:
                miCamion.idMarca=301;
                break;
            case 302:
                miCamion.idMarca=302;
                break;
            default:
                printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
                break;
            }

        }
        while(respuestaMarca!=300 && respuestaMarca!=301 && respuestaMarca !=302);
        printf("\nIngrese anio: ");
        scanf("%d",&miCamion.anio);
        printf("\nIngrese peso: ");
        scanf("%f",&miCamion.peso);
        printf("\nIngrese cantidad de ruedas: ");
        scanf("%d",&miCamion.ruedas);
        do
        {
            printf("\nIngrese tipo (1 para corta distancia - 2 para larga distancia) : ");
            scanf("%d",&respuestaTipo);
            switch(respuestaTipo)
            {
            case 1:
                strcpy(miCamion.tipo,corta);
                break;
            case 2:
                strcpy(miCamion.tipo,larga);
                break;
            default:
                printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
                break;
            }

        }
        while(respuestaTipo!=1 && respuestaTipo!=2);

        miCamion.estado=OCUPADO;
        miCamion.idCamion=id;
        miCamion.idChofer=idAux;
        listadoCamiones[i]=miCamion;
    }
    else
    {
        printf("\n---------------------------------------------------No hay lugar---------------------------------------------------");
    }

}

void eliminarChofer(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion,eNacion listadoNaciones[], int tNacion)
{
    int i;
    int j;
    int id;
    int flag = 0;
    eChofer aux;
    int respuesta;

    mostrarChoferesNacion(listadoChoferes,tChofer,listadoNaciones,tNacion);
    printf("\nIngrese id del chofer a eliminar: ");
    scanf("%d", &id);
    aux=buscarChoferPorId(listadoChoferes,tChofer,id);

    for(i=0; i<tChofer; i++)
    {
        if(aux.idChofer == listadoChoferes[i].idChofer)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        do
        {
            printf("\nDesea confirmar eliminacion? (1 para confirmar - 2 para cancelar)\n");
            scanf("%d",&respuesta);

            switch(respuesta)
            {
            case 1:
                ///  mostrarChofer(listadoChoferes[i]);
                listadoChoferes[i].estado = LIBRE;
                for(j=0; j<tCamion; j++)
                {
                    if(listadoCamiones[j].idChofer==listadoChoferes[i].idChofer)
                    {
                        listadoCamiones[j].estado = LIBRE;
                    }
                }
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

void mostrarCamionMarca(eCamion pCamion, eChofer listadoChoferes[], int tChofer, eMarca listadoMarcas[], int tMarca)
{
    eChofer auxChofer;
    eMarca auxMarca;

    auxMarca = buscarMarca(listadoMarcas,tMarca,pCamion.idMarca);
    auxChofer = buscarChoferPorId(listadoChoferes, tChofer, pCamion.idChofer);
    if(pCamion.estado == OCUPADO)
    {

        printf("%12s %16s %17d %20f %8d %22s %13s\n", auxMarca.nombre, pCamion.patente, pCamion.anio, pCamion.peso, pCamion.ruedas, pCamion.tipo, auxChofer.nombre);
    }


}

void mostrarCamionesMarca(eCamion listadoCamiones[], int tCamion, eChofer listadoChoferes[], int tChofer, eMarca listadoMarcas[], int tMarca)
{
    int i;
    printf("\n       Marca:         Patente:              Anio:             Peso:       Ruedas:         Tipo:          Chofer a cargo:");

    for(i=0; i<tCamion; i++)
    {
        if(listadoCamiones[i].estado==OCUPADO)
        {
            mostrarCamionMarca(listadoCamiones[i],listadoChoferes,tChofer,listadoMarcas,tMarca);
        }
    }

}

int menuModificarCamion()
{
    int opcion;
    printf("\n 1- Modificar Marca"
           "\n 2- Modificar Chofer"
           "\n 3- Continuar"
           "\n Ingrese una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}

void modificarCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[],int tCamion, eMarca listadoMarcas[],int tMarca)
{
    int i;
    int id;
    int flag = 0;
    eCamion aux;
    int opcion;
    int respuesta;
    int respuestaMarca;

    mostrarCamionesConId(listadoCamiones,tCamion,listadoMarcas,tMarca);
    printf("\n Ingrese id del camion a modificar: ");
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
        aux = listadoCamiones[i];
        mostrarCamionConId(aux,listadoMarcas,tMarca);
        do
        {
            opcion=menuModificarCamion();

            switch(opcion)
            {
            case 1:
                do
                {
                    mostrarMarcas(listadoMarcas,tMarca);
                    printf("\nReingrese id de marca: ");
                    scanf("%d",&respuestaMarca);
                    switch(respuestaMarca)
                    {
                    case 300:
                        aux.idMarca=300;
                        break;
                    case 301:
                        aux.idMarca=301;
                        break;
                    case 302:
                        aux.idMarca=302;
                        break;
                    default:
                        printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
                        break;
                    }

                }
                while(respuestaMarca!=300 && respuestaMarca!=301 && respuestaMarca !=302);
                break;
            case 2:
///                mostrarChoferes(listadoChoferes,tChofer);
                printf("Reingrese id del Chofer : ");
                scanf("%d",&aux.idChofer);
                break;
            case 3:
                break;
            default:
                printf("---------------------------------------------------Opcion incorrecta---------------------------------------------------");
                break;

            }
        }
        while(opcion!=3);

        do
        {
            mostrarCamionConId(aux,listadoMarcas,tMarca);
            printf("\nDesea confirmar modificacion? (1 para confirmar - 2 para cancelar)\n");
            scanf("%d", &respuesta);

            switch(respuesta)
            {
            case 1:
                listadoCamiones[i] = aux;
                printf("\n Modificacion excitosa\n");
                break;
            case 2:
                printf("\n Modificacion cancelada\n");
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

void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion)
{

    int contadorCamiones[tChofer];
    int i;
    int j;
    int k;

    for(i = 0; i<tChofer; i++)
    {
        contadorCamiones[i] = 0;
    }


    for(i = 0; i<tChofer; i++)
    {
        for(j = 0; j<tCamion; j++)
        {

            if(listadoChoferes[i].idChofer == listadoCamiones[j].idChofer)
            {

                contadorCamiones[i]++;

            }

        }

    }

    for(k = 0; k<tChofer; k++)
    {
        if(listadoChoferes[k].estado == OCUPADO && contadorCamiones[k]> 1)
        {

///            mostrarChofer(listadoChoferes[k]);
            printf("\nCantidad de camiones: %d\n",contadorCamiones[k]);

        }
    }


}

void mostrarCaminionesConMasDeUnaDecada(eChofer listadoChoferes[], int tChofer,eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{

    int Antiguedad[tCamion];
    int i;
    int j;

    for(i = 0; i<tCamion; i++)
    {
        if(listadoCamiones[i].estado == OCUPADO)
        {

            Antiguedad[i] = 2020 - listadoCamiones[i].anio;

        }

    }

    for(j = 0; j<tCamion; j++)
    {
        if(listadoCamiones[j].estado == OCUPADO && Antiguedad[j] > 10)
        {

            printf("\n----------------------------------------\n");
            mostrarCamionMarca(listadoCamiones[j], listadoChoferes, tChofer, listadoMarcas,tMarca);
            printf("\nAnios de antiguedad: %d\n",Antiguedad[j]);

        }
    }

}

void mostrarCamionesPorMarca(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{

    eMarca aux;
    int respuestaMarca;

    do
    {
        mostrarMarcas(listadoMarcas,tMarca);
        printf("\Ingrese id de marca a buscar: ");
        scanf("%d",&respuestaMarca);
        switch(respuestaMarca)
        {
        case 300:
            aux.idMarca=300;
            break;
        case 301:
            aux.idMarca=301;
            break;
        case 302:
            aux.idMarca=302;
            break;
        default:
            printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
            break;
        }

    }
    while(respuestaMarca!=300 && respuestaMarca!=301 && respuestaMarca !=302);

    for(int i = 0 ; i<tCamion; i++)
    {

        if(aux.idMarca == listadoCamiones[i].idMarca && listadoCamiones[i].estado == OCUPADO)
        {
            mostrarCamionMarca(listadoCamiones[i],listadoChoferes, tChofer, listadoMarcas, tMarca);
        }

    }


}

void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion)
{

    int contadorCamionesPorChofer[tChofer];
    eChofer aux;
    int i;
    int j;


    for(i = 0; i<tChofer; i++)
    {
        contadorCamionesPorChofer[i] = 0;
    }


    for(i = 0; i<tChofer; i++)
    {

        for(j = 0; j<tCamion; j++)
        {

            if(listadoChoferes[i].idChofer == listadoCamiones[j].idChofer && listadoCamiones[j].estado == OCUPADO)
            {

                contadorCamionesPorChofer[i]++;

            }

        }

    }


    for(i = 0; i<tChofer-1; i++)
    {

        for(j = i+1; j<tChofer; j++)
        {

            if(contadorCamionesPorChofer[i] < contadorCamionesPorChofer[j])
            {
                aux = listadoChoferes[i];
                listadoChoferes[i] = listadoChoferes[j];
                listadoChoferes[j] = aux;

            }

        }

    }

}

void ordenarChoferesPorCantidadDeCamionesAlfabeticamente(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion)
{

    int contadorCamionesPorChofer[tChofer];
    eChofer aux;
    int i;
    int j;


    for(i = 0; i<tChofer; i++)
    {
        contadorCamionesPorChofer[i] = 0;
    }


    for(i = 0; i<tChofer; i++)
    {

        for(j = 0; j<tCamion; j++)
        {

            if(listadoChoferes[i].idChofer == listadoCamiones[j].idChofer && listadoCamiones[j].estado == OCUPADO)
            {

                contadorCamionesPorChofer[i]++;

            }

        }

    }


    for(i = 0; i<tChofer-1; i++)
    {

        for(j = i+1; j<tChofer; j++)
        {

            if(contadorCamionesPorChofer[i] < contadorCamionesPorChofer[j])
            {
                aux = listadoChoferes[i];
                listadoChoferes[i] = listadoChoferes[j];
                listadoChoferes[j] = aux;

            }
            else
            {
                if (contadorCamionesPorChofer[i] == contadorCamionesPorChofer[j])
                {
                    if(strcmp(listadoChoferes[i].nombre,listadoChoferes[j].nombre)<0)
                    {
                        aux = listadoChoferes[i];
                        listadoChoferes[i] = listadoChoferes[j];
                        listadoChoferes[j] = aux;
                    }
                }
            }

        }

    }

}

void mostrarChoferesPorMarca(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca)
{
    eMarca aux;
    int respuestaMarca;
    int i;
    int j;

    do
    {
        mostrarMarcas(listadoMarcas,tMarca);
        printf("\Ingrese id de marca a buscar: ");
        scanf("%d",&respuestaMarca);
        switch(respuestaMarca)
        {
        case 300:
            aux.idMarca=300;
            break;
        case 301:
            aux.idMarca=301;
            break;
        case 302:
            aux.idMarca=302;
            break;
        default:
            printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
            break;
        }

    }
    while(respuestaMarca!=300 && respuestaMarca!=301 && respuestaMarca !=302);

    for(i = 0 ; i<tCamion; i++)
    {

        if(listadoCamiones[i].estado == OCUPADO && listadoCamiones[i].idMarca == aux.idMarca)
        {
            for(j = 0; j<tChofer; j++)
            {
                if(listadoChoferes[j].estado == OCUPADO && listadoCamiones[i].idChofer == listadoChoferes[j].idChofer)
                {
///                    mostrarChofer(listadoChoferes[j]);
                }
            }

        }
    }

}







