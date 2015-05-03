#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int listadditem(char** list, char* item, int* count, int capacity){

    if (*count >= capacity){
        return 0;
    }

        list[*count] = malloc(strlen(item)/sizeof(char));

        strcpy(list[*count], item);
        *count+=1;
        return 1;


}

int listfinditem(char** list, char* item, int count){

    if (list[0][0]!=0){

        int i;
        for (i = 0; i < count; i++){
            if (strcmp(list[i], item) == 0){
                return i;
            }
        }
        } return -1;

    }



int listdeleteitem(char** list, char* item, int* count){

    int find = 0;
    int i = 0;

    if ((find = listfinditem(list, item, *count)) >= 0){
    if (find >= 0){
        for (i = find; i < *count - 1; i++){
            strcpy(list[i], list[i + 1]);
        }
    }

    free(list[*count - 1]);
    list[*count - 1] = NULL;
    *count -= 1;
    return 1;
    }
    return 0;

}


void listprint(char** list, int count){
    int i;
    for (i = 0; i < count; i++)
        printf("Titel: %s\n", list[i]);
}

void listfreeallitems(char** list, int count){
    int i = 0;
    for (i; i < count; i++){
    free(list[i]);
    }
}
