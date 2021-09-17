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
/**
 * @fn int validarOpcion(char*, char*, int, int)
 * @brief Pide un numero entero entre un rango
 *
 * @param mensaje Mensaje que informa sobre lo que se pide
 * @param mensajeError Mensaje de error si no esta dentro del rango
 * @param minimo Minimo numero del rango
 * @param maximo Maximo numero del rango
 * @return El numero entero que se le devuelve al usuario
 */
int validarOpcion (char* mensaje, char* mensajeError, int minimo,int maximo);
/**
 * @fn float ingresarNumero(void)
 * @brief Permite el ingreso de un numero flotante con scanf
 *
 * @return El numero ingresado.
 */
float ingresarNumero(void);



#endif /* FUNCIONES_H_ */
