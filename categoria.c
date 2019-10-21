#include "categoria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarCategoria(eCategoria categoria)
{

    printf("  %d      %10s     %3.2f\n", categoria.id, categoria.descripcion, categoria.precio);

}
void mostrarCategorias(eCategoria categorias[], int tam)
{
    printf(" Id   Descripcion      Precio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarCategoria( categorias[i]);
    }
    printf("\n");
}

int cargarDescCategoria(int id, eCategoria categorias[], int tam, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == categorias[i].id)
        {
            strcpy(desc, categorias[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;

}
