#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include "juego.h"
#include "categoria.h"
#include "Alquileres.h"

#define TAM 10
#define TAMJ 5
#define TAMAL 20



int menuPrincipal();


//Prototipós informes
void mostrarInformes(eCliente clientes[], int tam, eJuego juegos[], int tamJ);
int menuInformes();
void mostrarClientesJuegos( eCliente clientes[],int tam,eJuego juegos[],int tamJ,int catPreferedida);
void mostrarClientesCategoriaSeleccionada( eCliente clientes[],int tam,eJuego juegos[],int tamJ);




int main()
{
    int codigo=0;
    int codAlquiler=0;
    eJuego juegos[TAMJ]= {{1,"Mesa",2.50},{2,"Azar",3.00},{3,"Estrategia",2.00},{4,"Salon",5.00},{5,"Magia",1.50}};
    eCliente lista[TAM];
    inicializarClientes( lista, TAM);
    codigo = codigo + harcodearClientes(lista, TAM, 10);
    eAlquileres alquileres[TAMAL];
    inicializarAlquileres( alquileres, TAMAL);
    codAlquiler = codAlquiler + hardcodearAlquileres(alquileres, TAMAL, 5);
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



void mostrarClientesJuegos( eCliente clientes[],int tam,eJuego juegos[],int tamJ,int catPreferedida)
{
    for(int i=0; i < tam; i++)
    {

        if( clientes[i].catPreferedida == catPreferedida && clientes[i].isEmpty == 0)
        {
            mostrarCliente(clientes[i], juegos, tamJ);
        }
    }
    printf("\n\n");
}

void mostrarClientesCategoriaSeleccionada( eCliente clientes[],int tam,eJuego juegos[],int tamJ )
{
    int catPreferedida;
    system("cls");
    printf("**** Mostrar Clientes de una Categoria ******\n\n");
    mostrarJuegos(juegos, tamJ);
    printf("Ingrese id Juego: ");
    scanf("%d", &catPreferedida);
    mostrarClientesJuegos(clientes, tam, juegos, tamJ, catPreferedida);
}







