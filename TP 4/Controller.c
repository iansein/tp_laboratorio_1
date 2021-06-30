#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Input&LinkedList.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	if(path!=NULL && pArrayListEmployee!=NULL)
	{

		if(parser_EmployeeFromText(path , pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}

	}

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(parser_EmployeeFromBinary(path,pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(addEmployee(pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(ModifyEmployee(pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(RemoveEmployee(pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}

	}
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(EmployeesList(pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(SortMenu(pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}

	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(SaveTheDataInCsv(path,pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}

	}

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(SaveTheDataInBin(path, pArrayListEmployee)==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}


    return 1;
}

