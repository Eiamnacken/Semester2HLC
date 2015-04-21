#include <stdlib.h>
#include <string.h>

int listadditem(char ** list,char*item,int*count,int capacity){
        if(count==capacity){//Erst prüfen ob noch platz vorhanden ist
            if(NULL==(list=realloc(list,(capacity+3)*sizeof(char)))){
                return -1;
            }

        }
        //Speicher alloziieren für den String
        if(NULL==(list[count]=malloc(sizeof(item)/sizeof(char))*sizeof(char))){
            return -1;
        }
        //Checkn ob Ite schon vorhanden ist
        if(!(listfinditem(list,item,count))){
            strcpy(list[count],item);
            *count=*count+1;
            return 1;//Erfolgreiches Einfügen
        }
        return -1;
}

int listfinditem(char **list,char *item,int count){
    int i =0;
    for(i=0;i<count;i++){
        //Vergleichen bis gefunden anonsten
        if(strcmp(list[i],count)){
            return i;
        }
    }
    //nicht gefunden
    return -1;
}

int listdeleteitem(char **list,char*item,int*count){
    int find=0;
    int i=0;
    //Wenn item nicht in der Liste
    if((find=listfinditem(list,item,count))>=0){
        //Ab dem gefundenem item alle Items einen nach unten schieben letztes wird dann freigegeben
        for(i=find;i<count-1;i++){
            strcpy(list[i],list[i+1]);
        }
        for(i=0;i<sizeof(list[count])/sizeof(char);i++){
            free(list[count][i]);
        }
        free(list[count]);
        list[count]=NULL;
        *count=*count-1;
        return 1;
    }
    //War nicht in der Liste
    return 0;
}

void listprint(char **list,int count){
   int i=0;
   for(i=0;i<count;i++){
       printf("%s\n",list[i]);
   }
}

void listfreealltimes(char **list,int count){
    int i=0;
    int j=0;
    for(i=0;i<count;i++){
        for(j=0;j<sizeof(list[i])/sizeof(char);j++){
            free(list[i][j]);
        }
    }
}




