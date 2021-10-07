/*
 * funcioneEmployees.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Usuario
 */

#include "ArrayEmployees.h"
int initEmployees(Employee* lista,int length){
	int retorno;
	int i;
	retorno =-1;
	if(lista != NULL && length > -1) {
		for(i=0;i<length;i++){
			lista[i].isEmpty = 1;
			retorno =0;
		}
	}
	return retorno;
}
int addEmployees(Employee* lista,int length,int id, char name[],char lastName[],float salary,int sector){
	int retorno;
	int index;
	retorno =-1;
	if(lista != NULL && length > -1) {
		index = findEmptyArrayPosition(lista, length);
		if(index != -1) {
			lista[index].id = id;
			strcpy(lista[index].name,name);
			strcpy(lista[index].lastName,lastName);
			lista[index].salary = salary;
			lista[index].sector = sector;
			printf("\nEmpleado a agregar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
			if(!verifyConfirmation("Cargar Empleado? S para confirmar, N para regresar: ")){
				lista[index].isEmpty = 0;
				printf("\nEmpleado %s %s cargado correctamente.\n", lista[index].lastName, lista[index].name);
				retorno = 0;
			}
			else {
				printf("Se cancelo la carga del empleado.\n");
			}
		}
	}
	return retorno;
}
int removeEmployee(Employee* lista, int length, int id){
	int retorno;
	int index;
	retorno =-1;
	if(lista != NULL && length > -1){
		index = findEmployeeById(lista, length, id);
		if(index != -1){
			printf("Empleado a eliminar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary,lista[index].sector);
			if(!verifyConfirmation("Ingrese S para confirmar la baja del empleado, N para regresar: "))
			{
				lista[index].isEmpty = 1;
				printf("\nEmpleado %s %s dado de baja correctamente.\n", lista[index].lastName, lista[index].name);
				retorno = 0;
			}
			else
			{
				printf("\nSe cancelo la baja del empleado.\n");
			}
		}
		else{
			printf("\nError. Empleado no encontrado...\n");
		}
	}
	return retorno;
}
int findEmployeeById(Employee* lista, int length,int id){
	int i;
	int index = -1;
	if(lista != NULL && length > -1) {
		for(i=0; i<length; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int findEmptyArrayPosition(Employee* lista, int length)
{
	int i;
	int index = -1;
	if(lista != NULL && length > -1)
	{
		for(i=0; i<length; i++)
		{
			if(lista[i].isEmpty == 1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int printEmployees(Employee* lista,int length) {
	int i;
	int retorno =-1;
	if(lista != NULL && length > -1) {
		printf("Mostrando lista de empleados\n"
			   "%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
		for(i=0;i<length;i++){
			if(lista[i].isEmpty == 0){
				printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[i].id, lista[i].name, lista[i].lastName, lista[i].salary, lista[i].sector);
			}
		}
	retorno =0;
	}
	return retorno;
}
int sortEmployees (Employee* lista, int length, int order){
	int retorno =-1;
	int i;
	int flagSwap;
	int nuevoLimite;
	nuevoLimite = length-1;
	Employee auxEmpleado;
	if(lista != NULL && length > -1) {
		do{
			flagSwap =0;
			for(i=0;i<nuevoLimite;i++){
				if(lista[i].isEmpty == 0 && lista[i+1].isEmpty == 0 && lista[i].sector > lista[i+1].sector){
					auxEmpleado = lista[i];
					lista[i] = lista[i+1];
					lista[i+1] = auxEmpleado;
					flagSwap = 1;
				}
				else
				{
					if(lista[i].isEmpty == 0 && lista[i+1].isEmpty == 0 && lista[i].sector==lista[i+1].sector){
						if(order == 1){
							if(lista[i].isEmpty == 0 && lista[i+1].isEmpty == 0 && strcmp(lista[i].lastName,lista[i+1].lastName) == 1){
								auxEmpleado = lista[i];
								lista[i] = lista[i+1];
								lista[i+1] = auxEmpleado;
								flagSwap = 1;

							}
						}
						else{
							if(order ==-0){
								if(lista[i].isEmpty == 0 && lista[i+1].isEmpty == 0 && strcmp(lista[i].lastName,lista[i+1].lastName) == -1)
								{
									auxEmpleado = lista[i];
									lista[i] = lista[i+1];
									lista[i+1] = auxEmpleado;
									flagSwap = 1;

								}
							}
						}
					}
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno =0;

	}
	return retorno;
}
int calculateSalarySumsAndAverages(Employee* lista,int length){
	int i;
	int retorno =-1;
	float promedio;
	float totalSalarios =0;
	int contadorEmpleados =0;
	int contadorEmpleadosArribaDelPromedio =0;
	if(lista != NULL && length > -1){
		for(i=0;i<length;i++){
			if(lista[i].isEmpty == 0){
				totalSalarios += lista[i].salary;
				contadorEmpleados++;
			}
		}
		promedio = totalSalarios / contadorEmpleados;
		for(i=0;i<length;i++){
			if(lista[i].isEmpty == 0){
				if(lista[i].salary > promedio){
					contadorEmpleadosArribaDelPromedio++;
				}
			}
		}
		printf("\nTotal de los salarios: $%.2f\n"
				"Promedio de los salarios: $%.2f\n"
				"Cantidad de empleados con salario mayor al promedio: %d\n",totalSalarios,promedio,
				                                                            contadorEmpleadosArribaDelPromedio);
		retorno=0;
	}
	return retorno;
}
int operateMainMenu(Employee*lista,int length){
	int retorno =-1;
	int opcionElegida;
	int cantidadDeEmpleados =0;
	int idCarga = 1;
	char salarioCarga[7];
	float salarioCargado;
	char nombreCarga[51];
	char apellidoCarga[51];
	int sectorCarga;
	int idBaja;

	if(lista != NULL && length > -1) {
		do
		{
			opcionElegida = getInteger("------------------------\n"
												"1-Altas\n"
												"2-Modificar\n"
												"3-Bajas\n"
												"4-Informar\n"
												"5-Salir\n"
												"Elija una opcion: ", "Error. Ingrese una opcion entre 1 y 5", 1, 5);
			switch(opcionElegida)
			{
			case 1:
				if(cantidadDeEmpleados < TAM) {
					printf("Cargar Empleado\n");
					//Carga nombre
					getString(nombreCarga, "Ingrese el nombre del empleado: ","Error en el ingreso del nombre (no puede ser mayor a 51 caracteres). Reingrese el nombre: " , 51);
					while(!isValidName(nombreCarga, 51)){
						printf("Error, se ingresaron caracteres no validos para el nombre.\n");
						getString(nombreCarga, "Reingrese el nombre del empleado: ","Error en el ingreso del nombre (no puede ser mayor a 51 caracteres). Reingrese el nombre: " , 51);
					}
					//Carga apellido
					getString(apellidoCarga, "Ingrese el apellido del empleado: ","Error en el ingreso del apellido (no puede ser mayor a 51 caracteres). Reingrese el apellido: " , 51);
					while(!isValidName(apellidoCarga, 51)){
						printf("Error, se ingresaron caracteres no validos para el apellido.\n");
						getString(apellidoCarga, "Reingrese el apellido del empleado: ","Error en el ingreso del apellido (no puede ser mayor a 51 caracteres). Reingrese el apellido: " , 51);
					}
					//Carga salario
					getString(salarioCarga, "Ingrese el salario del empleado: ","Error en el ingreso del salario (no puede ser negativo o mayor a 500000). Reingrese el salario: " , 7);
					while(!isValidSalary(salarioCarga, 7)){
						printf("Error, se ingresaron caracteres no validos para el salario.\n");
						getString(salarioCarga, "Reingrese el salario del empleado: ","Error en el ingreso del salario (no puede ser negativo o mayor a 500000). Reingrese el salario: " , 7);
					}
					salarioCargado = atof(salarioCarga);
					while(salarioCargado > 500000){
						printf("Error, no debe ser mayor a $500000\n");
						getString(salarioCarga, "Ingrese el salario del empleado: ","Error en el ingreso del salario (no puede ser negativo o mayor a 500000). Reingrese el salario: " , 7);
						while(!isValidSalary(salarioCarga, 7)){
							printf("Error, se ingresaron caracteres no validos para el salario.\n");
							getString(salarioCarga, "Ingrese el salario del empleado: ","Error en el ingreso del salario (no puede ser negativo o mayor a 500000). Reingrese el salario: " , 7);
						}
						salarioCargado = atof(salarioCarga);
					}
					//Carga sector
					sectorCarga = getInteger("Ingrese el sector del empleado: ", "Error en el ingreso del sector (debe estar entre 1 y 12)", 1, 12);

					if(!addEmployees(lista, length, idCarga, nombreCarga, apellidoCarga, salarioCargado, sectorCarga)){
						cantidadDeEmpleados++;
						idCarga++;
					}
					system("pause");
				}
				else {
					printf("No hay espacio disponible para agregar mas empleados.\n");
				}
				break;
			case 2:
				if(cantidadDeEmpleados > 0) {
					operateModificationsSubMenu(lista, length);
				}
				else {
					printf("No hay empleados en el listado\n");
				}
				break;
			case 3:
				if(cantidadDeEmpleados > 0) {
					printEmployees(lista, length);
					idBaja = getInteger("Ingrese ID del empleado a bajar.\n", "Error, el ID ingresado no es valido.", 1, 1000);
					if(!removeEmployee(lista, length, idBaja)){
						cantidadDeEmpleados--;
					}
					system("pause");
				}
				else {
					printf("No hay empleados en el listado\n");
				}
				break;
			case 4:
				if(cantidadDeEmpleados > 0){
					operateInfoSubMenu(lista, length);
				}
				else {
					printf("No hay empleados en el listado\n");
				}
				break;
			case 5:
				printf("Saliendo del programa\n");

				break;
			default:
				printf("Error en el programa. Reingrese una opcion\n");
				break;
			}
		}while(opcionElegida != 5);
		retorno =0;
	}
	else {
		printf("Error con la lista. Longitud invalida o array vacio");
	}
	return retorno;
}
int operateInfoSubMenu(Employee*lista,int length){
	int retorno =-1;
	int opcionElegida;
	int ordenInformar;
	if(lista != NULL && length > -1) {
		do{
			opcionElegida = getInteger("------------------------\n"
													"1-Listado de empleados\n"
													"2-Salarios y promedios\n"
													"3-Salir\n"
													"Elija una opcion: ", "Error. Ingrese una opcion entre 1 y 3", 1, 3);
			switch(opcionElegida) {
			case 1:
				ordenInformar = setSortingOrder("Ingrese el orden. 1 para ascendente -- 0 para descendente: ");
				sortEmployees(lista, length, ordenInformar);
				printEmployees(lista, length);
				system("pause");
				break;
			case 2:
				calculateSalarySumsAndAverages(lista, length);
				system("pause");
				break;
			case 3:
				break;
			default:
				printf("Error en el programa. Reingrese una opcion\n");
				break;
			}

		}while(opcionElegida !=3);
		retorno =0;
	}
	return retorno;
}
int operateModificationsSubMenu(Employee*lista,int length) {
	int opcionElegida;
	int retorno =-1;
	int index;
	int idAModificar;
	Employee auxEmpleado;
	if(lista != NULL && length > -1) {
		printEmployees(lista, length);
		idAModificar = getInteger("Ingrese ID del empleado a modificar(0-1000): ","Error en el ingreso del ID. Reintentar." , 1, 1000);
		index = findEmployeeById(lista, length, idAModificar);
		if(index != -1){
			printf("Empleado a modificar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
			do{
				auxEmpleado = lista[index];
				opcionElegida = getInteger("------------------------\n"
													"1-Modificar Nombre\n"
													"2-Modificar Apellido\n"
													"3-Modificar Salario\n"
													"4-Modificar Sector\n"
													"5-Salir\n"
													"Elija una opcion: ","Error. Ingrese una opcion entre 1 y 5", 1, 5);
				switch(opcionElegida){
				case 1:
					printf("Empleado a modificar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
					getString(auxEmpleado.name, "Ingrese el nombre del empleado: ", "Error. El nombre no debe ser mayor a 51 caracteres", 51);
					while(!isValidName(auxEmpleado.name, 51)){
						printf("Error, se ingresaron caracteres no validos para el nombre.\n");
						getString(auxEmpleado.name, "Reingrese el nombre del empleado: ","Error en el ingreso del nombre (no puede ser mayor a 51 caracteres). Reingrese el nombre: " , 51);
					}
					printf("\nEmpleado luego de la modificacion:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", auxEmpleado.id, auxEmpleado.name, auxEmpleado.lastName, auxEmpleado.salary, auxEmpleado.sector);
					if(!verifyConfirmation("Modificar Nombre? S para confirmar, N para regresar: ")){
						strcpy(lista[index].name,auxEmpleado.name);
						printf("\nEmpleado %s %s modificado correctamente\n",lista[index].lastName,lista[index].name);

					}
					else{
						printf("Se cancelo la modificacion del empleado\n");
					}
					system("pause");
					break;
				case 2:
					printf("Empleado a modificar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
					getString(auxEmpleado.lastName, "Ingrese el apellido del empleado: ", "Error. El apellido no debe ser mayor a 51 caracteres", 51);
					while(!isValidName(auxEmpleado.lastName, 51)){
						printf("Error, se ingresaron caracteres no validos para el apellido.\n");
						getString(auxEmpleado.lastName, "Reingrese el apellido del empleado: ","Error en el ingreso del apellido (no puede ser mayor a 51 caracteres). Reingrese el apellido: " , 51);
					}
					printf("\nEmpleado luego de la modificacion:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", auxEmpleado.id, auxEmpleado.name, auxEmpleado.lastName, auxEmpleado.salary, auxEmpleado.sector);
					if(!verifyConfirmation("Modificar Apellido? S para confirmar, N para regresar: ")){
						strcpy(lista[index].lastName,auxEmpleado.lastName);
						printf("\nEmpleado %s %s modificado correctamente\n",lista[index].lastName,lista[index].name);

					}
					else{
						printf("Se cancelo la modificacion del empleado\n");
					}
					system("pause");
					break;
				case 3:
					printf("Empleado a modificar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
					auxEmpleado.salary = getFloat("Ingrese el salario del empleado: ", "Error en el ingreso del salario (no puede ser negativo o mayor a 500000)", 0, 500000);

					printf("\nEmpleado luego de la modificacion:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", auxEmpleado.id, auxEmpleado.name, auxEmpleado.lastName, auxEmpleado.salary, auxEmpleado.sector);
					if(!verifyConfirmation("Modificar Salario? S para confirmar, N para regresar: ")){
						lista[index].salary = auxEmpleado.salary;
						printf("\nEmpleado %s %s modificado correctamente\n",lista[index].lastName,lista[index].name);

					}
					else{
						printf("Se cancelo la modificacion del empleado\n");
					}
					system("pause");
					break;
				case 4:
					printf("Empleado a modificar:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", lista[index].id, lista[index].name, lista[index].lastName, lista[index].salary, lista[index].sector);
					auxEmpleado.sector = getInteger("Ingrese el sector del empleado: ", "Error en el ingreso del sector (debe estar entre 1 y 12)", 1, 12);

					printf("\nEmpleado luego de la modificacion:\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					printf("%-5d %-20s %-20s $%-20.2f %-20d\n", auxEmpleado.id, auxEmpleado.name, auxEmpleado.lastName, auxEmpleado.salary, auxEmpleado.sector);
					if(!verifyConfirmation("Modificar Sector? S para confirmar, N para regresar: ")){
						lista[index].sector = auxEmpleado.sector;
						printf("\nEmpleado %s %s modificado correctamente\n",lista[index].lastName,lista[index].name);

					}
					else{
						printf("Se cancelo la modificacion del empleado\n");
					}
					system("pause");

					break;
				case 5:
					break;
				default:
					printf("Error en el programa, reingrese una opcion.\n");
					break;

				}

			}while(opcionElegida != 5);
		}
		else {
			printf("Error, empleado no encontrado\n");
		}
		retorno = 0;
	}
	return retorno;
}
int setSortingOrder(char*mensaje){
	char auxOrden;
	int orden;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&auxOrden);
	while(auxOrden != '1' && auxOrden != '0'){
		printf("Error. Reingrese el orden\n");
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&auxOrden);
	}
	while(!isdigit(auxOrden)){
		printf("Error. Reingrese el orden\n");
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&auxOrden);
	}
	if(auxOrden == '1'){
		orden = 1;
	}
	else {
		if(auxOrden == '0'){
			orden = 0;
		}
	}
	return orden;
}
