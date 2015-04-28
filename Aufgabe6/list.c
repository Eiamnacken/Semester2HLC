#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int listadditem(char ** list,char *item,int *count,int *capacity){
    int **list2;
    int i=0;
    if(NULL(list2=malloc((*capacity+1)*sizeof(char*)))){
        return -1;
    }
   for(i=0;i<*count;i++){
        list2[i]=list[i];
    }

    if((listfinditem(list,item,*count))==-1){
        if(*count== capacity){
            printf("Die liste ist voll \n");
            return 0;
        }
        //Speicher alloziieren für den String
        if(NULL==(list[*count]=malloc(strlen(item)*sizeof(char)))){
            return 0;
        }
            strcpy(list[*count],item);
            *count=*count+1;
            return 1;//Erfolgreiches Einfügen
    }
    return 0;
}



int listfinditem(char **list,char *item,int count){
    int i =0;//
    if(count!=0){
        for(i=0;i<count;i++){
            //Vergleichen bis gefunden anonsten ...
            if((strcmp(list[i],item))==0){
                return i;
            }
        }
    }
    //...nicht gefunden
    return -1;
}

int listdeleteitem(char **list,char*item,int*count){
    int find=0;
    unsigned int i=0;
    if(list[0][0]==0){//Sonderfall Liste leer da caloc kann auf null prüfen
        printf("Liste ist leer");
        return 0;
    }
    //Wenn item nicht in der Liste
    if((find=listfinditem(list,item,*count))>=0){
        //Ab dem gefundenem item alle Items einen nach unten schieben letztes wird dann freigegeben
        for(i=find;i<*count-1;i++){
            strcpy(list[i],list[i+1]);
        }
        free(list[*count-1]);
        list[*count-1]=NULL;
        *count=*count-1;
        return 1;
    }
    //War nicht in der Liste
    return 0;
}



void listprint(char **list,int count){
   int i=0;
   for(i=0;i<count;i++){
       printf("Titel:%s\n",list[i]);
   }
}



void listfreeallitems(char **list,int count){
    int i=0;
    for(i=0;i<count;i++){
       free(list[i]);
    }
}





