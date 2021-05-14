#include "sector.h"


/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: Note
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief muestra el menu de opciones principal y pide el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada por el usuario
 *
 */
int menu();

/** \brief muestra el menu de opciones para modificar las caracteristicas de un empleado y pide el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada por el usuario
 *
 */
int menuModify();

/** \brief muestra el menu de opciondes de informes y pide el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada por el usuario
 *
 */
int menuReports();

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eEmployee lista[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/
int addEmployee(eEmployee lista[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(eEmployee lista[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(eEmployee lista[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eEmployee lista[], int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(eEmployee lista[], int len);

/** \brief muestra el contenido de una estructura en el array eEmployee
 *
 * \param employee eEmployee estructura
 * \return int
 *
 */
int printEmployee(eEmployee employee);

/** \brief pide un numero de legajo y permite hacer modificaciones en las caracteristicas de un empleado,
 * Opciones:
 * 1- Nombre; 2- Apellido; 3- Sueldo; 4- Sector; 5- Salir.
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \param sectors[] eSector array de sectores
 * \param lenS int dimension del array de sectores
 * \return int retorna el numero de modificaciones que se hicieron en el empleado
 *
 */
int modifyEmployee(eEmployee lista[], int len, eSector sectors[], int lenS);

/** \brief permite ejecutar los informes
 * Opciones:
 * 1- Pide criterio de ordenamiento del array de empleados(1 ascendente, 0 descendente), ordena el array de
 * empleados por Apellido y sector.
 * 2- Muestra el total y promedio de los sueldos, tambien los empleados que estan por encima del promedio.
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \return int retorna 0 si se mostraron informes, sino retorna -1 (tambien en casos de NULL o dimension invalida)
 *
 */
int reports(eEmployee lista[], int len);

/** \brief Muestra el total y promedio de los sueldos, tambien los empleados que estan por encima del promedio.
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \return int retorna 0 si el total de sueldos es mayor a 0, sino retorna -1 (tambien en casos de NULL o dimension invalida)
 *
 */
int totalSalary(eEmployee lista[], int len);

/** \brief pide todas las caracteristicas para poder cargar un nuevo empleado, se piden nombre, apellido, sueldo y sector, el
 * id se asigna automaticamente y se aumenta en uno si la carga es exitosa.
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \param id int* puntero con el id del nuevo empleado
 * \param sectors[] eSector array de sectores
 * \param lenS int dimension del array de sectores
 * \return int retorna 0 si se pudo cargar el empleado exitosamente o retorna -1 si hay un error en las direcciones de memoria,
 * dimensiones o si el sistema no tiene espacio para guardar el nuevo empleado
 *
 */
int upEmployee(eEmployee lista[], int len, int* id, eSector sectors[], int lenS);

/** \brief busca en el array de empleados el primer espacio libre
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimensio del array de empleados
 * \return int retorna -1 si no se encontro un indice libre, de lo contrario devuelve el indice libre encontrado.
 *
 */
int findEmpty(eEmployee lista[], int len);

/** \brief verifica si la lista de empleados esta completamente vacia
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \return int retorna 1 si la lista esta vacia, sino retorna 0 (tambien en casos de NULL o dimension invalida)
 *
 */
int allEmpty(eEmployee lista[], int len);

/** \brief pide un id de empleado y los pasa a la funcion removeEmployee para poder dar de baja a un empleado, si la lista
 * de empleados queda vacia cambia el valor de la bandera a 0.
 *
 * \param lista[] eEmployee array de empleados
 * \param len int dimension del array de empleados
 * \return int retorna 0 si se dio de baja a el empleado, sino retorna -1 (tambien en casos de NULL o dimension invalida)
 *
 */
int downEmployee(eEmployee lista[], int len);

