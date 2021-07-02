
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* path del archivo que hay que cargar
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se cargo al menos un empleado, sino retorna 0 (tambien en caso de falla)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* path del archivo que hay que cargar
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se cargo al menos un empleado, sino retorna 0 (tambien en caso de falla)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief pide los datos de un nuevo empleado y si son correctos lo agrega a la lista
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int* puntero a un id
 * \return int retorna 1 si se cargo el empleado, sino retorna 0 (tambien en caso de falla)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);

/** \brief Modifica los datos de un empleado, pidiendo al usuario los nuevos datos
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se realizo una modificacion, sino retorna 0 ( tambien en caso de falla)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList* lista empleados
 * \return int retorna 1 si se realizo la baja, sino retorna 0 (tambien en caso de falla)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Imprime por pantalla los campos de todos los empleados de la lista
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si no hay fallas, sino retorna 0
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena empleados por id, nombre, horas trabajadas o sueldos.
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se realizo al menos un orden en la lista, sino retorna 0 (tambien en caso de falla)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* path donde se guardara la lista de empleados
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se pudo leer el archivos, sino retorna 0 ( tambien en caso de falla)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* path donde se guardara la lista de empleados
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 si se pudo leer el archivos, sino retorna 0 ( tambien en caso de falla)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


