/*
 * ingresoDatos.h
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */

#ifndef INGRESODATOS_H_
#define INGRESODATOS_H_



#endif /* INGRESODATOS_H_ */

/** \brief espera el ingreso de un numero entero por el usuario
 *
 * \param numero int* puntero a un numero entero
 * \return int retorna 1 si el ingreso del numero es correcto, en caso de error en el puntero retorna 0
 *
 */
int ingresarNumeroEntero(int* numero);

/** \brief espera el ingreso de un numero flotante por el usuario
 *
 * \param numero float* puntero a un numero flotante
 * \return int retorna 1 si el ingreso del numero es correcto, en caso de error en el puntero retorna 0
 *
 */
int ingresarNumeroFlotante(float* numero);

/** \brief espera el ingreso de una letra y en caso de ser mayuscula la transforma en minuscula.
 *
 * \param letra char* puntero a un caracter
 * \return int retorna 1 si el ingreso del caracter es correcto, en caso de error en el puntero retorna 0
 *
 */
int ingresarLetraMin(char* letra);


/** \brief espera el ingreso de una cadena, verifica que su largo no supere el requerido y guarda el valor en la cadena principal
 *
 * \param cadena[] char cadena principal
 * \param auxiliar[] char cadena auxiliar
 * \param tamCadena int tamanio maximo de la cadena principal
 * \return int retorna 1 en caso de que el ingreso sea correcto, si hay error en direcciones de memoria o dimension retorna 0.
 *
 */
int ingresarCadena(char cadena[], char auxiliar[], int tamCadena);
