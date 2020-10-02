/*
 * ArrayEmployees.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LONG 50
#define QTY_EMPLOYEES 1000
#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define MIN_NUMEROS 0
#define MAX_NUMEROS 999999

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int initEmployees(Employee *list, int len);
int addEmployee(Employee *list, int len);
int findEmployeeById(Employee *list, int len, int idBuscar,int *pIndice);
int employeeLibre(Employee *list, int len, int *pIndice);
int employee_modificar(Employee *list, int len);
int removeEmployee(Employee *list, int len);
int sortEmployees(Employee *list, int len, int order);
int printEmployees(Employee *list, int length);
int employee_SalaryMax(Employee *list,int * pResultado,  int length);
int employee_SalaryTotal(Employee *list, float * total, float * promedio, int * empleadosSuperan, int length);

#endif /* ARRAYEMPLOYEES_H_ */
