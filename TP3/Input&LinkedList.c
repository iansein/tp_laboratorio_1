#include "Input&LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Crea un menu para que el usuario interactur.
 *
 * \param void
 * \return int
 *
 */
int mainMenu(void)
{
	int option;

	printf("Ingrese una opcion\n");
	printf("1- Cargar archivos desde el archivo data.csv\n");
	printf("2- Cargar archivos desde el archivo data.bin\n");
	printf("3- Alta de un empleado\n");
	printf("4- Modificacion de un empleado\n");
	printf("5- Baja de un empleado\n");
	printf("6- Listado de empleados\n");
	printf("7- Ordenar empleados\n");
	printf("8- Guardar los datos de los empleados en el archivo data.csv\n");
	printf("9- Guardar los datos de los empleados en el archivo data.bin\n");
	printf("10- Salir\n");
	scanf("%d", &option);


	return option;
}

/** \brief Obtiene una cadena de caracteres.
 *
 * \param mensaje char*
 * \param employee char*
 *
 */

void GetString(char* message, char* employee)
{
	printf("%s", message);
	scanf("%s", employee);

}

/** \brief Agrega un empleado a la lista.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int addEmployee(LinkedList* pArrayListEmployee)
{

	int len;
	int i;
	int id;
	char name[50];
	int hoursWorked;
	int salary;
	Employee* aux;

	i = 0;
	id = 1001;

	if(pArrayListEmployee!=NULL)
	{

		Employee* employee = employee_new();

		len = ll_len(pArrayListEmployee);

		for(i = 0; i < len ; i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			if(id == aux->id)
			{
				id++;
			}
		}

		GetString("Ingrese el nombre del empleado\n", name);
		hoursWorked = GetInt("Ingrese las horas trabajadas del empleado\n");
		salary = GetInt("Ingrese el sueldo del empleado\n");

		employee_setId(employee, id);
		employee_setNombre(employee, name);
		employee_setHorasTrabajadas(employee, hoursWorked);
		employee_setSueldo(employee, salary);

		ll_add(pArrayListEmployee, employee);

	}

	return 1;
}

/** \brief Obtiene un numero entero.
 *
 * \param mensaje char*
 * \return int
 *
 */

int GetInt(char* message)
{
	int number;
	printf("%s", message);
	scanf("%d", &number);

	return number;
}


/** \brief Modifica a un empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ModifyEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	int i;
	int len;
	int index;
	int accountant;
	Employee* aux;
	Employee* employee;

	accountant = 0;

	if(pArrayListEmployee != NULL)
	{
		EmployeesList(pArrayListEmployee);

		id = GetInt("Ingrese la id del empleado para modificar\n");

		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			if(id==aux->id)
			{
				index = i;
				accountant++;
			}
		}

		if(accountant>0)
		{
			employee = RequestEmployeeData(pArrayListEmployee, id);

			ll_set(pArrayListEmployee, index, employee);
		}
		else
		{
			printf("Error, usted ha ingresado una ID erronea\n");
		}

	}

	return 1;

}

/** \brief Pide los datos para crear un empleado y luego reemplazarlo por otro.
 *
 * \param id int
 * \param pArrayListEmployee LinkedList*
 * \return Employee*
 *
 */
Employee* RequestEmployeeData(LinkedList* pArrayListEmployee, int id)
{
	Employee* employee;

	if(pArrayListEmployee!=NULL)
	{
		employee = employee_new();

		char name[50];
		int hoursWorked;
		int salary;

		GetString("Ingrese el nombre del empleado\n", name);
		hoursWorked = GetInt("Ingrese las horas trabajadas del empleado\n");
		salary = GetInt("Ingrese el sueldo del empleado\n");

		employee_setId(employee, id);
		employee_setNombre(employee, name);
		employee_setHorasTrabajadas(employee, hoursWorked);
		employee_setSueldo(employee, salary);
	}

	return employee;
}

/** \brief Genera una lista de empleados.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeesList(LinkedList* pArrayListEmployee)
{
	int len;
	int i;
	Employee* aux;
	len = ll_len(pArrayListEmployee);
	i = 0;

	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			printf("ID         NOMBRE      HT   SUELDO\n");
			for(i=0;i<len;i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee,i);
				printf("%d %11s %8d %7d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
			}
		}
		else
		{
			printf("La lista es inexistente, por lo que no se puede listar\n");
		}
	}

	return 1;

}

/** \brief Remueve a un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int RemoveEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int id;
	int index;
	int contador;
	int len;
	Employee* aux;

	contador = 0;

	if(pArrayListEmployee != NULL)
	{
		EmployeesList(pArrayListEmployee);
		id = GetInt("Ingrese la id del empleado para modificar\n");

		len = ll_len(pArrayListEmployee);

		for(i=0;i<len;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			if(id==aux->id)
			{
				index = i;
				contador++;
			}
		}

		if(contador>0)
		{
			ll_remove(pArrayListEmployee,index);
			printf("Usted ha dado de baja correctamente al empleado\n");

		}
		else
		{
			printf("Error, usted ha ingresado una ID erronea\n");
		}

	}

	return 1;
}

/** \brief Ordena la lista de empleados por nombre.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListByName(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeByName, 1);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Ordena la lista de empleados por salario.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListBySalary(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeBySalary, 1);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Ordena la lista de empleados por ID.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListById(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeById, 0);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Ordena la lista de empleados por horas trabajadas.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int EmployeeListByHours(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee)==0)
		{
			ll_sort(pArrayListEmployee, CompareEmployeeByHours, 1);
			printf("Se han ordenado los empleados con exito!\n");
		}
		else
		{
			printf("No existe ninguna lista para ordenar\n");
		}

	}

	return 1;

}

/** \brief Guarda la lista con empleados en un archivo.csv.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int SaveTheDataInCsv(char* path,LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aux;
	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	pFile = fopen(path,"w");

	for(i=0;i<len;i++)
	{
		aux = (Employee*) ll_get(pArrayListEmployee,i);
		fprintf(pFile,"%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
	}

	fclose(pFile);

	printf("Se han guardado los datos en el archivo csv con exito!\n");

	return 1;

}

/** \brief Guarda la lista con empleados en un archivo bin.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int SaveTheDataInBin(char* path, LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aux;
	int len;
	int i;

	len = ll_len(pArrayListEmployee);
	printf("%d\n", len);
	pFile = fopen(path,"wb");

	for(i=0;i<len;i++)
	{
		aux = (Employee*) ll_get(pArrayListEmployee,i);
		fwrite(aux,sizeof(Employee),1,pFile);
	}

	fclose(pFile);

	printf("Se han guardado los datos en el archivo bin con exito!\n");

	return 1;

}

/** \brief Menu de opciones para el ordenamiento.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int SortMenu(LinkedList* pArrayListEmployee)
{
	int option;

	do
	{
		printf("Como quiere ordenar la lista de empleados?\n");
		printf("1- Por nombre\n");
		printf("2- Por sueldo\n");
		printf("3- Por horas trabajadas\n");
		printf("4- Por ID\n");
		printf("5- Volver al menu\n");
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				if(EmployeeListByName(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 2:
				if(EmployeeListBySalary(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 3:
				if(EmployeeListByHours(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 4:
				if(EmployeeListById(pArrayListEmployee)==1)
				{

				}
				else
				{
					printf("Error\n");
				}
				break;

			case 5:
				break;
		}
	}while(option!=5);


	return 1;
}
