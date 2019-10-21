#include "categoria.h"
#include "cliente.h"


#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int codAlq;
    int codJuego;
    int codCliente;
    eFecha fechaAlquiler;
    int isEmpty;
} eAlquileres;

#endif // ALQUILERES_H_INCLUDED


void inicializarAlquileres(eAlquileres vec[], int tam);
int hardcodearAlquileres( eAlquileres vec[], int tam, int cantidad);
void mostrarAlquiler(eAlquileres x, eJuego juegos[], int tamJ);
void mostrarAlquileres(eAlquileres vec[],int tam, eJuego juegos[], int tamJ);
int buscarAlmuerzoLibre(eAlquileres vec[], int tam);
int altaAlquiler( eAlquileres alquileres[], int tAlquileres, int codAlquiler, eJuego juegos[], int tJuegos, eCliente clientes[], int tClientes);
eAlquileres newAlquiler(int codAlquiler,int codCliente,int codJuego, eFecha fecha);
