/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */


#include "funciones.h"
/**
 * @fn int getInteger(char*, char*, int, int)
 * @brief Pide un entero en un rango
 *
 * @param mensaje char* -- Mensaje que informa al usuario sobre lo que se le pide
 * @param mensajeError char* -- Mensaje de error que se muestra si el usuario ingresa un numero fuera del rango
 * @param minimo int -- El numero mas bajo del rango
 * @param maximo int -- El numero mas alto del rango
 * @return numero int -- El entero ingresado por el usuario
 */
int getInteger(char* mensaje,char* mensajeError, int minimo,int maximo) {
	int numero;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);

	while(numero < minimo || numero > maximo) {
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numero);
	}
	return numero;
}
/**
 * @fn void getString(char*, char*, char*, int)
 * @brief Permite el ingreso de una cadena/array de caracteres.
 *
 * @param cadena char* -- Donde se guarda la cadena
 * @param mensaje char* -- Mensaje que informa al usuario sobre lo que se le pide
 * @param mensajeError char* -- Mensaje de error que se muestra si el usuario ingresa un numero fuera del rango
 * @param max int -- El limite de caracteres
 */
void getString(char* cadena, char* mensaje, char* mensajeError, int max)
{
	char cadenaSinValidar[200];
	int tam;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadenaSinValidar);
	tam = strlen(cadenaSinValidar);

	while(tam > max)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%[^\n]", cadenaSinValidar);
		tam = strlen(cadenaSinValidar);
	}
	strlwr(cadenaSinValidar);
	cadenaSinValidar[0] = toupper(cadenaSinValidar[0]);
	for(int i=0;i<max;i++){
		if(cadenaSinValidar[i-1] == ' '){
			cadenaSinValidar[i] = toupper(cadenaSinValidar[i]);
		}
	}
	strcpy(cadena, cadenaSinValidar);
}
/**
 * @fn int answerYesOrNo(char*, char*)
 * @brief Pide uno de dos caracteres. S/s para si -- N/n para no
 *
 * @param caracter char* -- Donde se guarda el caracter
 * @param mensaje char* -- Mensaje que informa al usuario sobre lo que se le pide
 * @return int retorno -- -1(Error) si ambos parametros apuntan a NULL. 0 si el caracter puede ser ingresado correctamente.
 */
int answerYesOrNo(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		*caracter = toupper(*caracter);
		while(*caracter != 'S' && *caracter != 'N') {
			printf("Error. Reingrese.\n");
			printf("%s", mensaje);
			fflush(stdin);
			*caracter = getchar();
			*caracter = toupper(*caracter);
		}
		retorno = 0;
	}

	return retorno;
}
/**
 * @fn int verifyConfirmation(char*)
 * @brief Verifica que el usuario quiera proceder con el alta/baja/modificacion
 *
 * @param mensaje char* -- Mensaje que informa al usuario sobre lo que esta confirmando, junto a sus opciones
 * @return int retorno -- 0 si el usuario acepta. -1 si el usuario se niega.
 */
int verifyConfirmation(char* mensaje){
	int retorno = -1;
	char respuesta;
	answerYesOrNo(&respuesta, mensaje);
	if(respuesta == 'S')
	{
		retorno = 0;
	}
	return retorno;
}
/**
 * @fn int isValidNumber(char*, int)
 * @brief Valida que la cadena este compuesta solo por numeros
 *
 * @param cadena char* -- La cadena ingresada.
 * @param length int -- El tamaño de la cadena.
 * @return int retorno -- -1 si hay un error previo a la validacion.
 *                     	   0 si encuentra algo que no sea un numero o '\0'.
 *                         1 si no encuentra nada que no sea un numero.
 *
 */
int isValidNumber(char*cadena,int length){
	int retorno =-1;
	int i;
	if(cadena != NULL && length > -1){
		retorno = 1;
		for(i=0;i<length && cadena[i] != '\0';i++){
			if(cadena[i] > '9' || cadena[i] < '0'){
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * @fn int isValidName(char*, int)
 * @brief Valida que la cadena este compuesta solo por letras
 *
 * @param cadena char* -- La cadena ingresada.
 * @param length int -- El tamaño de la cadena.
 * @return int retorno -- -1 si hay un error previo a la validacion.
 *                     	   0 si encuentra algo que no sea una letra/espacio/'\0'.
 *                         1 si no encuentra nada que no sea una letra.
 */
int isValidName(char*cadena,int length){
	int retorno =-1;
	int i;
	if(cadena != NULL && length > -1){
		retorno = 1;
		for(i=0;i<length && cadena[i] != '\0';i++){
			if(cadena[i] == ' '){
				continue;
			}
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] > 'ñ'))
			{
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}

