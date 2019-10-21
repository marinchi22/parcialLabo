#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion [51];
    float precio;
}eCategoria;

#endif // CATEGORIA_H_INCLUDED

void mostrarCategoria(eCategoria categoria);
void mostrarCategorias(eCategoria categorias[], int tam);
int cargarDescCategoria(int id, eCategoria categorias[], int tam, char desc[]);
