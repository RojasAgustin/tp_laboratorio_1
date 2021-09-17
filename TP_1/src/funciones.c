/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */


#include "funciones.h"

int validarOpcion(char* mensaje,char* mensajeError, int minimo,int maximo) {
	int numero;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);

	while(numero < minimo || numero > maximo)
	{
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numero);
	}
	return numero;
}
float ingresarNumero(void) {
	float numeroIngresado;
	printf("Ingresar el operando: ");
	fflush(stdin);
	scanf("%f",&numeroIngresado);
	return numeroIngresado;
}
