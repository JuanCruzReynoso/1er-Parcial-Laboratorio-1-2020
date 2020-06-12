#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED

#include "nacionalidad.h"

typedef struct
{
    char nombre[20];
    char apellido[20];
    char dni[10];
    int legajo;
    ///char nacionalidad[20];
    char telefono[10];
    int edad;
    char sexo[20];
    int idChofer;
    int idNacion;
    int estado;
} eChofer;

void inicializarChoferes(eChofer listado[], int tam);
void hardCodearChoferes(eChofer listado[], int tam);
void mostrarChoferes(eChofer listadoChoferes[], int tChofer, eNacion listadoNaciones[], int tNacion);
void mostrarChofer(eChofer pChofer, eNacion pNacion);
int buscarChoferLibre(eChofer listado[], int tam);
int generarIdChofer(eChofer listado[], int tam);
eChofer buscarChoferPorId(eChofer listado[], int tam,int id);
void cargarChofer(eChofer listado[], int tam, eNacion listadoNaciones[], int tNacion);
int menuModificarChofer();
void modificarChofer(eChofer listado[], int tam);
void promedioEdadChoferes(eChofer listado[], int tam);
void porcentajeChoferesVarones(eChofer listado[], int tam);
void mostrarChoferNacion(eChofer pChofer, eNacion listadoNaciones[], int tNacion);
void mostrarChoferesPorNacionalidad(eChofer listadoChoferes[], int tChofer, eNacion listadoNaciones[], int tNacion);
void ordenarChoferesPorNacionalidadYNombre(eChofer listadoChoferes[],int tChofer);

#endif // CHOFERES_H_INCLUDED
