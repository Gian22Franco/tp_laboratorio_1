/*
 ============================================================================
 Name        : segundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Afiches.h"
#include "Controller.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaCliente = ll_newLinkedList();
	LinkedList* listaAfiche = ll_newLinkedList();

	controller_loadClienteFromText("clientes.txt", listaCliente);
	controller_loadAfichesFromText("afiches.txt", listaAfiche);

	controllerMenu(listaCliente, listaAfiche);

	return EXIT_SUCCESS;
}
