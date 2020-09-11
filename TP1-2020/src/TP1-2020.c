/*
 ============================================================================
 Name        : TP1-2020.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);
	float num1=0;
	int num1Validacion=0;
	float num2=0;
	int num2Validacion=0;
	int opcion;
	float respuestaCase1;
	float respuestaCase2;
	float sumado;
	float restado;
	float multiplicado;
	float dividido;
	float factorial1;
	float factorial2;

	do{
		printf("1-Ingresar 1er operando (A=%f)\n2-Ingresar 2do operando (B=%f)\n", num1, num2);
		printf("3-Calcular todas las operaciones\n a) Calcular la suma (A+B)\n b) Calcular la resta (A-B)\n c) Calcular la division (A/B)\n d) Calcular la multiplicacion (A*B)\n e) Calcular el factorial (A!/B!)\n4- Informar resultados\n5- Salir\n");
		fflush(stdin);
		scanf("%d", &opcion);
		switch(opcion){

				case 1:
					if((respuestaCase1 = utn_getNumeroFlotante(&num1, "\nIngrese el primer operando: ", "Error.\n", -999, 99999999, 3)) != 0)
									{
										printf("\nExpiraron sus intentos\n");
									}else{
										num1Validacion= 1;
									}

				    break;

				case 2:
									if((respuestaCase2 = utn_getNumeroFlotante(&num2, "\nIngrese el segundo operando: ", "Error.\n", -999, 99999999, 3)) != 0)
													{
														printf("\nExpiraron sus intentos\n");
													}else{
														num2Validacion=1;
													}

				    break;

				case 3:
					if (num1Validacion == 0 || num2Validacion == 0){

							printf("Falto ingresar uno o los 2 numeros. Volver a intentarlo.\n");

					}else if(num2 == 0){

						printf("\nEl numero ingresado debe ser distinto de 0 para poder realizar todas las operaciones con exito!\n");
						printf("\nIngrese un nuevo numero:\n");
						scanf("%f", &num2);
					}
						suma(&sumado,num1, num2);
						resta(&restado,num1, num2);
						multiplicacion(&multiplicado, num1, num2);
						division(&dividido, num1, num2);
						factorial1=factorial(num1);
						factorial2=factorial(num2);
						printf("\nCalculos exitosos!\n");
					break;
				case 4:
					if (num1Validacion == 0 || num2Validacion == 0){
						printf("Falto ingresar uno o los 2 numeros. Volver a intentarlo.\n");
					}
						printf("\nEl resultado de %f + %f es: %f \n", num1, num2, sumado);
						printf("\nEl resultado de %f - %f es: %f \n", num1, num2, restado);
						if(num2 == 0) //Validacion por si el numero es 0 en la division.
						                {
						                    printf("\nNo es posible dividir por cero.");
						                }
						                else
						                {
						                	printf("\nEl resultado de %f / %f es: %f \n", num1, num2, dividido);
						                }
						printf("\nEl resultado de %f * %f es: %f \n", num1, num2, multiplicado);

						if (factorial1 == 0) {
											printf("No se puede calcular factorial con numeros negativos\n");
										} else {
											printf("El factorial de %f es %f.\n", num1, factorial1);
										}
						if (factorial2 == 0) {
											printf("No se puede calcular factorial con numeros negativos\n");
										} else {
											printf("\nEl factorial de %f es %f.\n", num2, factorial2);
										}
					break;
		}
	}while(opcion != 5);
}
