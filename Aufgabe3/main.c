#include <stdio.h>
#include <stdlib.h>

#define Max 20
#define Min 8
#define SIZE 50

int toMinutes(int h1, int m1);

int search(int list[],int list2[],size_t size);

void sort(int list[],size_t size);

void swap(int *x,int *y);



int main(void)
{
    int begin[SIZE];
    int end[SIZE];
    int beginHour=0;
    int beginMinute=0;
    int endHour=0;
    int endMinute=0;
    int counter =0;
    int freetime=0;
    char buffer[100];

    printf("Bite geben sie ihr Termine ein: ");
    while(1){
        fgets(buffer,100,stdin);
        if(sscanf(buffer,"%d:%d %d:%d %*s",&beginHour,&beginMinute,&endHour,&endMinute)==4){
            if(counter<=SIZE&&beginHour>=Min&&endHour<=Max)
            {
                begin[counter]=toMinutes(beginHour,beginMinute);
                end[counter]=toMinutes(endHour,endMinute);
                counter++;
            }else
            {
                printf("Sie haben nur platz fuer 50 eintraege ziwschen 8 und 18 Uhr.\n");
            }
        }else{
            printf("Ende\n");
            break;
        }
    }
    sort(begin,counter);
    sort(end,counter);
    beginHour=end[search(begin,end,counter)];
    freetime=(counter==search(begin,end,counter)?(Max*60)-beginHour:begin[(search(begin,end,counter))+1]-beginHour);
    printf("Programmieren II bearbeiten um %d f\x81 \br %d Minuten\n",beginHour/60,freetime);
   
    //sort(minutes,0,size);
    //Listen werden auf den Stack gespeichert
}

int toMinutes(int h1, int m1){
    int end;
    end=(h1*60)+m1;
    return end;
}

/*void sort(int list[][], int i, size_t size){

}*/


void sort(int list[], size_t size){
    int i,j;
    for(i=0;i<size-1;i++){
        for (j  = 0;  j< size-(i+1); j++) {
            if(list[j]>list[j+1]){
                swap(list[j],list[j+1]);
            }
        }
    }

}

void swap(int *x, int *y){
   int tmp = *x;
   *x=*y;
   *y=tmp;
}

int search(int list[], int list2[], size_t size){
    int i=0;
    int position=0;
    int free=list[0]-Min*60;
    for (i = 1; i < size; i++) {
        if(free<list[i]-list2[i-1])
        {
            free=list[i]-list2[i-1];
            position=i;
        }
    }
    if(free<((Max*60)-list2[i])){
        free=((Max*60)-list2[i]);
        position=size;
    }
    return position;
}
