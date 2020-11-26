


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"



static int esNumerica(char* cadena, int limite);

Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr)
{
	Employee* this;
	this = employee_new();
	if(this != NULL && nombreStr != NULL)
	{
		employee_setId(this, atoi(idStr));
		employee_setNombre(this, nombreStr);
		employee_setHorasTrabajadas(this, horasTrabajadasStr);
		employee_setSueldo(this, sueldoStr);
	}
	return this;
}

int employee_delete(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_print(Employee* this)
{
	int retornar=-1;
	char auxName[200];
	int auxId;
	int auxHours;
	int auxSalary;
	if(this!=NULL)
	{
		if( !employee_getId(this, &auxId) &&
			!employee_getNombre(this, auxName) &&
			!employee_getHorasTrabajadas(this, &auxHours) &&
			!employee_getSueldo(this, &auxSalary))
		{
			printf("\nID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %.2d\n", auxId, auxName, auxHours, auxSalary);
			retornar = 0;
		}
	}
	return retornar;
}

int employee_setId(Employee* this, int id)
{
	int retorno=-1;
		if(this!=NULL && id>0)
		{
			this->id = id;
			retorno=0;
		}
		return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_getIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		sprintf(id, "%d", this->id);
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}


	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas > 1)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}


	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	int aux;

	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,1000))
		{
			aux = atoi(horasTrabajadas);
			if(horasTrabajadas >= 0)
			{
				this->horasTrabajadas = aux;
				retorno = 0;
			}
		}

	}


	return retorno;
}
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		sprintf(horasTrabajadas, "%d", this->horasTrabajadas);
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo > 1000)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}


	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	float aux;

	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo, 1000000))
		{
			aux = atoi(sueldo);
			if(aux >= 1000)
			{
				this->sueldo = aux;
				retorno = 0;
			}
		}
	}


	return retorno;
}
int employee_getSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		sprintf(sueldo, "%d", this->sueldo);
	}
	return retorno;
}

Employee* employee_add()
{
	char nAux[128];
	int hAux;
	int sAux;
	Employee* this = employee_new();

	if(this != NULL)
	{
		if(!utn_getNombre("Ingrese el nombre: ", "Nombre invalido, reintente.\n", nAux,3, 128))
		{
			if(!utn_getInt("Ingrese las horas trabajadas: ", "Numero invalido(1 a 1000).\n", &hAux, 3, 1000, 1))
			{
				if(!utn_getInt("Ingrese el sueldo: ", "Sueldo invalido(1000 a 1000000).\n",&sAux,3,1000000,1000))
				{
					employee_setId(this, -3);
					employee_setNombre(this, nAux);
					employee_setHorasTrabajadas(this, hAux);
					employee_setSueldo(this, sAux);
				}
			}
		}
	}else{
		printf("new NULL.\n");
	}



	return this;
}

int employee_sortSueldo(void* thisA, void* thisB)
{
		int retorno = 0;
		Employee* e1 = (Employee*) thisA;
		Employee* e2 = (Employee*) thisB;
		int sueldo1;
		int sueldo2;

		if(thisA != NULL && thisB != NULL)
		{
		employee_getSueldo(e1, &sueldo1);
		employee_getSueldo(e2, &sueldo2);

			if(sueldo1 > sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo1 < sueldo2)
			{
				retorno = -1;
			}
			else
			{
				retorno = 0;
			}
		}
		return retorno;
	}


int employee_sortNombre(void* thisA, void* thisB)
{
	int retorno = -2;
	Employee* pEmpleadoA = (Employee*) thisA;
	Employee* pEmpleadoB = (Employee*) thisB;

	char bufferNombreA[256];
	char bufferNombreB[256];

	int respuestaCmp;
	if(thisA != NULL && thisB != NULL)
	{
		employee_getNombre(pEmpleadoA, bufferNombreA);
		employee_getNombre(pEmpleadoB, bufferNombreB);

		respuestaCmp = strcmp(bufferNombreA, bufferNombreB);
		if(respuestaCmp > 0)
		{
			retorno = 1;
		}
		else if(respuestaCmp < 0 )
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
return retorno;
}

static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
