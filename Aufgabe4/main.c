#include <stdio.h>
#include <ceasar.h>
#include <anacae.h>



/*
 * Tauscht ein \n newline durch eine end notation \0
 * @param   string  Der text in dem das  newline getaushct wird
 * @param   size    Die groesse des Strings
*/
void changeNewLineIEnd(char string[],size_t size);

int main(int argc, char *argv[])
{
    char buffer[100];
    char string[100];
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
            printf("Bitte geben sie ihren Satz ein der verschl\u00fcsselt werden soll");
            printf("Es werden allerdings nur 100 zeichen eingelesen: ");
            fgets(string,100,stdin);
            fgets(string,100,stdin);
            sscanf(string,"%*s",string);
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
            sscanf(string,"%*s",string);
            char longText[]="Xl ptk xbg lmktaexgw-dtemxk Tikbemtz, ngw wbx Nakxg lvaenzxgwkxbsxag.Pbglmhg Lfbma, wtl Dbgg tg wbx Uknlm zxshzxg, nf wxf lvaxnllebvaxg Pbgw sn xgmzxaxg, lvaenxiymx ktlva wnkva wbx Zetlmnxkxg wxk Obvmhkr Fbxmldtlxkgx, whva gbvam ktlva zxgnz, nf sn oxkabgwxkg, wtll fbm baf tnva xbg zkbxllbzxk Lmtnupbkuxe axkxbgpxamx.";
            changeNewLineIEnd(string,sizeof(string)/sizeof(char));
            rasaec(string);
            printf("Der enschl\u00fcsselte Text:\n");
            printf("%s",string);

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
    return 0;


}

void changeNewLineIEnd(char string[], size_t size){
    unsigned int i=0;
    for(i=0;i<size;i++){
        if(string[i]=='\n'){
            string[i]='\0';
        }
    }
}

