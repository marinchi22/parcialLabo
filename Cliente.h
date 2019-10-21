#include "juego.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int codigo;
    char nombre[20];
    char apellido[20];
    char direccion[51];
    char sexo;
    eFecha fechaInscripcion;
    int telefono;
    int catPreferedida;
    int isEmpty;
} eCliente;


#endif // CLIENTE_H_INCLUDED


void inicializarClientes(eCliente vec[], int tam);
void mostrarCliente(eCliente x, eJuego juegos[], int tam);
void mostrarClientes(eCliente vec[], int tam, eJuego juegos[], int tamJ);
int buscarLibre(eCliente vec[], int tam);
int buscarCliente(int codigo, eCliente vec[], int tam);
int altaCliente(eCliente vec[], int tam, int codigo, eJuego juegos[], int tamC);
eCliente newCliente(int leg,char nombre[],char apellido[],char direccion[],int telefono, char sexo, eFecha fecha, int catPreferedida);
int harcodearClientes( eCliente vec[], int tam, int cantidad);
int bajaCliente(eCliente vec[], int tam, eJuego juegos[], int tamJ);
int modificarCliente(eCliente vec[], int tam, eJuego juegos[], int tamJ);
