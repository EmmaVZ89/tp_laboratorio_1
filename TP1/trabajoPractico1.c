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

int sumar(int* num1, int* num2, int* resultado)
{
    int todoOk = 0;

    if(num1 != NULL && num2 != NULL && resultado != NULL)
    {
        *resultado = *num1 + *num2;
        todoOk = 1;
    }
    return todoOk;
}

int restar(int* num1, int* num2, int* resultado)
{
    int todoOk = 0;

    if(num1 != NULL && num2 != NULL && resultado != NULL)
    {
        *resultado = *num1 - *num2;
        todoOk = 1;
    }
    return todoOk;
}

int dividir(int* num1, int* num2, float* resultado)
{
    int todoOk = 0;

    if(*num2 != 0 && resultado != NULL)
    {
        *resultado = (float) *num1 / *num2;
        todoOk = 1;
    }
    return todoOk;
}

int multiplicar(int* num1, int* num2, int* resultado)
{
    int todoOk = 0;

    if(num1 != NULL && num2 != NULL && resultado != NULL)
    {
        *resultado = *num1 * *num2;
        todoOk = 1;
    }
    return todoOk;
}

int factorizar(int* numero, int* resultado)
{
    int todoOk = 0;

    *resultado = 1;

    if( numero != NULL && resultado != NULL && *numero >= 0)
    {
        if(*numero == 1 || *numero == 0)
        {
            *resultado = 1;
        }
        else
        {
            for(int i = 1; i <= *numero; i++)
            {
                *resultado *= i;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
