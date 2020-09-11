/*
 * utn.h
 *
 *  Created on: 11 sep. 2020
 *      Author: Gian
 */


#ifndef UTN_H_
#define UTN_H_


/** \brief Funcion usada para pedir y validar numero.
 *
 * \param int Numero ingresado.
 * \param char Mensaje a mostrar para informar el paso a seguir.
 * \param char Mensaje de error en caso de que el dato ingresado no este entre los parametros establedicos.
 * \param int Paramentro de validación.
 * \param int Paramentro de validación.
 * \param int Cantidad de intentos.
 * \return float La funcion retorna un numero para usar en las futuras operaciones.
 *
 */
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
/** \brief Funcion usada para pedir y validar numero flotante.
 *
 * \param int Numero ingresado.
 * \param char Mensaje a mostrar para informar el paso a seguir.
 * \param char Mensaje de error en caso de que el dato ingresado no este entre los parametros establedicos.
 * \param int Paramentro de validación.
 * \param int Paramentro de validación.
 * \param int Cantidad de intentos.
 * \return float La funcion retorna un numero para usar en las futuras operaciones.
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, float minimo,float maximo,int reintentos);
/** \brief Funcion usada para pedir y validar caracter.
 *
 * \param int Caracter ingresado.
 * \param char Mensaje a mostrar para informar el paso a seguir.
 * \param char Mensaje de error en caso de que el dato ingresado no este entre los parametros establedicos.
 * \param int Paramentro de validación.
 * \param int Paramentro de validación.
 * \param int Cantidad de intentos.
 * \return float La funcion retorna un caracter para usar en las futuras operaciones.
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos);
/** \brief Funcion usada para imprimir un grupo de datos.
 *
 * \param int Grupo de datos.
 * \param int tamaño del grupo.
 * \return float La funcion retorna un grupo de datos del tamaño establecido.
 *
 */
int imprimirArrayInt(int pArray[], int size);
/** \brief Funcion usada para ordenar un grupo de datos.
 *
 * \param int Grupo de datos.
 * \param int tamaño del grupo.
 * \return float La funcion retorna un grupo de datos del tamaño establecidoordenado.
 *
 */
int ordenarArrayInt(int* pArray, int limite);
/** \brief Funcion usada para calcular el promedio de un grupo de datos.
 *
 * \param int Grupo de datos.
 * \param int tamaño del grupo.
 * \return float La funcion retorna el promedio de un grupo de datos del tamaño establecidoordenado.
 *
 */
float promedioArrayInt(float* resultado, int* pArray, int limite);
/** \brief Funcion usada para calcular el maximo de un grupo de datos.
 *
 * \param int Grupo de datos.
 * \param int tamaño del grupo.
 * \return float La funcion retorna el maximo de un grupo de datos del tamaño establecidoordenado.
 *
 */
int maximoArrayInt(int* resultado, int*pArray, int limite);
/** \brief Funcion usada para calcular el minimo de un grupo de datos.
 *
 * \param int Grupo de datos.
 * \param int tamaño del grupo.
 * \return float La funcion retorna el minimo de un grupo de datos del tamaño establecidoordenado.
 *
 */
int minimoArrayInt(int* resultado, int*pArray, int limite);
/** \brief Funcion usada para sumar dos numeros.
 *
 * \param float resultado.
 * \param float numero uno.
 * \param flaot numero dos.
 * \return int La funcion retorna la suma de los dos numeros pasados como variable.
 *
 */
int suma(float* pResultado,float numero1, float numero2);
/** \brief Funcion usada para restar dos numeros.
 *
 * \param float resultado.
 * \param float numero uno.
 * \param flaot numero dos.
 * \return int La funcion retorna la resta de los dos numeros pasados como variable.
 *
 */
int resta(float* pResultado,float numero1, float numero2);
/** \brief Funcion usada para multiplicar dos numeros.
 *
 * \param float resultado.
 * \param float numero uno.
 * \param flaot numero dos.
 * \return int La funcion retorna la multiplicación de los dos numeros pasados como variable.
 *
 */
int multiplicacion(float* pResultado,float numero1, float numero2);
/** \brief Funcion usada para dividir dos numeros.
 *
 * \param float resultado.
 * \param float numero uno.
 * \param flaot numero dos.
 * \return int La funcion retorna la division de los dos numeros pasados como variable.
 *
 */
int division(float* pResultado,float numero1, float numero2);
/** \brief Funcion usada para calcular el factorial de un numero.
 *
 * \param float numero al cual se le va a calcular el factorial.
 * \return int La funcion retorna el factorial de un numero pasado como variable.
 *
 */
int factorial(float numero1);




#endif /* UTN_H_ */
