#include "Alquileres.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inicializarAlquileres(eAlquileres vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void mostrarAlquiler(eAlquileres x, eJuego juegos[], int tamJ)
{
    char descJuego[20];

    cargarDescJuegos(x.codAlq, juegos, tamJ, descJuego);
    printf("  %d    %10s   %d  %02d/%02d/%d\n",
           x.codAlq,
           descJuego,
           x.codCliente,
           x.fechaAlquiler.dia,
           x.fechaAlquiler.mes,
           x.fechaAlquiler.anio);
}

void mostrarAlquileres(eAlquileres vec[], int tam,  eJuego juegos[], int tamJ)
{

    int flag = 0;
    system("cls");

    printf(" Id     Juego     Cliente    Fecha \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlquiler(vec[i], juegos, tamJ);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alquileres que mostrar\n");
    }

    printf("\n\n");
}

int buscarAlquilerLibre(eAlquileres vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlquiler( eAlquileres alquileres[], int tAlquiler,int codAlquiler, eJuego juegos[],int tJuegos, eCliente clientes[],int tClientes)
{
    int todoOk = 0;
    int indice;
    int codJuego;
    int codCliente;
    eFecha fechaAlquiler;

    system("cls");

    printf("*****Alta de Alquiler*****\n\n");

    indice = buscarAlquilerLibre(alquileres, tAlquiler);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarClientes(clientes,tClientes,juegos,tJuegos);
        printf("Ingrese codigo de cliente: ");
        scanf("%d", &codCliente);

        mostrarJuegos(juegos, tJuegos);
        printf("Ingrese id Juego: ");
        scanf("%d", &codJuego);

        printf("Ingrese fecha : ");
        scanf("%d/%d/%d", &fechaAlquiler.dia, &fechaAlquiler.mes, &fechaAlquiler.anio);



        alquileres[indice] = newAlquiler(codAlquiler, codCliente, codJuego, fechaAlquiler);
        todoOk = 1;
        printf("Alta de Alquiler exitosa!!\n\n");
    }
    return todoOk;
}

eAlquileres newAlquiler(int codAlquiler,int codCliente,int codJuego, eFecha fecha)
{
    eAlquileres al;
    al.codAlq = codAlquiler;
    al.codCliente = codCliente;
    al.codJuego = codJuego;
    al.fechaAlquiler = fecha;
    al.isEmpty = 0;

    return al;
}

int hardcodearAlquileres( eAlquileres vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlquileres suplentes[]=
    {
        { 0, 1, 0, {1, 10, 2019}, 0},
        { 1, 1, 2, {1, 10, 2019}, 0},
        { 2, 2, 2, {1, 10, 2019}, 0},
        { 3, 3, 3, {1, 10, 2019}, 0},
        { 4, 4, 1, {2, 10, 2019}, 0},
        { 5, 3, 3, {2, 10, 2019}, 0},
        { 6, 5, 1, {2, 10, 2019}, 0},
        { 7, 2, 5, {2, 10, 2019}, 0},
        { 8, 3, 4, {3, 10, 2019}, 0},
        { 9, 4, 1, {3, 10, 2019}, 0},

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
