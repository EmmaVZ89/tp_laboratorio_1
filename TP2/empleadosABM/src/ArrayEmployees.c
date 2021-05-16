/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresoDatos.h"
#include "ArrayEmployees.h"


int menu()
{
    int option;

    system("cls");
    printf("*** ABM Empleados ***\n\n");
    printf("Menu de opciones: \n\n");
    printf("1. Alta Empleado\n");
    printf("2. Modificar Empleado\n");
    printf("3. Baja Empleado\n");
    printf("4. Informes\n");
    printf("5. Salir\n\n");
    printf("Ingrese su opcion: ");
    ingresarNumeroEntero(&option);
    printf("\n");

    return option;
}

int menuModify()
{
    int option;

    printf("*** Modificar Empleado ***\n\n");
    printf("Seleccione que desea modificar: \n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Sueldo\n");
    printf("4. Sector\n");
    printf("5. Salir\n\n");
    printf("Ingrese su opcion: ");
    ingresarNumeroEntero(&option);
    printf("\n");

    return option;

}

int menuReports()
{
    int option;

    system("cls");
    printf("*** Informes de empleados ***\n\n");
    printf("Menu de opciones: \n\n");
    printf("1. Listar empleados alfabeticamente por Apellido y Sector.\n");
    printf("2. Total y promedio de sueldos.\n");
    printf("3. Salir\n\n");
    printf("Ingrese su opcion: ");
    ingresarNumeroEntero(&option);
    printf("\n");

    return option;
}

int initEmployees(eEmployee lista[], int len)
{
    int allOk = -1;
    if(lista != NULL && len > 0) // validacion
    {
        for(int i = 0; i < len; i++) // iteracion en el array de empleados
        {
            lista[i].isEmpty = 1; // se llena el campo isEmpty con 1
            allOk = 0;
        }
    }
    return allOk;
}

int addEmployee(eEmployee lista[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int allOk = -1;
    int indice;

    if(lista != NULL && len > 0 && name != NULL && lastName != NULL) // validacion
    {
        indice = findEmpty(lista,len); // busco el primer indice vacio
        if(indice != -1)// si se encuentra un indice vacio, se cargan los atributos en los campos del nuevo empleado.
        {
            lista[indice].id = id;
            strcpy(lista[indice].name,name);
            strcpy(lista[indice].lastName,lastName);
            lista[indice].salary = salary;
            lista[indice].sector = sector;
            lista[indice].isEmpty = 0;
            allOk = 0;
        }
    }
    return allOk;
}

int upEmployee(eEmployee lista[], int len, int* id, eSector sectors[], int lenS)
{
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;
    char auxStr[100];
    int allOk = -1;

    if(lista != NULL && len > 0 && id != NULL && sectors != NULL && lenS > 0) // validacion
    {
        if(findEmpty(lista,len) != -1)// se verifica que halla espacio en la lista de empleados antes de pedir el ingreso de datos al usuario
        {
            system("cls");
            printf("*** Alta Empleado ***\n\n");
            printf("Id: %d\n\n", *id);
            printf("Ingrese nombre: ");
            ingresarCadena(newName, auxStr, sizeof(newName));
            printf("Ingresar Apellido: ");
            ingresarCadena(newLastName, auxStr, sizeof(newLastName));
            printf("Ingresar sueldo: ");
            ingresarNumeroFlotante(&newSalary);
            printSectors(sectors,lenS); // muestra lista de sectores
            printf("Ingresar Id del Sector: ");
            ingresarNumeroEntero(&newSector);
            while(findSectorById(newSector,sectors,lenS) == -1) // valida si el sector existe
            {
                printf("Sector invalido!. Ingresar Id del Sector: ");
                ingresarNumeroEntero(&newSector);
            }
            if(addEmployee(lista,len,*id,newName,newLastName,newSalary,newSector) != -1)
            {
                // si el empleado se cargo correctamente se procede a aumentar el numero de id
                *id = *id + 1;
                allOk = 0;
            }
            else
            {
                printf("Hubo un problema, no se pudo realizar el alta\n\n");
            }
        }
        else
        {
            printf("No hay espacio en el sistema!\n\n");
        }
    }
    return allOk;
}

int findEmpty(eEmployee lista[], int len)
{
    int index = -1;

    if(lista != NULL && len > 0)// validacion
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty)
            {
                index = i; // indice del primer espacio vacio encontrado
                break;
            }
        }
    }
    return index;
}

int allEmpty(eEmployee lista[], int len)
{
    int empty = 1;
    if(lista != NULL && len > 0) // validacion
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0) // se verifica si la ubicacion esta ocupada
            {
                empty = 0; // al encontrarse una ubucacion ocupada se cambia el valor de la variable empty por 0, lo cual indica que el array no esta vacio
                break;
            }
        }
    }
    return empty; // devuelve 1 si el array esta vacio. Devuelve 0 si el array no esta vacio.
}

int findEmployeeById(eEmployee lista[], int len,int id)
{
    int index = -1;
    if(lista != NULL && len > 0)// validacion
    {
        for(int i = 0; i < len; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)// se verifica que el empleado este activo y que el id sea igual al ingresado como argumento
            {
                index = i; // se guarda el indice del empleado
                break;
            }
        }
    }
    return index; // se devuelve el indice -1 en caso de no encontrar el empleado ( o en caso de error), sino se devuelde el numero de indice.
}

int modifyEmployee(eEmployee lista[], int len, eSector sectors[], int lenS)
{
    // declaracion de variables
    int modifications = 0;
    char exitModify = 'n';
    char confirm;
    int flag;
    int index;
    int id;
    char option;
    char auxStr[100];
    eEmployee newEmployee[len];

    if(lista != NULL && len > 0 && sectors != NULL && lenS > 0) // validacion
    {
        system("cls");
        printf("*** Modificar Empleado ***\n\n");
        printEmployees(lista,len);// muestra la lista de empleados
        printf("Ingrese numero de Id: ");
        ingresarNumeroEntero(&id); // pide ingreso de numero de Id del empleado
        printf("\n");
        index = findEmployeeById(lista, len, id); // se busca a el empleado por el numero de Id
        if(index != -1)
        {
            printf("Desea modificar el empleado con el numero de Id %d ?\ns: Si\nn: No\nRespuesta: ", id);
            ingresarLetraMin(&option); // se pide confirmacion para ingresar al menu de modificacion de empleado.
            system("cls");
            if(option == 's')
            {
                newEmployee[index] = lista[index];
                do
                {
                    confirm = 'n';
                    flag = 0;
                    system("cls");
                    printf("---------------- Empleado a modificar ---------------------\n");
                    printEmployee(lista[index]); // muestra el empleado que se esta modificando
                    printf("-----------------------------------------------------------\n\n");
                    switch(menuModify())// se muestra el menu y se pide una opcion
                    {
                    case 1:
                        printf("Ingrese nombre: ");
                        ingresarCadena(newEmployee[index].name, auxStr, sizeof(newEmployee[index].name)); // ingreso de nombre
                        flag = 1;
                        printf("\n");
                        break;
                    case 2:
                        printf("Ingrese apellido: ");
                        ingresarCadena(newEmployee[index].lastName, auxStr, sizeof(newEmployee[index].lastName)); // ingreso de apellido
                        flag = 1;
                        printf("\n");
                        break;
                    case 3:
                        printf("Ingrese Sueldo: ");
                        ingresarNumeroFlotante(&newEmployee[index].salary);// ingreso de sueldo
                        flag = 1;
                        printf("\n");
                        break;
                    case 4:
                        printSectors(sectors,lenS); // muestra lista de sectores
                        printf("Ingrese Id del sector: ");
                        ingresarNumeroEntero(&newEmployee[index].sector);// ingreso de numero de id de sector
                        while(findSectorById(newEmployee[index].sector,sectors,lenS) == -1) // valida si el sector existe
                        {
                            printf("Sector invalido!. Ingrese Id del Sector: ");
                            ingresarNumeroEntero(&newEmployee[index].sector);
                        }
                        flag = 1;
                        printf("\n");
                        break;
                    case 5:
                        printf("Desea salir? \ns: Si\nn: No\nRespuesta: ");
                        ingresarLetraMin(&exitModify); // salir del menu de modificaciones
                        printf("\n");
                        break;
                    default:
                        printf("Opcion invalida!\n\n");
                        system("pause");
                        break;
                    }
                    if(flag)
                    {
                        printf("Confirma las modificaciones? \ns: Si\nn: No\nRespuesta: ");
                        ingresarLetraMin(&confirm);
                        if(confirm == 's')
                        {
                            modifications++;
                            lista[index] = newEmployee[index];
                            printf("\n---------------- Modificacion exitosa ---------------------\n");
                            printEmployee(lista[index]); // muestra a el empleado ya modificado
                            printf("-----------------------------------------------------------\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("\nModifiacion cancelada por el usuario\n\n");
                            system("pause");
                        }
                    }
                }
                while(exitModify != 's'); // se repite el bucle hasta que el usuario ingresa el caracter 's'.
            }
            else
            {
                printf("Se cancelo la modificacion del empleado.\n\n");
            }
        }
        else
        {
            printf("No se encontro el empleado con numero de Id %d.\n\n", id);
        }
    }
    return modifications; // devuelve el numero de modificaciones hechas
}

int downEmployee(eEmployee lista[], int len)
{
    int allOk = -1;
    int idEmployee;

    if(lista != NULL && len > 0) // validacion
    {
        system("cls");
        printf("*** Baja Empleado ***\n\n");
        printEmployees(lista,len); // muestra la lista de los empleados
        printf("Ingrese el numero de Id: ");
        ingresarNumeroEntero(&idEmployee); // pide el ingreso del Id
        printf("\n");
        if(removeEmployee(lista,len,idEmployee) != -1)// pasa el Id a la funcion removeEmployee para que de de baja al empleado
        {
            allOk = 0;
        }
    }
    return allOk;
}

int removeEmployee(eEmployee lista[], int len, int id)
{
    int allOk = -1;
    int index;
    char option;

    if(lista != NULL && len > 0) // validacion
    {
        index = findEmployeeById(lista, len, id); // busca al empleado por el numero de Id
        if(index != -1)
        {
            printf("Desea eliminar el empleado con el numero de Id %d ?\ns: Si\nn: No\nRespuesta: ", id);
            ingresarLetraMin(&option); // pide confirmacion para eliminar o no al empleado
            printf("\n");
            if(option == 's')
            {
                lista[index].isEmpty = 1; // si la respuesta es afirmativa el empleado se da de baja, campo isEmpty = 1
                allOk = 0;
            }
            else
            {
                printf("Se cancelo la baja del empleado.\n\n");
            }
        }
        else
        {
            printf("No se encontro el empleado con numero de Id %d.\n\n", id);
        }
    }
    return allOk;
}

void printEmployee(eEmployee employee)
{
    printf("%4d     %-10s     %-10s     %6.2f     %3d\n"
           , employee.id
           , employee.name
           , employee.lastName
           , employee.salary
           , employee.sector
          ); // muestra los campos de un empleado
}

int printEmployees(eEmployee lista[], int len)
{
    int allOk = -1;

    if(lista != NULL && len > 0) // validacion
    {
        printf("----------------------------------------------------------\n");
        printf(" Id      Nombre         Apellido       Sueldo       Sector\n");
        printf("----------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0) // verifica que la ubicacion del empleado este cargada
            {
                printEmployee(lista[i]); // muestra los campos del empleado
                allOk = 0;
            }
        }
        printf("----------------------------------------------------------\n\n");
    }
    return allOk;
}

int reports(eEmployee lista[], int len)
{
    int allOk = -1;
    char exit = 'n';
    int option;
    int order;

    if(lista != NULL && len >0) // validacion
    {
        do
        {
            option = menuReports();// muestra el menu de informes y pide el ingreso de una opcion
            switch(option)
            {
            case 1:
                printf("Que orden desea? \n1: Ascendente\n0: Descendente\nRespuesta: ");
                ingresarNumeroEntero(&order); // solicita el ingreso de el criterio de ordenamiento
                while(order > 1 || order < 0) // validacion para que el usuario ingrese 0 o 1
                {
                    printf("Orden invalido!. Reingrese orden: \n1: Ascendente\n0: Descendente\nRespuesta: ");
                    ingresarNumeroEntero(&order);
                }
                sortEmployees(lista,len,order); // se ordena la lista de empleados
                printf("\n");
                allOk = 0;
                system("pause");
                break;
            case 2:
                totalSalary(lista,len); // muestra el total y el promedio de los salarios
                allOk = 0;
                system("pause");
                break;
            case 3:
                printf("Desea salir? \ns: Si\nn: No\nRespuesta: ");
                ingresarLetraMin(&exit); // salir del menu de informes
                break;
            default:
                printf("Opcion invalida!!\n\n");
                system("pause");
                break;
            }
            system("cls");
        }
        while(exit != 's'); // el bucle se repite hasta que el usuario ingresa el caracter 's'
    }
    return allOk;
}

int sortEmployees(eEmployee lista[], int len, int order)
{
    int allOk = -1;
    eEmployee auxEmployee;
    eEmployee auxList[len];// array de empleados auxiliar

    if(lista != NULL && len > 0 && (order == 0 || order == 1))// validacion
    {
        for(int e = 0; e < len; e++)
        {
            auxList[e] = lista[e];// copia toda la lista de empleados a la auxiliar, asi la lista original no se modifica
        }
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i + 1; j < len; j++) // metodo de burbujeo
            {
                // depende el criterio de ordenamiento que el ususario halla ingresado la lista se ordena ascentende o descendente
                if((auxList[i].sector > auxList[j].sector || (auxList[i].sector == auxList[j].sector && strcmp(auxList[i].lastName, auxList[j].lastName) > 0) ) && order)
                {
                    auxEmployee = auxList[i];
                    auxList[i] = auxList[j];
                    auxList[j] = auxEmployee;
                }
                else
                {
                    if((auxList[i].sector < auxList[j].sector || (auxList[i].sector == auxList[j].sector && strcmp(auxList[i].lastName, auxList[j].lastName) < 0) ) && !order)
                    {
                        auxEmployee = auxList[i];
                        auxList[i] = auxList[j];
                        auxList[j] = auxEmployee;
                    }
                }
            }
        }
        printf("\n");
        printEmployees(auxList,len);// muestra la lista de empleados ordenada
        allOk = 0;
    }
    return allOk;
}

int totalSalary(eEmployee lista[], int len)
{
    int allOK = -1;
    float total = 0;
    int cant = 0;
    int cantEmployees = 0;
    float averageSalary;

    if(lista != NULL && len)// validacion
    {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("                     Total sueldos\n");
        printf("----------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(lista[i].isEmpty == 0) // se verifica que en el campo halla un empleado cargado
            {
                total += lista[i].salary; // se acumula el salario en la variable total
                cant++; // se cuenta la cantidad de empleados
            }
        }
        if(cant !=0 && total > 0) // si la cantidad de empleados  y el total de sueldos es distinta de 0 se procede a hacer las cuentas.
        {
            averageSalary = (float)total/cant;
            printf("             Promedio de sueldos: %.2f\n\n", averageSalary);
            printf("               Total Sueldos: %.2f\n", total);
            printf("----------------------------------------------------------\n\n");
            printf("----------------------------------------------------------\n");
            printf("         Empleados que superan el sueldo promedio\n");
            printf("----------------------------------------------------------\n");
            printf(" Id      Nombre         Apellido       Sueldo       Sector\n");
            printf("----------------------------------------------------------\n");
            for(int i = 0; i < len; i++)
            {
                if(lista[i].isEmpty == 0 && lista[i].salary > averageSalary) // se verifica que un empleado activo cobre por encima del sueldo promedio
                {
                    cantEmployees++; // cantidad de sueldos por encima del promedio
                    printEmployee(lista[i]); // se muestra el empleado que cobra por encima del promedio
                    allOK = 0;
                }
            }
            printf("\nCantidad de empleados sobre el sueldo promedio: %d\n", cantEmployees);
            printf("----------------------------------------------------------\n");
            printf("\n");
        }
        else
        {
            printf("No hay sueldos cargados!\n\n");
        }
    }
    return allOK;
}

