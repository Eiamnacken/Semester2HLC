/*
 * Programm:    Aufgab2
 * Funktion:    Liest ein 3 dimesnionalen Vektor ein und gibt den Betrag aus
 * Autor:       Sven Marquardt
*/
#include <stdio.h>
#include<math.h>

/*
 * Berechnet den Betrag eines Vekotrs
 * Param:y  Die y Achse des Vektors
 * Param:x  Die x achse des Vektors
 * Param:z  Die z achse des Vektors
 *
 * return:  Den Betrag des Vektors
*/
float vektor(int y,int x,int z);

int main(void)
{
    int dimension1=0;
    int dimension2=0;
    int dimension3=0;
    char buffer[9];
    printf("Bitte geben sie die 3 Dimensionen ihres Vektors wie folgt an\n");
    printf("Bitte geben sie Y,X und Z an: ");
    fgets(buffer,9,stdin);
    if(sscanf(buffer,"%d %d %d",&dimension1,&dimension2,&dimension3)==3){
        printf("Der betrag des Vektors(%dy,%dx,%dz) betreagt: ",dimension1,dimension2,dimension3);
        printf("%f\n",vektor(dimension1,dimension2,dimension3));
    }else{
        printf("Falsche eingabe");
    }

    return 0;

}

float vektor(int y, int x, int z){
    return sqrt((float)pow(y,2)+pow(x,2)+pow(z,2));
}

