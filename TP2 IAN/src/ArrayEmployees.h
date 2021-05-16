/*
 * ArrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: Sein Ian
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

//Estructura de empleados
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

//Menu principal
int Menu(void);

//Iniciar el array de empleados con espacios vacios.
int InitEmployees(eEmployee*, int);

//Busca un espacio libre dentro del array de empleados.
int SearchFree(eEmployee*, int);

//Pide los datos de un empleado.
eEmployee RequestEmployee(eEmployee*, int);

//Carga un empleaado a la base de datos.
int AddEmployee(eEmployee*, int);

//Retorna la ID de un empleado ingresada por el usuario.
int GetEmployeeId(eEmployee*, int);

//Recorre las ID's de los empleados con la ID ingresada por el usuario y retorna un indice.
int FindEmployeeById(eEmployee*, int, int);

//Da de baja a un empleado ya cargado.
int RemoveEmployee(eEmployee*, int, int);

//Ordena empleados por sector y por apellido
int SortEmployeesBySector(eEmployee*, int);

//Ordena empleados por apellido
void SortEmployeesByLastName(eEmployee*, int, eEmployee*);

//Muestra un listado de los empleados ordenados por sector y apellido.
int PrintEmployees(eEmployee*, int);

//Muestra un listado de los empleados con toda la informacion
void PrintfEmployeesWithAllData(eEmployee*, int);

//Modificar los datos de un empleado
void ModifyEmployee(eEmployee*, int, int);

//Menu de los listados
int MenuList(void);

//Calcula el total de los salarios
float CalculateTotalSalary(eEmployee*, int);

//Calcula el promedio de los salarios.
float CalculateAverageSalaries(eEmployee*, int);

//Calcula el total de empleados que tienen un salario mayor al salario promedio.
int CalculateEmployeesHigherThanAverageSalary(eEmployee*, int);

//Muestra un listado de : Total de salarios, promedio de salarios y el total de empleados que tienen un salario mayor al salario promedio
void EmployeesSalaryList(eEmployee*, int);

#endif /* ARRAYEMPLOYEES_H_ */
