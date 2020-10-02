/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"

int main(void) {
	setbuf(stdout, NULL);
	int op;
	int opInformar;
	float auxPromedio;
	float auxTotal;
	int auxEmpleadosSuperan;
	Employee arrayEmployees[QTY_EMPLOYEES];

	initEmployees( arrayEmployees,QTY_EMPLOYEES);

	do {

		utn_getInt(
				"\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Salir",
				"\nError", &op, 2, 6, 1);

		switch (op) {
		case 1:
			if (addEmployee( arrayEmployees, QTY_EMPLOYEES) == 0) {
				printf("\n                            \n");
				printf("\nCarga realizada con exito!!\n");
				printf("\n----------------------------\n");
			}
			break;
		case 2:
			printEmployees( arrayEmployees, QTY_EMPLOYEES);
			printf("\n                            \n");

			if (employee_modificar( arrayEmployees, QTY_EMPLOYEES) == 0) {
				printf("\n                            \n");
				printf("\nModificación realizada con exito!!\n");
				printf("\n----------------------------\n");
			}
			break;
		case 3:

			if (removeEmployee( arrayEmployees, QTY_EMPLOYEES) == 0) {
				printf("\n                            \n");
				printf("\nBaja realizada con exito!!\n");
				printf("\n                            \n");
				printf("\n----------------------------\n");
			}
			break;
		case 4:

			do
			{
				utn_getInt(
								"\n1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n3-Salir",
								"\nError", &opInformar, 2, 6, 1);
				switch(opInformar)
				{

					case 1:
						if (sortEmployees( arrayEmployees, QTY_EMPLOYEES, 1) == 0) {


									  printEmployees( arrayEmployees, QTY_EMPLOYEES);
									  printf("\n                            \n");
									  printf("\nCalculos realizados con exito!!\n");
									  printf("\n----------------------------\n");
									}

					break;


					case 2:
							if(employee_SalaryTotal( arrayEmployees, &auxTotal, &auxPromedio,&auxEmpleadosSuperan, QTY_EMPLOYEES)== 0)
							{

								printf("El total de los salarios es %f.\nEl promedio de los salarios es %f.\nY %d empleado/s supera/n el promedio.\n", auxTotal, auxPromedio, auxEmpleadosSuperan);
								printf("\n                            \n");
								printf("\nCalculos realizados con exito!!\n");
								printf("\n----------------------------\n");
							}
					break;

				}
			}while(opInformar !=3);

			break;
		}
	} while (op != 5);

	return EXIT_SUCCESS;
}
