/*
 * funciones.c
 *
 *  Created on: 3 sep. 2021
 *      Author: Usuario
 */


#include "funciones.h"
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
float getFloat(char* mensaje,char* mensajeError, float minimo,float maximo) {
	float numero;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);
	while(numero < minimo || numero > maximo) {
		printf("%s\n", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numero);
	}
	return numero;
}
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
int isValidSalary(char*cadena,int length){
	int retorno =-1;
	int i;
	if(cadena != NULL && length > -1){
		retorno = 1;
		for(i=0;i<length && cadena[i] != '\0' && cadena[i] != '.';i++){
			if(cadena[i] > '9' || cadena[i] < '0'){
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}
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
