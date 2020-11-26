/*
 * utn.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Gian
 */

#ifndef UTN_H_
#define UTN_H_
#define ARRAY_SIZE 4096

#define LIMITE_BUFFER_STRING 4096
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
int utn_getFloat(char* mensaje, char* mensajeError, float* pResultado,int reintentos,int maximo,int minimo);
int esUnNombreValido(char* cadena,int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getCuit(char msg[], char msgError[], char pResult[], int attemps, int limit);
int isCuit(char string[]);


#endif /* UTN_H_ */
