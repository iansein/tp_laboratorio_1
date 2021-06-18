/*
 * Funciones.h
 *
 *  Created on: 7 jun. 2021
 *      Author: Usuario
 */
#include "LinkedList.h"
#include "Employee.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int mainMenu(void);
void GetString(char*, char*);
int GetInt(char*);
int addEmployee(LinkedList*);
int ModifyEmployee(LinkedList*);
Employee* RequestEmployeeData(LinkedList*, int);
int EmployeesList(LinkedList*);
int RemoveEmployee(LinkedList*);
int EmployeeListByName(LinkedList*);
int SaveTheDataInCsv(char*, LinkedList*);
int SaveTheDataInBin(char*, LinkedList*);
int SortMenu(LinkedList*);

#endif /* FUNCIONES_H_ */
