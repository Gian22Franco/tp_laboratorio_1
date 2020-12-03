/*
 * Afiches.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#ifndef AFICHES_H_
#define AFICHES_H_
#define LONG_SIZE 101



typedef struct{
	int Id_afiche;
	int cliente_Id;
	int cantidad_afiches;
	char nombre_poster[LONG_SIZE];
	int zona;
	int estado;
}Afiches;


Afiches* afiches_new();
Afiches* afiches_newWithParameters(int clienteId, int aficheId, int cantidadAfiches, char* nombrePoster, int zona, int estado);
Afiches* afiches_newWithParametersTxt(char* clienteId, char* aficheId, char* cantidadAfiches, char* nombrePoster, char* zona, char* estado);


int afiches_getAficheId(Afiches* this, int* pResult);
int afiches_setAficheId(Afiches* this, int aficheId);
int afiches_setAficheIdTxt(Afiches* this, char* aficheId);

int afiches_getClienteId(Afiches* this, int* pResult);
int afiches_setClienteId(Afiches* this, int clienteId);
int afiches_setClienteIdTxt(Afiches* this, char* clienteId);

int afiches_getCantidadAfiches(Afiches* this, int* pResult);
int afiches_setCantidadAfiches(Afiches* this, int cantidadAfiches);
int afiches_setCantidadAfichesTxt(Afiches* this, char* aficheCantidad);

int afiches_getNombreAfiche(Afiches* this, char* pResult);
int afiches_setNombreAfiche(Afiches* this, char* nombrePoster);

int afiches_getZona(Afiches* this, int* pResult);
int afiches_setZona(Afiches* this, int zona);
int afiches_setZonaTxt(Afiches* this, char* zona);

int afiches_getEstado(Afiches* this, int* pResult);
int afiches_setEstado(Afiches* this, int estado);
int afiches_setEstadoTxt(Afiches* this, char* estado);

int afiches_estaVendida(void* this);
int afiches_noEstaVendida(void* this);

int afiches_idCargado(void* this, void* id);
int afiches_idNoCargado(void* this, void* id);

int afiches_print(void* this);


void afiches_delete();



#endif /* AFICHES_H_ */
