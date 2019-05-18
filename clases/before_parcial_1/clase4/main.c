#include <stdio.h>
#include <stdlib.h>

#include "../../lib/ddalaira.h"

int main()
{
    /*
    int intNum;
    float floatNum;
    char charLetter;
    int array[5] = {1,2,3,4,5,6};
    int random;


    intNum = inputInt("Ingrese un numero entero");
    floatNum = inputFloat("Ingrese un numero decimal");
    charLetter = inputChar("Ingrese una letra");
    random = getRandomNumber(0,100,0);



    printf("\n");
    printf("int %d: \n", intNum);
    printf("float %f: \n", floatNum);
    printf("char %c: \n", charLetter);
    for(int i=0; i < 5; i++){
        printf("array[%d]: %d \n", i, array[i]);
    }
    printf("random %d: \n", random);*/


    int array[5] = {1,"hola",3,4,5,6};

    for(int i=0; i < 5; i++){
        printf("array[%d]: %d \n", i, array[i]);
    }

}
