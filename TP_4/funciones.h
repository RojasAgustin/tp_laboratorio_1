/*
 * funciones.h
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getInteger (char* mensaje, char* mensajeError, int minimo,int maximo);
void getString(char* cadena, char* mensaje, char* mensajeError, int max);
int answerYesOrNo(char* caracter, char*mensaje);
int verifyConfirmation(char* mensaje);
int isValidNumber(char*cadena,int length);
int isValidName(char*cadena,int length);

#endif /* FUNCIONES_H_ */
