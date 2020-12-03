/*
 * Cliente.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define LONG_STRING 51
#define LONG_CUIT 20

typedef struct{
	int id;
	char nombre[LONG_STRING];
	char apellido[LONG_STRING];
	char cuit[LONG_CUIT];
}Cliente;


Cliente* cliente_new();
Cliente* cliente_add();
Cliente* cliente_newWithParameters(int id, char* name, char* lastName, char* cuit);
Cliente* cliente_newWithParametersTxt(char* id, char* name, char* lastName, char* cuit);

int cliente_getId(void* this, int* pResult);
int cliente_setId(Cliente* this, int id);
int cliente_setIdTxt(Cliente* this, char* id);

int cliente_getNombre(Cliente* this, char* pResult);
int cliente_setNombre(Cliente* this, char* name);

int cliente_getApellido(Cliente* this, char* pResult);
int cliente_setApellido(Cliente* this, char* lastName);

int cliente_getCuit(Cliente* this, char* pResult);
int cliente_setCuit(Cliente* this, char* cuit);

int cliente_print(void* this);


void cliente_delete();

#endif /* CLIENTE_H_ */
