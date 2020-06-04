#ifndef CHOFERESCAMIONES_H_INCLUDED
#define CHOFERESCAMIONES_H_INCLUDED
#include "choferes.h"
#include "camiones.h"
#include "marca.h"

#define LIBRE 0
#define OCUPADO 1

int menu();
void mostrarChoferesConCamiones(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion,eMarca listadoMarcas[], int tMarca);
void mostrarCamionesConChofer(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca);
void cargarCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca);
void eliminarChofer(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion);
void mostrarCamionMarca(eCamion pCamion, eChofer listadoChoferes[], int tChofer, eMarca listadoMarcas[], int tMarca);
void mostrarCamionesMarca(eCamion listadoCamiones[], int tCamion, eChofer listadoChoferes[], int tChofer, eMarca listadoMarcas[], int tMarca);
int menuModificarCamion();
void modificarCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[],int tCamion, eMarca listadoMarcas[], int tMarca);
void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion);
void mostrarCaminionesConMasDeUnaDecada(eChofer listadoChoferes[], int tChofer,eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca);
void mostrarCamionesPorMarca(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca);
void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion);
void ordenarChoferesPorCantidadDeCamionesAlfabeticamente(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion);
void mostrarChoferesPorMarca(eChofer listadoChoferes[], int tChofer, eCamion listadoCamiones[], int tCamion, eMarca listadoMarcas[], int tMarca);
#endif // CHOFERESCAMIONES_H_INCLUDED
