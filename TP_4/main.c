#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int banderaCarga = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	option = getInteger("------------------------\n"
							"1-Cargar los datos de los empleados desde el archivo dataTexto.csv (modo texto)\n"
							"2-Cargar los datos de los empleados desde el archivo dataBinario.csv (modo binario)\n"
							"3-Alta de empleado\n"
							"4-Modificar datos de empleado\n"
							"5-Baja de empleado\n"
							"6-Listar empleados\n"
							"7-Ordenar empleados\n"
							"8-Guardar los datos de los empleados en el archivo dataTexto.csv (modo texto).\n"
							"9-Guardar los datos de los empleados en el archivo dataBinario.csv (modo binario).\n"
							"10-Salir\n"
							"Elija una opcion: ", "\nError. Ingrese una opcion entre 1 y 10", 1, 10);

        switch(option)
        {
            case 1:
            	if(banderaCarga == 0){
            		controller_loadFromText("dataTexto.csv",listaEmpleados);
            		banderaCarga = 1;
            	}
            	else{
            		printf("Ya se han cargado los datos\n");
            	}
            	system("pause");
                break;
            case 2:
            	if(banderaCarga == 0){
            		if(controller_loadFromBinary("dataBinario.csv", listaEmpleados)==0){
            			banderaCarga = 1;
            		}
            	}
            	else{
            		printf("Ya se han cargado los datos\n");
            	}
            	system("pause");
            	break;
            case 3:
            	if(ll_len(listaEmpleados) > 0){
            		controller_addEmployee(listaEmpleados);
            	}
            	else{
            		printf("Cargue los datos primero.\n");
            	}
            	system("pause");
            	break;
            case 4:
            	if(ll_len(listaEmpleados) > 0){
                	controller_editEmployee(listaEmpleados);
				}
				else{
					printf("Listado vacio.\n");
					system("pause");
				}
            	break;
            case 5:
            	if(ll_len(listaEmpleados) > 0){
                	controller_removeEmployee(listaEmpleados);
				}
				else{
					printf("Listado vacio.\n");
				}
            	system("pause");
            	break;
            case 6:
            	if(ll_len(listaEmpleados) > 0){
                	controller_ListEmployee(listaEmpleados);
				}
				else{
					printf("Listado vacio.\n");
				}
            	system("pause");
            	break;
            case 7:
            	if(ll_len(listaEmpleados) > 0){
            		if(controller_sortEmployee(listaEmpleados)==0){
            			printf("Empleados ordenados con exito.\n");
                    	system("pause");
            		}
            	}
            	else{
            		printf("Listado vacio.\n");
                	system("pause");
            	}
            	break;
            case 8:
            	if(ll_len(listaEmpleados) > 0){
            		controller_saveAsText("dataTexto.csv", listaEmpleados);
            	}
            	else{
            		printf("Listado Vacio.\n");
            	}
            	system("pause");
            	break;
            case 9:
            	if(ll_len(listaEmpleados) > 0){
                	controller_saveAsBinary("dataBinario.csv", listaEmpleados);
				}
				else{
					printf("Listado Vacio.\n");
				}
            	system("pause");
            	break;
            case 10:
            	ll_deleteLinkedList(listaEmpleados);
            	break;
        }
    }while(option != 10);
    return 0;
}

