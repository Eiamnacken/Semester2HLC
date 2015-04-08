#include <stdio.h>
#include <ceasar.h>
#include <anacae.h>
void changeNewLineIEnd(char string[],size_t size);

int main(int argc, char *argv[])
{
    char buffer[100];
    char string[101];
    int offset=0;
    char decision;
    size_t size = sizeof(string)/sizeof(char);
    do{
        printf("\nBitte geben sie an welches Programm sie starten m\u00f6chten\n");
        printf("1 f\u00fcr Verschl\u00fcsseln oder 2 f\u00fcr Entschl\u00fcsseln 3 zum abbrechen: ");
        decision=getchar();
        switch(decision){
        case '1':{
            printf("\n");
            printf("Bitte geben sie ihren Satz ein der verschl\u00fcsselt werden soll:");
            fgets(string,101,stdin);
            fgets(string,100,stdin);
            changeNewLineIEnd(string,size);
            printf("Bitte gebe sie an um wie viel sie verschl\u00fcsseln m\u00f6chten: ");
            fgets(buffer,100,stdin);
            sscanf(buffer,"%d",&offset);
            ceasar(string,offset);
            printf("%s \n",string);
        }
            break;
        case '2':{
            printf("Bitte geben sie ihren zu entschl\u00fcsselnden Satz ein: \n");
            fgets(string,100,stdin);
            fgets(string,100,stdin);
            char longText[]="Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag.Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxg Pbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk Obvmhkr Fbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baf tnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";
            changeNewLineIEnd(longText,sizeof(longText)/sizeof(char));
            rasaec(longText);
            printf("Der enschl\u00fcsselte Text:\n");
            printf("%s",longText);
        }
            break;

        case '3':
            printf("Programm beendet!\n");
            decision='0';
            break;
        default:
            printf("Falsche eingabe\n");
            decision='0';
            break;
        }
    }while(decision!='0');


}

void changeNewLineIEnd(char string[], size_t size){
    unsigned int i=0;
    for(i=0;i<size;i++){
        if(string[i]=='\n'){
            string[i]='\0';
        }
    }
}

