/*
 * operacionesMatematicas.h
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */

#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_
#include <stdio.h>
#include <stdlib.h>
/**
 * @fn float sumar(float, float)
 * @brief Suma dos numeros
 *
 * @param A Primer numero
 * @param B Segundo numero
 * @return El resultado de la suma
 */
float sumar(float A, float B);
/**
 * @fn float restar(float, float)
 * @brief Resta dos numeros
 *
 * @param A Primer numero
 * @param B Segundo numero
 * @return El resultado de la resta
 */
float restar(float A, float B);
/**
 * @fn float multiplicar(float, float)
 * @brief Multiplica dos numeros
 *
 * @param A Primer numero
 * @param B Segundo numero
 * @return El resultado de la multiplicacion
 */
float multiplicar(float A, float B);
/**
 * @fn float dividir(float, float)
 * @brief Divide dos numeros
 *
 * @param A El dividendo
 * @param B El divisor
 * @return El resultado de la division
 */
float dividir(float A, float B);
/**
 * @fn long int calcularFactorial(float)
 * @brief Calcula el factorial de un número. Si el número es decimal, redondea hacía abajo (3.8! = 3! = 6).
 * salvo que se ingrese un número como: "3.99999999", que redondea hacia arriba.
 *
 * @param num El numero cuyo factorial sera calculado
 * @return El factorial
 */
long int calcularFactorial(float num);


#endif /* OPERACIONESMATEMATICAS_H_ */
