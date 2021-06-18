#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Setea el id dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _id int
 * \return int
 *
 */
int employee_setId(Employee* employee,int _id)
{
	if(employee!= NULL)
	{
		employee->id = _id;

	}

	return 1;
}

/** \brief Devuelve el id dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* employee,int* id)
{

	if(employee!=NULL && id!=NULL)
	{
		*id = employee->id;

	}


	return 1;
}


/** \brief Setea el nombre dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* employee,char* _nombre)
{

	if(employee!= NULL)
	{
		strcpy(employee->nombre, _nombre);

	}

	return 1;
}

/** \brief Devuelve el nombre dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* employee,char* nombre)
{

	if(employee!=NULL && nombre!=NULL)
	{
		strcpy(nombre, employee->nombre);


	}

	return 1;
}

/** \brief Setea las horas de trabajo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* employee,int _horasTrabajadas)
{

	if(employee!= NULL)
	{
		employee->horasTrabajadas = _horasTrabajadas;

	}

	return 1;
}

/** \brief Devuelve las horas de trabajo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas)
{

	if(employee!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = employee->horasTrabajadas;

	}

	return 1;
}

/** \brief Setea el sueldo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param _sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* employee,int _sueldo)
{

	if(employee!= NULL)
	{
		employee->sueldo = _sueldo;

	}

	return 1;
}

/** \brief Devuelve el sueldo dentro de una estructura de empleado.
 *
 * \param employee Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* employee,int* sueldo)
{

	if(employee!=NULL && sueldo!=NULL)
	{
		*sueldo = employee->sueldo;

	}

	return 1;
}


/** \brief Crea un nuevo empleado mediante mediante el parseo de sus pasajes en cadena.
 *
 * \param employee Employee*
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employee = employee_new();

	int id;
	int horasTrabajadas;
	int sueldo;

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{

		id = atoi(idStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);


		if(employee_setId(employee, id)==1 && employee_setNombre(employee, nombreStr)==1 && employee_setHorasTrabajadas(employee, horasTrabajadas) == 1 && employee_setSueldo(employee, sueldo) ==1)
		{

		}
		else
		{
			printf("Error\n");
		}
	}

	return employee;

}

/** \brief Crea un nuevo empleado de manera dinamica.
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
	Employee* newEmployee;
	newEmployee = (Employee*)malloc(sizeof(Employee));

	return newEmployee;
}

/** \brief Compara dos nombres.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeByName(void* employeeOne, void* employeeTwo)
{
	int comparison;
	char firstName[128];
	char secondName[128];

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getNombre((Employee*)employeeOne,firstName)==1 && employee_getNombre((Employee*)employeeTwo,secondName)==1)
		{

			comparison = strcmp(firstName, secondName);

			if(comparison > 0)
			{
				comparison = 1;
			}
			else
			{
				if(comparison < 0 )
				{
					comparison = -1;
				}
				else
				{
						comparison = 0;
				}
			}
		}

	}

	return comparison;
}

/** \brief Compara dos ID's.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeById(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstId;
	int secondId;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getId((Employee*)employeeOne,&firstId)==1 && employee_getId((Employee*)employeeTwo,&secondId)==1)
		{
			if(firstId > secondId)
			{
				comparison = 1;
			}
			else
			{
				if(firstId == secondId)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}
		}

	}

	return comparison;
}

/** \brief Compara dos salarios.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeBySalary(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstSalary;
	int secondSalary;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getSueldo((Employee*)employeeOne,&firstSalary)==1 && employee_getSueldo((Employee*)employeeTwo,&secondSalary)==1)
		{
			if(firstSalary > secondSalary)
			{
				comparison = 1;
			}
			else
			{
				if(firstSalary == secondSalary)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}

		}
	}


	return comparison;
}

/** \brief Compara las horas trabajadas.
 *
 * \param employeeOne Employee*
 * \param employeeTwo Employee*
 * \return int
 *
 */
int CompareEmployeeByHours(void* employeeOne, void* employeeTwo)
{
	int comparison;
	int firstHours;
	int secondHours;

	if(employeeOne!=NULL && employeeTwo!=NULL)
	{
		if(employee_getHorasTrabajadas((Employee*)employeeOne,&firstHours)== 1 && employee_getHorasTrabajadas((Employee*)employeeTwo,&secondHours) ==1)
		{
			if(firstHours > secondHours)
			{
				comparison = 1;
			}
			else
			{
				if(firstHours == secondHours)
				{
					comparison = 0;

				}
				else
				{
					comparison = -1;
				}
			}
		}

	}

	return comparison;
}


