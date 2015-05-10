#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct listnode_ {
	int data;
	struct listnode_* next;
} Listnode;

char findMax(char s[]);
double avgArray(int values[], size_t count);
int exists(int values[], size_t count, int (*fkt)(int));
int capsFile(char* filename);
int maxList(Listnode* head);
Listnode* addFront(Listnode* head, int item);
void freeList(Listnode* head);
int is42(int x);

/* Es folgen die Aufgaben */
// **************************

// Aufgabe 1 (15 Punkte)
/**
 * Bestimmt den haeufigsten Buchstaben in der Zeichenkette s
 * @param s Zeichenkette
 * @return Haeufigster Buchstabe in s
 */
char findMax(char s[]) {
    int letters[26]={0};
    int i=0;
    int j=0;
    int max=0;
    for(i=0;i<strlen(s);i++){
        if(s[i]>='a'&&s[i]<='z'){
            letters[s[i]-'a']++;
        }
        if(s[i]>='A'&&s[i]<='Z'){
            letters[s[i]-'A']++;
        }
    }
    for(i=0;i<26;i++){
        if(letters[i]>max){
            max=letters[i];
            j=i;
        }
    }
    return j+'A';

}

// Aufgabe 2 (10 Punkte)

/**
 * Bestimmt den Durchschnittswert der Elemente im uebergebenen Array
 * @param values Array der zu summierenden Elemente
 * @param count Anzahl der Elemente in dem Array values
 * @return Durchschnittswert der Elemente
 */
double avgArray(int values[], size_t count) {
    int i=0;
    int max=0;
    for(i=0;i<count;i++){
       max+=values[i];
    }
    return (float) max/count;

}

// Aufgabe 3 (15 Punkte)

/**
 * Wendet auf jedes Element eines int-Arrays eine Funktion an. Die angewendete
 * Funktion muss fuer jedes Element des int-Array 0 (falsch) oder 1 (wahr) liefern.
 * Falls die angewendete Funktion fuer ein Array-Element (wahr) 1 liefert, dann liefert
 * die exists auch wahr. Andernfalls liefert exists falsch.
 * Hinweis: is42 waere eine moegliche solche Funktion fkt.
 * @param values Array von int-Werten
 * @param count Anzahl der Elemente in values
 * @param fkt Funktionspointer auf die anzuwendende Funktion
 * @return 1 falls fkt fuer ein Elemet wahr liefert und 0 sonst.
 */
int exists(int values[], size_t count, int (*fkt)(int)) {
    int i=0;
    for(i=0;i<count;i++){
        if(fkt(values[i])){
            return 1;
        }
    }
    return 0;
}

// Aufgabe 4 (20 Punkte)

/**
 * Die Funktion ermittelt ob die Anzahl der Grossbuchstaben oder der Kleinbuchstaben
 * in der uebergebenen Datei groesser ist.
 * Dazu oeffnet die Funktion die Datei mit fopen
 * liest die Datei zeichenweise mit fgetc ein bis das Ergebnis
 * EOF ist und schliesst die Datei mit fclose
 * Hinweis: Umlaute / Sonderzeichen koennen wie immer unberuecksichtigt bleiben
 * @param filename Dateiname
 * @return wahr falls es mehr Grossbuchstaben als Kleinbuchstaben gibt, falsch sonst
 */
int capsFile(char* filename) {
    FILE * file;
    char c;
    int little=0;
    int big=0;
    file=fopen(filename,"r");
    if(file==NULL){
        exit(-1);
    }
    while((c=fgetc(file))!=EOF){
        if(c>='A'&&c<='Z'){
            big++;
        }
        if(c>='a'&&c<='z'){
            little++;
        }
    }
    if(big>little){
        return 1;
    }
    return 0;
}

// Aufgabe 5 (20 Punkte)

/**
 * Bestimmt den maximalen Wert der in der verketteten Liste
 * gespeicherten Werte.
 * @param head Zeiger auf das erste Element der Liste
 * @return Maximaler Wert in Liste falls Liste nicht leer und INT_MIN sonst.
 */
int maxList(Listnode* head) {
    int values=0;
    while(head!=NULL){
        values+=head->data;
        head=head->next;
    }
    if(values=0){
        return INT_MIN;
    }
    return values;
}

// Aufgabe 6 (20 Punkte)

// Eine Pruefungsliste soll in C verwaltet werden
// Erstellen Sie einen typedef Pruefung fuer eine Struktur.
// In der Stuktur sollen das Fach und seine Note
// enthalten sein.
// Erstellen Sie eine Funktion mkPr(fach, note), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.
typedef struct pruefungsListe_{
    char fach[50];
    float note;
    struct pruefungsListe_ *next;
}Pruefungen;

typedef Pruefungen * PtrPruefungen;

PtrPruefungen mkPr(char * fach,float note,PtrPruefungen head){
    PtrPruefungen newPruefung = malloc(sizeof(Pruefungen));
    newPruefung->next=head;
    strcpy(newPruefung->fach,fach);
    newPruefung->note=note;
    return newPruefung;
}

// Aufgabe 7 (20 Bonuspunkte)

/**
 * Die Funktion mix mischt zwei Zeichenketten fair. Aus Christiane und Max wird
 * CMharxistiane.
 * @param src1 Erster zu mischender String
 * @param src2 Zweiter zu mischender String
 * @param dest Zielpuffer fuer das Ergebnis.
 * Der Puffer muss mindestens strlen(src1) + strlen(src2) + 1 Zeichen
 * aufnehmen koennen.
 */
void mix(char* src1, char* src2, char* dest) {
    size_t size1=strlen(src1);
    size_t size2=strlen(src2);
    int i=0;
    int j=0;
    for(i=0;i<size1+size2;i++){
        if(i<size1){
            dest[j]=src1[i];
            j++;
        }
        if(i<size2){
            dest[j]=src2[i];
            j++;
        }
    }
}

// Ende der Aufgaben
// Die folgenden Hilfsfunktionen koennen Ihnen helfen, falls
// Sie Ihren Code testen moechten.

Listnode* addFront(Listnode* head, int item) {
	Listnode* newHead = (Listnode*) malloc(sizeof(Listnode));
	newHead->next = head;
	newHead->data = item;
	return newHead;
}

void freeList(Listnode* head) {
	if (head == NULL)
		return;
	freeList(head->next);
	free(head);
}

int is42(int x) {
	return x == 42;
}

void printList(PtrPruefungen list){
    while(list!=NULL){
        printf("%s %f\n",list->fach,list->note);
        list=list->next;
    }
}

void freePruefung(PtrPruefungen head){
    if(head==NULL){
        return;
    }
    freePruefung(head->next);
    free(head);
}

int main(void) {
    char string[]={"HAAALLOrjvtgtc4rv!§$%&/()=tg78vcwweffrdfwncrg4q84487wqznc5rc478x9qrnudcz2qxn49uzc4rt84rfqpxorrrrrrrrrRRRRRRRRRRRrrrr"};//R ist richtig :P
    printf("%c\n",findMax(string));
    char string1[]="Christian";
    char string2[]="Max";
    char fach[][30]={"Mathe","Irgendwas","Nochwas"};
    float note[]={1.2,1.3,5.0};
    char *dest;
    int i=0;
    PtrPruefungen liste = NULL;
    for(i=0;i<3;i++){
        liste=mkPr(fach[i],note[i],liste);
    }
    printList(liste);
    freePruefung(liste);
    dest=malloc(strlen((string1)+strlen(string2)+1)*sizeof(char));
    mix(string1,string2,dest);
    printf("%s\n",dest);
}
