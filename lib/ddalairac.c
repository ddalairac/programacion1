 #include <stdio.h>
 #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>

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
    strlwr(vec);
    vec[0] = toupper(vec[0]);
    while( vec[i] != '\0'){
        if( vec[i] == ' '){
            vec[i + 1] = toupper(vec[i+1]);
        }
        i++;
    }
}

char
