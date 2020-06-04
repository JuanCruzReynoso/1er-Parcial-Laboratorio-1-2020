#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferesCamiones.h"

#define LIBRE 0
#define OCUPADO 1
#define TCHO 12
#define TCAM 25
#define TMAR 3

int main()
{
    eChofer listadoChoferes[TCHO];
    eCamion listadoCamiones[TCAM];
    eMarca listadoMarcas[TMAR];
    int opcion;

    inicializarChoferes(listadoChoferes,TCHO);
    inicializarCamiones(listadoCamiones,TCAM);
    hardCodearChoferes(listadoChoferes,TCHO);
    hardCodearCamiones(listadoCamiones,TCAM);
    inicializarMarcas(listadoMarcas,TMAR);
    hardCodearMarcas(listadoMarcas,TMAR);
    do
    {
        opcion=menu();

        switch(opcion)
        {
        case 1:
            mostrarChoferes(listadoChoferes, TCHO);
            break;
        case 2:
            ///mostrarCamionesConChofer(listadoChoferes,TCHO,listadoCamiones,TCAM,listadoMarcas,TMAR);
            mostrarCamionesMarca(listadoCamiones,TCAM,listadoChoferes,TCHO,listadoMarcas,TMAR);
            break;
        case 3:
            mostrarChoferesConCamiones(listadoChoferes, TCHO, listadoCamiones, TCAM, listadoMarcas, TMAR);
            break;
        case 4:
            cargarCamion(listadoChoferes, TCHO, listadoCamiones, TCAM,listadoMarcas,TMAR);
            break;
        case 5:
            eliminarCamion(listadoCamiones,TCAM,listadoMarcas,TMAR);
            break;
        case 6:
            modificarCamion(listadoChoferes, TCHO, listadoCamiones, TCAM,listadoMarcas,TMAR);
            break;
        case 7:
            cargarChofer(listadoChoferes,TCHO);
            break;
        case 8:
            eliminarChofer(listadoChoferes, TCHO, listadoCamiones, TCAM);
            break;
        case 9:
            ordenarCamionesPorTipo(listadoCamiones,TCAM);
            ////   mostrarCamionesConChofer(listadoChoferes,TCHO,listadoCamiones,TCAM,listadoMarcas,TMAR);
            break;
        case 10:
            modificarChofer(listadoChoferes,TCHO);
            break;
        case 11:
            mostrarChoferesConMasDeUnCamion(listadoChoferes, TCHO,  listadoCamiones, TCAM);
            break;
        case 12:
            mostrarCaminionesConMasDeUnaDecada(listadoChoferes, TCHO, listadoCamiones, TCAM, listadoMarcas, TMAR);
            break;
        case 13:
            mostrarCamionesPorMarca(listadoChoferes, TCHO, listadoCamiones, TCAM, listadoMarcas, TMAR);
            break;
        case 14:
            ordenarChoferesPorCantidadDeCamiones(listadoChoferes, TCHO, listadoCamiones, TCAM);
            mostrarChoferes(listadoChoferes,TCHO);
            break;
        case 15:
            ordenarChoferesPorCantidadDeCamionesAlfabeticamente(listadoChoferes, TCHO, listadoCamiones, TCAM);
            mostrarChoferes(listadoChoferes,TCHO);
            break;
        case 16:
            promedioEdadChoferes(listadoChoferes, TCHO);
            break;
        case 17:
            promedioAntiguedadCamiones(listadoCamiones, TCAM);
            break;
        case 18:
            porcentajeChoferesVarones(listadoChoferes, TCHO);
            break;
        case 19:
            mostrarChoferesPorMarca(listadoChoferes, TCHO, listadoCamiones, TCAM, listadoMarcas, TMAR);
            break;
        case 20:
            printf("\nCerrando...");
            break;
        default:
            printf("Opcion incorrecta");
            break;

        }
    }
    while(opcion!=20);

    return 0;
}
