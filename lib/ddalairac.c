#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>// tolower
#include <time.h>

#ifdef __unix__
    #include <linux/string.h> // linux
    #include <termios.h> // linux
    #include <stdio_ext.h>
#else
    #include <string.h>
    #include <conio.h> // input output
#endif // __unix

#define TRUE 1
#define FALSE 0


#include "struct_date.h"


/**********************************************
*
*  Libreria de funciones genericas.
*
***********************************************/


int validNumber(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if(str[i] < '0' || str[i] > '9'){
           validation = 0;
        }
       i++;
   }
   return validation;
}

int validFloat(char str[]){
    int i=0;
    int validation = 1;
    int contDot = 0;
    int contNum = 0;
    while(str[i] != '\0'){
        if(str[i] < '0' || str[i] > '9' ){
            if( str[i] != '.'){
                validation = 0;
            } else if( str[i] == '.'){
                contDot++;
            }
        } else {
            contNum++;
        }
        i++;
    }
    if(contDot > 1){
        validation = 0;
    }

    /* introducir solo '.' es valido. Es igual a 0.00,
    pero me parece sucio asi que valido que introduzca por lo menos 1 numero*/
    if(contDot == 1 && contNum < 1){
        validation = 0;
    }
    if(str[0] == '.'){
        validation = 0;
    }

    return validation;
}

int validLetter(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
           validation = 0;
        }
       i++;
   }
   return validation;
}

int validAlphaNumeric(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){
           validation = 0;
       }
       i++;
   }
   return validation;
}

int validDate(char cdd[],char cmm[],char cyy[]){
   int vd,vm,vy,dd,mm,yy;
   int validation = 0;

   vd = validNumber(cdd);
   vm = validNumber(cmm);
   vy = validNumber(cyy);

   if(vd+vm+vy == 3){
        dd = atoi(cdd);
        mm = atoi(cmm);
        yy = atoi(cyy);
        //valid year
        if(yy>=1800 && yy<=9999){
            //valid month
            if(mm>=1 && mm<=12){
                //valid days
                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                    //printf("Date is valid.\n");
                    validation = 1;
                } else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                    //printf("Date is valid.\n");
                    validation = 1;
                } else if((dd>=1 && dd<=28) && (mm==2)){
                    //printf("Date is valid.\n");
                    validation = 1;
                } else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                    //printf("Date is valid.\n");
                    validation = 1;
                } else {
                    //printf("Error, dia es invalido\n");
                    validation = -1;
                }
            } else {
                //printf("Error, mes es invalido \n");
                validation = -2;
            }
        } else {
            //printf("Error, año es invalido\n");
            validation = -3;
        }
    } else {
        //printf("Error, fecha invalida. Ingrese solo numeros separados por espacios\n");
        validation = 0;
    }
   return validation;
}

int validPhone(char str[]){
    int i=0;
    int countHyphen=0;
    int countPluss=0;
    int validation = 1;
    while(str[i] != '\0'){
        if((str[i] != '+') && (str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')){
            validation = 0;
        }
        if(str[i] == '-'){
            countHyphen++;
        }
        if(str[i] == '+'){
            countPluss++;
        }
        i++;
   }
    if(countHyphen > 2){ // debe tener 2 guiones maximo
        validation = -1;
    }
    if(countPluss > 1){ // debe tener 1 mas como maximo
        validation = -2;
    }

    return validation;
}

int inputInt(char message[]){
    int number;
    //printf("Ingrese un int \n");
    printf("%s",message);
    scanf("%d", &number);
    return number;
}

float inputFloat(char message[]){
    float number;
    printf("%s",message);
    scanf("%f", &number);
    return number;
}

char inputChar(char message[]){
    char character;
    printf("%s",message);
    fflush(stdin);// Win
    //fpurge(stdn);// Linux OSx
    scanf("%c", &character);
    return character;
}

void inputStr(char message[],char str[]){
    printf("%s ",message);
    #ifdef __unix__
        //fpurge(stdn);// Linux OSx
        scanf("%s",str);//linux
    #else
        fflush(stdin);// Win
        gets(str); // win
    #endif // __unix
}

int inputValidInt(char message[], int max){
    int value;
    char input[500] ;
    int length;
    int loop = TRUE;

    do{
        if(max < 0){
            printf("Error de configuracion: inputValidInt(.. max) debe ser un numero positivo \n\n");
            break;
        }
        inputStr(message,input);
        length = strlen (input);
        if(length > 0){
            if(validNumber(input)){
                if(max == 0 || atoi(input) <= max){
                    value = atoi(input);
                    loop = FALSE;
                } else {
                    printf("Error, debe introducir un numero menor o igual a %d. \n\n",max);
                }
            } else {
                printf("Error, debe introducir solo numeros. \n\n");
            }

        } else {
            if(length == 0){
                printf("Error, este campo es Obligatorio. \n\n");
            } else {
            }
        }

    }while(loop);

    return value;
}

float inputValidFloat(char message[], int max){
    float value;
    char input[500] ;
    int length;
    int loop = TRUE;

    do{
    if(max < 0){
        printf("Error de configuracion: inputValidInt(.. max) debe ser un numero positivo \n\n");
        break;
    }
    inputStr(message,input);
    length = strlen (input);
    if(length > 0){
        if(validNumber(input)){
            if(max == 0 || atoi(input) <= max){
                value = atoi(input);
                loop = FALSE;
            } else {
                printf("Error, debe introducir un numero entre 0 y %d. \n\n",max);
            }
        } else {
            printf("Error, debe introducir solo numeros. \n\n");
        }
    } else {
        if(length == 0){
            printf("Error, este campo es Obligatorio. \n\n");
        } else {
        }
    }

    }while(loop);

    return value;
}

void inputValidLetterString(char message[], char str[],int length){
    char input[300] ;
    int inputLength;
    int loop = TRUE;
    int max = length - 1;

    do{
        inputStr(message,input);
        inputLength = strlen (input);
        if(inputLength > 0 && inputLength < max){
            if(validLetter(input)){
                strcpy(str, input);
                loop = FALSE;

            } else {
                printf("Error, debe introducir solo letras \n\n");
            }

        } else {
            if(inputLength == 0){
                printf("Error, este campo es Obligatorio. \n\n");
            } else {
                printf("Error, el maximo de caracteres es %d. \n\n", max);
            }
        }
    }while(loop);
}

void inputValidAlphaNumericString(char message[], char str[],int length){
    char input[300] ;
    int inputLength;
    int loop = TRUE;
    int max = length - 1;

    do{
        inputStr(message,input);
        inputLength = strlen (input);
        if(inputLength > 0 && inputLength < max){
            if(validAlphaNumeric(input)){
                strcpy(str, input);
                loop = FALSE;

            } else {
                printf("Error, debe introducir solo letras o numeros \n\n");
            }

        } else {
            if(inputLength == 0){
                printf("Error, este campo es Obligatorio. \n\n");
            } else {
                printf("Error, el maximo de caracteres es %d. \n\n", max);
            }
        }
    }while(loop);
}

void inputValidDate(char message[], eDate date){
    int dd,mm,yy;
    char cdd[20],cmm[20],cyy[20];
    int loop = TRUE;
    int validation = 0;

    do{
        printf("%s",message);
        printf("(DD MM YYYY): ");
        scanf("%s %s %s", cdd, cmm, cyy);

        validation = validDate(cdd,cmm,cyy);
        switch(validation){
            case 0:
                printf("Error, fecha invalida. Ingrese solo numeros separados por espacios\n");
                break;

            case -1:
                printf("Error, dia invalido\n");
                break;

            case -2:
                printf("Error, mes invalido \n");
                break;

            case -3:
                printf("Error, ano invalido\n");
                break;

            case 1:
                loop = FALSE;
                dd = atoi(cdd);
                mm = atoi(cmm);
                yy = atoi(cyy);
                //printf("Fecha correcta %d/%d/%d \n",dd,mm,yy);
                break;
            default:
                printf("Error, fecha invalida. \n");
                break;
        }

    } while(loop == TRUE);

    date.day = dd;
    date.month = mm;
    date.year = yy;
}

void inputValidPhone(char message[], char str[],int length){
    char input[300] ;
    int inputLength, valitation;
    int loop = TRUE;
    int max = length - 1;

    do{
        inputStr(message,input);
        inputLength = strlen (input);
        if(inputLength > 0 && inputLength <= max){
            valitation = validPhone(input);
            if(valitation == 1){
                strcpy(str, input);
                loop = FALSE;

            } else {
                switch(valitation){
                    case 0:
                        printf("Error, caracter incorrecto (validos: numeros, espacios, guiones y un signo mas) \n\n");
                        break;
                    case -1:
                        printf("Error, no puede haber mas de 2 guiones \n\n");
                        break;
                    case -2:
                        printf("Error, solo puede haber un signo + \n\n");
                        break;
                }
            }

        } else {
            if(inputLength == 0){
                printf("Error, Este campo es Obligatorio. \n\n");
            } else {
                printf("Error, El maximo de caracteres es %d. \n\n", max);
            }
        }
    }while(loop);
}


void initRandom(){
    srand(time(NULL));
}

int getRandomNumber(int from, int to){
    return from + (rand() % (to + 1 - from) );
}

char getRandomChar(){
    char randomletter;
    int r = getRandomNumber(0, 25);
    randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[r];
    return randomletter;
}

char getRandomCharCustom(char options[], int size){
    char randomletter;
    randomletter = options[getRandomNumber(0, size)];
    return randomletter;
}

void getRandomString(char string[], int size){
    char randomString[size+1];
    int i;
    for(i=0; i < size; i++){
        randomString[i] = getRandomChar();
    }
    randomString[size] = '\0';
    strcpy(string,randomString);
}

int getRandomName(char string[],int size){
    char names[][20] = {
        {'A','v','a','\0'}, {'L','i','a','m','\0'}, {'E','m','m','a','\0'}, {'N','o','a','h','\0'}, {'W','i','l','l','i','a','m','\0'}, {'J','a','m','e','s','\0'}, {'L','o','g','a','n','\0'}, {'B','e','n','j','a','m','i','n','\0'}, {'M','a','s','o','n','\0'}, {'E','l','i','j','a','h','\0'}, {'O','l','i','v','e','r','\0'}, {'J','a','c','o','b','\0'}, {'L','u','c','a','s','\0'}, {'M','i','c','h','a','e','l','\0'}, {'A','l','e','x','a','n','d','e','r','\0'}, {'E','t','h','a','n','\0'}, {'D','a','n','i','e','l','\0'}, {'S','o','f','i','a','\0'}, {'M','a','t','t','h','e','w','\0'}, {'E','l','l','a','\0'}, {'A','i','d','e','n','\0'}, {'H','e','n','r','y','\0'}, {'J','o','s','e','p','h','\0'}, {'J','a','c','k','s','o','n','\0'}, {'A','r','i','a','\0'}, {'S','a','m','u','e','l','\0'}, {'G','r','a','c','e','\0'}, {'S','e','b','a','s','t','i','a','n','\0'}, {'D','a','v','i','d','\0'}, {'C','a','r','t','e','r','\0'}, {'W','y','a','t','t','\0'}, {'R','i','l','e','y','\0'}, {'J','a','y','d','e','n','\0'}, {'L','a','y','l','a','\0'}, {'J','o','h','n','\0'}, {'O','w','e','n','\0'}, {'N','o','r','a','\0'}, {'D','y','l','a','n','\0'}, {'Z','o','e','y','\0'}, {'L','u','k','e','\0'}, {'M','i','l','a','\0'}, {'G','a','b','r','i','e','l','\0'}, {'H','a','n','n','a','h','\0'}, {'I','s','a','a','c','\0'}, {'L','i','l','y','\0'}, {'G','r','a','y','s','o','n','\0'}, {'J','a','c','k','\0'}, {'J','u','l','i','a','n','\0'}, {'L','e','v','i','\0'}, {'L','u','n','a','\0'}, {'C','h','r','i','s','t','o','p','h','e','r','\0'}, {'J','o','s','h','u','a','\0'}, {'A','n','d','r','e','w','\0'}, {'L','e','a','h','\0'}, {'M','a','t','e','o','\0'}, {'R','y','a','n','\0'}, {'H','a','z','e','l','\0'}, {'J','a','x','o','n','\0'}, {'E','l','l','i','e','\0'}, {'N','a','t','h','a','n','\0'}
    };
    char name[20] = " ";
    int i,length;
    int valid = 0;
    for(i=0; i < 60; i++){
        strcpy(name,names[getRandomNumber(0,59)]);
        length = strlen(name);
        if(length < size){
            valid = 1;
            break;
        }
    }
    //printf("length %5d name %20s \n",length,name);
    strcpy(string,name);
    return valid;
}
int getRandomLastname(char string[],int size){
    char names[][20] = {
        {'A','l','v','a','r','e','z','\0'},
        {'B','e','n','í','t','e','z','\0'},
        {'B','e','r','m','u','d','e','z','\0'},
        {'B','l','á','z','q','u','e','z','\0'},
        {'D','í','e','z','\0'},
        {'D','o','m','í','n','g','u','e','z','\0'},
        {'E','n','r','í','q','u','e','z','\0'},
        {'F','e','r','n','á','n','d','e','z','\0'},
        {'M','u','l','l','e','r','\0'},
        {'S','m','i','r','n','o','v','\0'},
        {'S','m','i','t','h','\0'},
        {'H','e','r','n','a','n','d','e','z','\0'},
        {'G','o','n','z','a','l','e','z','\0'},
        {'G','a','r','c','i','a','\0'},
        {'N','g','u','y','e','n','\0'},
    };
    char name[20] = " ";
    int i,length;
    int valid = 0;
    for(i=0; i < 15; i++){
        strcpy(name,names[getRandomNumber(0,14)]);
        length = strlen(name);
        if(length < size){
            valid = 1;
            break;
        }
    }
    //printf("length %5d name %20s \n",length,name);
    strcpy(string,name);
    return valid;
}


void setSleep(int ms){
    #ifdef __unix__
        usleep(ms*1000);
    #else
        _sleep(ms);
    #endif // __unix__
}

int calcAddition(int a, int b){
    int result = a + b;
    return result;
}

int calcSubtraction(int a, int b){
    int result = a - b;
    return result;
}

int calcMultiplication(int a, int b){
    int result = a * b;
    return result;
}

float calcDivision(int a, int b){
    float result = (float)a / b;
    return result;
}

int calcFactorial(int number){
    int result = 1;
    int i;
    for (i=number;i>0;i--){
        result = result*i;
    }
    return result;
}

int calcPrime(int number){
    int i;
    int flag = 0;
    int isPrime = 1;
    for (i = 1; i <= number; i++){
        if(number%i == 0){
            if(flag == 0){
                flag = 1;
            } else {
                printf(",");
            }
            printf("%d", i);
            isPrime = 0;
		}
    }
    return isPrime;
}

float calcAverage(int total, int amount){
    float response = (float) total / amount;
    return response;
}

int calcTotal(int vec[], int length){
    int i;
    int total = 0;
    for(i = 0; i < length; i++){
        total += vec[i];
    }
    return total;
}

int calcMax(int vec[], int length){
    int i,max;
    max = vec[0];
    for(i=1; i<length; i++){
        if(max < vec[i]){
            max = vec[i];
        }
    }
    return max;
}
int calcMin(int vec[], int length){
    int i,min;
    min = vec[0];
    for(i=1; i<length; i++){
        if(min > vec[i]){
            min = vec[i];
        }
    }
    return min;
}


int findInt(int num, int vec[], int vecSize){
    int i;
    int index = -1;
    for(i=0; i< vecSize; i++){
        if( num == vec[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

void sortIntVectorByInsertion(int vec[], int size, char order){
    // Insertion technique
    int i,j,aux;
    for (i = 1; i < size; i++) {
        aux = vec[i];
        if(order == 'd'){// DESC
            for (j = i - 1; j >= 0 && vec[j] < aux; j = j - 1) {
                vec[j + 1] = vec[j];
            }
        } else {// ASC
            for (j = i - 1; j >= 0 && vec[j] > aux; j = j - 1) {
                vec[j + 1] = vec[j];
            }
        }
        vec[j + 1] = aux;
    }
}

void sortIntVector(int vec[],int size, char order){
    // Bubbling technique
    int i,j,aux;
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if(order == 'd'){
                if(vec[i] < vec[j]){// DESC
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            } else {
                if(vec[i] > vec[j]){// ASC
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

void strCapitalize(char vec[]){
    int i = 0;

    #ifdef __unix__

    #else
        strlwr(vec);
    #endif // __unix
    vec[0] = toupper(vec[0]);
    while( vec[i] != '\0'){
        if( vec[i] == ' '){
            vec[i + 1] = toupper(vec[i+1]);
        }
        i++;
    }
}

int displayMenu(char menuOptions[][100], int size, int type){
    int option, i;
    int loop = 0;

    do{
        switch(type){
            case 0:
                system("cls");
                printf("***************************************************************************************************************** \n\n");
                printf("   %s \n\n",menuOptions[0]);
                printf("***************************************************************************************************************** \n\n");
                printf("   ** Menu de opciones: **\n");
                for(i = 1; i <= size; i++){
                    printf("   %d. %s \n",i,menuOptions[i]);
                }
                printf("\n");
                break;
            case 1:
                displayTitle(menuOptions[0]);
                printf("   ** Menu de opciones: **\n");
                for(i = 1; i <= size; i++){
                    printf("   %d. %s \n",i,menuOptions[i]);
                }
                printf("\n");
                break;

            case 2:
                displaySubtitle(menuOptions[0]);
                printf("   ** Menu de opciones: **\n");
                for(i = 1; i <= size; i++){
                    printf("   %d. %s \n",i,menuOptions[i]);
                }
                printf("\n");
                break;

            default:
                printf("Error de configuracion: 'type' debe ser de 0 a 2 \n\n",size);
                break;

        }
        option = inputValidInt("- Seleccione una opcion: ",size);
        if(option != 0){
            loop = 1;
        } else {
            printf("Error, debe introducir un numero mayor a 0 y menor o igual a %d. \n\n",size);
            if(type == 0){
                pause();
            }

        }
    }while(loop == 0);

    printf("\n");
    return option;
}

int displayMenuConfirmacion(){
    int option;
    printf("   ** Menu de opciones: **\n");
    printf("   0. Cancelar \n" );
    printf("   1. Confirmar \n" );
    option = inputValidInt("- Seleccione una opcion: ",1);

    return option;
}

void displayTitle(char message[]){
    printf("   %s \n",message);
    printf("----------------------------------------------------------------------------------------------------------------- \n");
}

void displaySubtitle(char message[]){
    printf("   ** %s ** \n",message);
    printf("   -- \n\n");
}

void pause(){
    printf("\n   Presione cualquier tecla para continuar");
    //printf("Press 'Enter' to continue: ... ");

    #ifdef __unix__
        int c = getchar();
    #else
        getche();
    #endif // __unix
}

void clear(){
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif // __unix
}

void margen(){
    printf("   ");
}

