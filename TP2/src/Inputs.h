/*
 * Inputs.h
 *
 *  Created on: 15 may. 2021
 *      Author: Sein Ian
 */

#ifndef INPUTS_H_
#define INPUTS_H_


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Retorna un numero flotante.
float GetFloat(char*);

//Retorna una cadena de caracteres.
void GetString(char*, char*);

//Valida un rango de un numero en especifico.
int ValidateRange(char*, int, int, int);

//Retorna un numero entero.
int GetInt(char*);

#endif /* INPUTS_H_ */
