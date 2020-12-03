/*
 ============================================================================
 Name        : segundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* listaCliente = ll_newLinkedList();
	LinkedList* listaAfiche = ll_newLinkedList();

	controller_loadClienteFromText("clientes.txt", listaCliente);
	controller_loadAfichesFromText("afiches.txt", listaAfiche);

	controllerMenu(listaCliente, listaAfiche);

	return EXIT_SUCCESS;
}
