#ifndef SAVEWORDS
#define SAVEWORDS
#include <stdio.h>
/**
  Zaehlt die woerter und sol sie ausgeben
 * @brief readWords
 * @param file  Die datei die gezaehlt wird
 * @param wordList  Die woerter
 * @param size  Die groesse der WortListe zweite dimension fuer realloc
 * @return  Die anzahl der woerter
 */
int readWords(FILE * file,char * * wordList,size_t size);
#endif // SAVEWORDS

