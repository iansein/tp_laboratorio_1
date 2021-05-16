/*
 * Inputs.c
 *
 *  Created on: 15 may. 2021
 *      Author: Sein Ian
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Inputs.h"

int GetInt(char *message)
{
    int wholeNumber;
    printf("%s" , message);
    scanf("%d", &wholeNumber);

    return wholeNumber;
}

void GetString(char *message, char *string)
{
    printf("%s", message);
    fflush(stdin);
    scanf("%s", string);
}

float GetFloat(char *message)
{
    int floatingNumber;
    printf("%s" , message);
    scanf("%d", &floatingNumber);

    return floatingNumber;
}

int ValidateRange(char *message, int maxNumber, int minNumber, int numberToValidate)
{
    while(numberToValidate > maxNumber || numberToValidate < minNumber)
    {
        numberToValidate = GetInt(message);
    }

    return numberToValidate;
}
