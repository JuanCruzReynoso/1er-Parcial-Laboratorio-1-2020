#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED

typedef struct
{
    char nombre[20];
    char apellido[20];
    char dni[10];
    int legajo;
    char nacionalidad[20];
    char telefono[10];
    int edad;
    char sexo[20];
    int idChofer;
    int estado;
} eChofer;

void inicializarChoferes(eChofer listado[], int tam);
void hardCodearChoferes(eChofer listado[], int tam);
void mostrarChoferes(eChofer listado[], int tam);
void mostrarChofer(eChofer pChofer);
int buscarChoferLibre(eChofer listado[], int tam);
int generarIdChofer(eChofer listado[], int tam);
eChofer buscarChoferPorId(eChofer listado[], int tam,int id);
void cargarChofer(eChofer listado[], int tam);
int menuModificarChofer();
void modificarChofer(eChofer listado[], int tam);
void promedioEdadChoferes(eChofer listado[], int tam);
void porcentajeChoferesVarones(eChofer listado[], int tam);

#endif // CHOFERES_H_INCLUDED
