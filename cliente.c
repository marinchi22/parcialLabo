#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarCliente(eCliente x, eJuego juegos[], int tam)
{
    char descJuegos[20];

    cargarDescJuegos(x.idJuego, juegos, tam, descJuegos);
    printf("  %d  %10s   %15s      %15s     %10d       %c            %02d/%02d/%d   %10s\n",
           x.codigo,
           x.nombre,
           x.apellido,
           x.direccion,
           x.telefono,
           x.sexo,
           x.fechaInscripcion.dia,
           x.fechaInscripcion.mes,
           x.fechaInscripcion.anio,
           descJuegos);
}



void mostrarClientes(eCliente vec[], int tam,  eJuego juegos[], int tamJ)
{

    int flag = 0;
    system("cls");

    printf(" Cod     Nombre           Apellido         Direccion        Telefono      sexo          FInscripcion    Tipo de juego\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarCliente(vec[i], juegos, tamJ);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Clientes que mostrar\n");
    }

    printf("\n\n");
}

int altaCliente(eCliente vec[], int tam, int cod, eJuego juegos[], int tamC)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char apellido[20];
    char direccion[20];
    int telefono;
    char sexo;
    int idJuego;
    eFecha fecha;

    system("cls");

    printf("*****Alta Cliente*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);


        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese direccion: ");
        fflush(stdin);
        gets(direccion);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);
        while(sexo != 'f' && sexo != 'm' && sexo != 'o')
        {
            fflush(stdin);
            printf("ERROR,Reingrese sexo : ");
            fflush(stdin);
            scanf("%c", &sexo);

        }

        printf("Ingrese Telefono: ");
        fflush(stdin);
        scanf("%d",&telefono);

        printf("Ingrese fecha de alquiler: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarJuegos(juegos, tam);
        printf("Ingrese id juego: ");
        scanf("%d", &idJuego);

        vec[indice] = newCliente(cod, nombre,apellido,direccion,telefono, sexo, fecha, idJuego);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eCliente newCliente(
    int cod,
    char nombre[],
    char apellido[],
    char direccion[],
    int telefono,
    char sexo,
    eFecha fecha,
    int idJuego
)
{

    eCliente cl;
    cl.codigo = cod;
    strcpy( cl.nombre, nombre);
    strcpy( cl.apellido, apellido);
    strcpy( cl.direccion, direccion);
    cl.telefono=telefono;
    cl.sexo = sexo;
    cl.fechaInscripcion = fecha;
    cl.idJuego = idJuego;
    cl.isEmpty = 0;

    return cl;
}
int buscarCliente(int codigo, eCliente vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigo == codigo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarLibre(eCliente vec[], int tam)
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

void inicializarClientes(eCliente vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int harcodearClientes( eCliente vec[], int tam, int cantidad)
{
    int cont = 0;

    eCliente suplentes[]=
    {
        { 0, "Juan","Perez","Calle 834 109", 'm',  {12, 5, 2015}, 42005421, 1002, 0},
        { 1, "Alberto","Niño","Calle 845 541",'m', {12, 5, 2019}, 52172900,1001, 0},
        { 2, "Ana","Echazarreta","Viamonte 345",'f', {2, 7, 2018}, 42372961,1002, 0},
        { 3, "Luis","Bidone","Montevideo 123",'m', {21, 5, 2018}, 42376129,1000, 0},
        { 4, "Roberto","Cordoba","Maipu 272",'f', {11, 9, 2017}, 42132900,1001, 0},
        { 5, "Diego","Franco","Cuelli 3231",'m', {12, 4, 2014}, 42171613,1000, 0},
        { 6, "Marina","Montiel","Rivadavia 234",'f', {12, 2, 2014}, 1159615196,1002, 0},
        { 7, "Clara","Molina","Monteverde 973",'f', {28, 8, 2018}, 1160161247,1001, 0},
        { 8, "Mauro","Zarate","Martin Rodriguez 33",'m', {23, 3, 2015}, 1169061247,1001, 0},
        { 9, "Daniela","Herrero","Callao 987",'f', {10, 10, 2016}, 52172913,1000, 0},
        { 10, "Agustin","Canapino","Almafuerte 330",'m', {1, 7, 2017}, 42210041,1002, 0},
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

int bajaCliente(eCliente vec[], int tam, eJuego juegos[], int tamJ)
{
    int todoOk = 0;
    int codigo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Cliente *****\n\n");
    printf("Ingrese Codigo de Cliente: ");
    scanf("%d", &codigo);

    indice = buscarCliente(codigo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un cliente con ese codigo\n\n");

    }
    else
    {
        mostrarCliente(vec[indice], juegos, tamJ);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

int modificarCliente(eCliente vec[], int tam, eJuego juegos[], int tamj)
{

    int todoOk = 0;
    int codigo;
    int indice;
    system("cls");
    printf("***** Modificar Cliente *****\n\n");
    printf("Ingrese Codigo cliente: ");
    scanf("%d", &codigo);
    int opcion;

    indice = buscarCliente(codigo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un Cliente con ese legajo\n\n");

    }
    else
    {

        mostrarCliente(vec[indice], juegos, tamj);

        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar direccion\n");
        printf("4- Modificar Telefono\n");
        printf("5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);
            break;

        case 2:
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(vec[indice].apellido);
            break;

        case 3:
            printf("Ingrese Direccion: ");
            fflush(stdin);
            gets(vec[indice].direccion);
            break;

        case 4:
            printf("Ingrese Telefono: ");
            fflush(stdin);
            scanf("%d", &vec[indice].telefono);
            break;
        case 5:
            fflush(stdin);
            printf("Se ha cancelado la modificacion ");
            break;

        }
    }
    return todoOk;
}


