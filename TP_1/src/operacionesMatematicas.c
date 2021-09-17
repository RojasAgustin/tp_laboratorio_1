/*
 * operacionesMatematicas.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */

#include "operacionesMatematicas.h"

float sumar(float A, float B) {
	float suma;
	suma = A + B;
	return suma;
}

float restar(float A, float B) {
	float resta;
	resta = A - B;
	return resta;
}

float dividir(float A, float B) {
	float division;
	if(B != 0) {
	division = (float)A / B;
	}
	return division;
}



float multiplicar(float A, float B) {
	float multiplicacion;
	multiplicacion = A * B;
	return multiplicacion;
}

long int calcularFactorial(float num) {
	num = (int)num;
	long int factorial = 1;
	if (num > 1)
	{
		factorial = num * calcularFactorial(num-1);
	}
	return factorial;
}
