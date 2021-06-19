#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* path del archivo de texto a leer
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se cargo al menos un empleado al archivo, sino retorna 0 (tambien en caso de falla)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* path del archivo binario a leer
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se cargo al menos un empleado al archivo, sino retorna 0 (tambien en caso de falla)
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
