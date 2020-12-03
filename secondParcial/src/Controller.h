/*
 * Controller.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define LONG 4096

int controllerMenu(LinkedList* listaProductos, LinkedList*listaArticulos);

int controller_loadClienteFromText(char* path, LinkedList* listaCliente);
int controller_loadAfichesFromText(char* path, LinkedList* ListaAfiches);

int controller_saveClienteAsTexto(char* path, LinkedList* listaCliente);
int controller_saveAfichesAsTexto(char* path, LinkedList* ListaAfiches);

int controller_addCliente(LinkedList* listaClientes);
int controller_addAfiche(LinkedList* listaClientes, LinkedList* listaAfiches);

int controller_buscarPorId(LinkedList* lista, int (*pFunc)(void*,int*), int id, int* index);
int controller_print(LinkedList* lista, int (*pFunc)(void*));

int controller_modificarAfiche(LinkedList* clientList, LinkedList* sellList);
int controller_cobrarVenta(LinkedList* ListaClientes, LinkedList* ListaAfiches);

int controller_guardarClientesConAfichesCobrados(LinkedList* clientList, LinkedList* sellList);
int controller_guardarClientesConAfichesNoCobrados(LinkedList* clientList, LinkedList* sellList);

#endif /* CONTROLLER_H_ */
