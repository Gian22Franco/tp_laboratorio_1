/*
 * cliente.c
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Afiches.h"
#include "utn.h"



Cliente* cliente_new()
{
	return (Cliente*)malloc(sizeof(Cliente));
}



Cliente* cliente_newWithParameters(int id, char* name, char* lastName, char* cuit)
{
	Cliente* this = cliente_new();
	if(this!=NULL)
	{
		if(!cliente_setId(this, id) && !cliente_setNombre(this, name) && !cliente_setApellido	(this, lastName) && !cliente_setCuit(this,cuit) )
		{
			return this;
		}
		else
		{
			cliente_delete(this);
		}
	}
	return NULL;
}

Cliente* cliente_newWithParametersTxt(char* id, char* name, char* lastName, char* cuit)
{
	Cliente* this = cliente_new();
	if(this!=NULL)
	{
		if( !cliente_setIdTxt(this, id) && !cliente_setNombre(this, name) && !cliente_setApellido(this, lastName) && !cliente_setCuit(this, cuit))
		{
			return this;
		}
		else
		{
			cliente_delete(this);
		}
	}
	return NULL;
}


void cliente_delete(Cliente* this)
{
	free(this);
}

int cliente_getId(void* this, int* pResult)
{
	int retornar=-1;
	Cliente* bufferClient;
	if(this!=NULL)
	{
		bufferClient = (Cliente*) this;
		*pResult = bufferClient->id;
		retornar=0;
	}
	return retornar;
}

int cliente_getNombre(Cliente* this, char* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		retornar=0;
		strncpy(pResult, this->nombre, LONG_STRING);
	}
	return retornar;
}

int cliente_getApellido(Cliente* this, char* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		retornar=0;
		strncpy(pResult, this->apellido, LONG_STRING);
	}
	return retornar;
}

int cliente_getCuit(Cliente* this, char* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		retornar=0;
		strncpy(pResult, this->cuit, LONG_STRING);
	}
	return retornar;
}

int cliente_setId(Cliente* this, int id)
{
	int retorno=-1;
	if(this!=NULL && id>-1)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}

int cliente_setIdTxt(Cliente* this, char* id)
{
	int retorno=-1;
	if(this!=NULL && id > 0)
	{
		this->id = atoi(id);
		retorno=0;
	}
	return retorno;
}

int cliente_setNombre(Cliente* this, char* name)
{
	int retorno=-1;
	if(this!=NULL && name != NULL)
	{
		strncpy(this->nombre, name, LONG_STRING);
		retorno=0;
	}
	return retorno;
}

int cliente_setApellido(Cliente* this, char* lastName)
{
	int retorno=-1;
	if(this!=NULL && lastName != NULL)
	{
		strncpy(this->apellido, lastName, LONG_STRING);
		retorno=0;
	}
	return retorno;
}

int cliente_setCuit(Cliente* this, char* cuit)
{
	int retorno=-1;
	if(this!=NULL && cuit > 0)
	{
		strncpy(this->cuit, cuit, LONG_STRING);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Funcion para imprimir todos los datos de un cliente
 * \void* this: Puntero a void que luego convertiremos en un tipo de dato Cliente
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int cliente_print(void* this)
{
	int retorno=-1;
	Cliente* bufferClient;
	int bufferId;
	char bufferNombre[LONG_STRING];
	char bufferApellido[LONG_STRING];
	char bufferCuit[LONG_CUIT];
	if(this!=NULL)
	{
		retorno=0;
		bufferClient = (Cliente*) this;
		if( !cliente_getId(bufferClient, &bufferId) && !cliente_getNombre(bufferClient, bufferNombre) &&
			!cliente_getApellido(bufferClient, bufferApellido) && !cliente_getCuit(bufferClient, bufferCuit))
		{
			printf("\nID: %d - Nombre: %s - Apellido: %s - Cuit: %s", bufferId, bufferNombre, bufferApellido, bufferCuit);
		}
	}
	return retorno;
}



