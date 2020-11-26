#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		FILE* pArch;

		if(path != NULL && pArrayListEmployee != NULL)
		{
			pArch = fopen(path, "r");
			if(pArch!= NULL && (parser_EmployeeFromText(pArch, pArrayListEmployee)==0))
			{
				retorno = 0;
			}
			else
			{
				printf("\nError al cargar desde el texto\n");
				return -1;
			}
		}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		FILE* pArch;
		if(path != NULL && pArrayListEmployee != NULL)
		{
			pArch= fopen(path, "rb");
			if(pArch!= NULL && parser_EmployeeFromBinary(pArch, pArrayListEmployee)==0)
			{
				retorno = 0;
			}
		}
		return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		if(pArrayListEmployee != NULL)
		{
			Employee* this = employee_add();
			ll_add(pArrayListEmployee, this);
			retorno = 0;
			printf("\nAgregado con exito.\n");
		}else{
			printf("\nError al agregar.\n");
		}
	    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		int i;
		int idComparar;
		char auxNombre[128];
		int auxHoras;
		int auxSueldo;
		Employee* auxEmployee;
		int idIngresado;
		int opcion;
		if(pArrayListEmployee != NULL)
		{


			if(utn_getInt("\nIngrese el id a modificar:","Error id no encontrado\n", &idIngresado,3,99999,0) == 0)
			{
				for(i = 0;  i < ll_len(pArrayListEmployee); i ++)
				{
					auxEmployee = ll_get(pArrayListEmployee, i);
					if(auxEmployee != NULL)
					{
						employee_getId(auxEmployee, &idComparar);
						if(idIngresado == idComparar)
						{
							if(!utn_getInt("\n1.Modificar Nombre.\n2.Modificar Horas.\n3.Modificar Sueldo.\n","\nError 1 a 4.\n", &opcion, 3, 4, 1))
							{
								switch(opcion)
								{
								 	 case 1:
								 		 if(!utn_getNombre("\nIngrese nuevo nombre: ","\nError reintente.\n", auxNombre,3, 50))
								 		 {
								 			 employee_setNombre(auxEmployee, auxNombre);
								 			 printf("\nModificacion exitosa.\n");
								 		 }
								 		 break;
								 	 case 2:
								 		 if(!utn_getInt( "\nIngrese la nueva cantidad de horas: ", "\nError 1 a 1000.\n", &auxHoras,3, 1000, 2))
								 		 {
								 			 employee_setHorasTrabajadas(auxEmployee, auxHoras);
								 			 printf("\nModificacion exitosa.\n");
								 		 }
								 		 break;
								 	 case 3:
								 		 if(!utn_getInt("\nIngrese el nuevo sueldo: ", "\nError 1000 a 1000000.\n", &auxSueldo, 3 ,1000000, 1000))
								 		 {
								 			 employee_setSueldo(auxEmployee, auxSueldo);
								 			 printf("\nModificacion exitosa.\n");
								 		 }
								 		 break;

								}
							}

						}else{
							printf("\nEl id no existe.\n");
							break;
						}
					}

				}
			}

		}
	    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
		int i;
		int idComparar;
		char auxNombre[128];
		int auxHoras;
		int auxSueldo;
		int confirma;
		Employee* auxEmployee;
		int idIngresado;
		if(pArrayListEmployee != NULL)
		{

			printf("\n-------------------------------------------------------\n");
			if(utn_getInt("\nIngrese el id a borrar:","Error id no encontrado\n", &idIngresado,3,99999,0) == 0)
			{
				for(i = 0;  i < ll_len(pArrayListEmployee); i ++)
				{
					auxEmployee = ll_get(pArrayListEmployee, i);
					if(auxEmployee != NULL)
					{
						employee_getId(auxEmployee, &idComparar);
						if(idIngresado == idComparar)
						{
							employee_getNombre(auxEmployee, auxNombre);
							employee_getHorasTrabajadas(auxEmployee, &auxHoras);
							employee_getSueldo(auxEmployee, &auxSueldo);
							printf("\n-------------------------------------------------------\n");
							printf("\nId: %d Nombre: %s Horas: %d Sueldo: %d.\n", idComparar, auxNombre, auxHoras, auxSueldo);
							printf("\n-------------------------------------------------------\n");
							printf("\n                                                       \n");
							if(utn_getInt("\nSeguro desea eliminar si = 1 / no = 2?","Error\n", &confirma,3,2,1) == 0)
							{
								if(confirma== 1)
								{
								employee_delete(auxEmployee);
								ll_remove(pArrayListEmployee, i);
								printf("\n-------------------------------------------------------\n");
								printf("\nBorrado con exito.\n");
								printf("\n-------------------------------------------------------\n");
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


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
		int retorno= -1;
		int len = ll_len(pArrayListEmployee);
		Employee* aux;
		if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
		{
			for(int i = 0; i < len; i ++)
			{
					aux = ll_get(pArrayListEmployee, i);
					employee_print(aux);
					retorno=0;
			}
		}
	    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int auxOrden;

		if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
		{
			if(utn_getInt("Ordenar: 1.Ascendente\n2.Descendente\n","Error 1 o 2\n", &auxOrden, 3, 2, 1)==0)
			{
				ll_sort(pArrayListEmployee, employee_sortNombre, auxOrden);
				retorno = 0;
				printf("\nOrdenado Correctamente!\n");
			}

		}
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		FILE* pArchivo = fopen(path, "w");
		Employee* aux;
		char auxId[20];
		char auxNombre[128];
		char auxHoras[20];
		char auxSueldo[20];
		if(path != NULL && pArrayListEmployee != NULL && pArchivo != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i ++)
			{
				aux = ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					employee_getIdTxt(aux, auxId);
					employee_getNombre(aux, auxNombre);
					employee_getHorasTrabajadasTxt(aux, auxHoras);
					employee_getSueldoTxt(aux, auxSueldo);
					fprintf(pArchivo,"%s,%s,%s,%s\n", auxId, auxNombre, auxHoras, auxSueldo);
					retorno = 0;
				}
			}
			if(retorno == 0)
			{
				printf("Cargado correctamente\n");
			}
		}
		fclose(pArchivo);
	    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		FILE* pArchivo = fopen(path, "wb");
		Employee* pBuffer;
		if(path != NULL && pArrayListEmployee != NULL && pArchivo != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i ++)
			{
				pBuffer = ll_get(pArrayListEmployee, i);
				if(pBuffer != NULL)
				{
					fwrite(pBuffer, sizeof(Employee), 1, pArchivo);
					retorno = 0;
				}
			}
			if(retorno == 0)
			{
				printf("Cargado correctamente\n");
			}
		}
		fclose(pArchivo);
	    return retorno;
}

