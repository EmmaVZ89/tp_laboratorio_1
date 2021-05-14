/*
 * sector.c
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "sector.h"


int printSectors(eSector sectors[], int len)
{
    int allOk = -1;
    if(sectors != NULL && len > 0) // validacion
    {
        printf("\n   ***  Sectores  ***\n");
        printf("   Id        Descripcion\n");
        printf("-------------------------\n");
        for(int i = 0; i < len; i++)
        {
            printSector(sectors[i]); // muestra lista de sectores
            allOk = 0;
        }
        printf("\n");
    }
    return allOk;
}

void printSector(eSector sector)
{
    printf("   %d        %-10s\n", sector.id, sector.descripcion); // muestra campos de un sector
}

int findSectorById(int id, eSector sectors[], int len)
{
    int index = -1;
    if(sectors!=NULL && len > 0)// validacion
    {
        for(int i = 0; i < len; i++)
        {
            if(sectors[i].id == id)// compara el Id pasado por parametro y el de cada sector
            {
                index = i; // guarda el indice del sector
                break;
            }
        }
    }
    return index; // devuelve el indice del sector o -1 en caso de no encontrarlo o tambien en caso de error.
}

