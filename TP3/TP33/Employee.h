#include "LinkedList.h"


#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief muestra un menu de opciones y espera que el usuario ingrese un numero
 *
 * \return int retorna el numero ingresado por el usuario (1-10)
 *
 */
int employee_menu();

/** \brief muestra un menu de opciones y espera que el usuario ingrese un numero
 *
 * \return int retorna el numero ingresado por el usuario (1-4)
 *
 */
int employee_menuEdit();

/** \brief muestra un menu de opciones y espera que el usuario ingrese un numero
 *
 * \return int retorna el numero ingresado por el usuario (1-5)
 *
 */
int employee_menuSort();


/** \brief busca el mayor numero de id en una linked list
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int* puntero donde se guarda el numero de id
 * \return int retorna 1 si no hay falla, sino retorna 0
 *
 */
int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id);

/** \brief busca el indide de un empleado por su numero de id
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int numero de id
 * \param indice int* puntero donde se guarda el indice
 * \return int retorna 1 si se encuentra un indice, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_buscarPorId(LinkedList* pArrayListEmployee, int id, int* indice);

/** \brief crea y retorna un puntero a un empleado con sus campos inicializados
 *
 * \return Employee* retorna un puntero a un empleado o NULL(falla)
 *
 */
Employee* employee_new();

/** \brief crea y retorna un puntero a un empleado con sus campos cargados segun su tipo de dato
 *
 * \param idStr char* cadena con el numero de id
 * \param nombreStr char* cadena con el nombre
 * \param horasTrabajadasStr char* cadena con las horas trabajadas
 * \param sueldoStr char* cadena con el sueldo
 * \return Employee* retorna un puntero a un empleado o NULL(falla)
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief crea y retorna un puntero a un empleado con sus campos cargados
 *
 * \param id int numero de id
 * \param nombre char* nombre
 * \param horasTrabajadas int numero de horas trabajadas
 * \param sueldo int sueldo
 * \return Employee* retorna un puntero a un empleado o NULL(falla)
 *
 */
Employee* employee_newParametrosPorTipo(int id,char* nombre,int horasTrabajadas,int sueldo);


/** \brief libera la memoria asignada a un empleado
 *
 * \param employee Employee* puntero a un empleado
 * \return void
 *
 */
void employee_delete(Employee* employee);

/** \brief valida un id, si es valido lo carga en el campo de un empleado
 *
 * \param this Employee* puntero a un empleado
 * \param id int numero de id
 * \return int retorna 1 si se pudo cargar el id, sino retorna 0 ( tambien en caso de falla)
 *
 */
int employee_setId(Employee* this,int id);

/** \brief valida que el id cargado en el campo de un empleado sea valido y lo carga en un puntero
 *
 * \param this Employee* puntero a un empleado
 * \param id int* puntero de un numero de id
 * \return int retorna 1 si se pudo cargar el id, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief valida un nombre, si es valido lo carga en el campo de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int retorna 1 si se pudo cargar el nombre, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief valida que el nombre cargado en el campo de un empleado sea valido y lo carga en un puntero
 *
 * \param this Employee* puntero a un empleado
 * \param nombre char* nombre de un nombre
 * \return int retorna 1 si se pudo cargar el nombre, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief valida el numero de horas trabajadas, si es valido lo carga en el campo de un empleado
 *
 * \param this Employee* puntero a un empleado
 * \param horasTrabajadas int cantidad de horas trabajadas
 * \return int retorna 1 si se pudo cargar las horas trabajadas, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief valida que las cantidad de horas trabajadas en el campo de un empleado sea valido y lo carga en un puntero
 *
 * \param this Employee* puntero a un empleado
 * \param horasTrabajadas int* puntero a cantidad de horas trabajadas
 * \return int retorna 1 si se pudo cargar las horas trabajadas, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief valida el numero el sueldo, si es valido lo carga en el campo de un empleado
 *
 * \param this Employee* puntero a un empleado
 * \param sueldo int sueldo
 * \return int retorna 1 si se pudo cargar el sueldo, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief valida que el sueldo en el campo de un empleado sea valido y lo carga en un puntero
 *
 * \param this Employee* puntero a un empleado
 * \param sueldo int* puntero a un sueldo
 * \return int retorna 1 si se pudo cargar el sueldo, sino retorna 0 (tambien en caso de falla)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief compara el campo id de dos empleados
 *
 * \param idUno void* puntero al id un empleado
 * \param idDos void* puntero al id un empleado
 * \return int retorna 0 en caso de falla, retorna 1 si idUno > idDos, retorna -1 si idUno < idDos
 *
 */
int employee_cmpIds(void* idUno, void* idDos);

/** \brief compara el campo nombre de dos empleados
 *
 * \param nombreUno void* puntero al nombre de un empleado
 * \param nombreDos void* puntero al nombre de un empleado
 * \return int retorna 0 si los nombre son iguales, retorna 1 si nombreUno > nombreDos, retorna 1 si nombreUno < nombreDos
 * si hay falla retorna -2.
 *
 */
int employee_cmpNombres(void* nombreUno, void* nombreDos);

/** \brief compara el campo horasTrabajadas de dos empleados
 *
 * \param horasUno void* puntero a horas trabajadas de un empleado
 * \param horasDos void* puntero a horas trabajadas de un empleado
 * \return int retorna 0 en caso de falla, retorna 1 si horasUno > horasDos, retorna -1 si horasUno < horasDos
 *
 */
int employee_cmpHorasTrabajadas(void* horasUno, void* horasDos);

/** \brief ompara el campo horasTrabajadas de dos empleados
 *
 * \param sueldoUno void* puntero al sueldo de un empleado
 * \param sueldoDos void* puntero al sueldo de un empleado
 * \return int retorna 0 en caso de falla, retorna 1 si sueldoUno > sueldoDos, retorna -1 si sueldoUno < sueldoDos
 *
 */
int employee_cmpSueldos(void* sueldoUno, void* sueldoDos);

#endif // employee_H_INCLUDED
