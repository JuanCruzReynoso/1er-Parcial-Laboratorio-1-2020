#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choferesCamiones.h"

#define LIBRE 0
#define OCUPADO 1
#define TCHO 12
#define TCAM 25


void inicializarChoferes(eChofer listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listado[i].estado = LIBRE;
    }
}

void hardCodearChoferes(eChofer listado[], int tam)
{
    char nombre[6][20]= {"Lucrecia","Jorge","Natalia","Matias","Jeremias","Miguel"};
    char apellido[6][20]= {"Castro","Morales","Martinez","Reynoso","Maldini","Santos"};
    char dni[6][10]= {"21585456","34666987","12020324","41363891","44323098","32555378"};
    int legajo[6]= {200,201,202,203,204,205};
    char nacionalidad[6][20]= {"Argentina","Paraguay","Bolivia","Argentina","Uruguay","Peru"};
    char telefono[6][10]= {"4303-6805","4302-6685","4301-8822","4302-6645","4301-6869","4323-2020"};
    int edad[6]= {55,44,28,35,62,38};
    char sexo[6][20]= {"femenino","masculino","femenino","masculino","masculino","masculino"};
    int idChofer[6]= {100,101,102,103,104,105};

    int i;

    for(i=0; i<6; i++)
    {
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].apellido, apellido[i]);
        strcpy(listado[i].dni, dni[i]);
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad, nacionalidad[i]);
        strcpy(listado[i].telefono, telefono[i]);
        listado[i].edad = edad[i];
        strcpy(listado[i].sexo, sexo[i]);
        listado[i].idChofer = idChofer[i];
        listado[i].estado = OCUPADO;
    }

}
void mostrarChoferes(eChofer listado[], int tam)
{
    int i;

    printf("Nombre y Apellido: \t     DNI: \t       Legajo: \t Nacionalidad: \t Telefono: \t     Edad: \t     Sexo:         ID: \n");

    for(i=0; i<tam; i++)
    {
        mostrarChofer(listado[i]);
    }

}
void mostrarChofer(eChofer pChofer)
{
    if(pChofer.estado==OCUPADO)
    {
        printf("%8s %8s \t %12s \t %12d \t %8s \t %8s \t %8d \t %12s %8d \n",pChofer.nombre
               ,pChofer.apellido
               ,pChofer.dni
               ,pChofer.legajo
               ,pChofer.nacionalidad
               ,pChofer.telefono
               ,pChofer.edad
               ,pChofer.sexo
               ,pChofer.idChofer);
    }
}

int buscarChoferLibre(eChofer listado[], int tam)
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

int generarIdChofer(eChofer listado[], int tam)
{
    int idAux= 99;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            if(listado[i].idChofer > idAux)
            {
                idAux = listado[i].idChofer;
            }
        }
    }

    return idAux+1;
}

eChofer buscarChoferPorId(eChofer listado[], int tam,int id)
{
    int i;
    eChofer aux= {"No existe","No existe","No existe",-999,"No existe","No existe",-1,"no existe",-100};

    for(i=0; i<tam; i++)
    {
        if(listado[i].idChofer==id)
        {
            aux=listado[i];
            break;
        }
    }

    return aux;
}

void cargarChofer(eChofer listado[], int tam)
{
    eChofer miChofer;
    int i;
    int id;
    int respuestaSexo;
    char masculino[20]="masculino";
    char femenino[20]="femenino";

    i=buscarChoferLibre(listado,tam);
    id=generarIdChofer(listado,tam);

    if (i != -1)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(miChofer.nombre);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(miChofer.apellido);
        printf("\nIngrese dni: ");
        fflush(stdin);
        gets(miChofer.dni);
        printf("\nIngrese legajo: ");
        scanf("%d",&miChofer.legajo);
        printf("\nIngrese nacionalidad: ");
        fflush(stdin);
        gets(miChofer.nacionalidad);
        printf("\nIngrese telefono: ");
        fflush(stdin);
        gets(miChofer.telefono);
        printf("\nIngrese edad: ");
        scanf("%d",&miChofer.edad);
        do
        {
            printf("\nIngrese sexo (1 para masculino - 2 para femenino): ");
            scanf("%d",&respuestaSexo);
            switch(respuestaSexo)
            {
            case 1:
                strcpy(miChofer.sexo,masculino);
                break;
            case 2:
                strcpy(miChofer.sexo,femenino);
                break;
            default:
                printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
                break;
            }
        }
        while(respuestaSexo!=1 && respuestaSexo!=2);

        miChofer.estado=OCUPADO;
        miChofer.idChofer=id;
        listado[i]=miChofer;
    }
    else
    {
        printf("\n---------------------------------------------------No hay lugar---------------------------------------------------");
    }
}

int menuModificarChofer()
{
    int opcion;
    printf("\n 1- Modificar nombre"
           "\n 2- Modificar apellido"
           "\n 3- Modificar dni"
           "\n 4- Modificar legajo"
           "\n 5- Modificar nacionalidad"
           "\n 6- Modificar telefono"
           "\n 7- Modificar edad"
           "\n 8- Modificar sexo"
           "\n 9- Continuar"
           "\n Ingrese una opcion: \n");
    scanf("%d",&opcion);
    return opcion;
}

void modificarChofer(eChofer listado[], int tam)
{
    int i;
    int id;
    int flag = 0;
    eChofer aux;
    int opcion;
    int respuesta;
    int respuestaSexo;
    char masculino[20]="masculino";
    char femenino[20]="femenino";

    mostrarChoferes(listado,tam);
    printf("\n Ingrese id del chofer a modificar: ");
    scanf("%d", &id);
    aux=buscarChoferPorId(listado,tam,id);

    for(i=0; i<tam; i++)
    {
        if(aux.idChofer == listado[i].idChofer)
        {
            flag = 1;
            break;
        }
    }
    if(flag==1)
    {
        aux = listado[i];
        mostrarChofer(aux);
        do
        {
            opcion=menuModificarChofer();

            switch(opcion)
            {
            case 1:
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(aux.nombre);
                break;
            case 2:
                printf("Reingrese apellido: ");
                fflush(stdin);
                gets(aux.apellido);
                break;
            case 3:
                printf("Reingrese dni: ");
                fflush(stdin);
                gets(aux.dni);
                break;
            case 4:
                printf("Reingrese legajo: ");
                scanf("%d",&aux.legajo);
                break;
            case 5:
                printf("Reingrese nacionalidad: ");
                fflush(stdin);
                gets(aux.nacionalidad);
                break;
            case 6:
                printf("Reingrese telefono: ");
                fflush(stdin);
                gets(aux.telefono);
                break;
            case 7:
                printf("Reingrese edad: ");
                scanf("%d",&aux.edad);
                break;
            case 8:
                do
                {
                    printf("Reingrese sexo (1 para masculino - 2 para femenino): ");
                    scanf("%d",&respuestaSexo);
                    switch(respuestaSexo)
                    {
                    case 1:
                        strcpy(aux.sexo,masculino);
                        break;
                    case 2:
                        strcpy(aux.sexo,femenino);
                        break;
                    default:
                        printf("---------------------------------------------------Respuesta incorrecta---------------------------------------------------");
                        break;
                    }
                }
                while(respuestaSexo!=1 && respuestaSexo!=2);

                break;
            case 9:
                break;
            default:
                printf("---------------------------------------------------Opcion incorrecta---------------------------------------------------");
                break;

            }
        }
        while(opcion!=9);

        do
        {
            mostrarChofer(aux);
            printf("\nDesea confirmar modificacion? (1 para confirmar - 2 para cancelar)\n");
            scanf("%d", &respuesta);

            switch(respuesta)
            {
            case 1:
                listado[i] = aux;
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

void promedioEdadChoferes(eChofer listado[], int tam)
{
    int i;
    float promedio;
    int acumuladorEdades = 0;
    int contadorEdades = 0;

    for(i = 0; i<tam; i++)
    {

        if(listado[i].estado == OCUPADO)
        {
            acumuladorEdades = acumuladorEdades + listado[i].edad;
            contadorEdades++;
        }

    }

    promedio = (float)acumuladorEdades/contadorEdades;

    printf("\nEl promedio de edades es %.2f.\n",promedio);

}

void porcentajeChoferesVarones(eChofer listado[], int tam)
{
    int i;
    float promedio;
    int contador = 0;
    int contadorVarones = 0 ;


    for(i = 0; i<tam; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            if(strcmp(listado[i].sexo,"masculino")==0)
            {
                contadorVarones++;
            }
            contador++;
        }

    }

    promedio = (float)contadorVarones/contador;


    printf("\nEl porcentaje de choferes varones es del: %.2f\n",promedio*100);

}




