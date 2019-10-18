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

typedef struct
{
    int id;
    char descripcion [51];
}eCategoria;

int menuPrincipal();


//prototipos Alquileres
void inicializarAlquileres(eAlquileres vec[], int tam);
int hardcodearAlquileres( eAlquileres vec[], int tam, int cantidad);
void mostrarAlquiler(eAlquileres x, eJuego juegos[], int tamJ);
void mostrarAlquileres(eAlquileres vec[],int tam, eJuego juegos[], int tamJ);
int buscarAlmuerzoLibre(eAlquileres vec[], int tam);
int altaAlquiler( eAlquileres alquileres[], int tAlquileres, int codAlquiler, eJuego juegos[], int tJuegos, eCliente clientes[], int tClientes);
eAlquileres newAlquiler(int codAlquiler,int codCliente,int codJuego, eFecha fecha);


//Prototipós informes
void mostrarInformes(eCliente clientes[], int tam, eJuego juegos[], int tamJ);
int menuInformes();
void mostrarClientesJuegos( eCliente clientes[],int tam,eJuego juegos[],int tamJ,int idJuego);
void mostrarClientesCategoriaSeleccionada( eCliente clientes[],int tam,eJuego juegos[],int tamJ);




int main()
{
    int codigo=0;
    int codAlquiler=0;
    eJuego juegos[TAMJ]= {{1000,"Mesa",2.50},{1001,"Salon",3.00},{1002,"Didacticos",2.00}};
    eCliente lista[TAM];
    inicializarClientes( lista, TAM);
    codigo = codigo + harcodearClientes(lista, TAM, 6);
    eAlquileres alquileres[TAMAL];
    inicializarAlquileres( alquileres, TAMAL);
    codAlquiler = codAlquiler + hardcodearAlquileres(alquileres, TAMAL, 10);
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
            mostrarAlquileres(alquileres,TAMAL,juegos,TAMJ);
            break;

        case 7:
            mostrarInformes(lista, TAM, juegos, TAMJ);
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
    printf("6. Listar alquileres\n");
    printf("7. Mostrar Informes\n");
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

void mostrarInformes(eCliente clientes[], int tam, eJuego juegos[], int tamJ)
{


    char salir = 'n';

    do
    {
        switch( menuInformes())
        {
        case 1:
                mostrarClientesCategoriaSeleccionada(clientes, tam, juegos, tamJ);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            printf("Informe 5\n");
            break;

        case 6:
            printf("Informe 6\n");
            break;

        case 7:
            printf("Informe 7\n");
            break;

        case 8:
            printf("Informe 8\n");
            break;

        case 10:
            printf("Informe 10\n");
            break;

        case 11:
            printf("Informe 11\n");
            break;

        case 12:
            printf("Informe 12\n");
            break;

        case 13:
            printf("Informe 13\n");
            break;

        case 20:
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
}


int menuInformes()
{
    int opcion;
    system("cls");
    printf("****** Informes *******\n\n");
    printf(" 1-Mostrar Juegos de una Categoria\n");
    printf(" 2-Mostrar alquileres por cliente\n");
    printf(" 3-Mostrar total de importes por cliente\n");
    printf(" 4-Listar Clientes sin alquileres\n");
    printf(" 5-Listar Juegos sin alquilar\n");
/*    printf(" 6-Mostrar Alumnos Varones\n");
    printf(" 7-Mostrar Mujeres de Alguna Carrera\n");
    printf(" 8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf(" 9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una determinada comida\n");
    printf("11-Listar cantidad de almuerzos x carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");*/
    printf("20-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int hardcodearAlquileres( eAlquileres vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlquileres suplentes[]=
    {
        { 0, 20000, 5000, {1, 10, 2019}, 0},
        { 1, 20001, 5002, {1, 10, 2019}, 0},
        { 2, 20005, 5002, {1, 10, 2019}, 0},
        { 3, 20003, 5004, {1, 10, 2019}, 0},
        { 4, 20004, 5001, {2, 10, 2019}, 0},
        { 5, 20001, 5000, {2, 10, 2019}, 0},
        { 6, 20002, 5002, {2, 10, 2019}, 0},
        { 7, 20004, 5004, {2, 10, 2019}, 0},
        { 8, 20003, 5000, {3, 10, 2019}, 0},
        { 9, 20001, 5001, {3, 10, 2019}, 0},

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
void mostrarClientesJuegos( eCliente clientes[],int tam,eJuego juegos[],int tamJ,int idJuego)
{
    for(int i=0; i < tam; i++)
    {

        if( clientes[i].idJuego == idJuego && clientes[i].isEmpty == 0)
        {
            mostrarCliente(clientes[i], juegos, tamJ);
        }
    }
    printf("\n\n");
}

void mostrarClientesCategoriaSeleccionada( eCliente clientes[],int tam,eJuego juegos[],int tamJ )
{
    int idJuego;
    system("cls");
    printf("**** Mostrar Clientes de una Categoria ******\n\n");
    mostrarJuegos(juegos, tamJ);
    printf("Ingrese id Juego: ");
    scanf("%d", &idJuego);
    mostrarClientesJuegos(clientes, tam, juegos, tamJ, idJuego);
}







