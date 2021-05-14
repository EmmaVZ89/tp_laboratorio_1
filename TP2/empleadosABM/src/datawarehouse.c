/*
 * datawarehouse.c
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresoDatos.h"
#include "ArrayEmployees.h"
#include "datawarehouse.h"


char nombres[10][20] =
{
    "Victor",
    "Juana",
    "Manuel",
    "Maria",
    "Diego",
    "Marianela",
    "Francisca",
    "Agustina",
    "Sebastian",
    "Julio",
};

char apellidos[10][20] =
{
    "Gonzales",
    "Martinez",
    "Godoy",
    "Ojeda",
    "Brito",
    "Ramos",
    "Ramirez",
    "Antunez",
    "Arevalo",
    "Ortiz"
};

int edades[10] =
{
    32,45,56,12,34,65,90,45,33,22
};

char sexos[10] =
{
    'm','f','m','f','m','f','f','f','m','m'
};

float sueldos[10] =
{
    10000,12000,14500,12200,13200,11100,23000,20100,25000,12400
};

int idSectores[10] = {500,504,502,501,504,500,501,503,503,502};


int idComida[10] = {1003,1004,1000,1001,1002,1003,1004,1000,1001,1002};

int hardcodearEmpleados(eEmployee lista[], int len, int cant, int* id)
{
    int cantidad = 0;

    if(lista != NULL && len > 0 && cant >= 0 && cant <= len && id != NULL)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *id;
            *id = *id + 1;
            strcpy(lista[i].name, nombres[i]);
            strcpy(lista[i].lastName, apellidos[i]);
            lista[i].salary = sueldos[i];
            lista[i].sector = idSectores[i];
            lista[i].isEmpty = 0;
            cantidad++;
        }
    }
    return cantidad;
}
