/*
 * utn.c
 *
 *  Created on: 11 sep. 2020
 *      Author: Gian
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}


int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos){

		int retorno = -1;
		float bufferFloat;
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%f",&bufferFloat);
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}while(reintentos >= 0);
		}
		return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

int imprimirArrayInt(int pArray[], int size)
	{
		int i;
		int retorno = -1;
		if (pArray != NULL && size > 0){
			for(i = 0; i < size; i++)
							{
								printf("El indice [%d] tiene como valor %d\n", i, pArray[i]);
							}
		}
		return retorno;
	}

float promedioArrayInt(float* resultado, int*pArray, int limite)
{
	int i;
	int sumador=0;
	int contador =0;
	int retorno = -1;

	if (pArray != NULL && limite >= 0)
	{
		retorno=0;
		for (i=0; i<limite;i++)
			{
			  sumador+= pArray[i];
			  contador ++;
			}
	}
	*resultado = sumador / contador;
	return retorno;
}

int maximoArrayInt(int*resultado, int*pArray, int limite)
{
	int i;
	int maximo;
	int retorno = -1;

	for (i=0; i < limite; i++)
	{
		retorno = 0;
		if(maximo==0)
		{
			maximo=pArray[i];
		}
		if(maximo>pArray[i])
		{
			maximo = pArray[i];
		}
	}

	*resultado = maximo;
	return retorno;
}

int minimoArrayInt(int*resultado, int*pArray, int limite)
{
	int i;
	int minimo;
	int retorno =-1;

	for (i=0; i < limite; i++)
	{
		retorno =0;
		if(minimo==0)
		{
			minimo = pArray[i];
		}
		if(minimo<pArray[i])
		{
			minimo = pArray[i];
		}
	}
	*resultado=minimo;
	return retorno;
}

int ordenarArrayInt(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador=0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<limite - 1 ; i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

int suma(float* pResultado, float numero1, float numero2){
	*pResultado= numero1 + numero2;
	return 0;
}
int resta(float* pResultado, float numero1, float numero2){
	*pResultado= numero1 - numero2;
	return 0;
}
int multiplicacion(float* pResultado, float numero1, float numero2){
	*pResultado= numero1 * numero2;
	return 0;
}
int division(float* pResultado, float numero1, float numero2){
		*pResultado = numero1 / numero2;
	return 0;
}
int factorial(float numero){
	float resp;
	if(numero <= 0){
		return 0;
	}
	if(numero==1)
	return 1;
	resp=numero* factorial(numero-1);
	return (resp);
}
