/*
Programmname:	Quelle.cpp
Funktion:		Zerlegt eine Zahl mittels Primfaktorzerlegung
Autor:			Sven Marquardt
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
Zerlegt eine Zahl in seine einzelnen Primzahlen
Beispiel: 10=5*2
parameter:	Die Zahl die geteilt werden soll
return:		Die Zahl durch die geteilt wurde
*/
int primDivision(int n);

/* Prueft eine Zahl ob sie prim ist
parameter:	Die zahl die zu pruefen ist auf prim
return:		1 oder 0 wenn zahl prim ist oder nciht.
*/
int isPrim(int n);

int eingabe = 0;

int main(void){
    unsigned int counter = 0;
    char buffer[9]; //unser buffer fuer die eingabe
    printf("Bitte die zu zerlegen Zahl eingeben: ");
    fgets(buffer, 9,stdin);
        if (((sscanf(buffer, "%d", &eingabe)) !=0) &&eingabe>0){ //prueft ob eine zahl  eingegeben wurde und ob sie groesser null ist
            printf("%d= ", eingabe); // Um zahl richtig darzustellen
            while (eingabe != 0){
                printf("%d", primDivision(eingabe)); // Die rueckgabe der Funktion wird ausgegeben also der Teiler
                if (eingabe > 0){ // Um eine * zeichen hinter der letzten Zahl zu vermeiden
                    printf(" * ");
                }
            }
            printf("\n");
        }
        else{
            printf("Falsche eingabe!!\n"); // Es wurde keine Zahl eingeben
        }
}



int primDivision(int n){
    int i = 0;
    if (n == 0) return 0;
    if (n == 1) {
        eingabe = 0;
        return 1;
    }
    for (i = 2; i <= n; i++){
        if (isPrim(i)){ // Pruefe ob zahl prim ist um zerlegen zu koennen
            if ((n%i) == 0){ //zerlege die zahl
                eingabe = n / i;
                return i; //Rueckgabe der Zahl mit der geteilt wurde
            }
        }
    }
    return 0;
}

int isPrim(int n){
    int i = 0;
    if (n == 2) return 1;
    for (i = 2; i<n; i++){ //Zaehlt solange hoch bis zahl sich teilen laesst also somit nicht prim
        if ((n%i) == 0){
            return 0;
        }
    }
    return 1;
}
