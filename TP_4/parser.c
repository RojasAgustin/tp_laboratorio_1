#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si puede añadir del archivo a la lista con exito. -1 hay un error.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	char* nombre = (char*)malloc(sizeof(char)*25);
	char* id = (char*)malloc(sizeof(char)*10);
	char* horas = (char*)malloc(sizeof(char)*10);
	char* sueldo = (char*)malloc(sizeof(char)*10);
	if(pArrayListEmployee != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horas,sueldo);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horas,sueldo);
			if(feof(pFile)){
				break;
			}
			Employee* unEmpleado = employee_newParametros(id, nombre, horas, sueldo);
			 if(unEmpleado != NULL){
				 ll_add(pArrayListEmployee, unEmpleado);
				 retorno=0;
			 }
		}
		fclose(pFile);
		if(retorno ==0){
			printf("Empleados agregados con exito.\n");
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si puede añadir del archivo a la lista con exito. -1 hay un error.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* pEmpleado = NULL;
	if(pArrayListEmployee != NULL){
		while(!feof(pFile)){
			pEmpleado = employee_new();
			fread(pEmpleado, sizeof(Employee), 1, pFile);
			if(feof(pFile)){
				break;
			}
			ll_add(pArrayListEmployee, pEmpleado);
		}
		retorno =0;
		fclose(pFile);
		printf("Empleados agregados con exito.\n");

	}
    return retorno;
}
