#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* employee;
	FILE* pFile;

	char name[128];
	char id [50] ;
	char salary [50] ;
	char hoursWorked[50];

	ll_clear(pArrayListEmployee);

	pFile = fopen(path, "r");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hoursWorked, salary);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hoursWorked, salary);
			employee = employee_newParametros(id,name,hoursWorked,salary);
			ll_add(pArrayListEmployee, employee);
		}

		fclose(pFile);

		printf("Se ha cargado el archivo csv con exito!\n");
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		Employee* employee;
		FILE* pFile;

		ll_clear(pArrayListEmployee);

		pFile = fopen(path, "rb");

		while(!feof(pFile))
		{
			employee = employee_new();
			if(fread(employee, sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, employee);
			}

		}
		fclose(pFile);


		printf("Se ha cargado el archivo bin con exito!\n");
	}


    return 1;
}
