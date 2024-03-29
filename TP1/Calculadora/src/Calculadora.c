/*
 ============================================================================
 Name        : Calculadora.c
 Author      : Emmanuel Zelarayan
 Version     : 1.00
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "trabajoPractico1.h"


int main()
{
	setbuf(stdout, NULL);

    char seguir = 'n';
    int a;
    int b;
    int opcion;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoProducto;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flagOp1 = 1;
    int flagOp2 = 1;
    int flagOperaciones = 1;
    int divisionOk;
    int factorialAOk;
    int factorialBOk;

    do
    {
    	opcion = menu(a,b,flagOp1,flagOp2);
        switch(opcion)
        {
            case 1:
                printf("Ingrese un numero: ");
                ingresarNumero(&a);
                activarFlag(&flagOp1);
                systemPause();
            break;

            case 2:
                if(flagOp1 == 0)
                {
                    printf("Ingrese un numero: ");
                    ingresarNumero(&b);
                    activarFlag(&flagOp2);
                }
                else
                {
                    printf("Antes de ingresar el segundo operando debe ingresar el primero.\n");
                }
                systemPause();
            break;

            case 3:
                if(flagOp2 == 0)
                {
                    sumar(a, b, &resultadoSuma);
                    restar(a, b, &resultadoResta);
                    divisionOk = dividir(a, b, &resultadoDivision);
                    multiplicar(a, b, &resultadoProducto);
                    factorialAOk = factorizar(a, &resultadoFactorialA);
                    factorialBOk = factorizar(b, &resultadoFactorialB);
                    activarFlag(&flagOperaciones);
                    printf("Se realizaron todas las operaciones...\n");
                }
                else
                {
                    printf("Antes de calcular las operaciones debe ingresar el PRIMER y el SEGUNDO operando.\n");
                }
                systemPause();
            break;

            case 4:
                if(flagOperaciones == 0)
                {
                    mostrarResultados(a, b, resultadoSuma, resultadoResta, resultadoDivision, resultadoProducto, resultadoFactorialA, resultadoFactorialB, divisionOk, factorialAOk, factorialBOk);
                    resetearFlag(&flagOp1);
                    resetearFlag(&flagOp2);
                    resetearFlag(&flagOperaciones);
                }
                else
                {
                    if(flagOp1 || flagOp2)
                    {
                        printf("Antes de mostrar los resultados debe ingresar el PRIMER y el SEGUNDO operando.\n");
                    }
                    else
                    {
                        printf("Primero se deben calcular las operaciones para poder mostrar los resultados.\n");
                    }
                }
                systemPause();
            break;

            case 5:
                printf("Esta seguro que quiere salir? \ns: Si\nn: No\nRespuesta: ");
                ingresarLetraMin(&seguir);
            break;
        }
    }
    while(seguir == 'n');

    return EXIT_SUCCESS;
}
