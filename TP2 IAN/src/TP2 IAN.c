/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Sein Ian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ArrayEmployees.h"
#include "Inputs.h"


#define LEN 15


int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    int option;
    int optionTwo;
    int ModifyEmployeeId;
    int CancelEmployeeId;
    int flag;

    eEmployee employee [LEN];

    InitEmployees(employee, LEN);
    if(InitEmployees(employee, LEN) == -1)
    {
    	printf("ERROR\n");
    }

    flag = 0;


    do
    {
        option = Menu();

        switch(option)
        {
            case 1:
            AddEmployee(employee, LEN);
            flag = 1;
            break;

            case 2:
            if(flag == 1)
            {
            	PrintfEmployeesWithAllData(employee, LEN);
                ModifyEmployeeId = GetEmployeeId(employee, LEN);
                ModifyEmployee(employee, LEN, ModifyEmployeeId);
            }
            else
            {
                printf("Para modificar a un empleado es necesario dar de alta uno.\n");
            }
            break;

            case 3:
            if(flag == 1)
            {
                CancelEmployeeId = GetEmployeeId(employee, LEN);
                if(RemoveEmployee(employee,LEN,CancelEmployeeId) == -1)
                {
                	printf("ERROR\n");
                }
            }
            else
            {
                printf("Para dar de baja un empleado es necesario dar de alta a uno.\n");
            }
            break;

            case 4:
            if(flag == 1)
            {
            	do
            	{
            		optionTwo = MenuList();

            		switch(optionTwo)
            		{
                    	case 1:
                    	if(SortEmployeesBySector(employee, LEN) == -1)
                    	{
                    		printf("ERROR\n");
                    	}
                    	else
                    	{
                    		if(PrintEmployees(employee, LEN) == -1)
                    		{

                    		printf("ERROR\n");

                    		}
                    	}
                    	break;

                    	case 2:
                    	EmployeesSalaryList(employee, LEN);
                    	break;

                    	case 3:
                    	break;

            		}
            	}while(optionTwo != 3);
            }
            else
            {
                printf("Para mostrar los listados necesario dar de alta a un empleado.\n");
            }
            break;

            case 5:
            break;


        }

    }while(option != 5);

    return 0;
}
