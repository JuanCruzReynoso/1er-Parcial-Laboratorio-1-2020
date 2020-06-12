#ifndef NACIONALIDAD_H_INCLUDED
#define NACIONALIDAD_H_INCLUDED

typedef struct
{
    char pais[20];///italia argentina uruguay
    char idioma[20];
    char descripcion[20];///italiano argentino uruguayo
    int estado;
    int idNacion;///400 401 402
} eNacion;

void inicializarNacionalidad(eNacion listado[], int tam);
void hardCodearNacionalidad(eNacion listado[], int tam);
eNacion buscarNacionalidad(eNacion listado[], int tam, int id);
void mostrarNacionalidades(eNacion listado[], int tam);
void mostrarNacionalidad(eNacion pNacion);



#endif // NACIONALIDAD_H_INCLUDED
