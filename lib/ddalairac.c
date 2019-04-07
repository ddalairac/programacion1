#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int inputInt(char message[]){
    int number;
    //printf("Ingrese un int \n");
    printf("%s: ",message);
    scanf("%d", &number);
    return number;
}

float inputFloat(char message[]){
    float number;
    //printf("Ingrese un float \n");
    printf("%s: ",message);
    fflush(stdin);// Win
    scanf("%f", &number);
    return number;
}

char inputChar(char message[]){
    char character;
    //printf("Ingrese una letra \n");
    printf("%s: ",message);
    fflush(stdin);// Win
    //fpurge(stdn);// Linux OSx
    scanf("%c", &character);
    return character;
}

void inputStr(char message[],char str[]){

    printf("%s: ",message);
    fflush(stdin);// Win
    //fpurge(stdn);// Linux OSx
    gets(str);
}

int getRandomNumber(int from, int to, int init){
    if (!init){
        srand(time(NULL));
    }
    return from + (rand() % (to + 1 - from) );
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

int calcDivision(int a, int b){
    int result = a / b;
    return result;
}

void calcFactoring(int number){
    int flag = 0;
    for (int i = 1; i <= number; i++){
        if(number%i == 0){
            if(flag == 0){
                flag = 1;
            } else {
                printf(",");
            }
            printf("%d", i);
		}
    }
}

int findInt(int num, int vec[], int vecSize){
    int index = -1;
    for(int i=0; i< vecSize; i++){
        if( num == vec[i])
        {
            index = i;
            break;
        }
    }
    return index;
}
