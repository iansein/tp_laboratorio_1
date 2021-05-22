/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Ian Sein
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{

    int opcion;
    int primerOperando;
    int segundoOperando;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialPrimerOperando;
    int factorialSegundoOperando;
    int flagPrimerOperando;
    int flagSegundoOperando;
    int flagCalcularOperaciones;

    setbuf(stdout , NULL);
    flagPrimerOperando = 1;
    flagSegundoOperando = 1;
    flagCalcularOperaciones = 1;
    primerOperando = 0;
    segundoOperando = 0;



    do
    {
        printf("Ingrese una de las opciones \n");
        printf("1 - Ingresar primer operando (A = %d) \n", primerOperando);
        printf("2 - Ingresar segundo operando (B = %d) \n" , segundoOperando);
        printf("3 - Calcular todas las operaciones\n");
        printf("4 - Mostrar todos los resultados \n");
        printf("5 - Salir \n");
        printf("Su opcion es : \n");
        scanf("%d" , &opcion);

        switch(opcion)
        {
            case 1 :
            primerOperando = IngresarPrimerOperando();
            flagPrimerOperando = 0;
            break;

            case 2 :
            segundoOperando = IngresarSegundoOperando();
            flagSegundoOperando = 0;
            break;

            case 3 :
            if(flagPrimerOperando == 0 && flagSegundoOperando == 0)
            {
                suma = CalcularSuma(primerOperando , segundoOperando);
                resta = CalcularResta(primerOperando , segundoOperando);
                division = CalcularDivision (primerOperando , segundoOperando);
                multiplicacion = CalcularMultiplicacion (primerOperando , segundoOperando);
                factorialPrimerOperando = CalcularFactorialPrimerOperando(primerOperando);
                factorialSegundoOperando = CalcularFactorialSegundoOperando(segundoOperando);

                printf("Las operaciones han sido calculadas exitosamente \n\n");
                flagCalcularOperaciones = 0;
            }
            else
            {
                printf("Para calcular todas las operaciones es necesario que ingreses los operandos\n\n");
            }
            break;

            case 4 :
            if(flagPrimerOperando == 0 && flagSegundoOperando == 0 && flagCalcularOperaciones == 0)
            {


                printf("La suma de estos 2 numeros es %d\n" , suma);
                printf("La resta de estos 2 numeros es %d\n" , resta);
                if(segundoOperando == 0)
                {
                    printf("Dividir por 0 no es posible, por lo cual no se encontro ningun resultado\n");
                }
                else
                {
                    printf("La division de estos 2 numeros es %f\n" , division);
                }
                printf("La multiplicacion de estos 2 numeros es %d\n" , multiplicacion);
                printf("El factorial del primero operando es %d\n" , factorialPrimerOperando);
                printf("El factorial del segundo operando es %d\n \n" , factorialSegundoOperando);
            }
            else
            {
                printf("Para mostrar los resultados es necesario que usted ingrese los 2 operandos y/o calcule las operaciones\n\n");
            }
            break;

            case 5 :
            break;

         }

    }while(opcion != 5);
	return EXIT_SUCCESS;
}
