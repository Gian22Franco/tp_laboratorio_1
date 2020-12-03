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
#include "Estadisticas.h"

static int controller_isCuitRegistrado(LinkedList* clientList, char* cuit);
static int controller_generarId(LinkedList* list, int (*pFunc)(void*,int*));


int controllerMenu(LinkedList* listaClientes, LinkedList* listaAfiches)
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

					if(!controller_addCliente(listaClientes))
						{
							printf("\nCliente ingresado exitosamente\n");
							controller_saveClienteAsTexto("clientes.txt", listaClientes);
						}
					break;
				case 2:
					if(!ll_isEmpty(listaClientes))
									{
										if(!controller_addAfiche(listaClientes, listaAfiches))
										{
											printf("\nVenta 'a cobrar' cargada exitosamente\n");
											controller_saveAfichesAsTexto("ventas.txt", listaAfiches);
										}
									}
									else
									{
										printf("\nNo hay clientes cargados\n");
									}
					break;
				case 3:
					if(!ll_isEmpty(listaClientes) && !ll_isEmpty(listaAfiches))
							{
								if(!controller_modificarAfiche(listaClientes, listaAfiches))
								{
								printf("\nAfiche modificado exitosamente\n");
								controller_saveAfichesAsTexto("afiches.txt", listaAfiches);
								}
							}
							else
							{
								printf("\nNo hay cliente o ventas cargadas\n");
							}
					break;
				case 4:
					if(!ll_isEmpty(listaClientes) && !ll_isEmpty(listaAfiches))
							{
								if(!controller_cobrarVenta(listaClientes, listaAfiches))
								{
									printf("\nVenta cobrada exitosamente\n");
									controller_saveAfichesAsTexto("ventas.txt", listaAfiches);
								}
							}
							else
							{
									printf("\nNo hay cliente o ventas cargadas\n");
							}
					break;
				case 5:
					if(!ll_isEmpty(listaClientes) && !ll_isEmpty(listaAfiches))
								{
									if(!controller_guardarClientesConAfichesCobrados(listaClientes, listaAfiches))
									{
										printf("\nArchivo guardado exitosamente\n");
									}
								}
								else
								{
									printf("\nNo hay cliente o ventas cargadas\n");
								}
					break;
				case 6:
					if(!ll_isEmpty(listaClientes) && !ll_isEmpty(listaAfiches))
									{
										if(!controller_guardarClientesConAfichesNoCobrados(listaClientes, listaAfiches))
										{
											printf("\nArchivo guardado exitosamente\n");
										}
									}
									else
									{
										printf("\nNo hay cliente o ventas cargadas\n");
									}
					break;
				case 7:
					estadisticas_menu(listaClientes, listaAfiches);
					break;
			}
		}
	}while(opcion != 8);

	return retorno;
}

/** \brief Cargar los clientes desde un archivo que recibimos por parametro
 * \param char* path: Recibimos el nombre del archivo
 * \param LinkedList* ListaCliente: Puntero a la lista de clientes
 * \return (-1) si algo salio mal (0) si Ok
 */
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
/** \brief Cargar los afiches desde un archivo que recibimos por parametro
 * \param char* path: Recibimos el nombre del archivo
 * \param LinkedList* ListaAfiches: Puntero a la lista de ventas
 * \return (-1) si algo salio mal (0) si Ok
 */
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


/*
brief Guarda los datos de los Clientes en el archivo de texto.
*
* \param path char* Ruta del archivo en donde guardar los datos
* \param pArrayListEmployee LinkedList* puntero a la lista enlazada
* \return int (0) si salio todo bien (-1)si hubo un error
*/
int controller_saveClienteAsTexto(char* path, LinkedList* ListaClientes)
{
	int retornar=-1;
	FILE* pFile;
	Cliente* bufferClient;
	int bufferId;
	char bufferNombre[LONG_STRING];
	char bufferApellido[LONG_STRING];
	char bufferCuit[LONG_CUIT];
	if(path!=NULL && ListaClientes!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,nombre,apellido,cuit\n");
			retornar=0;
			for(int i=0;i<ll_len(ListaClientes);i++)
			{
				bufferClient = ll_get(ListaClientes, i);
				if(bufferClient!=NULL)
				{
					if( !cliente_getId(bufferClient, &bufferId) && !cliente_getNombre(bufferClient, bufferNombre) &&
						!cliente_getApellido(bufferClient, bufferApellido) && !cliente_getCuit(bufferClient, bufferCuit))
					{
						fprintf(pFile, "%d,%s,%s,%s\n",bufferId, bufferNombre, bufferApellido, bufferCuit);

					}

				}
			}

		}
		fclose(pFile);
	}
	return retornar;
}
/*
brief Guarda los datos de las Ventas en el archivo de texto.
*
* \param path char* Ruta del archivo en donde guardar los datos
* \param pArrayListEmployee LinkedList* puntero a la lista enlazada
* \return int (0) si salio todo bien (-1)si hubo un error
*/
int controller_saveAfichesAsTexto(char* path, LinkedList* ListaAfiches)
{
	int retornar=-1;
	FILE* pFile;
	Afiches* bufferAfiches;
	int bufferIdAfiches;
	int bufferIdCliente;
	int bufferAfichesQty;
	char bufferNombreAfiche[LONG_SIZE];
	int bufferZona;
	int bufferEstado;
	if(path!=NULL && ListaAfiches!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id_venta,id_cliente,cantidad_afiches,nombre_archivo,zona,estado\n");
			retornar=0;
			for(int i=0;i<ll_len(ListaAfiches);i++)
			{
				bufferAfiches = ll_get(ListaAfiches, i);
				if( !afiches_getAficheId(bufferAfiches, &bufferIdAfiches) && !afiches_getClienteId(bufferAfiches, &bufferIdCliente) && !afiches_getCantidadAfiches(bufferAfiches, &bufferAfichesQty) &&
					!afiches_getNombreAfiche(bufferAfiches, bufferNombreAfiche) && !afiches_getZona(bufferAfiches, &bufferZona) && !afiches_getEstado(bufferAfiches, &bufferEstado))
				{
					fprintf(pFile, "%d,%d,%d,%s,%d,%d\n",bufferIdAfiches,bufferIdCliente,bufferAfichesQty,bufferNombreAfiche,bufferZona,bufferEstado);
				}
			}
		}
		fclose(pFile);
	}
	return retornar;
}

int controller_addCliente(LinkedList* listaClientes)
{
	int retorno=-1;
	Cliente* bufferCliente = cliente_new();
	char nombre[128];
	char apellido[128];
	char bufferCuit [128];
	int bufferId;

	if(listaClientes!=NULL)
	{
		if(utn_getNombre("\nNombre a ingresar: ","\nError",nombre,3,128)==0 &&
		   utn_getNombre("\nApellido a ingresar: ","\nError",apellido,3,128)==0 &&
		   utn_getCuit("Ingrese el cuit del nuevo cliente: ", "\nERROR!", bufferCuit, 3, LONG_CUIT)==0)
		{
				if(!controller_isCuitRegistrado(listaClientes, bufferCuit))
				{
					retorno=0;
					bufferId = controller_generarId(listaClientes, cliente_getId);
					printf("\nID para el nuevo cliente: %d", bufferId);
					bufferCliente = cliente_newWithParameters(bufferId, nombre, apellido, bufferCuit);
					ll_add(listaClientes, bufferCliente);
				}
				else
				{
					printf("El cuit ya existe\n");
				}
		}
	}
    return retorno;
}


int controller_addAfiche(LinkedList* listaClientes, LinkedList* listaAfiches)
{
	int retornar=-1;
	int bufferIdCliente;
	int bufferIdAfiche;
	int index;
	int bufferPosterQty;
	char bufferFileName[LONG_SIZE];
	int bufferZone;
	Afiches* bufferAfiches;
	if(listaClientes!=NULL)
	{
		if( !controller_print(listaClientes, cliente_print) && !utn_getInt("\nIngrese el ID del cliente: ", "\nERROR!", &bufferIdCliente, 2, 999999,1 ) &&
			!controller_buscarPorId(listaClientes, cliente_getId, bufferIdCliente, &index))
		{
			if( !utn_getInt("\nIngrese la cantidad de afiches a vender: ", "\nERROR!", &bufferPosterQty, 2, 99999,1) &&
				!utn_getNombre("\nIngrese el nombre del afiche: \n", "\nError, vuelva a intentarlo..", bufferFileName, 3, LONG_SIZE) &&
				!utn_getInt("\nIngrese la zona donde se pegaran los afiches: \n1)CABA\n2)ZONA SUR\n3)ZONA OESTE", "\nERROR!", &bufferZone, 2, 1, 3))
			{
				retornar=0;
				bufferIdAfiche = controller_generarId(listaAfiches, afiches_getAficheId);
				printf("\nID para la venta: %d", bufferIdAfiche);
				bufferAfiches = afiches_newWithParameters(bufferIdCliente, bufferIdAfiche, bufferPosterQty, bufferFileName, bufferZone, 0);
				ll_add(listaAfiches, bufferAfiches);
			}
			else
			{
				printf("\nError en la obtencion de datos");
			}
		}
		else
		{
			printf("\nID cliente no existente");
		}
	}
	return retornar;
}
/** \brief Funcion para imprimir una lista
 * \param LinkedList* clientList: Puntero a la lista de clientes
 * \param pFunc: funcion criterio para determinar que lista imprimimos
 * \return (-1) si algo salio mal o (0) si OK
 */
int controller_print(LinkedList* lista, int (*pFunc)(void*))
{
	int retornar=-1;
	if(lista!=NULL && pFunc!=NULL)
	{
		retornar=0;
		ll_map(lista, pFunc);
		printf("\n---------------------------------------------------------------------\n");
	}
	return retornar;
}

/** \brief Busca en la lista el id que pasamos por parametro y compara a traves de una funcion criterio, devuelve el indice por referencia
 * \param LinkedList* list: Puntero a la lista
 * \param int pFunc: Funcion criterio que recibe dos parametros
 * \param int id: Recibimos el id a comparar
 * \param int* index: Devolvemos por referencia el indice encontrado
 * \return (-1) si algo salio mal o (0) si OK
 */
int controller_buscarPorId(LinkedList* lista, int (*pFunc)(void*,int*), int id, int* index)
{
	int retornar=-1;
	int len = ll_len(lista);
	int bufferId;
	void* bufferEntity;
	if(lista!=NULL && id>0 && index!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			bufferEntity = ll_get(lista, i);
			if(!pFunc(bufferEntity, &bufferId) && bufferId == id)
			{
				retornar = 0;
				*index = i;
				break;
			}
		}
	}
	return retornar;
}

/** \brief Busca en la lista de empleados el maximo id y retorna ese valor + 1
 * \param LinkedList* lista: Puntero a la lista
 * \param int pFunc: Funcion criterio que recibe dos parametros
 * \return el valor del maximo id encontrado + 1 o (-1) si algo salio mal
 */
static int controller_generarId(LinkedList* lista, int (*pFunc)(void*,int*))
{
	int retornar=-1;
	int len = ll_len(lista);
	void* bufferEntity;
	int id;
	int maxId;
	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			bufferEntity = ll_get(lista, i);
			if(!pFunc(bufferEntity, &id))
			{
				if(i==0 || id>maxId)
				{
					maxId = id;
				}
			}
		}
		retornar = maxId+1;
	}
	return retornar;
}
/** \brief Funcion para verificar si el cuit que recibimos por parametro ya es de un cliente existente
 * \param LinkedList* ListaClientes: Puntero a la lista de clientes
 * \param char* cuit: Recibimos el cuit a comparar
 * \return (-1) si algo salio mal o (0) si OK
 */
static int controller_isCuitRegistrado(LinkedList* ListaClientes, char* cuit)
{
	int retornar=-1;
	Cliente* bufferClient;
	char bufferCuit[LONG_CUIT];
	if(ListaClientes!=NULL && cuit!=NULL)
	{
		retornar=0;
		for(int i=0;i<ll_len(ListaClientes);i++)
		{
			bufferClient = ll_get(ListaClientes, i);
			if(bufferClient!=NULL && !cliente_getCuit(bufferClient, bufferCuit))
			{
				if(!strncmp(bufferCuit, cuit,LONG_CUIT))
				{
					retornar=1;
				}
			}
		}
	}
	return retornar;
}

/** \brief Modificar una venta NO cobrada
 * \param LinkedList* clientList: Puntero a la lista de clientes
 * \param LinkedList* sellList: Puntero a la lista de ventas
 * \return (-1) si algo salio mal (0) si Ok
 */
int controller_modificarAfiche(LinkedList* clientList, LinkedList* sellList)
{
	int retornar=-1;
	LinkedList* bufferSaleList;
	int bufferId;
	int indexSale;
	int indexClient;
	Cliente* bufferClient;
	Afiches* bufferSale;
	int choosenOption;
	int bufferInt;
	char bufferString[LONG_SIZE];
	if(clientList!=NULL && sellList!=NULL)
	{
		bufferSaleList = ll_cloneFilter(sellList, afiches_estaVendida);
		if( !controller_print(bufferSaleList, afiches_print) && !utn_getInt("\nIngrese el ID de la venta a modificar: ", "\nERROR!", &bufferId, 2, 1, 99999) &&
			!controller_buscarPorId(sellList, afiches_getAficheId, bufferId, &indexSale))
		{
			bufferSale = ll_get(sellList, indexSale);
			if(afiches_estaVendida(bufferSale) && !afiches_getClienteId(bufferSale, &bufferId) && !controller_buscarPorId(clientList, cliente_getId, bufferId, &indexClient))
			{
				bufferClient = ll_get(clientList, indexClient);
				cliente_print(bufferClient);
				if( !utn_getInt("\n\nIngrese el campo a modificar:\n1)Cantidad de afiches\n2)Nombre del archivo\n3)Zona\n4)Volver atras\n> > OPCION: ", "\nERROR!", &choosenOption, 2, 4, 1))
				{
					switch(choosenOption)
					{
						case 1:
							if( !utn_getInt("\nIngrese la nueva cantidad de afiches: ", "\nERROR!", &bufferInt, 2, 999999, 1) && !afiches_setCantidadAfiches(bufferSale, bufferInt))
							{
								ll_set(sellList, indexSale, bufferSale);
								retornar=0;
							}
						break;
						case 2:
							if( !utn_getNombre("\nIngrese el nuevo nombre del archivo: ", "\nERROR!", bufferString, 2, LONG_SIZE) &&
								!afiches_setNombreAfiche(bufferSale, bufferString))
							{
								ll_set(sellList, indexSale, bufferSale);
								retornar=0;
							}
						break;
						case 3:
							if( !utn_getInt("\nIngrese la nueva zona: ", "\nERROR!", &bufferInt, 2, 3, 1) && !afiches_setZona(bufferSale, bufferInt))
							{
								ll_set(sellList, indexSale, bufferSale);
								retornar=0;
							}
						break;
					}
				}
			}
			else
			{
				printf("\nID de venta 'a cobrar' no encontrado!\n");
			}
		}
		else
		{
			printf("\nID no encontrado!\n");
		}
	}
	return retornar;
}

/** \brief Cobrar una venta NO cobrada
 * \param LinkedList* clientList: Puntero a la lista de clientes
 * \param LinkedList* sellList: Puntero a la lista de ventas
 * \return (-1) si algo salio mal (0) si Ok
 */
int controller_cobrarVenta(LinkedList* ListaClientes, LinkedList* ListaAfiches)
{
	int retornar=-1;
	LinkedList* bufferAfichesList;
	int bufferId;
	int indexAfiches;
	int indexCliente;
	Cliente* bufferCliente;
	Afiches* bufferAfiches;
	int bufferInt;
	if(ListaClientes!=NULL && ListaAfiches!=NULL)
	{
		bufferAfichesList = ll_cloneFilter(ListaAfiches, afiches_estaVendida);
		if( !controller_print(bufferAfichesList, afiches_print) && !utn_getInt("\nIngrese el ID de la venta a cobrar: ", "\nERROR!", &bufferId, 2, 99999, 1) &&
			!controller_buscarPorId(ListaAfiches, afiches_getAficheId, bufferId, &indexAfiches))
		{
			bufferAfiches = ll_get(ListaAfiches, indexAfiches);
			if(afiches_estaVendida(bufferAfiches) && !afiches_getClienteId(bufferAfiches, &bufferId) && !controller_buscarPorId(ListaClientes, cliente_getId, bufferId, &indexCliente))
			{
				bufferCliente = ll_get(ListaClientes, indexCliente);
				cliente_print(bufferCliente);
				if( !utn_getInt("\n\nDesea cobrar esta venta?\nPresione 1 para cobrar o 2 para volver atras: ", "\nERROR!", &bufferInt, 2,2, 1) &&
					bufferInt==1 && !afiches_setEstado(bufferAfiches, 1))
				{
					ll_set(ListaAfiches, indexAfiches, bufferAfiches);
					retornar=0;
				}
				else
				{
					printf("\nVenta NO cobrada\n");
				}
			}
			else
			{
				printf("\nID no encontrado!\n");
			}
		}
		else
		{
			printf("\nID no encontrado!\n");
		}
	}
	return retornar;
}


/** \brief Guardar en un archivo los clientes con las ventas cobradas
 * \param LinkedList* clientList: Puntero a la lista de clientes
 * \param LinkedList* sellList: Puntero a la lista de ventas
 * \return (-1) si algo salio mal (0) si Ok
 */
int controller_guardarClientesConAfichesCobrados(LinkedList* ListaCliente, LinkedList* ListaAfiches)
{
	int retornar=-1;
	Cliente* bufferClient;
	FILE* pFile;
	LinkedList* bufferAficheList;
	int counter;
	int bufferId;
	char bufferNombre[LONG_STRING];
	char bufferApellido[LONG_STRING];
	char bufferCuit[LONG_CUIT];
	if(ListaCliente!=NULL && ListaAfiches!=NULL)
	{
		bufferAficheList = ll_cloneFilter(ListaAfiches, afiches_noEstaVendida);
		pFile = fopen("cobrados.txt", "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,nombre,apellido,cuit,ventas_cobradas\n");
			for(int i=0;i<ll_len(ListaCliente);i++)
			{
				bufferClient = ll_get(ListaCliente, i);
				if( !cliente_getId(bufferClient, &bufferId) && !cliente_getNombre(bufferClient, bufferNombre) &&
					!cliente_getApellido(bufferClient, bufferApellido) && !cliente_getCuit(bufferClient, bufferCuit))
				{
					if(!ll_reduceInt(bufferAficheList, afiches_idCargado, bufferId ,&counter) && counter!=0)
					{
						fprintf(pFile, "%d,%s,%s,%s,%d\n", bufferId, bufferNombre, bufferApellido, bufferCuit, counter);
					}
				}
			}
		}
		retornar=0;
		fclose(pFile);
	}
	return retornar;
}


/** \brief Guardar en un archivo los clientes con las ventas NO cobradas
 * \param LinkedList* clientList: Puntero a la lista de clientes
 * \param LinkedList* sellList: Puntero a la lista de ventas
 * \return (-1) si algo salio mal (0) si Ok
 */
int controller_guardarClientesConAfichesNoCobrados(LinkedList* ListaClientes, LinkedList* ListaAfiches)
{
	int retornar=-1;
	Cliente* bufferClient;
	FILE* pFile;
	LinkedList* bufferAficheList;
	int counter;
	int bufferId;
	char bufferNombre[LONG_STRING];
	char bufferApellido[LONG_STRING];
	char bufferCuit[LONG_CUIT];
	if(ListaClientes!=NULL && ListaAfiches!=NULL)
	{
		bufferAficheList = ll_cloneFilter(ListaAfiches, afiches_estaVendida);
		pFile = fopen("a_cobrar.txt", "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "id,nombre,apellido,cuit,ventas_a_cobrar\n");
			for(int i=0;i<ll_len(ListaClientes);i++)
			{
				bufferClient = ll_get(ListaClientes, i);
				if( !cliente_getId(bufferClient, &bufferId) && !cliente_getNombre(bufferClient, bufferNombre) &&
					!cliente_getApellido(bufferClient, bufferApellido) && !cliente_getCuit(bufferClient, bufferCuit))
				{
					if(!ll_reduceInt(bufferAficheList, afiches_idNoCargado, bufferId ,&counter) && counter!=0)
					{
						fprintf(pFile, "%d,%s,%s,%s,%d\n", bufferId, bufferNombre, bufferApellido, bufferCuit, counter);
					}
				}
			}
		}
		retornar=0;
		fclose(pFile);
	}
	return retornar;
}
