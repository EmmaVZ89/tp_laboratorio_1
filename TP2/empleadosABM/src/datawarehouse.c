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


char nombres[20][20] =
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
	"Emmanuel",
	"Jose",
	"Anabella",
	"Ramon",
	"Axel",
	"Luis",
	"Mario",
	"Fidel",
	"Martin",
	"Javier",
};

char apellidos[20][20] =
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
    "Ortiz",
	"Salazar",
	"Zelaya",
	"Bauen",
	"Perez",
	"Alonso",
	"Yeri",
	"Manini",
	"Fernandez",
	"Villarreal",
	"Diamante",
};

float sueldos[20] =
{
    10000,12000,14500,12200,13200,11100,23000,20100,25000,12400,
	21200,27500,35100,18900,22000,15400,19900,12300,15000,16000
};

int idSectores[20] = {500,504,502,501,504,500,501,503,503,502,
500,500,501,501,502,502,503,503,504,504};


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
