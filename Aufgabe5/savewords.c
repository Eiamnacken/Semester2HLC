#include <stdio.h>
#include <stdlib.h>


int readWords(FILE * file, char * * wordList, size_t size){
    char c; // Das eingelesen zeichen
    int counter=0; //Fuer die erste Dimension
    int counterSecondD=0; //Fuer die zweite Dimension
    int i=0;
    int j=0;
    while((c=fgetc(file))!=EOF){//Solange nciht das ende der Datei erreicht ist
        if(counterSecondD==size){//Realloc wenn speicher voll
            size += 10;//Groesse erhoehen
            if(NULL==(wordList = realloc(wordList,size * sizeof(char*)))){
                exit(EXIT_FAILURE);
            }
            for(i=size-10;i<size;i++){
                if(NULL==(wordList[i]=malloc(40*sizeof(char)))){
                    exit(1);
                }
            }
        }
            if(c!=' '&&c!='\t'&&c!='\r'&&c!='\n'){//Sonderzeichen sind keine woerter
                wordList[counterSecondD][counter]=c;//Speichere zeichen
                counter++;
            }else if(counter!=0){
                counterSecondD++;
                counter=0;
            }

    }
    for(i=0;i<counterSecondD;i++){
        for(j=0;j<40;j++){
            printf("%c",wordList[i][j]);
        }
        printf("%d",j);
        printf("\n");
    }
    for(i=0;i<counterSecondD;i++){
        free(wordList[i]);
    }
    free(wordList);
    return counterSecondD-1;//Wegen dem letzten zeichen -1 sonst immer einen zu viel
}



