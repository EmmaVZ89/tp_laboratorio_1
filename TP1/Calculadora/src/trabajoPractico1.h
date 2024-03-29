/*
 * trabajoPractico1.h
 *
 *  Created on: 9 abr. 2021
 *      Author: Emmanuel Zelarayan
 */

#ifndef TRABAJOPRACTICO1_H_
#define TRABAJOPRACTICO1_H_



#endif /* TRABAJOPRACTICO1_H_ */

/** \brief genera una pausa en el programa esperando que se ingrese un caracter seguido de ENTER
 *
 * \return void
 *
 */
void systemPause();


/** \brief Pide el ingreso de un numero y verifica si el ingreso es correcto.
 *
 * \param numero int* Puntero que contiene la direccion de memoria donde se guardara el numero.
 * \return int Devuelve un 0 si la direccion de memoria es NULL o un 1 si todos los datos estan correctos.
 *
 */
int ingresarNumero(int* numero);


/** \brief Pide el ingreso de una letra y verifica si el ingreso es correcto.
 *
 * \param letra char* Puntero que contiene la direccion de memoria donde se guardara el caracter.
 * \return int Devuelve un 0 si la direccion de memoria es NULL o un 1 si todos los datos estan correctos.
 *
 */
int ingresarLetraMin(char* letra);


/** \brief recibe la direccion de memoria de una bandera y la activa.
 *
 * \param flag int* Puntero que contiene la direccion de la bandera a activar.
 * \return int Devuelve un 0 si la bandera no su pudo modificar o devuelve un 1 si esto se pudo hacer.
 *
 */
int activarFlag(int* flag);


/** \brief recibe la direccion de memoria de una bandera y la resetea a su valor original.
 *
 * \param flag int* Puntero que contiene la direccion de la bandera a resetear.
 * \return int Devuelve un 0 si la bandera no su pudo modificar o devuelve un 1 si esto se pudo hacer.
 *
 */
int resetearFlag(int* flag);

/** \brief realiza la suma de 2 numeros enteros y guarda el resultado en un tercer parametro.
 *
 * \param num1 int variable que contiene el primer numero a sumar
 * \param num2 int variable que contiene el segundo numero a sumar
 * \param resultado int* puntero con la direccion de memoria donde se guarda el resultado de la suma.
 * \return int devuelve 1 si la suma se llevo a cabo, o devuelve 0 si no se pudo realizar.
 *
 */
int sumar(int num1, int num2, int* resultado);

/** \brief realiza la resta de dos numeros enteros y guarda el resultado en un tercer parametro.
 *
 * \param num1 int variable que contiene el primer numero a restar
 * \param num2 int variable que contiene el segundo numero, el cual se le resta al primero.
 * \param resultado int* puntero con la direccion de memoria donde se guarda el resultado de la resta.
 * \return int devuelve 1 si la resta se llevo a cabo, o devuelve 0 si no se pudo realizar.
 *
 */
int restar(int num1, int num2, int* resultado);


/** \brief realiza la division de dos enteros
 *
 * \param num1 int dividendo de la operacion
 * \param num2 int divisor de la operacion
 * \param resultado float* puntero con la direccion donde se guardara el resultado.
 * \return int devuelve 1 si pudo hacer la division o 0 si no lo pudo hacer
 *
 */
int dividir(int num1, int num2, float* resultado);

/** \brief realiza la multiplicacion entre dos numeros enteros y guarda el resultado.
 *
 * \param num1 int primer numero entero para multiplicar
 * \param num2 int segunda numero entero para multiplicar
 * \param resultado int* puntero con la direccion donde se guardara el producto
 * \return int devuelve 1 si pudo hacer la multiplicacion o 0 si no lo pudo hacer.
 *
 */
int multiplicar(int num1, int num2, int* resultado);

/** \brief realiza el factorial de un numero entero
 *
 * \param numero int numero entero al cual se le realizara el factorial
 * \param resultado int* puntero con una direccion de memoria donde se guardara el resultado
 * \return int devuelve 1 si pudo hacer el factorial o 0 si no lo pudo hacer.
 *
 */
int factorizar(int numero, int* resultado);

/** \brief muestra un menu de opciones de una calculadora
 *
 * \param num1 int primer operando a mostrar
 * \param num2 int segundo operando a mostrar
 * \param flag1 int bandera del primer operando
 * \param flag2 int bandera del segundo operando
 * \return int devuelve la opcion que el usuario ingreso (del 1 al 5)
 *
 */
int menu(int num1, int num2, int flag1, int flag2);

/** \brief muestra los resultados y/o errores de las operaciones de la calculadora
 *
 * \param num1 int primer operando
 * \param num2 int segundo operando
 * \param suma int resultado de la suma
 * \param resta int resultado de la resta
 * \param division float resultado de la division
 * \param producto int resultado de la multiplicacion
 * \param factorial1 int resultado del factorial del primer operando
 * \param factorial2 int resultado del factorial del segundo operando
 * \param divisionOk int indica si la division se pudo calcular o no (1 si, 0 no)
 * \param factorial1Ok int indica si el primer factorial se pudo calcular o no (1 si, 0 no)
 * \param factorial2Ok int indica si el segundo factorial se pudo calcular o no (1 si, 0 no)
 * \return void
 *
 */
void mostrarResultados(int num1, int num2, int suma, int resta, float division, int producto, int factorial1, int factorial2, int divisionOk, int factorial1Ok, int factorial2Ok);

