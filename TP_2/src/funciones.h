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
/**
 * @fn int getInteger(char*, char*, int, int)
 * @brief Asks for an integer in a range
 *
 * @param mensaje Message that informs the user about what is being asked
 * @param mensajeError Error message that displays if the user enters a number outside of the range or a letter
 * @param minimo Lowest possible number in the range
 * @param maximo Highest possible number in the range
 * @return The integer entered by the user
 */
int getInteger (char* mensaje, char* mensajeError, int minimo,int maximo);
/**
 * @fn float getFloat(char*, char*, float, float)
 * @brief Asks for a float number in a range
 *
 * @param mensaje Message that informs the user about what is being asked
 * @param mensajeError Error message that displays if the user enters a number outside of the range
 * @param minimo Lowest possible number in the range
 * @param maximo Highest possible number in the range
 * @return The float number entered by the user
 */
float getFloat(char*mensaje,char*mensajeError,float minimo, float maximo);
/**
 * @fn void getString(char*, char*, char*, int)
 * @brief Asks for a string/characters array
 *
 * @param cadena Where the string is stored
 * @param mensaje Message that informs the user about what is being asked
 * @param mensajeError Error message that displays if the user goes above the limit
 * @param max The characters limit
 */
void getString(char* cadena, char* mensaje, char* mensajeError, int max);
/**
 * @fn int answerYesOrNo(char*, char*)
 * @brief Asks for one of two characters. S/s for yes -- N/n for no
 *
 * @param caracter Where the character is stored
 * @param mensaje Message that informs the user about what is being asked
 * @return int retorno -1(Error) if both parameters are NULL. 0 if the caracther can be entered correctly.
 */
int answerYesOrNo(char* caracter, char*mensaje);
/**
 * @fn int verifyConfirmation(char*)
 * @brief Verifies that the user wants to go ahead with the upload/removal/modification
 *
 * @param mensaje Message that informs the user about what is being confirmed, along with the options
 * @return int retorno 0 if the user agrees. -1 if the user backs out.
 */
int verifyConfirmation(char* mensaje);
/**
 * @fn int isValidSalary(char*, int)
 * @brief Checks that the string is only comprised of numbers so that it may be casted into a float after.
 *
 * @param cadena The string entered.
 * @param length The character length of the string.
 * @return int retorno -1 if the string is empty or the length is invalid.
 *                     0 if it finds something that is not a number/dot/'\0'.
 *                     1 if it does not find anything that isn't a number
 *                     (the string can be then converted into a float using atof).
 *
 */
int isValidSalary(char*cadena,int length);
/**
 * @fn int isValidName(char*, int)
 * @brief Checks that the string is only comprised of letters.
 *
 * @param cadena The string entered.
 * @param length The character length of the string.
 * @return int retorno -1 if the string is empty or the length is invalid.
 *                     0 if it finds something that is not a letter/space/'\0'.
 *                     1 if it does not find anything that isn't a letter.
 */
int isValidName(char*cadena,int length);

#endif /* FUNCIONES_H_ */
