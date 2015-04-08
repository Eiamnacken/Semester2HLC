/*
 *  Filename: ceasar.c
 *  Autor:Sven Marquardt
 *  Created on:08.04.2015
*/

#include <ceasar.h>

void ceasar(char text[], char offset){
    int i=0;
    for(i=0;;i++){
        if(text[i]!='\0'){
            if((text[i]>65&&text[i]<90)||(text[i]>97&&text[i]<122)){
                if(text[i]==90){
                    text[i]=65;
                    text[i]+=(offset-1);
                }else if(text[i]==122){
                    text[i]=97;
                    text[i]+=(offset-1);
                }else{
                    text[i]+=offset;
                }

            }
        }else{
            break;
        }
    }
}

