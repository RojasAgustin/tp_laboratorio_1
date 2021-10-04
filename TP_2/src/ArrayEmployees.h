/*
 * funcioneEmployee.h
 *
 *  Created on: 22 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONEEmployee_H_
#define FUNCIONEEmployee_H_
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "string.h"
#include "ctype.h"
#define TAM 1000
typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;
/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all positions in the array are empty, this function sets the flag (isEmpty) to TRUE
 * 		  in all positions of the array
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if error (NULL array or invalid length). 0 if OK.
 */
int initEmployees(Employee* lista,int length);
/**
 * @fn int addEmployees(Employee*, int, int, char[], char[], float, int)
 * @brief add in an existing list of employees the values received as parameters
 *        in the first empty position
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @param id int -- Employee's ID
 * @param name char* -- Employee's name
 * @param lastName char* -- Employee's surname
 * @param salary float -- Employee's salary
 * @param sector int -- Employee's sector
 * @return retorno int -- -1 if error (NULL array or invalid length) or user cancels the upload.
 *                        0 if the upload is confirmed.
 */
int addEmployees(Employee* lista,int length,int id, char name[],char lastName[],float salary,int sector);
/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief finds an Employee by Id and returns the index position in array.
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @param id int -- Employee's ID
 * @return index int -- Returns employee's index position. -1 if there is an error (NULL array, invalid length or employee not found).
 */
int findEmployeeById(Employee* lista, int length,int id);
/**
 * @fn int findEmptyArrayPosition(Employee*, int)
 * @brief Finds the first empty position in the array and returns it
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return index int -- The first empty index found. -1 if there is an error(NULL array, invalid length
 * 						or no empty positions found)
 */
int findEmptyArrayPosition(Employee* lista, int length);
/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove a Employee by Id (by setting isEmpty Flag to 1)
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @param id int -- Employee's ID
 * @return retorno int -- -1 if there is an error(NULL array, invalid length), user cancels the removal
 *                        or the employee is not found (whether the array is full or not is verified in the menu,
 *                        so that the user does not complete every field only to be told that there is no space
 *                        available. 0 if the removal is confirmed.
 */
int removeEmployee(Employee* lista, int length, int id);
/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order
	      indicate UP or DOWN order
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @param order int --  1 indicates up/ascending, 0 indicates down/descending.
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int sortEmployees(Employee* lista, int length, int order);
/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int printEmployees(Employee* lista, int length);
/**
 * @fn int calculateSalarySumsAndAverages(Employee*, int)
 * @brief Calculates the sum of the salaries, its average
 *        and the ammount of employees whose salary is higher than said average.
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int calculateSalarySumsAndAverages(Employee* lista,int length);
/**
 * @fn int operateMainMenu(Employee*, int)
 * @brief Displays and lets the user interact with the employees' main menu
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int operateMainMenu(Employee*lista,int length);
/**
 * @fn int operateInfoSubMenu(Employee*, int)
 * @brief  Displays and lets the user interact with the menu that handles the list of employees
 *         and salaries/averages
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int operateInfoSubMenu(Employee*lista,int length);
/**
 * @fn int operateModificationsSubMenu(Employee*, int)
 * @brief Displays and lets the user interact with the menu that handles modifications
 *
 * @param lista Employee* -- Pointer to array of employees
 * @param length int -- Array length
 * @return retorno int -- -1 if there is an error(NULL array or invalid length). 0 if OK.
 */
int operateModificationsSubMenu(Employee*lista, int length);
/**
 * @fn int setSortingOrder(char*)
 * @brief Sets order to ascending(1) or descending(0)
 *
 * @param mensaje Message that informs the user about what is being asked
 * @return int orden The number entered
 */
int setSortingOrder(char*mensaje);

#endif /* FUNCIONEEmployee_H_ */
