#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
    float precio;

} eJuego;
#endif // JUEGO_H_INCLUDED


int cargarDescJuegos(int id, eJuego juegos[], int tam, char desc[]);
void mostrarJuego(eJuego juego);
void mostrarJuegos(eJuego juegos[], int tam);
