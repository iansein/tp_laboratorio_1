/*
 * Funciones.c
 *
 *  Created on: 4 abr. 2021
 *      Author: Ian Sein
 */
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>

int IngresarPrimerOperando (void)
{
    int primerOperando;
    printf("Ingrese el primer operando (A = X) : ");
    scanf("%d" , &primerOperando);
    printf("El primer operando es %d\n \n" , primerOperando);
    return primerOperando;

}


int IngresarSegundoOperando (void)
{
    int  segundoOperando;
    printf("Ingrese el segundo operando (B = X) : ");
    scanf("%d" , &segundoOperando);
    printf("El segundo operando es %d\n \n" , segundoOperando);
    return segundoOperando;

}


int CalcularSuma(int primerOperando , int segundoOperando)
{

    int resultadoSuma;

    resultadoSuma = primerOperando + segundoOperando;
    return resultadoSuma;

}


int CalcularResta(int primerOperando , int segundoOperando)
{

    int resultadoResta;

    resultadoResta = primerOperando - segundoOperando;
    return resultadoResta;

}


float CalcularDivision (int primerOperando , int segundoOperando)
{
    float resultadoDivision;

    resultadoDivision = (float) primerOperando / segundoOperando;
    return resultadoDivision;
}


int CalcularMultiplicacion (int primerOperando , int segundoOperando)
{
    int resultadoMultiplicacion;

    resultadoMultiplicacion = primerOperando * segundoOperando;
    return resultadoMultiplicacion;
}


int CalcularFactorialPrimerOperando (int primerOperando)
{
    int factorial;
    int i;

    factorial = 1;

    for (i = primerOperando; i > 1; i--)
    {
        factorial = factorial * i;
    }

    return factorial;

}


int CalcularFactorialSegundoOperando (int SegundoOperando)
{
    int factorial;
    int i;

    factorial = 1;

    for (i = SegundoOperando; i > 1; i--)
    {
        factorial = factorial * i;
    }

    return factorial;

}

