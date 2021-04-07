#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "trabajoPractico1.h"

void systemPause()
{
    printf("\n");
    printf("Presione una tecla para continuar...");
    fflush(stdin);
    getch();
}

int ingresarNumero(int* numero)
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

int activarFlag(int* flag)
{
    int todoOk = 0;
    if(flag != NULL && *flag == 1)
    {
        *flag = 0;
        todoOk = 1;
    }
    return todoOk;
}

int resetearFlag(int* flag)
{
    int todoOk = 0;
    if(flag != NULL && *flag == 0)
    {
        *flag = 1;
        todoOk = 1;
    }
    return todoOk;
}
