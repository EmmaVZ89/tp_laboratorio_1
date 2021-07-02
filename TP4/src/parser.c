#include <stdio.h>
#include <stdlib.h>
#include "../inc/parser.h"
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cant = 0;
    char buffer[4][128];
    Employee* auxEmp = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            if(cant == 4)
            {
                auxEmp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(auxEmp != NULL)
                {
                    if( !ll_add(pArrayListEmployee, auxEmp))
                    {
                        retorno = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int cant = 0;
    Employee* auxEmp = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        while(!feof(pFile))
        {
            auxEmp = employee_new();
            if(auxEmp != NULL)
            {
                cant = fread(auxEmp,sizeof(Employee),1,pFile);
                if(cant < 1)
                {
                    break;
                }
                if( !ll_add(pArrayListEmployee, auxEmp))
                {
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
