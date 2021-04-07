#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "trabajoPractico1.h"


int main()
{
    char seguir = 'n';
    int opcion;
    int a;
    int b;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoProducto;
    int resultadoFactorialA;
    int resultadoFactorialB;
    int flagOp1 = 1;
    int flagOp2 = 1;
    int flagOperaciones = 1;
    int flagMostrar = 1;

    do
    {
        system("cls");
        printf("   *** Calculadora ***\n\n");
        if(flagOp1 && flagOp2)
        {
            printf("1. Ingresar primer operando (A = x)\n");
            printf("2. Ingresar segundo operando (B = y)\n");
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
        }
        else
        {
            if(flagOp2 == 0)
            {
                printf("1. Ingresar primer operando (A = %d)\n", a);
                printf("2. Ingresar segundo operando (B = %d)\n", b);
                printf("3. Calcular todas las operaciones\n");
                printf("    a. Calcular la suma (%d+%d))\n", a, b);
                printf("    b. Calcular la resta (%d-%d))\n", a, b);
                printf("    c. Calcular la division (%d/%d))\n", a, b);
                printf("    d. Calcular la multiplicacion (%d*%d))\n", a, b);
                printf("    e. Calcular el factorial (%d! y %d!))\n", a, b);
                printf("4. Informar resultados\n");
                if(flagMostrar)
                {
                    printf("    a. El resultado de %d+%d es: r\n", a, b);
                    printf("    b. El resultado de %d-%d es: r\n", a, b);
                    printf("    c. El resultado de %d/%d es: r\n", a, b);
                    printf("    d. El resultado de %d*%d es: r\n", a, b);
                    printf("    e. El factorial de %d es: r1 y El factorial de %d es: r2\n", a, b);
                }
                else
                {
                    printf("    a. El resultado de %d+%d es: %d\n", a, b, resultadoSuma);
                    printf("    b. El resultado de %d-%d es: %d\n", a, b, resultadoResta);
                    if(dividir(&a, &b, &resultadoDivision))
                    {
                        printf("    c. El resultado de %d/%d es: %.2f\n", a, b, resultadoDivision);
                    }
                    else
                    {
                        printf("    c. No es posible dividir por cero\n");
                    }
                    printf("    d. El resultado de %d*%d es: %d\n", a, b, resultadoProducto);
                    if(factorizar(&a, &resultadoFactorialA) && factorizar(&b, &resultadoFactorialB))
                    {
                        printf("    e. El factorial de %d es: %d y El factorial de %d es: %d\n", a, resultadoFactorialA, b, resultadoFactorialB);
                    }
                    else
                    {
                        if(factorizar(&a, &resultadoFactorialA) == 0 && factorizar(&b, &resultadoFactorialB) == 0)
                        {
                            printf("    e. El factorial de %d NO EXISTE y El factorial de %d NO EXISTE\n", a, b);
                        }
                        else
                        {
                            if(factorizar(&a, &resultadoFactorialA))
                            {
                                printf("    e. El factorial de %d es: %d y El factorial de %d NO EXISTE\n", a, resultadoFactorialA, b);
                            }
                            else
                            {
                                printf("    e. El factorial de %d NO EXISTE y El factorial de %d es: %d\n", a, b, resultadoFactorialB);
                            }
                        }
                    }
                    resetearFlag(&flagOp1);
                    resetearFlag(&flagOp2);
                    resetearFlag(&flagOperaciones);
                    resetearFlag(&flagMostrar);
                }
            }
            else
            {
                printf("1. Ingresar primer operando (A = %d)\n", a);
                printf("2. Ingresar segundo operando (B = y)\n");
                printf("3. Calcular todas las operaciones\n");
                printf("    a. Calcular la suma (%d+B))\n", a);
                printf("    b. Calcular la resta (%d-B))\n", a);
                printf("    c. Calcular la division (%d/B))\n", a);
                printf("    d. Calcular la multiplicacion (%d*B))\n", a);
                printf("    e. Calcular el factorial (%d! y B!))\n", a);
                printf("4. Informar resultados\n");
                printf("    a. El resultado de %d+B es: r\n", a);
                printf("    b. El resultado de %d-B es: r\n", a);
                printf("    c. El resultado de %d/B es: r\n", a);
                printf("    d. El resultado de %d*B es: r\n", a);
                printf("    e. El factorial de %d es: r1 y El factorial de B es: r2\n", a);
            }
        }

        printf("5. Salir\n\n");
        printf("Ingrese su opcion: ");
        ingresarNumero(&opcion);
        printf("\n");

        switch(opcion)
        {
            case 1:
                printf("Ingrese un numero: ");
                if(ingresarNumero(&a))
                {
                    activarFlag(&flagOp1);
                }
                systemPause();
            break;

            case 2:
                if(flagOp1 == 0)
                {
                    printf("Ingrese un numero: ");
                    if(ingresarNumero(&b))
                    {
                        activarFlag(&flagOp2);
                    }
                }
                else
                {
                    printf("Antes de ingresar el segundo operando debe ingresar el primero.\n");
                }
                systemPause();
            break;

            case 3:
                if(flagOp1 == 0 && flagOp2 == 0)
                {
                    sumar(&a, &b, &resultadoSuma);
                    restar(&a, &b, &resultadoResta);
                    dividir(&a, &b, &resultadoDivision);
                    multiplicar(&a, &b, &resultadoProducto);
                    factorizar(&a, &resultadoFactorialA);
                    factorizar(&b, &resultadoFactorialB);
                    activarFlag(&flagOperaciones);
                }
                else
                {
                    if(flagOp1 && flagOp2)
                    {
                        printf("Antes de calcular las operaciones debe ingresar el PRIMER y el SEGUNDO operando.\n");
                    }
                    else
                    {
                        if(flagOp1 == 0)
                        {
                            printf("Antes de calcular las operaciones debe ingresar el SEGUNDO operando.\n");
                        }
                        else
                        {
                            printf("Antes de calcular las operaciones debe ingresar el PRIMER operando.\n");
                        }
                    }
                }
                systemPause();
            break;

            case 4:
                if(flagOperaciones == 0)
                {
                    activarFlag(&flagMostrar);
                }
                else
                {
                    printf("Primero se deben calcular las operaciones para poder mostrarlas.\n");
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

    return 0;
}
