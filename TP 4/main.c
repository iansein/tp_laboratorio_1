#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input&LinkedList.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagArchivoCsv;
    int flagArchivoBin;

    setbuf(stdout, NULL);

   LinkedList* listaEmpleados = ll_newLinkedList();
   flagArchivoCsv = 0;
   flagArchivoBin = 0;


    do{
    	option = mainMenu();
        switch(option)
        {
            case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)==1)
            {

            	flagArchivoCsv = 1;

            }
            else
            {
            	printf("Error\n\n");
            }
            break;

            case 2:
            if(flagArchivoBin == 1)
            {
            	if(controller_loadFromBinary("data.bin", listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para cargar el archivo bin es necesario que lo guarde primero\n\n");
            }
            break;

            case 3:
            if(flagArchivoCsv == 1)
            {
            	if(controller_addEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para dar de alta un empleado, es necesario que cargue el archivo\n\n");
            }

            break;

            case 4:
            if(flagArchivoCsv == 1)
            {
            	if(controller_editEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para modificar un empleado es necesario que ingrese por por lo menos 1\n\n");
            }
            break;

            case 5:

            if(flagArchivoCsv == 1)
            {
            	if(controller_removeEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para dar de baja a un empleado es necesario que ingrese por por lo menos 1\n\n");
            }
            break;

            case 6:
            if(flagArchivoCsv == 1)
            {
            	if(controller_ListEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para listar es necesario que ingrese empleados\n\n");
            }
            break;

            case 7:
            if(flagArchivoCsv == 1)
            {
            	if(controller_sortEmployee(listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para ordenar es necesario que ingrese empleados\n\n");
            }
            break;

            case 8:
            if(flagArchivoCsv == 1)
            {
            	if(controller_saveAsText("data.csv", listaEmpleados)==1)
            	{

            	}
            	else
            	{
            		printf("Error\n\n");
            	}
            }
            else
            {
            	printf("Para guardar en el archivo es necesario que ingrese empleados\n");
            }

            break;

            case 9:
            if(flagArchivoCsv == 1)
            {
            	if(controller_saveAsBinary("data.bin", listaEmpleados)==1)
            	{
            		flagArchivoBin = 1;
            	}
            	else
            	{
            		printf("Error\n");
            	}
            }
            else
            {
            	printf("Para guardar en el archivo es necesario que ingrese empleados\n");
            }

            break;

            case 10:
            break;


        }
    }while(option != 10);

    return 0;
}

