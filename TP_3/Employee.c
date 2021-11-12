#include "Employee.h"

/**
 * @fn Employee employee_new*()
 * @brief Crea espacio para un puntero a Employee y lo devuelve
 *
 * @return empleadoRetorno Employee* El puntero a Employee
 */
Employee* employee_new(){
	Employee* empleadoRetorno = NULL;
	empleadoRetorno = (Employee*)malloc(sizeof(Employee));
	return empleadoRetorno;
}
/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Crea un puntero a Employee, guarda los parametros en el y lo devuelve
 *
 * @param idStr char* el ID del empleado
 * @param nombreStr char* el nombre del empleado
 * @param horasTrabajadasStr char* las horas trabajadas del empleado
 * @param sueldoStr char* el sueldo del empleado
 * @return empleado Employee* El puntero a Employee
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* empleado = NULL;
	if(idStr!=NULL && nombreStr != NULL && horasTrabajadasStr !=NULL && sueldoStr != NULL){
		empleado = employee_new();
		if(empleado !=NULL){
			employee_setId(empleado,atoi(idStr));
			employee_setNombre(empleado, nombreStr);
			employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
			employee_setSueldo(empleado, atoi(sueldoStr));
		}
	}
	return empleado;
}
/**
 * @fn void employee_delete(Employee*)
 * @brief Borra el espacio de memoria asignado al empleado
 *
 * @param this Employee* El puntero al empleado
 */
void employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
		this = NULL;
	}
}
/**
 * @fn int employee_setId(Employee*, int)
 * @brief Guarda el valor del parametro id en el campo id del puntero a empleado
 *
 * @param this Employee* el puntero al empleado
 * @param id int el ID a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int employee_setId(Employee* this,int id){
	int retorno =-1;
	if(this != NULL && id > -1){
		this->id = id;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Guarda el valor del parametro nombre en el campo nombre del puntero a empleado
 *
 * @param this Employee* el puntero al empleado
 * @param nombre char* el nombre a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Guarda el valor del parametro horasTrabajadas en el campo horasTrabajadas del puntero a empleado
 *
 * @param this Employee* el puntero al empleado
 * @param horasTrabajadas int el dato a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno =-1;
	if(this != NULL && horasTrabajadas > -1){
		this->horasTrabajadas = horasTrabajadas;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Guarda el valor del parametro sueldo en el campo sueldo del puntero a empleado
 *
 * @param this Employee* el puntero al empleado
 * @param sueldo int el sueldo a cargar
 * @return retorno int 0 si lo puede cargar.-1 si hay un error
 */
int employee_setSueldo(Employee* this,int sueldo){
	int retorno =-1;
	if(this != NULL && sueldo > -1){
		this->sueldo = sueldo;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Guarda el valor del campo id en el puntero que recibe como parametro
 *
 * @param this Employee* el puntero al empleado
 * @param id int* donde se guarda el dato
 * @return retorno int 0 si puede asignar el dato.-1 si hay un error
 */
int employee_getId(Employee* this,int* id){
	int retorno =-1;
	if(this != NULL && id != NULL )
	{
		*id = this->id;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Guarda el valor del campo nombre en el puntero que recibe como parametro
 *
 * @param this Employee* el puntero al empleado
 * @param nombre char* donde se guarda el dato
 * @return retorno int 0 si puede asignar el dato.-1 si hay un error
 */
int employee_getNombre(Employee* this,char* nombre){
	int retorno =-1;
	if(this != NULL && nombre != NULL )
	{
		strcpy(nombre,this->nombre);
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Guarda el valor del campo horasTrabajadas en el puntero que recibe como parametro
 *
 * @param this Employee* el puntero al empleado
 * @param horasTrabajadas int* donde se guarda el dato
 * @return retorno int 0 si puede asignar el dato.-1 si hay un error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno =-1;
	if(this != NULL && horasTrabajadas != NULL )
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Guarda el valor del campo sueldo en el puntero que recibe como parametro
 *
 * @param this Employee* el puntero al empleado
 * @param sueldo int* donde se guarda el dato
 * @return retorno int 0 si puede asignar el dato.-1 si hay un error
 */
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno =-1;
	if(this != NULL && sueldo != NULL )
	{
		*sueldo = this->sueldo;
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_operateModificationsSubMenu(Employee*)
 * @brief Abre y permite trabajar con el sub menu para las modificaciones
 *
 * @param this Employee* el puntero al empleado
 * @return retorno int 0 si puede abrir el menu. -1 si hay un error.
 */
int employee_operateModificationsSubMenu(Employee* this){
	int retorno =-1;
	int* opcion = (int*)malloc(sizeof(int));
	char* auxHoras = (char*)malloc(sizeof(char)*10);
	char* auxSueldo = (char*)malloc(sizeof(char)*10);
	Employee auxEmpleado;
	if(this != NULL){
		printf("Empleado a modificar:\n%-10s %-21s %-10s %-10s\n","ID","Nombre","Horas","Sueldo");
		printf("%-10d %-21s %-10d %-10d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
		do{
			auxEmpleado = *this;
			*opcion = getInteger("------------------------\n"
							    "1-Modificar Nombre\n"
							    "2-Modificar Horas\n"
							    "3-Modificar Sueldo\n"
							    "4-Salir\n"
							    "Elija una opcion: ","Error. Ingrese una opcion entre 1 y 4", 1, 4);
			switch(*opcion){
			case 1:
				printf("Empleado a modificar:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d%-21s %-10d %-10d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
				getString(auxEmpleado.nombre, "Ingrese el nombre del empleado: ", "Error. El nombre no debe ser mayor a 25 caracteres: ", 21);
				while(!isValidName(auxEmpleado.nombre, 21)){
					printf("Error, se ingresaron caracteres no validos para el nombre.\n");
					getString(auxEmpleado.nombre, "Reingrese el nombre del empleado: ","Error en el ingreso del nombre (no puede ser mayor a 25 caracteres). Reingrese el nombre: " , 21);
				}
				printf("Empleado luego de la modificacion:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",auxEmpleado.id,auxEmpleado.nombre,auxEmpleado.horasTrabajadas,auxEmpleado.sueldo);
				if(!verifyConfirmation("Modificar Nombre? S para confirmar, N para regresar: ")){
					strcpy(this->nombre,auxEmpleado.nombre);
					printf("Empleado %s modificado correctamente\n",this->nombre);
				}
				else{
					printf("Se cancelo la modificacion del empleado\n");
				}
				system("pause");
				break;
			case 2:
				printf("Empleado a modificar:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
				getString(auxHoras, "Ingrese las horas trabajadas del empleado: ", "Error. Reingresar horas trabajadas: ", 7);
				while(!isValidNumber(auxHoras, 7)){
					printf("Error, se ingresaron caracteres no validos para las horas trabajadas .\n");
					getString(auxHoras, "Reingrese las horas trabajadas del empleado: ","Error en el ingreso de las horas trabajadas. Reingrese: " , 7);
				}
				auxEmpleado.horasTrabajadas = atoi(auxHoras);
				printf("Empleado luego de la modificacion:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",auxEmpleado.id,auxEmpleado.nombre,auxEmpleado.horasTrabajadas,auxEmpleado.sueldo);
				if(!verifyConfirmation("Modificar Horas Trabajadas? S para confirmar, N para regresar: ")){
					this->horasTrabajadas = auxEmpleado.horasTrabajadas;
					printf("Empleado %s modificado correctamente\n",this->nombre);
				}
				else{
					printf("Se cancelo la modificacion del empleado\n");
				}
				system("pause");
				break;
			case 3:
				printf("Empleado a modificar:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
				getString(auxSueldo, "Ingrese el sueldo del empleado: ", "Error en el ingreso del sueldo (no puede ser mayor a 8 cifras). Reingresar: ", 8);
				while(!isValidNumber(auxSueldo, 8)){
					printf("Error, se ingresaron caracteres no validos para el sueldo.\n");
					getString(auxSueldo, "Reingrese el sueldo del empleado: ","Error en el ingreso del sueldo (no puede ser mayor a 8 cifras). Reingrese: " , 8);
				}
				auxEmpleado.sueldo = atoi(auxSueldo);
				printf("Empleado luego de la modificacion:\n%-10s %-21s %-10s %-10s\n", "ID", "Nombre", "Horas", "Sueldo");
				printf("%-10d %-21s %-10d %-10d\n",auxEmpleado.id,auxEmpleado.nombre,auxEmpleado.horasTrabajadas,auxEmpleado.sueldo);
				if(!verifyConfirmation("Modificar Sueldo? S para confirmar, N para regresar: ")){
					this->sueldo = auxEmpleado.sueldo;
					printf("Empleado %s modificado correctamente\n",this->nombre);
				}
				else{
					printf("Se cancelo la modificacion del empleado\n");
				}
				system("pause");
				break;
			case 4:
				break;
			}
		}while(*opcion != 4);
		employee_delete(&auxEmpleado);
		retorno =0;
	}
	return retorno;
}
/**
 * @fn int employee_sortById(void*, void*)
 * @brief Elige el criterio de ordenamiento id para la funcion ll_sort
 *
 * @param empleadoUno void* El primer empleado que se compara
 * @param empleadoDos void* El segundo empleado que se compara
 * @return retorno int
 */
int employee_sortById(void* empleadoUno,void* empleadoDos){
	int retorno =1;
	Employee* pEmpleadoUno;
	Employee* pEmpleadoDos;
	if(empleadoUno!=NULL && empleadoDos!=NULL){
		pEmpleadoUno = (Employee*)empleadoUno;
		pEmpleadoDos = (Employee*)empleadoDos;
		if(pEmpleadoUno->id < pEmpleadoDos->id){
			retorno =-1;
		}
		else{
			if(pEmpleadoUno->id == pEmpleadoDos->id){
				retorno =0;
			}
		}
		pEmpleadoUno = NULL;
		pEmpleadoDos = NULL;
	}
	return retorno;
}
/**
 * @fn int employee_sortByName(void*, void*)
 * @brief Elige el criterio de ordenamiento nombre para la funcion ll_sort
 *
 * @param empleadoUno void* El primer empleado que se compara
 * @param empleadoDos void* El segundo empleado que se compara
 * @return retorno int
 */
int employee_sortByName(void* empleadoUno,void* empleadoDos){
	int retorno =1;
	Employee* pEmpleadoUno;
	Employee* pEmpleadoDos;
	if(empleadoUno!=NULL && empleadoDos!=NULL){
		pEmpleadoUno = (Employee*)empleadoUno;
		pEmpleadoDos = (Employee*)empleadoDos;
		if(strcmp(pEmpleadoUno->nombre,pEmpleadoDos->nombre)==-1){
			retorno =-1;
		}
		else{
			if(strcmp(pEmpleadoUno->nombre,pEmpleadoDos->nombre)==0){
				retorno =0;
			}
		}
		pEmpleadoUno = NULL;
		pEmpleadoDos = NULL;
	}
	return retorno;
}
/**
 * @fn int employee_sortByHours(void*, void*)
 * @brief Elige el criterio de ordenamiento horasTrabajadas para la funcion ll_sort
 *
 * @param empleadoUno void* El primer empleado que se compara
 * @param empleadoDos void* El segundo empleado que se compara
 * @return retorno int
 */
int employee_sortByHours(void* empleadoUno,void* empleadoDos){
	int retorno =1;
	Employee* pEmpleadoUno;
	Employee* pEmpleadoDos;
	if(empleadoUno!=NULL && empleadoDos!=NULL){
		pEmpleadoUno = (Employee*)empleadoUno;
		pEmpleadoDos = (Employee*)empleadoDos;
		if(pEmpleadoUno->horasTrabajadas < pEmpleadoDos->horasTrabajadas){
			retorno =-1;
		}
		else{
			if(pEmpleadoUno->horasTrabajadas == pEmpleadoDos->horasTrabajadas){
				retorno =0;
			}
		}
		pEmpleadoUno = NULL;
		pEmpleadoDos = NULL;
	}
	return retorno;
}
/**
 * @fn int employee_sortBySalary(void*, void*)
 * @brief Elige el criterio de ordenamiento Sueldo para la funcion ll_sort
 *
 * @param empleadoUno void* El primer empleado que se compara
 * @param empleadoDos void* El segundo empleado que se compara
 * @return retorno int
 */
int employee_sortBySalary(void* empleadoUno,void* empleadoDos){
	int retorno =1;
	Employee* pEmpleadoUno;
	Employee* pEmpleadoDos;
	if(empleadoUno!=NULL && empleadoDos!=NULL){
		pEmpleadoUno = (Employee*)empleadoUno;
		pEmpleadoDos = (Employee*)empleadoDos;
		if(pEmpleadoUno->sueldo < pEmpleadoDos->sueldo){
			retorno =-1;
		}
		else{
			if(pEmpleadoUno->sueldo == pEmpleadoDos->sueldo){
				retorno =0;
			}
		}
		pEmpleadoUno = NULL;
		pEmpleadoDos = NULL;
	}
	return retorno;
}
