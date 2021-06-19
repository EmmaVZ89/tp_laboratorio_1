#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int nextId = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = employee_menu();
        switch(option)
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("\n   El archivo fue cargado con exito!\n\n");
                employee_buscarMayorId(listaEmpleados,&nextId);
            }
            else
            {
                printf("\n   No se pudo cargar el archivo!\n\n");
            }
            system("pause");
            break;
        case 2:
            if(controller_loadFromBinary("data.bin", listaEmpleados))
            {
                printf("\n   El archivo fue cargado con exito!\n\n");
                employee_buscarMayorId(listaEmpleados,&nextId);
            }
            else
            {
                printf("\n   No se pudo cargar el archivo!\n\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("***  Alta Empleado Linked List  ***\n\n");
            if(controller_addEmployee(listaEmpleados,&nextId))
            {
                printf("\n   Alta exitosa!\n\n");
            }
            else
            {
                printf("\n   No se pudo realizar el alta!\n\n");
            }
            system("pause");
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("\n   Modificaciones realizadas con exito!\n\n");
                }
                else
                {
                    printf("\n   No se realizaron modificaciones!\n\n");
                }
            }
            system("pause");
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                system("cls");
                printf("***  Baja Empleado Linked List  ***\n\n");
                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("\n   Baja exitosa!\n\n");
                }
                else
                {
                    printf("\n   No se pudo realizar la baja!\n\n");
                }
            }
            system("pause");
            break;
        case 6:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                system("cls");
                controller_ListEmployee(listaEmpleados);
            }
            system("pause");
            break;
        case 7:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("\n   Empleados ordenados con exito!\n\n");
                }
                else
                {
                    printf("\n   No se ordenaron los empleados!\n\n");
                }
            }
            system("pause");
            break;
        case 8:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                if(controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("\n   El archivo fue guardado con exito!\n\n");
                }
                else
                {
                    printf("\n   No se pudo guardar el archivo!\n\n");
                }
            }
            system("pause");
            break;
        case 9:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("\n   No hay empleados cargados!\n\n");
            }
            else
            {
                if(controller_saveAsBinary("data.bin", listaEmpleados))
                {
                    printf("\n   El archivo fue guardado con exito!\n\n");
                }
                else
                {
                    printf("\n   No se pudo guardar el archivo!\n\n");
                }
            }
            system("pause");
            break;
        }
    }
    while(option != 10);
    ll_deleteLinkedList(listaEmpleados);

    return EXIT_SUCCESS;
}

