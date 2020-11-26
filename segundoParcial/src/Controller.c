/*
 * controller.c
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cliente.h"
#include "Parser.h"
#include "Afiches.h"
#include "utn.h"

int controllerMenu(LinkedList* listaClientes, LinkedList*listaAfiches)
{
	int retorno = -1;
	int opcion;
	//int opcionEstadisticas;

	do{
		if(!utn_getInt("\n1.Agregar Cliente\n2.Vender Afiches\n3.Modificar Venta\n4.Cobrar Venta\n5.Generar Informe de cobre\n6.Generar informe de deudas\n7.Generar estadisticas\n8.Salir\n",
				"\nError 1 a 6\n",&opcion, 3, 7, 1))
		{
			retorno = 0;

			switch(opcion)
			{
				case 1:
					if(controller_addCliente(listaClientes)==0)
					{
						printf("Cliente cargado con exito!");
					}
					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				case 7:

					break;
			}
		}
	}while(opcion != 8);

	return retorno;
}


int controller_loadClienteFromText(char* path, LinkedList* listaCliente)
{
	int retornar=-1;
	FILE* pFile;
	if(path!=NULL && listaCliente!=NULL)
	{

		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_clientFromText(pFile, listaCliente))
		{
			retornar=0;
		}
		else
		{
			printf("\nEl archivo no existe");
		}
		fclose(pFile);
	}
    return retornar;
}

int controller_loadAfichesFromText(char* path, LinkedList* ListaAfiches)
{
	int retornar=-1;
	FILE* pFile;
	if(path!=NULL && ListaAfiches!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL && !parser_afichesFromText(pFile, ListaAfiches))
		{
			retornar=0;
		}
		else
		{
			printf("\nEl archivo no existe");
		}
		fclose(pFile);
	}
    return retornar;
}


int controller_addCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
		if(pArrayListCliente != NULL)
		{
			Cliente* this = cliente_add();
			ll_add(pArrayListCliente, this);
			retorno = 0;
			printf("\nAgregado con exito.\n");
		}else{
			printf("\nError al agregar.\n");
		}
	    return retorno;
}


