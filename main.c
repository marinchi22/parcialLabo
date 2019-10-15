#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include "juego.h"

#define TAM 10
#define TAMJ 3
#define TAMAL 20


typedef struct
{
    int codAlq;
    int codJuego;
    int codCliente;
    eFecha fechaAlquiler;
    int isEmpty;
} eAlquileres;

int menuPrincipal();


//prototipos Alquileres
void inicializarAlquileres(eAlquileres vec[], int tam);
//int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlquiler(eAlquileres x, eJuego juegos[], int tamJ);
void mostrarAlquileres(eAlquileres vec[],int tam, eJuego juegos[], int tamJ);
int buscarAlmuerzoLibre(eAlquileres vec[], int tam);
int altaAlquiler( eAlquileres alquileres[], int tAlquileres, int codAlquiler, eJuego juegos[], int tJuegos, eCliente clientes[], int tClientes);
eAlquileres newAlquiler(int codAlquiler,int codCliente,int codJuego, eFecha fecha);




int main()
{
    int codigo=0;
    int codAlquiler=0;
    eJuego juegos[TAMJ]= {{1000,"Mesa"},{1001,"Naipes"},{1002,"Bingo"}};
    eCliente lista[TAM];
    inicializarClientes( lista, TAM);
    codigo = codigo + harcodearClientes(lista, TAM, 6);
    eAlquileres alquileres[TAMAL];
    inicializarAlquileres( alquileres, TAMAL);
    char salir= 'n';
    do
    {
        switch( menuPrincipal())
        {
        case 1:
            if(altaCliente(lista, TAM,codigo, juegos, TAMJ))
            {
                codigo++;
            }
            break;

        case 2:
            modificarCliente(lista, TAM, juegos, TAMJ);
            break;

        case 3:
            bajaCliente(lista, TAM, juegos, TAMJ);
            break;

        case 4:
            mostrarClientes(lista,TAM,juegos,TAMJ);
            break;
        case 5:
            if(altaAlquiler(alquileres, TAMAL, codAlquiler, juegos, TAMJ, lista, TAM))
            {
                codAlquiler++;
            }
            break;
        case 6:
            break;

        case 9:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}

int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("                                 =Menu Principal=\n");
    printf("\n\n");
    printf("  - CLIENTES  -\n");
    printf("\n\n");
    printf("1. Alta de Cliente\n");
    printf("2. Modificar Cliente\n");
    printf("3. Baja Cliente\n");
    printf("4. Listar Clientes\n");
    printf("5. Alta de Alquiler\n");
    printf("6. Mostrar Informes\n");
    printf("9. Salir\n");
    printf("\n\n>");
    printf(" Ingrese la opcion deseada :");
    fflush(stdin);
    scanf(" %d",&opcion);
    return opcion;
}


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

    printf(" Id       juego      cliente    Fecha \n\n");

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
        mostrarCliente(clientes,tClientes,juegos,tJuegos);
        printf("Ingrese codigo de cliente: ");
        scanf("%d", &codCliente);

        mostrarJuegos(juegos, tJuegos);
        printf("Ingrese id Juego: ");
        scanf("%d", &codJuego);

        printf("Ingrese fecha : ");
        scanf("%d/%d/%d", &fechaAlquiler.dia, &fechaAlquiler.mes, &fechaAlquiler.anio);



        alquileres[indice] = newAlquileres(codAlquiler, codCliente, codJuego, fechaAlquiler);
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
