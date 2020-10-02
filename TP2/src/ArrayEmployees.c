/*
 * ArrayEmployees.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

static int generarIdNuevo(void);

/** \brief  To indicate that all position in the array are empty, *
 *           this function put the flag (isEmpty) in TRUE in all *
 *           position of the array
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int initEmployees(Employee *list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief  Función que permite dar de alta un Empleado, *
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int addEmployee(Employee *list, int len) {
	int retorno = -1;
	int indice;

	Employee bufferEmployee;

	if (list != NULL && len > 0) {
		if (employeeLibre (list, len, &indice) == 0) {
			if (utn_getNombre("\nIngrese el nombre :\n", "error",
					bufferEmployee.name, 2, LONG) == 0
					&& utn_getNombre("\nIngrese el apellido:\n",
							"ERROR", bufferEmployee.lastName, 3, LONG) == 0
					&& utn_getInt(
							"\nIngrese el sector: \n",
							"\nError!\n", &bufferEmployee.sector, 3,
							MAX_NUMEROS, MIN_NUMEROS) == 0
					&& utn_getFloat("\nIngrese el salario:\n",
							"\nError!\n", &bufferEmployee.salary, 3,
							MAX_NUMEROS, MIN_NUMEROS) == 0) {
				list[indice] = bufferEmployee;
				list[indice].id = generarIdNuevo();
				list[indice].isEmpty = FALSE;
			} else {
				printf("horror");
			}
		} else {
			printf(" \n No quedan espacios libres");
		}
	}
	return retorno;
}
/** \brief  Función que encuentra un empleado por su id.
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \param idBuscar int dato que proviene del usuario y es el valor a comparar.
 *           * \param *pIndice int se guarda el indice del empleado que tiene el id buscado.
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int findEmployeeById(Employee *list, int len, int idBuscar,
		int *pIndice) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0 && pIndice != NULL && idBuscar >= 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == idBuscar) {
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	} else {
		printf("Error!");
	}
	return retorno;
}
/** \brief  Busca posiciones del array libres.
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *          * \param *pIndice int se guarda el indice del empleado libre.
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int employeeLibre(Employee *list, int len, int *pIndice) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0 && pIndice != NULL) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/** Función que sirve par remover un empleado de la lista
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int removeEmployee(Employee *list, int len) {
	int retorno = -1;
		int buffer;
				if (list != NULL && len>0){
				printEmployees(list, len);
				utn_getInt("\nIngrese ID del alumno a borrar:\n","\nError",&buffer,3, MAX_NUMEROS, MIN_NUMEROS);
				for (int i = 0 ; i<len ;  i++){
					if (buffer == list[i].id){ //hacer que la busqueda sea por id.
						list[i].isEmpty = TRUE;
						retorno = 0;
					}
				}
			}
	return retorno;
}
/** \brief  Función que sirve para modificar los valores del empleado
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int employee_modificar(Employee *list, int len) {
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Employee bufferPantalla;

	if (list != NULL && len > 0) {
		printEmployees(list, len);

		if (utn_getInt("ID:", "ERROR!", &idBuscar, 2, 9999, 0) == 0) {
			if (findEmployeeById(list, len, idBuscar, &indiceAModificar) == 0) {
				bufferPantalla = list[indiceAModificar]; // IMPORTANTE!

				if (utn_getNombre("\nNueva Nombre?", "error",
						bufferPantalla.name, 2, LONG) == 0) {
					if (utn_getNombre("\nNuevo Apellido?", "error",
							bufferPantalla.lastName, 2, LONG) == 0) {
						if (utn_getInt("\nNuevo sector?", "ERROR",
								&bufferPantalla.sector, 3, MAX_NUMEROS,
								MIN_NUMEROS) == 0) {
							if (utn_getFloat(
									"\nNuevo salario?:\n",
									"\nError",
									&bufferPantalla.salary, 3,
									MAX_NUMEROS, MIN_NUMEROS) == 0) {
								list[indiceAModificar] = bufferPantalla; // COPIAMOS AL ARRAY
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
/** \brief  Funcion que ordena a los empleados
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \param orderint Indica que tipo de ordenamiento se desea.
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
		int estadoDesordenado = 1;
		Employee aux;
		if (list != NULL && len > 0) {
			while (estadoDesordenado) //mientras este desordenado
			{
				estadoDesordenado = 0;
				for (int i = 0; i < (len - 1); i++) {
					if ((order == 1 && strncmp(list[i].lastName,list[i + 1].lastName, LONG) > 0) && (list[i].sector < list[i + 1].sector) || (order == 0	&& strncmp(list[i].lastName,list[i + 1].lastName, LONG) < 0)  && (list[i].sector > list[i + 1].sector) ) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estadoDesordenado = 1;
					}
				}
			}
			retorno = 0;
		}
		return retorno;
}
/** \brief  Imprime los empleados
 *           * \param list Employee* Pointer to array of employees
 *           * \param length int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int printEmployees(Employee *list, int length) {
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\nID:%d - Nombre: %s - Apellido: %s - Salario: %f - Sector: %d ",list[i].id, list[i].name,list[i].lastName,list[i].salary, list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/** \brief  To indicate that all position in the array are empty, *
 *           this function put the flag (isEmpty) in TRUE in all *
 *           position of the array
 *           * \param list Employee* Pointer to array of employees
 *           * \param len int Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
static int generarIdNuevo(void) {
	static int id = 0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id + 1;
	return id;
}
/** \brief  Función que calcula el total, promedio y que salarios superan el promedio., *
 *           * \param list Employee* Pointer to array of employees
 *           * \param length int Array length
 *           * \param total float donde se guarda el total
 *           * \param promedio float donde se guarda el promedio
 *           * \param empleadosSuperan int donde se guarda el total de salarios que superan el promedio.
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int employee_SalaryTotal(Employee *list, float *total, float *promedio,
		int *empleadosSuperan, int length)
{
	int retorno = -1;
	int contador = 0;
	int contadorSuperan = 0;
	float acumulador;
	float prom;
	if (list != NULL
			&& length
					> 0&& total != NULL && promedio != NULL && empleadosSuperan != NULL)
	{
		for (int i = 0; i < length; i++) {
			acumulador = list[i].salary + acumulador;
			contador++;
		}
		prom = acumulador / contador;
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty == FALSE)
			{
				if (list[i].salary > prom)
				{
					contadorSuperan++;
				}
			}
		}

		*promedio = acumulador / contador;
		*total = acumulador;
		*empleadosSuperan = contadorSuperan;
		retorno = 0;
	}
	return retorno;
}

