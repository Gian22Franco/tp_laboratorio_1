/*
 * Controller.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define LONG 4096


int controller_loadClienteFromText(char* path, LinkedList* listaCliente);
int controller_loadAfichesFromText(char* path, LinkedList* ListaAfiches);


int controllerMenu(LinkedList* listaProductos, LinkedList*listaArticulos);
int controller_addCliente(LinkedList* pArrayListCliente);

#endif /* CONTROLLER_H_ */
