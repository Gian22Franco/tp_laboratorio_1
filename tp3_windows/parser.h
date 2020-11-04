/*
 * parser.h
 *
 *  Created on: 2 nov. 2020
 *      Author: Gian
 */

#ifndef PARSER_H_
#define PARSER_H_

/*brief lee de un archivo abierto de forma binaria y guarda todo lo leido en el linkedlist
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/*brief lee de un archivo abierto en forma de texto y guarda todo lo leido en el linkedlist
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
