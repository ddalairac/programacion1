#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //orderBy();
    userNameInput();
    return 0;
}
void orderBy(){

    int size = 10;
    int num[] = {2,6,9,34,32,54,98,13,45,89};
    int sex[] =  {'m','f','m','f','m','f','m','m','f','f',};
    int leg[] = {1212,8566,6789,3234,6532,4554,8198,4113,1345,7589};

    int i;
    int j;
    int auxInt;
    int auxChar;

    // desordenado
    printf("Desordenado \n");
    printf("Sex    Leg       Num  \n");
    for(i=0;i<size;i++){
        printf("%c      %d      %d   \n",sex[i],leg[i],num[i]);
    }
    printf("\n");
    /*
    // Ordenar por sexo
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(sex[i]>sex[j]){// ASC
                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = num[i];
                num[i] = num[j];
                num[j] = auxInt;

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;
            }
        }
    }

    // ordenado
    printf("Ordenado por sexo \n");
    printf("Sex    Leg       Num  \n");
    for(i=0;i<size;i++){
        printf("%c      %d      %d   \n",sex[i],leg[i],num[i]);
    }
    printf("\n");

*/

    // Ordenar por sexo y legajo
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(sex[i]<sex[j]){// DES
                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = num[i];
                num[i] = num[j];
                num[j] = auxInt;

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;
            } else {
                if(sex[i]==sex[j] && leg[i]>leg[j]){
                    auxInt = num[i];
                    num[i] = num[j];
                    num[j] = auxInt;

                    auxInt = leg[i];
                    leg[i] = leg[j];
                    leg[j] = auxInt;
                }
            }
        }
    }

    // ordenado
    printf("Ordenado por sexo y legajo \n");
    printf("Sex    Leg       Num  \n");
    for(i=0;i<size;i++){
        printf("%c      %d      %d   \n",sex[i],leg[i],num[i]);
    }
    printf("\n");

    printRow(sex,leg,num,size,1212);
}
void printRow(char sex[],int leg[],int num[], int size,int findLeg){
    int index = -1;
    int i;
    for(i=0;i<size;i++){
        if(findLeg == leg[i]){
                index = i;
            //printf("Sex    Leg       Num  \n");
            //printf("%c      %d      %d   \n",sex[i],leg[i],num[i]);
            break;
        }
    }
    return index;
}
void userNameInput(){
    char name[20];
    char surname[25];
    char fullName[46]; //19+25+2

    printf("ingrese su nombre: ");
    gets(name);
    printf("ingrese su apellido: ");
    gets(surname);
    //name = inputStr("ingrese su nombre",name);
    //surname = inputChar("ingrese su apellido",surname);
    strcpy(fullName, surname);
    strcat(fullName,', ');
    //strcat(fullName,name);

    puts(fullName);


}
