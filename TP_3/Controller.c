#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo dataTexto.csv
 *
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si encuentra el archivo. -1 si no lo encuentra.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* pFile;
	pFile = fopen(path, "r");
	if(pFile !=NULL){
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		pFile = NULL;
		retorno =0;
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo dataBinario.csv
 *
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si encuentra el archivo. -1 si no lo encuentra.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	FILE* pFile;
	pFile = fopen(path, "rb");
	if(pFile !=NULL){
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		pFile = NULL;
		retorno =0;
	}
	else{
		printf("El archivo no fue creado todavia.\n");
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si se confirma el alta del empleado. -1 si se cancela el alta o la lista apunta a NULL.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* pEmpleado;
	Employee* ultimoEmpleado;
	int* ultimoID = (int*)malloc(sizeof(int));
	char* auxID = (char*)malloc(sizeof(char)*10);
	char* auxNombre = (char*)malloc(sizeof(char)*25);
	char* auxHoras = (char*)malloc(sizeof(char)*8);
	char* auxSueldo = (char*)malloc(sizeof(char)*10);
	int length = ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL){
		//Id autoincremental
		if(ll_len(pArrayListEmployee) == 0){
			*ultimoID = 1;
		}
		else {
			ultimoEmpleado = ll_get(pArrayListEmployee, length-1);//Trae el ultimo empleado en la lista
			*ultimoID = (ultimoEmpleado->id)+1;
		}
    	// Datos
    	getString(auxNombre, "Ingrese nombre del empleado: ", "Error en el ingreso del nombre (no puede ser mayor a 25 caracteres). Reingrese el nombre: ", 21);
		while(!isValidName(auxNombre, 21)){
			printf("Error, se ingresaron caracteres no validos para el nombre.\n");
			getString(auxNombre, "Reingrese el nombre del empleado: ","Error en el ingreso del nombre (no puede ser mayor a 25 caracteres). Reingrese el nombre: " , 21);
		}
		getString(auxHoras, "Ingrese las horas trabajadas del empleado: ", "Error. Reingresar horas trabajadas: ", 7);
		while(!isValidNumber(auxHoras, 7)){
			printf("Error, se ingresaron caracteres no validos para las horas trabajadas .\n");
			getString(auxHoras, "Reingrese las horas trabajadas del empleado: ","Error en el ingreso de las horas trabajadas. Reingrese: " , 7);

		}
		getString(auxSueldo, "Ingrese el sueldo del empleado: ", "Error en el ingreso del sueldo (no puede ser mayor a 8 cifras). Reingresar: ", 8);
		while(!isValidNumber(auxSueldo, 8)){
			printf("Error, se ingresaron caracteres no validos para el sueldo.\n");
			getString(auxSueldo, "Reingrese el sueldo del empleado: ","Error en el ingreso del sueldo (no puede ser mayor a 8 cifras). Reingrese: " , 8);
		}
		itoa(*ultimoID,auxID,10);
		pEmpleado = employee_newParametros(auxID, auxNombre, auxHoras, auxSueldo);
		printf("Empleado a agregar:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
		printf("%-10d %-21s %-10d %-10d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);

		//Confirmacion
		if(!verifyConfirmation("Agregar empleado? S para confirmar, N para regresar: ")){
			ll_add(pArrayListEmployee, pEmpleado);
			printf("Empleado %s agregado correctamente\n",pEmpleado->nombre);
			retorno =0;
		}
		else{
			printf("Se cancelo el alta del empleado\n");
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si encuentra al empleado con el ID ingresado y puede acceder al sub menu de modificaciones.
 * 				      -1 si no lo encuentra o la lista apunta a NULL.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
    Employee* empleado;
	int* idAModificar = (int*)malloc(sizeof(int));
	int banderaEncontrado = 0;
	if(pArrayListEmployee!=NULL){
		controller_ListEmployee(pArrayListEmployee);
		*idAModificar = getInteger("Ingrese el ID del empleado a modificar: ", "Error. ID invalido, reingresar.", 0, 10000);
		for(int i =0;i<ll_len(pArrayListEmployee);i++){
			empleado = ll_get(pArrayListEmployee, i);
			if(*idAModificar == empleado->id){
				employee_operateModificationsSubMenu(empleado);
				banderaEncontrado =1;
				retorno =0;
				break;
			}
		}
		if(banderaEncontrado == 0){
			printf("Empleado no encontrado\n");
			system("pause");
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si se confirma la baja. -1 si no lo encuentra, se cancela la baja o la lista apunta a NULL.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* empleado;
	int* idAEliminar = (int*)malloc(sizeof(int));
	int banderaEncontrado = 0;
	int index;
	if(pArrayListEmployee!=NULL){
		controller_ListEmployee(pArrayListEmployee);
		*idAEliminar = getInteger("Ingrese el ID del empleado a eliminar: ", "Error. ID invalido, reingresar.", 0, 10000);
		for(int i =0;i<ll_len(pArrayListEmployee);i++){
			empleado = ll_get(pArrayListEmployee, i);
			if(*idAEliminar == empleado->id){
				banderaEncontrado = 1;
				index = ll_indexOf(pArrayListEmployee, empleado);
				printf("Empleado a eliminar:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
				if(!verifyConfirmation("Eliminar empleado? S para confirmar, N para regresar: ")){
					ll_remove(pArrayListEmployee, index);
					printf("Empleado %s eliminado con exito\n",empleado->nombre);
					retorno =0;
				}
				else{
					printf("Se cancelo la baja del empleado\n");
				}
				break;
			}
		}
		if(banderaEncontrado == 0){
			printf("Empleado no encontrado\n");
		}
	}
    return retorno;
}

/** \brief Muestra la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si puede mostrar el listado. -1 si la lista apunta a NULL.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* pEmpleado;
	if(pArrayListEmployee!=NULL){
		printf("%-10s %-21s %-10s %-10s\n","ID","Nombre","Horas","Sueldo");
		for(int i=0;i<ll_len(pArrayListEmployee);i++){
			pEmpleado = ll_get(pArrayListEmployee, i);
			printf("%-10d %-21s %-10d %-10d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordena la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si puede ordenar el listado. -1 si la lista apunta a NULL.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	int (*pEmpleadoSort) (void*,void*);
	int opcion;
	if(pArrayListEmployee!=NULL){
		opcion = getInteger("1.ID Ascendente\n"
							"2.ID Descendente\n"
							"3.Nombre Ascendente\n"
							"4.Nombre Descendente\n"
							"5.Horas Ascendente\n"
							"6.Horas Descendente\n"
							"7.Salario Ascendente\n"
							"8.Salario Descendente\n"
							"Seleccione un criterio de ordenamiento: ", "Error. Ingrese una de las 8 opciones", 1, 8);
		printf("Se ordenaran los empleados. Si hay muchos empleados cargados puede tardar unos segundos\n");
		system("pause");
		switch(opcion){
		case 1:
			pEmpleadoSort=employee_sortById;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 1);
			break;
		case 2:
			pEmpleadoSort=employee_sortById;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 0);
			break;
		case 3:
			pEmpleadoSort=employee_sortByName;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 1);
			break;
		case 4:
			pEmpleadoSort=employee_sortByName;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 0);
			break;
		case 5:
			pEmpleadoSort=employee_sortByHours;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 1);
			break;
		case 6:
			pEmpleadoSort=employee_sortByHours;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 0);
			break;
		case 7:
			pEmpleadoSort = employee_sortBySalary;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 1);
			break;
		case 8:
			pEmpleadoSort = employee_sortBySalary;
			ll_sort(pArrayListEmployee, pEmpleadoSort, 0);
			break;
		}
		retorno=0;
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo dataTexto.csv
 *
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si encuentra el archivo. -1 si no lo encuentra.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* pEmpleado;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee!=NULL){
		pFile = fopen(path,"w");
		if(pFile!=NULL){
			for(int i=0;i<ll_len(pArrayListEmployee);i++){
				/*if(i==0){
					fprintf(pFile,"%s,%s,%s,%s\n","ID","Nombre","Horas Trabajadas","Sueldo");//Cabecera. Da error al abrir archivo con excel, no con bloc de notas o wordpad.
																							//Por las dudas lo comento pero al cargar los datos nuevamente se va a saltear la primera linea ya que no hay cabecera para el fscanf
																							//Si se descomenta funciona bien pero excel no abre el archivo
				}*/
				pEmpleado = ll_get(pArrayListEmployee, i);
				fprintf(pFile,"%d,%s,%d,%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);//Datos
			}
			printf("Empleados cargados en %s con exito\n",path);
			fclose(pFile);
			pFile = NULL;
			retorno =0;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo dataBinario.csv
 *
 * \param path char* La direccion del archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return retorno int 0 si encuentra el archivo. -1 si no lo encuentra.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno =-1;
	Employee* pEmpleado;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee!=NULL){
		pFile = fopen(path,"wb");
		if(pFile!=NULL){
			for(int i=0;i<ll_len(pArrayListEmployee);i++){
				pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(pEmpleado,sizeof(Employee),1,pFile);
			}
			printf("Empleados cargados en %s con exito\n",path);
			fclose(pFile);
			pFile = NULL;
			retorno =0;
		}
	}
    return retorno;
}

