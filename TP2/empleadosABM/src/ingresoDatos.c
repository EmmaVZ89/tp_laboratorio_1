/*
 * ingresoDatos.c
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ingresoDatos.h"


int ingresarNumeroEntero(int* numero)
{
    int todoOk = 0;
    if(numero != NULL)
    {
        fflush(stdin);
        todoOk = scanf("%d", numero);
        while(todoOk == 0)
        {
            printf("Error. Debe ingresar un numero: ");
            fflush(stdin);
            todoOk = scanf("%d", numero);
        }
    }
    return todoOk;
}

int ingresarNumeroFlotante(float* numero)
{
    int todoOk = 0;
    if(numero != NULL)
    {
        fflush(stdin);
        todoOk = scanf("%f", numero);
        while(todoOk == 0)
        {
            printf("Error. Debe ingresar un numero: ");
            fflush(stdin);
            todoOk = scanf("%f", numero);
        }
    }
    return todoOk;
}

int ingresarLetraMin(char* letra)
{
    int todoOk = 0;
    if(letra != NULL)
    {
        fflush(stdin);
        scanf("%c", letra);
        *letra = tolower(*letra);
        while(isdigit(*letra))
        {
            printf("Error. Debe ingresar una letra: ");
            fflush(stdin);
            scanf("%c", letra);
            *letra = tolower(*letra);
        }
        todoOk = 1;
    }
    return todoOk;
}

int ingresarCadena(char cadena[], char auxiliar[], int tamCadena)
{
    int todoOk = 0;

    if(cadena != NULL && auxiliar != NULL && tamCadena > 0)
    {
        fflush(stdin);
        gets(auxiliar);
        while(strlen(auxiliar) >= tamCadena)
        {
            printf("Error. Nombre demasiado largo. Reingrese nombre: ");
            fflush(stdin);
            gets(auxiliar);
        }
        strcpy(cadena, auxiliar);
        todoOk = 1;
    }
    return todoOk;
}
