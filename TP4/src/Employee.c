#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/utn.h"
#include "../inc/Employee.h"
#include "../inc/validaciones.h"

int employee_menu()
{
	int option;
	system("cls");
	printf("***  ABM Empleados Linked List  ***\n\n");
	printf("Menu de opciones: \n");
	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos de empleado\n");
	printf("5. Baja de empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
	printf("10. Salir\n\n");
	utn_getNumero(&option,"Ingrese opcion: ","Opcion no valida!!\n\n",1,10,5);
	return option;
}

int employee_menuEdit()
{
	int option;
	printf("***  Editar Empleado Linked List  ***\n\n");
	printf("Menu de opciones: \n");
	printf("1. Nombre\n");
	printf("2. Horas Trabajadas\n");
	printf("3. Sueldo\n");
	printf("4. Salir\n\n");
	utn_getNumero(&option,"Ingrese opcion: ","Opcion no valida!!\n\n",1,4,5);
	return option;
}

int employee_menuSort()
{
	int option;
	printf("***  Ordenar Empleados Linked List  ***\n\n");
	printf("Menu de opciones: \n");
	printf("1. Ordenar por Id\n");
	printf("2. Ordenar por Nombre\n");
	printf("3. Ordenar por Horas Trabajadas\n");
	printf("4. Ordenar por Sueldo\n");
	printf("5. Salir\n\n");
	utn_getNumero(&option,"Ingrese opcion: ","Opcion no valida!!\n\n",1,5,5);
	return option;
}

int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = 0;
	Employee* auxEmp = NULL;
	int mayor;
	if(pArrayListEmployee!=NULL)
	{
		for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
			if(i == 0 || auxEmp->id > mayor)
			{
				mayor = auxEmp->id;
			}
		}
		*id = mayor + 1;
		retorno = 1;
	}
	return retorno;
}

int employee_buscarPorId(LinkedList* pArrayListEmployee, int id, int* indice)
{
	int retorno = 0;
	Employee* employee = NULL;
	if(pArrayListEmployee != NULL && id > 0 && indice != NULL)
	{
		*indice = -1;
		for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee,i);
			if(employee != NULL)
			{
				if(employee->id == id)
				{
					*indice = i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

Employee* employee_new()
{
	Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		strcpy(newEmployee->nombre, "");
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
	}
	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* newEmployee = employee_new();
	if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(!(employee_setId(newEmployee,atoi(idStr)) &&
				employee_setNombre(newEmployee,nombreStr) &&
				employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr)) &&
				employee_setSueldo(newEmployee,atoi(sueldoStr))))
		{
			employee_delete(newEmployee);
			newEmployee = NULL;
		}
	}
	return newEmployee;
}

Employee* employee_newParametrosPorTipo(int id,char* nombre,int horasTrabajadas,int sueldo)
{
	Employee* newEmployee = employee_new();
	if(newEmployee != NULL && nombre != NULL)
	{
		if(!(employee_setId(newEmployee,id) &&
				employee_setNombre(newEmployee,nombre) &&
				employee_setHorasTrabajadas(newEmployee,horasTrabajadas) &&
				employee_setSueldo(newEmployee,sueldo)))
		{
			employee_delete(newEmployee);
			newEmployee = NULL;
		}
	}
	return newEmployee;
}


void employee_delete(Employee* employee)
{
	free(employee);
}


int employee_setId(Employee* this,int id)
{
	int retorno = 0;
	if(this!=NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this!=NULL && nombre!=NULL && isValidNombre(nombre,sizeof(nombre)))
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this!=NULL && nombre!= NULL && isValidNombre(this->nombre,sizeof(this->nombre)))
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;
	if(this!=NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;
	if(this!=NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_cmpIds(void* idUno, void* idDos)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(idUno != NULL && idDos != NULL)
	{
		emp1 = (Employee*) idUno;
		emp2 = (Employee*) idDos;

		if(emp1->id > emp2->id)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->id < emp2->id)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_cmpNombres(void* nombreUno, void* nombreDos)
{
	int retorno = -2;
	Employee* emp1;
	Employee* emp2;
	if(nombreUno != NULL && nombreDos != NULL)
	{
		emp1 = (Employee*) nombreUno;
		emp2 = (Employee*) nombreDos;
		retorno = strcmp(emp1->nombre,emp2->nombre);
	}
	return retorno;
}

int employee_cmpHorasTrabajadas(void* horasUno, void* horasDos)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(horasUno != NULL && horasDos != NULL)
	{
		emp1 = (Employee*) horasUno;
		emp2 = (Employee*) horasDos;

		if(emp1->horasTrabajadas > emp2->horasTrabajadas)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->horasTrabajadas < emp2->horasTrabajadas)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_cmpSueldos(void* sueldoUno, void* sueldoDos)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(sueldoUno != NULL && sueldoDos != NULL)
	{
		emp1 = (Employee*) sueldoUno;
		emp2 = (Employee*) sueldoDos;

		if(emp1->sueldo > emp2->sueldo)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->sueldo < emp2->sueldo)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

