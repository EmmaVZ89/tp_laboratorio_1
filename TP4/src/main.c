/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/Controller.h"


int main(void)
{
    int nextId = 1000;
    Employee* employee1 = NULL;
    Employee* employee2 = NULL;
    Employee* employee3 = NULL;
    Employee* employee4 = NULL;
    Employee* employee5 = NULL;
    LinkedList* listaEmpleados = NULL;
    LinkedList* listaEmpleados2 = NULL;
    LinkedList* listaEmpleados3 = NULL;
    int indice;

    printf("*****************   ll_newLinkedList()   *****************\n");
    printf("\n   Creamos una nueva LinkedList:\n");
    listaEmpleados = ll_newLinkedList();
    if(listaEmpleados != NULL)
    {
        printf("\n   Lista creada con exito!\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");

    printf("\n*** controller_loadFromText('data.csv',listaEmpleados) ***\n");
    printf("\n   Cargamos una lista desde un archivo de texto:\n");
    if(controller_loadFromText("data.csv",listaEmpleados))
    {
        printf("\n   El archivo fue cargado con exito!\n\n");
        employee_buscarMayorId(listaEmpleados,&nextId);
    }
    else
    {
        printf("\n   No se pudo cargar el archivo!\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n**************   ll_len(listaEmpleados)   ****************\n");
    printf("\n   Mostramos el tamanio de la lista:\n");
    printf("\n   Dimension de la lista: %d\n\n", ll_len(listaEmpleados));
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*********   ll_add(listaEmpleados,employee1)   ***********\n");
    printf("\n   Agregamos un empleado nuevo a la lista:\n");
    employee1 = employee_newParametrosPorTipo(1010,"Julio",400,35000);
    if(employee1 != NULL)
    {
        printf("\n   Lista inicial:\n");
        controller_ListEmployee(listaEmpleados);
        if( !ll_add(listaEmpleados,employee1))
        {
            printf("   Lista con el elemento agregado:\n");
            controller_ListEmployee(listaEmpleados);
        }
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*************   ll_get(listaEmpleados, 3)   **************\n");
    employee2 = ll_get(listaEmpleados, 3);
    if(employee2 != NULL)
    {
        printf("\n   Se tomo el elemento ubicado en el indice 3\n\n");
        printf("Id: %d\n", employee2->id);
        printf("Nombre: %s\n", employee2->nombre);
        printf("Horas trabajadas: %d\n", employee2->horasTrabajadas);
        printf("Sueldo: %d\n\n", employee2->sueldo);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*********   ll_set(listaEmpleados,3,employee3)   *********\n");
    employee3 = employee_newParametrosPorTipo(1011,"Maria",250,38000);
    if(employee3 != NULL)
    {
        if( !ll_set(listaEmpleados,3,employee3))
        {
            printf("\n   Se reemplazo un elemento en el indice 3\n");
            controller_ListEmployee(listaEmpleados);
        }
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n************   ll_remove(listaEmpleados,4)   *************\n");
    if( !ll_remove(listaEmpleados,4))
    {
        printf("\n   Se elimino el elemento en el indice 4\n");
        controller_ListEmployee(listaEmpleados);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n********   ll_indexOf(listaEmpleados,employee1)   ********\n");
    printf("\n   Buscamos el indice de un elemento en la lista:\n");
    indice = ll_indexOf(listaEmpleados,employee1);
    if(indice != -1)
    {
        printf("\n   El indice del elemento employee1 es %d\n\n", indice);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n************   ll_isEmpty(listaEmpleados)   **************\n");
    printf("\n   Verificamos si la lista esta vacia:\n");
    if( ll_isEmpty(listaEmpleados))
    {
        printf("\n   La lista esta vacia\n\n");
    }
    else
    {
        printf("\n   La lista NO esta vacia\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*********   ll_push(listaEmpleados,6,employee4)   ********\n");
    printf("\n   Insertamos el elemento employee4 en la lista:\n");
    employee4 = employee_newParametrosPorTipo(1012,"Juan",150,20000);
    if( !ll_push(listaEmpleados,6,employee4))
    {
        printf("\n   Se inserto un elemento en el indice 6\n\n");
        controller_ListEmployee(listaEmpleados);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*************   ll_pop(listaEmpleados,1)   ***************\n");
    printf("\n   Eliminamos un elemento de la lista y lo guardamos en employee5:\n");
    employee5 = ll_pop(listaEmpleados,1);
    if(employee5 != NULL)
    {
        printf("\n   Se elimino el elemento en el indice 1\n\n");
        printf("Elemento eliminado de la lista: \n\n");
        printf("Id: %d\n", employee5->id);
        printf("Nombre: %s\n", employee5->nombre);
        printf("Horas trabajadas: %d\n", employee5->horasTrabajadas);
        printf("Sueldo: %d\n\n", employee5->sueldo);
        printf("   Lista sin el elemento eliminado:\n");
        controller_ListEmployee(listaEmpleados);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*******   ll_contains(listaEmpleados, employee5)   *******\n");
    printf("\n   Verificamos si el elemento employee5 esta en la lista:\n");
    if( !ll_contains(listaEmpleados, employee5))
    {
        printf("\n   El employee5 NO esta en la lista\n\n");
    }
    else
    {
        printf("\n   El employee5 esta en la lista\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n***********   ll_subList(listaEmpleados,0,5)   ***********\n");
    printf("\n   Creamos una segunda lista a partir de la lista principal:\n");
    listaEmpleados2 = ll_subList(listaEmpleados,0,5);
    if(listaEmpleados2 != NULL)
    {
        printf("\n   Sublista creada desde indice 0 hasta el indice 4.\n\n   Lista 2:\n");
        controller_ListEmployee(listaEmpleados2);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n***   ll_containsAll(listaEmpleados, listaEmpleados2)  ***\n");
    printf("\n   Verificamos que todos los elementos de la lista 2 esten en la lista 1:\n");
    if( !ll_containsAll(listaEmpleados, listaEmpleados2))
    {
        printf("\n   Hay elementos de la lista 2 que No estan en la lista 1\n\n");
    }
    else
    {
        printf("\n   Todos los elementos de la lista 2 estan en la lista 1\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n**************   ll_clone(listaEmpleados)   **************\n");
    printf("\n   Creamos una tercer lista identica a la lista 1:\n");
    listaEmpleados3 = ll_clone(listaEmpleados);
    if(listaEmpleados3 != NULL)
    {
        printf("\n   Lista 1 clonada con exito\n\n");
        printf("   Lista 3(copia de la lista 1):\n");
        controller_ListEmployee(listaEmpleados3);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n****   ll_sort(listaEmpleados,employee_cmpNombres,1)  ****\n");
    printf("\n   Ordenamos una lista segun el criterio de la funcion employee_cmpNombres:\n");
    printf("\n   Lista 1 sin ordenar:\n");
    controller_ListEmployee(listaEmpleados);
    if( !ll_sort(listaEmpleados,employee_cmpNombres,1))
    {
        printf("   Lista 1 ordenada por nombre:\n");
        controller_ListEmployee(listaEmpleados);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*** controller_saveAsText('data2.csv', listaEmpleados) ***\n");
    printf("\n   Guardamos la lista 1 en un archivo de texto:\n");
    if(controller_saveAsText("data2.csv", listaEmpleados))
    {
        printf("\n   El archivo fue guardado con exito!\n\n");
    }
    else
    {
        printf("\n   No se pudo guardar el archivo!\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n**************   ll_clear(listaEmpleados)   **************\n");
    printf("\n   Eliminamos todos los elementos de la lista 1:\n");
    if( !ll_clear(listaEmpleados))
    {
        printf("\n   Se eliminaron todos los elementos de la lista\n");
        printf("\n   Lista 1 vacia:\n");
        controller_ListEmployee(listaEmpleados);
    }
    printf("**********************************************************\n\n");
    system("pause");


    printf("\n*********   ll_deleteLinkedList(listaEmpleados)   ********\n");
    printf("\n   Eliminamos la lista 1:\n");
    if( !ll_deleteLinkedList(listaEmpleados))
    {
        printf("\n   Lista 1 Eliminada con exito!\n\n");
    }
    printf("**********************************************************\n\n");
    system("pause");

    return 0;
}
