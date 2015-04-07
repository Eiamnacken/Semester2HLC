#include <stdio.h>
#include <stdlib.h>

#define Max 18*60
#define Min 8*60
#define SIZE 50
/*
 * Konvertiert zwei zahlen in ein einheitliches zeit format zum sortieren
 * @param   h1 Die stunde die zu konvertieren ist
 * @param   m1 Doie minute die zu konvertieren ist
 * @return  Die minuten anzahl der beiden zahlen
*/
int toMinutes(int h1, int m1);

/*
 * durchsucht die Liste nach der groessten freien zeit
 * @param   list    Die liste mit den anfangszeiten
 * @param   list2   Die liste mit den endzeiten
 * @param   size    Die groesse der listeneinraege
 * @return  Die stelle in list2 wo die meiste freie Zeit vorhanden ist
 *
*/
int search(int list[],int list2[],size_t size);

/*
 * Sortiert eine Liste mittels bubblesort
 * @param   list    list Die liste die zu sortieren ist
 * @param   size    Die anzahl an eintreagen
*/
void sort(int list[],size_t size);

int main(void)
{
    int begin[SIZE];
    int end[SIZE];
    int beginHour=0;
    int beginMinute=0;
    int endHour=0;
    int position=0;
    int endMinute=0;
    int counter =0;
    int freetime=0;
    char buffer[100];

    printf("Bite geben sie ihr Termine ein: ");
    while(1){
        fgets(buffer,100,stdin);
        if(sscanf(buffer,"%d:%d %d:%d %*s",&beginHour,&beginMinute,&endHour,&endMinute)==4){
            if(counter<=SIZE&&beginHour>=Min/60&&endHour<=Max/60)
            {
                begin[counter]=toMinutes(beginHour,beginMinute);
                end[counter]=toMinutes(endHour,endMinute);
                counter++;
            }else
            {
                printf("Sie haben nur platz f\u00fcr 50 eintraege ziwschen 8 und 18 Uhr.\n");
            }
        }else{
            printf("Ende\n");
            break;
        }
    }
    sort(begin,counter);
    sort(end,counter);
    position=search(begin,end,counter);
    if(position==-1){
        beginHour=Min;
        freetime=begin[0]-Min;
    }else if(position==counter){
        beginHour=end[position];
        freetime=(Max)-end[position];
    }else{
        beginHour=end[position];
        freetime=begin[position+1]-end[position];
    }

    printf("Programmieren II bearbeiten um %d f\u00fcr %d Minuten\n",beginHour/60,freetime);
   

}

int toMinutes(int h1, int m1){
    int end;
    end=(h1*60)+m1;
    return end;
}

void sort(int list[], size_t size){
    int i,j;
    int tmp=0;
    for(i=0;i<size-1;i++){
        for (j  = 0;  j< size-(i+1); j++) {
            if(list[j]>list[j+1]){
                tmp=list[j];
                list[j]=list[j+1];
                list[j+1]=tmp;
            }
        }
    }

}



int search(int list[], int list2[], size_t size){
    int i=0;
    int position=-1;
    int free=list[0]-Min;
    if(list[0]==Min&&list2[0]==Max){
        return position=-1;
    }
    if(size>1){
    for (i = 0; i < size; i++) {
        if(free<list[i]-list2[i-1])
        {
            free=list[i]-list2[i-1];
            position=i;
        }
    }
    }
    if(free<((Max)-list2[i])){
        position=size;
    }
    return position;
}
