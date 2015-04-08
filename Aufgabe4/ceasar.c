/*
 *  Filename: ceasar.c
 *  Autor:Sven Marquardt
 *  Created on:08.04.2015
*/
#include <stdio.h>
#include <ceasar.h>

void ceasar(char text[], char offset){
    unsigned int i=0;
    int j=0;
    for(i=0;;i++){
        if(text[i]!='\0'){
            if((text[i]>64&&text[i]<91)||(text[i]>96&&text[i]<123)){
                for(j=0;j<offset;j++){
                    if(text[i]==90){
                        text[i]=65;
                        text[i]-=1;


                    }if(text[i]==122){
                        text[i]=97;
                        text[i]-=1;


                    }
                        text[i]+=1;
                }
            }
        }else{
            break;
        }
    }
}

