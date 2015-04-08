/*
 *  ceasar.h
 *  Autor: Sven Marquardt
 *  Created on: 08.04.15
*/
#ifndef CEASAR_H
#define CEASAR_H

/*
 * Verschluesselt einen uebergebenen Text
 * Verschiebt die Buchstaben um die stellen die im offste angegeben sind im Alphabet
 * groß und kleinschreibung wird beibehalten
 * @param   text[]  Der txt der verschluesselt werden soll
 * @param   offset  Gibt an um wie viele stellen ein Buchstabe verschoben werden sol
*/
void ceasar(char text[],char offset);

#endif // CEASAR_H

