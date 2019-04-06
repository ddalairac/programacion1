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

int addition(int a, int b){
    int result = a + b;
    return result;
}

int subtraction(int a, int b){
    int result = a - b;
    return result;
}

int multiplication(int a, int b){
    int result = a * b;
    return result;
}

int division(int a, int b){
    int result = a / b;
    return result;
}

void factoring(int number){
    /*int flag = 0;
    for (int i = 1; i <= number; i++){
        if(number%i == 0){
            if(flag == 0){
                flag = 1;
            } else {
                printf(",");
            }
            printf("%d", i);
		}
    }*/
}
