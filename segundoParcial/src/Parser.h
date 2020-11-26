/*
 * Parser.h
 *
 *  Created on: 25 nov. 2020
 *      Author: Gian
 */

#ifndef PARSER_H_
#define PARSER_H_


int parser_clientFromText(FILE* pFile , LinkedList* clientList);
int parser_afichesFromText(FILE* pFile , LinkedList* sellList);


#endif /* PARSER_H_ */
