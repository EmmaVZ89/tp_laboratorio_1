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

