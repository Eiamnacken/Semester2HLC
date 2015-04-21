#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <savewords.h>
#define WORDLENGTH 40 //Ich erwarte das ein Deutsches wort nicht mehr als 40 Zeichen hat
#define LISTLENGTH 10 //Anzahl der woerter
int main(void)
{
    char buffer[100];
    FILE * file; //Die eingelesene Datei
    char * * wordList; //Unsere Woerter Liste
    int words=0;//Anzahl der Woerter
    int i=0;//Zaehler fuer die for-Schleife
    int j=0;//Zaehler fuer for-Schleife
    printf("Bitte geben sie an welche datei sie einlesen möchten: ");
    fgets(buffer,100,stdin);
    buffer[strcspn(buffer,"\n")]=0;//\n herausfiltern
    file = fopen(buffer,"r");//Datei zm lesen oeffnen
    printf("\n");//Platz machen
    if(file==NULL){//Bei nicht vorhandener Datei
        printf("Falscher dateiname oder Datei nicht vorhanden\n");
        exit(EXIT_FAILURE);
    }else{
        if((wordList=malloc(LISTLENGTH*sizeof(char*)))==NULL){
            printf("Speicher Allozieieren fehlgeschlagen");
            exit(EXIT_FAILURE);
        }else{
            for(i=0;i<LISTLENGTH;i++){
                if(NULL==(wordList[i]=malloc(WORDLENGTH*sizeof(char)))){
                    exit(EXIT_FAILURE);
                }
            }
          words=readWords(file,wordList,LISTLENGTH);//Liest di woerter und gibt die Anzahl zurueck
          /*for(i=0;i<words;i++){
              for(j=0;j<WORDLENGTH;j++){
                  printf("%c",wordList[i][j]);
              }
              printf("\n");
          }*/
          /*for(i=0;i<WORDLENGTH;i++){
              free(wordList[i]);
          }
          free(wordList);*/
          fclose(file);
          file=NULL;
          printf("%s %d\n",buffer,words);
        }
    }



}

