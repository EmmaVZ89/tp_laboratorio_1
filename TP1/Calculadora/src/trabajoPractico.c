/*
 * trabajoPractico.c
 *
 *  Created on: 9 abr. 2021
 *      Author: Emmanuel Zelarayan
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "trabajoPractico1.h"

void systemPause()
{
    printf("\n");
    printf("Presione ENTER para continuar...");
    fflush(stdin);
    getchar();
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

int sumar(int num1, int num2, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
        *resultado = num1 + num2;
        todoOk = 1;
    }
    return todoOk;
}

int restar(int num1, int num2, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
        *resultado = num1 - num2;
        todoOk = 1;
    }
    return todoOk;
}

int dividir(int num1, int num2, float* resultado)
{
    int todoOk = 0;

    if(num2 != 0 && resultado != NULL)
    {
        *resultado = (float) num1 / num2;
        todoOk = 1;
    }
    return todoOk;
}

int multiplicar(int num1, int num2, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL)
    {
        *resultado = num1 * num2;
        todoOk = 1;
    }
    return todoOk;
}

int factorizar(int numero, int* resultado)
{
    int todoOk = 0;

    if(resultado != NULL && numero >= 0)
    {
    	*resultado = 1;
        if(numero > 1)
        {
            for(int i = 1; i <= numero; i++)
            {
                *resultado *= i;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int menu(int num1, int num2, int flag1, int flag2)
{
    int opcion;

    system("cls");
    printf("   *** Calculadora ***\n\n");
    printf("Menu de opciones: \n\n");
    if(flag1 && flag2)
    {
        printf("1. Ingresar primer operando (A = x)\n");
        printf("2. Ingresar segundo operando (B = y)\n");
    }
    else
    {
        if(flag2 == 0)
        {
            printf("1. Ingresar primer operando (A = %d)\n", num1);
            printf("2. Ingresar segundo operando (B = %d)\n", num2);
        }
        else
        {
            printf("1. Ingresar primer operando (A = %d)\n", num1);
            printf("2. Ingresar segundo operando (B = y)\n");
        }
    }
    printf("3. Calcular todas las operaciones\n");
    printf("    a. Calcular la suma (A+B))\n");
    printf("    b. Calcular la resta (A-B))\n");
    printf("    c. Calcular la division (A/B))\n");
    printf("    d. Calcular la multiplicacion (A*B))\n");
    printf("    e. Calcular el factorial (A! y B!))\n");
    printf("4. Informar resultados\n");
    printf("    a. El resultado de A+B es: r\n");
    printf("    b. El resultado de A-B es: r\n");
    printf("    c. El resultado de A/B es: r\n");
    printf("    d. El resultado de A*B es: r\n");
    printf("    e. El factorial de A es: r1 y El factorial de B es: r2\n");
    printf("5. Salir\n\n");
    printf("Ingrese una opcion: ");
    ingresarNumero(&opcion);
    while(opcion < 1 || opcion > 5)
    {
        printf("Error. Debe ser un numero del 1 al 5.\nIngrese su opcion: ");
        ingresarNumero(&opcion);
    }
    printf("\n");

    return opcion;
}


void mostrarResultados(int num1, int num2, int suma, int resta, float division, int producto, int factorial1, int factorial2, int divisionOk, int factorial1Ok, int factorial2Ok)
{
	printf("Los resultados son los siguientes: \n\n");
    printf("    a. El resultado de %d+%d es: %d\n", num1, num2, suma);
    printf("    b. El resultado de %d-%d es: %d\n", num1, num2, resta);
    if(divisionOk)
    {
        printf("    c. El resultado de %d/%d es: %.2f\n", num1, num2, division);
    }
    else
    {
        printf("    c. No es posible dividir por cero\n");
    }
    printf("    d. El resultado de %d*%d es: %d\n", num1, num2, producto);
    if(factorial1Ok && factorial2Ok)
    {
        printf("    e. El factorial de %d es: %d y El factorial de %d es: %d\n", num1, factorial1, num2, factorial2);
    }
    else
    {
        if(factorial1Ok == 0 && factorial2Ok == 0)
        {
            printf("    e. El factorial de %d NO EXISTE y El factorial de %d NO EXISTE\n", num1, num2);
        }
        else
        {
            if(factorial1Ok)
            {
                printf("    e. El factorial de %d es: %d y El factorial de %d NO EXISTE\n", num1, factorial1, num2);
            }
            else
            {
                printf("    e. El factorial de %d NO EXISTE y El factorial de %d es: %d\n", num1, num2, factorial2);
            }
        }
    }
}
