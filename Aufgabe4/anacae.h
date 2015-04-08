#ifndef ANACAE_H
#define ANACAE_H
/*
 * Findet den meist genutzten Buchstaben in einer Verschluesselung
 * und findet durch die differenz heraus um welchen offset der Text verschlüsselt wurde
 * Diesen offset gibt die Funktion zurueck
 * @param   string[]    Der text der entschlüsselt werden soll
 * @return  Den offset um den Text wieder zu entschluesseln
*/
void rasaec(char string[]);
#endif // ANACAE_H

