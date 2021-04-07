#ifndef TRABAJOPRACTICO1_H_INCLUDED
#define TRABAJOPRACTICO1_H_INCLUDED


#endif // TRABAJOPRACTICO1_H_INCLUDED

/** \brief genera una pausa en el programa esperando que se ingrese un caracter
 *
 * \return void no retorna ningun valor
 *
 */
void systemPause();


/** \brief Pide el ingreso de un numero y verifica si el ingreso es correcto.
 *
 * \param numero int* Puntero que contiene la direccion de memoria donde se guardara el numero.
 * \return int Devuelve un 0 si la direccion de memoria es incorrecta o un 1 si todos los datos estan correctos.
 *
 */
int ingresarNumero(int* numero);


/** \brief Pide el ingreso de una letra y verifica si el ingreso es correcto.
 *
 * \param letra char* Puntero que contiene la direccion de memoria donde se guardara la letra.
 * \return int Devuelve un 0 si la direccion de memoria es incorrecta o un 1 si todos los datos estan correctos.
 *
 */
int ingresarLetraMin(char* letra);


/** \brief recibe una direccion de memoria de una bandera y si esta vale 1 su valor sera cambiado por 0
 *
 * \param flag int* Puntero que contiene la direccion de la bandera a activar.
 * \return int Devuelve un 0 si la bandera no su pudo modificar o devuelve un 1 si esto se pudo hacer.
 *
 */
int activarFlag(int* flag);


/** \brief recibe una direccion de memoria de una bandera y si esta vale 0 su valor sera cambiado por 1
 *
 * \param flag int* Puntero que contiene la direccion de la bandera a resetear.
 * \return int Devuelve un 0 si la bandera no su pudo modificar o devuelve un 1 si esto se pudo hacer.
 *
 */
int resetearFlag(int* flag);

/** \brief recibe 3 direcciones de memoria, suma la primera y la segunda, y guarda el resultado en la tercera.
 *
 * \param num1 int* puntero que contiene la direccion de memoria del primer numero a sumar
 * \param num2 int* puntero que contiene la direccion de memoria del segundo numero a sumar
 * \param resultado int* puntero con la direccion de memoria donde se guarda el resultado de la suma.
 * \return int devuelve 1 si la suma se llevo a cabo, o devuelve 0 si no se pudo realizar.
 *
 */
int sumar(int* num1, int* num2, int* resultado);

/** \brief recibe 3 direcciones de memoria, realiza una resta,  la primera menos la segunda, y guarda el resultado en la tercera.
 *
 * \param num1 int* puntero que contiene la direccion de memoria del primer numero a restar
 * \param num2 int* puntero que contiene la direccion de memoria del segundo numero, el cual se le resta al primero.
 * \param resultado int* puntero con la direccion de memoria donde se guarda el resultado de la resta.
 * \return int devuelve 1 si la resta se llevo a cabo, o devuelve 0 si no se pudo realizar.
 *
 */
int restar(int* num1, int* num2, int* resultado);


/** \brief realiza la division de dos enteros
 *
 * \param num1 int* dividendo de la operacion
 * \param num2 int* divisor de la operacion
 * \param resultado float* puntero con la direccion donde se guardara el resultado.
 * \return int devuelve 1 si pudo hacer la division o 0 si no lo pudo hacer
 *
 */
int dividir(int* num1, int* num2, float* resultado);

/** \brief realiza la multiplicacion entre dos numeros enteros y guarda el resultado.
 *
 * \param num1 int* puntero con la direccion del primer numero entero
 * \param num2 int* puntero con la direccion del segundo numero entero
 * \param resultado int* puntero con la direccion donde se guardara el producto
 * \return int devuelve 1 si pudo hacer la multiplicacion o 0 si no lo pudo hacer.
 *
 */
int multiplicar(int* num1, int* num2, int* resultado);

/** \brief realiza el factorial de un numero entero
 *
 * \param numero int* puntero con la direccion de un numero entero al cual se le realizara el factorial
 * \param resultado int* puntero con una direccion de memoria donde se guardara el resultado
 * \return int devuelve 1 si pudo hacer el factorial o 0 si no lo pudo hacer.
 *
 */
int factorizar(int* numero, int* resultado);
