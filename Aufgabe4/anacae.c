#include <anacae.h>
#include <string.h>
#include <ceasar.h>

#define MAX 27

void addChar(char buffer,char counts[][2]);

void rasaec(char string[]){
    int i=0;
    int highestValue=0;
    char buffer[sizeof(string)/sizeof(char)]={0};
    char anzahl[MAX][2]={0};
    strcpy(buffer,string);
    while(buffer[i]!='\0'){
        if(buffer[i]<97){
            buffer[i]+=32;
        }
        addChar(buffer[i],anzahl);

    }
    for(i=0;i<MAX;i++){
        if(anzahl[i][1]>highestValue){
            highestValue=anzahl[i][1];
        }
    }
    ceasar(string,highestValue);
}

void addChar(char buffer, char counts[][2]){
    int i=0;
    while(i<MAX){
        if(buffer==counts[i][0]){
            counts[i][1]+=1;
            return;
        }
        i++;
    }
    i=0;
    while(counts[i][1]==0){
        i++;
    }
    if(i<MAX){
    counts[i][0]=buffer;
    counts[i][1]+=1;
    return;
    }
}
