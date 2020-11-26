/*
 * Parser.c
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Afiches.h"
#include "Parser.h"
#define BUFFER 4096

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*: Direccion del archivo
 * \param pArrayListEmployee LinkedList*: Puntero a la LinkedList
 * \return (-1) Si algo salio mal o (0) si todo esta bien
 *
 */
int parser_clientFromText(FILE* pFile , LinkedList* clientList)
{
	int retornar=-1;
	char bufferId[BUFFER];
	char bufferName[BUFFER];
	char bufferLastName[BUFFER];
	char bufferCuit[BUFFER];
	Cliente* bufferCliente;
	if(pFile!=NULL && clientList!=NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferCuit)==4)
			{
				bufferCliente = cliente_newWithParametersTxt(bufferId, bufferName, bufferLastName, bufferCuit);
				ll_add(clientList, bufferCliente);
				retornar=0;
			}
			else
			{
				cliente_delete(bufferCliente);
			}
		}while(feof(pFile)==0);
	}
    return retornar;
}

int parser_afichesFromText(FILE* pFile , LinkedList* sellList)
{
	int retornar=-1;
	char bufferIdSell[BUFFER];
	char bufferIdClient[BUFFER];
	char bufferPosterQty[BUFFER];
	char bufferFileName[BUFFER];
	char bufferZone[BUFFER];
	char bufferState[BUFFER];
	Afiches* bufferAfiches;
	if(pFile!=NULL && sellList!=NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferIdSell, bufferIdClient,bufferPosterQty,bufferFileName,bufferZone, bufferState)==6)
			{
				bufferAfiches = afiches_newWithParametersTxt(bufferIdClient, bufferIdSell, bufferPosterQty, bufferFileName, bufferZone, bufferState);
				ll_add(sellList, bufferAfiches);
				retornar=0;
			}
			else
			{
				afiches_delete(bufferAfiches);
			}
		}while(feof(pFile)==0);
	}
    return retornar;
}
