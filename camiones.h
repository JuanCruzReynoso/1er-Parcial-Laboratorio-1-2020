#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED
#include "choferes.h"
#include "marca.h"

typedef struct
{
    char patente[10];

    int anio;
    float peso;
    int ruedas;
    char tipo[20];///{CortaDistancia,LargaDistancia})
    int idCamion;
    int idChofer;
    int idMarca;
    int estado;

} eCamion;

void inicializarCamiones(eCamion listado[], int tam);
void hardCodearCamiones(eCamion listado[], int tam);
int buscarCamionLibre(eCamion listado[], int tam);
int generarIdCamion(eCamion listado[], int tam);
void mostrarCamiones(eCamion listadoCamiones[], int tCamion, eMarca listadoMarca [], int tMarca);
void mostrarCamion(eCamion pCamion,eMarca pMarca);
void mostrarCamionesConId(eCamion listadoCamiones[], int tCamion,eMarca listadoMarcas[], int tMarca);
void mostrarCamionConId(eCamion pCamion,eMarca listadoMarcas[], int tMarca);
eCamion buscarCamionPorId(eCamion listado[], int tam,int id);
void eliminarCamion(eCamion listadoCamiones[],int tCamion, eMarca listadoMarcas[], int tMarca);
void ordenarCamionesPorTipo(eCamion listado[],int tam);
void promedioAntiguedadCamiones(eCamion listado[], int tam);
#endif // CAMIONES_H_INCLUDED
