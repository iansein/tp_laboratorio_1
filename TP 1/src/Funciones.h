/*
 * Funciones.h
 *
 *  Created on: 4 abr. 2021
 *      Author: Ian Sein
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>

/*En esta funcion lo que realiza es el pedido del primer operando (Parametros : 2 operandos)*/
int IngresarPrimerOperando (void);

/*En esta funcion lo que realiza es el pedido del segundo operando (Parametros : 2 operandos)*/
int IngresarSegundoOperando (void);

/*En esta funcion se realiza la suma de los dos operandos (Parametros : 2 operandos)*/
int CalcularSuma(int , int);

/*En esta funcion se realiza la resta de los dos operandos (Parametros : 2 operandos)*/
int CalcularResta(int , int);

/*En esta funcion se realiza la division de los dos operandos (Parametros : 2 operandos)*/
float CalcularDivision (int , int);

/*En esta funcion se realiza la multiplicacion de los dos operandos (Parametros : 2 operandos)*/
int CalcularMultiplicacion (int , int);

/*En esta funcion se realiza el factorial del primer operando (Parametros : primer operandos)*/
int CalcularFactorialPrimerOperando(int);

/*En esta funcion se realiza el factorial del segundo operando (Parametros : segundo operando)*/
int CalcularFactorialSegundoOperando (int);

#endif /* FUNCIONES_H_ */
