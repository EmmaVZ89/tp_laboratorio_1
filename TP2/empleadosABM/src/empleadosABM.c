/*
 ============================================================================
 Name        : empleadosABM.c
 Author      : Emmanuel Zelarayan
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresoDatos.h"
#include "ArrayEmployees.h"
#include "sector.h"
#include "datawarehouse.h"

#define TAM 1000
#define TAMSEC 5


int main()
{
	setbuf(stdout, NULL);
    // Declaracion de variables
    int nextId = 1000;
    char salir = 'n';
    int opcion;
    // Creo el array de empleados
    eEmployee nomina[TAM];
    // Inicializo el array de empleados, pongo sus campos isEmpty en 1
    initEmployees(nomina,TAM);

    // array de sectores inicializado
    eSector sectors[TAMSEC] =
    {
        {500, "Sistemas"},
        {501, "Legales"},
        {502, "RRHH"},
        {503, "Contable"},
        {504, "Ventas"}
    };


    // Hardcodeo para pruebas *******
    hardcodearEmpleados(nomina, TAM, 8, &nextId);
    // ******************************

    do
    {
        opcion = menu(); // Se muestra el menu principal y se pide el numero de opcion
        switch(opcion)
        {
        case 1:
            if(upEmployee(nomina,TAM,&nextId,sectors,TAMSEC) != -1)// Se verifica si se pudo dar de alta el empleado y se muestra un mensaje.
            {
                printf("\n   Alta exitosa!\n\n");
            }
            else
            {
                printf("   No se realizo el alta!\n\n");
            }
            system("pause");
            break;
        case 2:
            if(!allEmpty(nomina,TAM)) // Si la lista de empleados no esta vacia se entra en el menu de modificaciones
            {
                if(modifyEmployee(nomina,TAM,sectors,TAMSEC) != 0) // Si se realizaron o no modificaciones se muestra un mensaje en consecuencia.
                {
                    printf("   Se realizaron las modificaciones con exito!\n\n");
                }
                else
                {
                    printf("   No se realizaron modificaciones!\n\n");
                }
            }
            else
            {
                printf("   No hay empleados dados de alta!\n\n");
            }
            system("pause");
            break;
        case 3:
            if(!allEmpty(nomina,TAM)) // Si la lista de empleados no esta vacia se entra en el menu de bajas
            {
                if(downEmployee(nomina,TAM) != -1)// Si se realizo o no la baja se muestra un mensaje en consecuencia.
                {
                    printf("   Baja exitosa!\n\n");
                }
                else
                {
                    printf("   No se pudo realizar la baja!\n\n");
                }
            }
            else
            {
                printf("   No hay empleados dados de alta!\n\n");
            }
            system("pause");
            break;
        case 4:
            if(!allEmpty(nomina,TAM))// Si la lista de empleados no esta vacia se entra en el menu de informes
            {
                reports(nomina, TAM);
            }
            else
            {
                printf("   No hay empleados dados de alta!\n\n");
                system("pause");
            }
            break;
        case 5:
            printf("Desea salir? \ns: Si\nn: No\nRespuesta: ");
            ingresarLetraMin(&salir); // salir del programa
            break;
        default:
            printf("Opcion invalida!!\n\n");
            system("pause");
            break;
        }
    }
    while(salir != 's'); // El bucle se repite hasta que el usuario ingresa el caracter 's'
    return EXIT_SUCCESS;
}
