#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarJuegos(eJuego juegos[], int tam)
{
    printf("    Id      Descripcion   Precio  \n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarJuego( juegos[i]);
    }
    printf("\n");
}

void mostrarJuego(eJuego juego)
{
    printf("  %d      %10s     %3.2f\n", juego.id, juego.descripcion, juego.precio);

}
int cargarDescJuegos(int id, eJuego juegos[], int tam, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == juegos[i].id)
        {
            strcpy(desc, juegos[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

