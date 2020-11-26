#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define LONG 200

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

int retorno = -1;
	char auxId[50];
	char auxNombre[128];
	char auxHorasTrabajadas[50];
	char auxSueldo[50];
	char buffer[200];
	int flag = 0;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(flag == 0)
			{
				fscanf(pFile,"%[^\n]",buffer);
				flag = 1;
			}
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo) == 4)
			{
				Employee* aux = employee_new();
				if(!employee_setId(aux, atoi(auxId)) && !employee_setNombre(aux, auxNombre) && !employee_setHorasTrabajadasTxt(aux, auxHorasTrabajadas)
									&& !employee_setSueldoTxt(aux, auxSueldo))
				{
					ll_add(pArrayListEmployee, aux);
					retorno = 0;
				}
			}



		}while(!feof(pFile));

	}
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
		int retorno=-1;
		Employee* auxBuffer;
		int read;

		if(pFile!=NULL)
		{
			retorno = 0;
			do
			{
				auxBuffer = employee_new();
				if(auxBuffer != NULL)
				{
					read = fread(auxBuffer, sizeof(Employee), 1, pFile);
					if(read == 1)
					{
						ll_add(pArrayListEmployee, auxBuffer);
					}
					else
					{
						employee_delete(auxBuffer);
					}
				}
			}while(feof(pFile)==0);
		}
		return retorno;
	}
