/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones

Rojas Agustin DIV D
 */

#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	float numeroIngresadoUno;
	float numeroIngresadoDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	long int factorialUno;
	long int factorialDos;
	int opcionElegida;
	int banderaOperaciones;
	int banderaInicio;
	int banderaA;
	int banderaB;

	banderaOperaciones = 0;
	banderaInicio = 0;
	banderaA = 0;
	banderaB = 0;

	do
	{
		//Mostrar menu de opciones
		if(banderaInicio == 0)
		{
			opcionElegida = validarOpcion("Ingrese un operando\n1.Ingresar primer operando (A = x)\n2.Ingresar segundo operando (B = y)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n","Primero debe ingresar uno de los operandos", 1, 2);
			banderaInicio = 1;
		}
		else
		{
			if(banderaA == 1 && banderaB == 0)
			{
				printf("Elija una opcion\n1.Ingresar primer operando (A = %.3f)\n2.Ingresar segundo operando (B = y)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",numeroIngresadoUno);
				fflush(stdin);
				scanf("%d", &opcionElegida);
			}
			else
			{
				if(banderaA == 0 && banderaB == 1)
				{
					printf("Elija una opcion\n1.Ingresar primer operando (A = x)\n2.Ingresar segundo operando (B = %.3f)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",numeroIngresadoDos);
					fflush(stdin);
					scanf("%d", &opcionElegida);
				}
				else
				{
					printf("Elija una opcion\n1.Ingresar primer operando (A = %.3f)\n2.Ingresar segundo operando (B = %.3f)\n3.Calcular todas las operaciones\n4.Informar resultados\n5.Salir\n",numeroIngresadoUno,numeroIngresadoDos);
					fflush(stdin);
					scanf("%d", &opcionElegida);
				}
			}
		}

		switch(opcionElegida)
		{
		case 1:
			//Pedir numero entero A
			numeroIngresadoUno = ingresarNumero();
			banderaOperaciones = 0;
			banderaA = 1;
			break;
		case 2:
			//Pedir numero entero B
			numeroIngresadoDos = ingresarNumero();
			banderaOperaciones = 0;
			banderaB = 1;
			break;
		case 3:
			//Operaciones Matematicas
			if(banderaA == 0 || banderaB == 0)
			{
				printf("Aun no se han ingresado ambos numeros.\n");
			}
			else
			{
				resultadoSuma = sumar(numeroIngresadoUno,numeroIngresadoDos);
				resultadoResta = restar(numeroIngresadoUno,numeroIngresadoDos);
				resultadoDivision = dividir(numeroIngresadoUno,numeroIngresadoDos);
				resultadoMultiplicacion= multiplicar(numeroIngresadoUno,numeroIngresadoDos);
				//Sin el if, si se ingresan numeros positivos o negativos de siete digitos o mas, el programa se rompe
				if((numeroIngresadoUno > 0 && numeroIngresadoDos > 0)&&(numeroIngresadoUno < 12.9 && numeroIngresadoDos < 12.9))
				{
				factorialUno = calcularFactorial(numeroIngresadoUno);
				factorialDos = calcularFactorial(numeroIngresadoDos);
				}
				banderaOperaciones = 1;
				printf("Operaciones Realizadas.\n");
			}
			break;

		case 4:
			//Mostrar Resultados
			if(banderaOperaciones == 1)
			{
				printf("-------------------\n");
				//Suma
				printf("A)El resultado de %.3f + %.3f es igual a: %.3f\n", numeroIngresadoUno,numeroIngresadoDos,resultadoSuma);

				//Resta
				printf("B)El resultado de %.3f - %.3f es igual a: %.3f\n", numeroIngresadoUno,numeroIngresadoDos,resultadoResta);

				//Division
				if(numeroIngresadoDos != 0)
				{
					printf("C)El resultado de %.3f / %.3f es igual a: %.3f\n", numeroIngresadoUno,numeroIngresadoDos,resultadoDivision);
				}
				else
				{
					printf("C)No se puede dividir por cero\n");
				}

				//Multiplicacion
				printf("D)El resultado de %.3f * %.3f es igual a: %.3f\n", numeroIngresadoUno,numeroIngresadoDos,resultadoMultiplicacion);

				//Factoriales
				if(numeroIngresadoUno < 0 || numeroIngresadoDos < 0)
				{
					printf("E)No se puede calcular el factorial de un numero menor a 0\n");
				}
				else
				{
					if(numeroIngresadoUno > 12.9 || numeroIngresadoDos > 12.9)
					{
						printf("E)El programa no puede calcular factoriales mayores a 12\n");
					}
					else
					{
						printf("E)El factorial de %d es: %ld -- El factorial de %d es: %ld\n",(int)numeroIngresadoUno,factorialUno,(int)numeroIngresadoDos,factorialDos);
					}
				}
				printf("-------------------\n");
			}
			else
			{
				printf("Aun no se han realizado las operaciones.\n");
			}
			break;

		case 5:
			//Salir
			printf("Fin del programa\n");
			break;

		default:
			//Si no se ingresa un numero del uno al cinco
			printf("\nTiene que elegir una de las cinco opciones\n");
			break;
		}
		if (opcionElegida < 5)
		{
			//Pausa y limpia consola
			system("pause");
			printf("\n\n\n\n\n\n\n\n");
		}
	}while(opcionElegida != 5);
	return EXIT_SUCCESS;
	}


