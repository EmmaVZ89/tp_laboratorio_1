#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/utn.h"
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/parser.h"
#include "../inc/Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char confirma = 'n';
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"r");
		if(f == NULL)
		{
			printf("\n   No se pudo abrir el archivo o el archivo no existe\n\n");
		}
		else
		{
			if(ll_len(pArrayListEmployee) > 0)
			{
				printf("Se van a sobrescribir los empleados. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
				fflush(stdin);
				scanf("%c", &confirma);
			}

			if(ll_len(pArrayListEmployee) == 0 || confirma == 's')
			{
				if(parser_EmployeeFromText(f, pArrayListEmployee))
				{
					retorno = 1;
				}
			}
		}
		fclose(f);
	}

	return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char confirma = 'n';
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"rb");
		if(f == NULL)
		{
			printf("\n   No se pudo abrir el archivo o el archivo no existe\n\n");
		}
		else
		{
			if(ll_len(pArrayListEmployee) > 0)
			{
				printf("Se van a sobrescribir los empleados. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
				fflush(stdin);
				scanf("%c", &confirma);
			}

			if(ll_len(pArrayListEmployee) == 0 || confirma == 's')
			{
				if(parser_EmployeeFromBinary(f,pArrayListEmployee))
				{
					retorno = 1;
				}
			}
		}
		fclose(f);
	}
	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = 0;
	Employee* newEmployee = NULL;
	Employee* auxEmp = NULL;
	if(pArrayListEmployee!=NULL)
	{
		auxEmp = employee_new();
		if(auxEmp != NULL)
		{
			utn_getNombre(auxEmp->nombre,sizeof(auxEmp->nombre),"Ingrese nombre: ","Nombre invalido\n\n",3);
			utn_getNumero(&auxEmp->horasTrabajadas,"Ingrese horas trabajadas(0-500): ","Cantidad de horas invalidas\n\n",0,500,3);
			utn_getNumero(&auxEmp->sueldo,"Ingrese Sueldo: ","Sueldo invalido\n\n",0,1000000,3);
			newEmployee = employee_newParametrosPorTipo(*id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
			if(newEmployee != NULL)
			{
				if( !ll_add(pArrayListEmployee, newEmployee))
				{
					*id = *id + 1;
					employee_delete(auxEmp);
					auxEmp = NULL;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int flag;
	int opcion;
	int id;
	int indice;
	char confirma = 'n';
	char confirmaCambios = 'n';
	Employee* employee = NULL;
	Employee* auxEmp = NULL;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&id,"\nIngrese numero de Id: ","Ingreso invalido!!\n\n",-1000000,1000000,3);
		employee_buscarPorId(pArrayListEmployee,id,&indice);
		if(indice != -1)
		{
			employee = (Employee*) ll_get(pArrayListEmployee,indice);
			printf("Desea editar el  empleado con el id numero %d ?\n", id);
			getChar(&confirma,"s: Si\nn: No\nRespuesta: ","Ingreso invalido!!\n\n",3);
			if(confirma == 's')
			{
				auxEmp = employee_new();
				do
				{
					flag = 0;
					*auxEmp = *employee;
					system("cls");
					printf("---------  Empleado a Editar  -------\n");
					printf("  Id     Nombre       Horas    Sueldo\n");
					printf("-------------------------------------\n");
					printf("%4d     %-10s    %3d     %5d\n",
							employee->id,
							employee->nombre,
							employee->horasTrabajadas,
							employee->sueldo);
					printf("-------------------------------------\n\n");
					opcion = employee_menuEdit();
					switch(opcion)
					{
					case 1:
						utn_getNombre(auxEmp->nombre,sizeof(auxEmp->nombre),"Ingrese nombre: ",
								"Nombre invalido\n\n",3);
						flag = 1;
						break;
					case 2:
						utn_getNumero(&auxEmp->horasTrabajadas,"Ingrese horas trabajadas(0-500): ",
								"Cantidad de horas invalidas\n\n",0,500,3);
						flag = 1;
						break;
					case 3:
						utn_getNumero(&auxEmp->sueldo,"Ingrese Sueldo: ","Sueldo invalido\n\n",0,1000000,3);
						flag = 1;
						break;
					}
					if(flag)
					{
						getChar(&confirmaCambios,"Desea confirmar los cambios? \ns: Si\nn: No\nRespuesta: ",
								"Ingreso invalido!!\n\n",3);
						if(confirmaCambios == 's')
						{
							*employee = *auxEmp;
							retorno = 1;
							printf("\n   Modificacion realizada con exito!\n\n");
							system("pause");
						}
						else
						{
							printf("\n   Modificacion cancelada por el usuario!\n\n");
							system("pause");
						}
					}
				}
				while(opcion != 4);
				employee_delete(auxEmp);
				auxEmp = NULL;
			}
			else
			{
				printf("\n   Modificacion cancelada por el usuario\n\n");
			}
		}
		else
		{
			printf("\n   No se encontro el empleado con el numero de id %d.\n\n",id);
		}
	}
	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	int indice;
	char confirma = 'n';
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&id,"\nIngrese numero de Id: ","Ingreso invalido!!\n\n",-1000000,1000000,3);
		employee_buscarPorId(pArrayListEmployee,id,&indice);
		if(indice != -1)
		{
			printf("Desea confirmar la baja del empleado con el id numero %d ?\n", id);
			getChar(&confirma,"s: Si\nn: No\nRespuesta: ","Ingreso invalido!!\n\n",3);
			if(confirma == 's')
			{
				ll_remove(pArrayListEmployee,indice);
				retorno = 1;
			}
			else
			{
				printf("\n   Baja cancelada por el usuario\n\n");
			}
		}
		else
		{
			printf("\n   No se encontro el empleado con el numero de id %d.\n\n",id);
		}
	}
	return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	Employee* auxEmp = NULL;
	if(pArrayListEmployee!=NULL)
	{
		printf("-------------------------------------\n");
		printf("  Id     Nombre       Horas    Sueldo    Indice\n");
		printf("-------------------------------------\n");
		for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
		{
			auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
			if(auxEmp!=NULL && employee_getId(auxEmp,&id) && employee_getNombre(auxEmp,nombre) &&
					employee_getHorasTrabajadas(auxEmp,&horasTrabajadas) && employee_getSueldo(auxEmp,&sueldo))
			{
				printf("%4d     %-10s    %3d     %5d     %3d\n",
						id,
						nombre,
						horasTrabajadas,
						sueldo,
						i);
			}
		}
		printf("-------------------------------------\n\n");
		retorno = 1;
	}
	return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char confirmaCambios = 'n';
	int flag;
	int opcion;
	int orden;
	LinkedList* listaAux = NULL;
	if(pArrayListEmployee != NULL)
	{
		do
		{
			flag = 0;
			listaAux = ll_clone(pArrayListEmployee);
			system("cls");
			opcion = employee_menuSort();
			if(opcion != 5)
			{
				utn_getNumero(&orden,"\nIngrese tipo de orden.\n1: Ascendente\n0: Descendente\nRespuesta: ",
						"Ingreso invalido!\n\n",0,1,5);
			}
			if(orden == 1 || orden == 0)
			{
				switch(opcion)
				{
				case 1:
					ll_sort(listaAux,employee_cmpIds,orden);
					flag = 1;
					break;
				case 2:
					ll_sort(listaAux,employee_cmpNombres,orden);
					flag = 1;
					break;
				case 3:
					ll_sort(listaAux,employee_cmpHorasTrabajadas,orden);
					flag = 1;
					break;
				case 4:
					ll_sort(listaAux,employee_cmpSueldos,orden);
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				printf("\n----------  LISTA ORDENADA  ---------\n");
				controller_ListEmployee(listaAux);
				getChar(&confirmaCambios,"Desea guardar los cambios en la lista principal? \ns: Si\nn: No\nRespuesta: ",
						"Ingreso invalido!!\n\n",3);
				if(confirmaCambios == 's')
				{
					printf("\n   Cambios guardados con exito!\n\n");
					*pArrayListEmployee = *listaAux;
					retorno = 1;
					system("pause");
				}
				else
				{
					printf("\n   Cambios cancelados por el usuario!\n\n");
					system("pause");
				}
			}
		}
		while(opcion != 5);
		listaAux = NULL;
	}

	return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char confirma = 'n';
	FILE* f = NULL;
	Employee* auxEmp = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"r");
		if(f != NULL)
		{
			printf("Cuidado el archivo exite y se va a sobrescribir. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		fclose(f);

		if(confirma == 's')
		{
			f = fopen(path,"w");
			if(f == NULL)
			{
				printf("\n   No se pudo abrir el archivo\n\n");
			}
			else
			{
				fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
					if(auxEmp != NULL)
					{
						fprintf(f,"%d,%s,%d,%d\n",
								auxEmp->id,
								auxEmp->nombre,
								auxEmp->horasTrabajadas,
								auxEmp->sueldo);
					}
					auxEmp = NULL;
				}
				retorno = 1;
			}
			fclose(f);
		}
	}

	return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char confirma = 's';
	FILE* f = NULL;
	Employee* auxEmp;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path,"rb");
		if(f != NULL)
		{
			printf("Cuidado el archivo existe y se va a sobrescribir. Desea confirmar?\ns: Si\nn: No\nRespuesta: ");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		fclose(f);

		if(confirma == 's')
		{
			f = fopen(path,"wb");
			if(f == NULL)
			{
				printf("\n   No se pudo abrir el archivo\n\n");
			}
			else
			{
				for(int i = 0; i < ll_len(pArrayListEmployee) ; i++)
				{
					auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
					fwrite(auxEmp,sizeof(Employee),1,f);
				}
				retorno = 1;
			}
			fclose(f);
		}
	}
	return retorno;
}

