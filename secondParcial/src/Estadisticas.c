/*
 * Estadisticas.c
 *
 *  Created on: 2 dic. 2020
 *      Author: Gian
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Linkedlist.h"
#include "Parser.h"
#include "utn.h"
#include "Controller.h"
#include "Afiches.h"

static int estadisticas_clienteMaxAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche);
static int controller_clienteMinAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche);
static int controller_VentaMaxAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche);


int estadisticas_menu(LinkedList* listaClientes, LinkedList* listaAfiches)
{
	int retorno = -1;
	int opcion;
	//int opcionEstadisticas;

	do{
		if(!utn_getInt("\n1.Cliente al que se le vendió mas afiches\n2.Cliente al que se le vendió menos afiches\n3Venta con mas afiches vendidos \n4.Salir\n",
				"\nError 1 a 6\n",&opcion, 3, 3, 1))
		{
			retorno = 0;

			switch(opcion)
			{
				case 1:
					if(!estadisticas_clienteMaxAfichesQty(listaClientes, listaAfiches))
						{
							retorno=0;
						}
					break;
				case 2:
					if(!controller_clienteMinAfichesQty(listaClientes, listaAfiches))
						{
							retorno=0;
						}
					break;
				case 3:
					if(!controller_VentaMaxAfichesQty(listaClientes, listaAfiches))
						{
							retorno=0;
						}
					break;
			}
		}
	}while(opcion != 4);

	return retorno;
}

static int estadisticas_clienteMaxAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche)
{
	int retornar=-1;
	int maxQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	if(ListaCliente!=NULL && ListaAfiche!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(ListaCliente);i++)
		{
			bufferClient = ll_get(ListaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(ListaAfiche, afiches_idCargado, bufferClientId, &currentCounter))
			{
				if(i==0 || maxQty<currentCounter)
				{
					maxQty = currentCounter;
				}
			}
		}
		printf("\nEl/los cliente/s con mas afiches es/son: \n");
		for(int i=0;i<ll_len(ListaCliente);i++)
		{
			bufferClient = ll_get(ListaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(ListaAfiche, afiches_idCargado, bufferClientId, &currentCounter))
			{
				if(currentCounter == maxQty)
				{
					cliente_print(bufferClient);
				}
			}
		}
	}
	return retornar;
}

static int controller_clienteMinAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche)
{
	int retornar=-1;
	int minQty;
	int currentCounter;
	int bufferClientId;
	Cliente* bufferClient;
	if(ListaCliente!=NULL && ListaAfiche!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(ListaCliente);i++)
		{
			bufferClient = ll_get(ListaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(ListaAfiche, afiches_idCargado, bufferClientId, &currentCounter))
			{
				if((i==0 || minQty>currentCounter))
				{
					minQty = currentCounter;
				}
			}
		}
		printf("\nEl/los cliente/s con menos afiches es/son: \n");
		for(int i=0;i<ll_len(ListaCliente);i++)
		{
			bufferClient = ll_get(ListaCliente, i);
			if(bufferClient!=NULL && !cliente_getId(bufferClient, &bufferClientId) && !ll_reduceInt(ListaAfiche, afiches_idCargado, bufferClientId, &currentCounter))
			{
				if(currentCounter == minQty)
				{
					cliente_print(bufferClient);
				}
			}
		}
	}
	return retornar;
}

static int controller_VentaMaxAfichesQty(LinkedList* ListaCliente, LinkedList* ListaAfiche)
{
	int retornar=-1;
	int bufferPosterQty;
	int maxPosterQty;
	int bufferIdSale;
	int bufferIdClient;
	int clientIndex;
	char bufferCuit[LONG_CUIT];
	int bufferState;
	Afiches* bufferSale;
	Cliente* bufferClient;
	if(ListaCliente!=NULL && ListaAfiche!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(ListaAfiche);i++)
		{
			bufferSale = ll_get(ListaAfiche, i);
			if(bufferSale!=NULL && !afiches_getCantidadAfiches(bufferSale, &bufferPosterQty) && !afiches_getEstado(bufferSale, &bufferState))
			{
				if((i==0 || maxPosterQty<bufferPosterQty) && bufferState==1)
				{
					maxPosterQty=bufferPosterQty;
				}
			}
		}
		printf("\nLa/las venta/s con mas afiches vendidos es/son: \n");
		for(int i=0;i<ll_len(ListaAfiche);i++)
		{
			bufferSale = ll_get(ListaAfiche, i);
			if(bufferSale!=NULL && !afiches_getCantidadAfiches(bufferSale, &bufferPosterQty) && !afiches_getEstado(bufferSale, &bufferState))
			{
				if( bufferPosterQty==maxPosterQty && bufferState==1 && !afiches_getClienteId(bufferSale, &bufferIdClient) &&
					!afiches_getAficheId(bufferSale, &bufferIdSale)  && !controller_buscarPorId(ListaCliente, cliente_getId, bufferIdClient, &clientIndex))
				{
					bufferClient = ll_get(ListaCliente, clientIndex);
					if(bufferClient!=NULL && !cliente_getCuit(bufferClient, bufferCuit))
					{
						printf("\nID venta: %d - Cuit cliente: %s", bufferIdSale, bufferCuit);
					}
				}
			}
		}
	}
	return retornar;
}
