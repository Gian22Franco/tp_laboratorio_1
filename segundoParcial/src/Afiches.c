/*
 * Afiches.c
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Afiches.h"
#include "Cliente.h"
#include "utn.h"


Afiches* afiches_new()
{
	return (Afiches*) malloc(sizeof(Afiches));
}


Afiches* afiches_newWithParameters(int clienteId, int aficheId, int cantidadAfiches, char* nombrePoster, int zona, int estado)
{
	Afiches* this = afiches_new();
	if(this!=NULL)
	{
		if( !afiches_setClienteId(this, clienteId) && !afiches_setAficheId(this, aficheId) && !afiches_setCantidadAfiches(this, cantidadAfiches) &&
			!afiches_setNombreAfiche(this, nombrePoster) && !afiches_setZona(this, zona) && !afiches_setEstado(this, estado))
		{
			return this;
		}
		else
		{
			afiches_delete(this);
		}
	}
	return NULL;
}

Afiches* afiches_newWithParametersTxt(char* clienteId, char* aficheId, char* cantidadAfiches, char* nombrePoster, char* zona, char* estado)
{
	Afiches* this = afiches_new();
	if(this!=NULL)
	{
		if( !afiches_setClienteIdTxt(this, clienteId) && !afiches_setAficheIdTxt(this, aficheId) && !afiches_setCantidadAfichesTxt(this, cantidadAfiches) &&
			!afiches_setNombreAfiche(this, nombrePoster) && !afiches_setZonaTxt(this, zona) && !afiches_setEstadoTxt(this, estado))
		{
			return this;
		}
		else
		{
			afiches_delete(this);
		}
	}
	return NULL;
}

void afiches_delete(Afiches* this)
{
	free(this);
}

int afiches_getClienteId(Afiches* this, int* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		*pResult = this->cliente_Id;
		retornar=0;
	}
	return retornar;
}

int afiches_getAficheId(Afiches* this, int* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		*pResult = this->Id_afiche;
		retornar=0;
	}
	return retornar;
}

int afiches_getCantidadAfichesy(Afiches* this, int* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		*pResult = this->cantidad_afiches;
		retornar=0;
	}
	return retornar;
}

int afiches_getNombreAfiche(Afiches* this, char* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		retornar=0;
		strncpy(pResult, this->nombre_poster, LONG_SIZE);
	}
	return retornar;
}

int afiches_getZona(Afiches* this, int* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		*pResult = this->zona;
		retornar=0;
	}
	return retornar;
}

int afiches_getEstado(Afiches* this, int* pResult)
{
	int retornar=-1;
	if(this!=NULL)
	{
		*pResult = this->estado;
		retornar=0;
	}
	return retornar;
}

int afiches_setClienteId(Afiches* this, int clienteId)
{
	int retornar=-1;
	if(this!=NULL && clienteId>-1)
	{
		this->cliente_Id = clienteId;
		retornar=0;
	}
	return retornar;
}

int afiches_setClienteIdTxt(Afiches* this, char* clienteId)
{
	int retornar=-1;
	if(this!=NULL && clienteId!=NULL)
	{
		this->cliente_Id = atoi(clienteId);
		retornar=0;
	}
	return retornar;
}

int afiches_setAficheId(Afiches* this, int Id_afiche)
{
	int retornar=-1;
	if(this!=NULL && Id_afiche>-1)
	{
		this->Id_afiche = Id_afiche;
		retornar=0;
	}
	return retornar;
}



int afiches_getCantidadAfiches(Afiches* this, int* pResult)
{
	int retornar=-1;
		if(this!=NULL)
		{
			*pResult = this->cantidad_afiches;
			retornar=0;
		}
		return retornar;
}

int afiches_setCantidadAfiches(Afiches* this, int cantidadAfiches)
{
	int retornar=-1;
		if(this!=NULL && cantidadAfiches>-1)
		{
			this->cantidad_afiches = cantidadAfiches;
			retornar=0;
		}
		return retornar;
}

int afiches_setNombreAfiche(Afiches* this, char* nombre_poster)
{
	int retornar=-1;
	if(this!=NULL && nombre_poster!=NULL )
	{
		strncpy(this->nombre_poster, nombre_poster, LONG_SIZE);
		retornar=0;
	}
	return retornar;
}

int afiches_setZona(Afiches* this, int zona)
{
	int retornar=-1;
	if(this!=NULL && (zona>0 && zona<5))
	{
		this->zona = zona;
		retornar=0;
	}
	return retornar;
}

int afiches_setZonaTxt(Afiches* this, char* zona)
{
	int retornar=-1;
	if(this!=NULL && zona!=NULL && zona != NULL)
	{
		this->zona = atoi(zona);
		retornar=0;
	}
	return retornar;
}

int afiches_setEstado(Afiches* this, int estado)
{
	int retornar=-1;
	if(this!=NULL && (estado==0 || estado==1))
	{
		this->estado = estado;
		retornar=0;
	}
	return retornar;
}


int afiches_setAficheIdTxt(Afiches* this, char* aficheId)
{
	int retornar=-1;
		if(this!=NULL && aficheId!=NULL)
		{
			this->Id_afiche = atoi(aficheId);
			retornar=0;
		}
		return retornar;

}

int afiches_setCantidadAfichesTxt(Afiches* this, char* aficheCantidad)
{
	int retornar=-1;
		if(this!=NULL && aficheCantidad!=NULL)
		{
			this->cantidad_afiches = atoi(aficheCantidad);
			retornar=0;
		}
		return retornar;
}


int afiches_setEstadoTxt(Afiches* this, char* estado)
{
	int retornar=-1;
		if(this!=NULL && estado!=NULL)
		{
			this->estado = atoi(estado);
			retornar=0;
		}
		return retornar;
}

