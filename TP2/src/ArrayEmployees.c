

#include "ArrayEmployees.h"
#include "Inputs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Menu(void)
{
    int option;
    printf("Ingrese una opcion\n");
    printf("1-Alta\n");
    printf("2-Modificacion\n");
    printf("3-Baja\n");
    printf("4-Listados\n");
    printf("5-Salir\n");
    scanf("%d", &option);

    return option;
}

int MenuList(void)
{
    int option;
    printf("Ingrese una opcion\n");
    printf("1-Empleados con su respectivo sector\n");
    printf("2-Total y promedios de salarios, y empleados que superan el salario promedio\n");
    printf("3-Volver al menu principal\n");
    scanf("%d", &option);

    return option;
}


int InitEmployees(eEmployee *employee, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        (employee+i)->isEmpty = 0;
    }

    return 0;
}

int SearchFree(eEmployee *employee, int len)
{
    int index;
    int i;

    index = -1;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 0)
        {
            index = i;
        }
    }

    return index;
}

eEmployee RequestEmployee(eEmployee *oldEmployee, int len)
{
    eEmployee employee;
    int i;

    employee.id = 0;

    for(i=0;i<len;i++)
    {
        if(employee.id == (oldEmployee+i)->id)
        {
            employee.id = employee.id + 1;
        }
    }

    GetString("Ingrese el nombre del empleado\n", employee.name);

    GetString("Ingrese el apellido del empleado\n", employee.lastName);

    employee.salary = GetFloat("Ingrese el salario del empleado\n");

    employee.sector = GetInt("Ingrese el sector del empleado (1-15)\n");
    employee.sector = ValidateRange("Error : Reingrese el sector del empleado (1-15)\n", 15, 1, employee.sector);

    return employee;

}


int AddEmployee(eEmployee *employee, int len)
{
    int index;

    index = SearchFree(employee, len);

    if(index != -1)
    {
        *(employee + index) = RequestEmployee(employee, len);
        (employee + index)->isEmpty = 1;
    }
    else
    {
        printf("No hay espacio disponible!\n");
    }

    return -1;

}


int GetEmployeeId(eEmployee *employee, int len)
{
    int idEmployee;
    int i;

    printf("Ingrese el ID del empleado\n");
    scanf("%d", &idEmployee);

    return idEmployee;
}


int FindEmployeeById(eEmployee *employee, int len, int id)
{
    int i;
    int index;

    index = -1;

    for(i=0;i<len;i++)
    {
        if(id == (employee+i)->id)
        {
            index = i;
        }
    }

    return index;
}

int RemoveEmployee(eEmployee *employee, int len, int id)
{
    int index;

    index = FindEmployeeById(employee, len, id);

    if(index != -1)
    {
        (employee+index)->isEmpty = 0;
        printf("Se ha dado de baja al empleado!\n");
    }
    else
    {
        printf("No se encontro la ID ingresada\n");
    }

    return 0;
}

void ModifyEmployee(eEmployee *employee, int len, int id)
{
    int index;
    int option;

    index = FindEmployeeById(employee,len,id);

    if(index != -1)
    {
        PrintfEmployeesWithAllData(employee, len);
        option = GetInt("Ingrese la opcion a modificar\n1-SECTOR\n2-SALARIO\n3-NOMBRE\n4-APELLIDO\n");
        option = ValidateRange("Error : Ingrese la opcion a modificar\n1-SECTOR\n2-SALARIO\n3-NOMBRE\n4-APELLIDO\n", 4, 1, option);
    }
    else
    {
        printf("No se encontro la ID ingresada\n");
    }

    switch(option)
    {
        case 1:
        (employee+index)->sector = GetInt("Ingrese el sector del empleado (1-15)\n");
        (employee+index)->sector = ValidateRange("Error : Reingrese el sector del empleado (1-15)\n", 15, 1, (employee+index)->sector);
        printf("Modificacion realizada!\n");
        break;

        case 2:
        (employee+index)->salary = GetFloat("Ingrese el salario del empleado\n");
        printf("Modificacion realizada!\n");
        break;

        case 3:
        GetString("Ingrese el nombre del empleado\n", (employee+index)->name);
        printf("Modificacion realizada!\n");
        break;

        case 4:
        GetString("Ingrese el apellido del empleado\n", (employee+index)->lastName);
        printf("Modificacion realizada!\n");
        break;

    }

}

int SortEmployeesBySector(eEmployee *employee, int len)
{
    int i;
    int j;
    eEmployee auxiliar;

    for (i=0; i<len - 1; i++)
	{
		for (j = i+1; j<len; j++)
		{
			if ((employee+i)->sector > (employee+j)->sector)
			{
				auxiliar = employee[i];
				employee[i] = employee[j];
				employee[j] = auxiliar;
			}
			else
			{
				if((employee+i)->sector == (employee+j)->sector)
				{
					SortEmployeesByLastName((employee+i), len, (employee+j));
				}
			}
		}
	}

    return 0;
}

void SortEmployeesByLastName(eEmployee *employee, int len, eEmployee *employeeOtro)
{
	eEmployee *auxiliar;

	if(strcmp(employee->lastName, employeeOtro->lastName) > 0)
	{
		auxiliar = employee;
		employee = employeeOtro;
		employeeOtro = auxiliar;
	}


}


int PrintEmployees(eEmployee *employee, int len)
{
    int i;
    int j;

    int validation;

    validation = 1;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1 && (employee+i)->sector != (employee+validation)->sector)
        {
            printf("SECTOR : %d\n", (employee+i)->sector);
            for(j=0;j<len;j++)
            {
                if((employee+i)->sector == (employee+j)->sector)
                {

                	printf("%s\n\n", (employee+j)->lastName);

                }

            }
        }

        validation++;
    }

    return 0;
}

void PrintfEmployeesWithAllData(eEmployee *employee, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1)
        {
            printf("\nID: %d     NOMBRE: %s     APELLIDO: %s     SALARIO: %.2f    SECTOR: %d\n", (employee+i)->id, (employee+i)->name, (employee+i)->lastName, (employee+i)->salary, (employee+i)->sector);

        }
    }
}

float CalculateTotalSalary(eEmployee *employee, int len)
{
    float totalSalary;
    int i;

    totalSalary = 0;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1)
        {
            totalSalary+=(employee+i)->salary;
        }
    }

    return totalSalary;
}

float CalculateAverageSalaries(eEmployee *employee, int len)
{
    int i;
    int employeeAccountant;
    float totalSalary;
    float averageSalaries;

    totalSalary = CalculateTotalSalary(employee, len);
    employeeAccountant = 0;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1)
        {
            employeeAccountant++;
        }
    }

    averageSalaries = totalSalary / employeeAccountant;

    return averageSalaries;
}

int CalculateEmployeesHigherThanAverageSalary(eEmployee *employee, int len)
{
    float averageSalaries;
    int employeeAccountant;
    int i;

    averageSalaries = CalculateAverageSalaries(employee, len);
    employeeAccountant = 0;

    for(i=0;i<len;i++)
    {
        if((employee+i)->isEmpty == 1 && (employee+i)->salary > averageSalaries)
        {
            employeeAccountant++;
        }
    }

    return employeeAccountant;
}

void EmployeesSalaryList(eEmployee *employee, int len)
{
    float totalSalary;
    float averageSalaries;
    int employeeAccountant;

    totalSalary = CalculateTotalSalary(employee, len);
    averageSalaries = CalculateAverageSalaries(employee, len);
    employeeAccountant = CalculateEmployeesHigherThanAverageSalary(employee, len);

    printf("\nEl salario total es de $%.2f\n", totalSalary);
    printf("El promedio de los salarios es de $%.2f\n", averageSalaries);
    printf("Los empleados que superan el salario promedio son %d\n\n", employeeAccountant);
}
