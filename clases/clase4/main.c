#include <stdio.h>
#include <stdlib.h>

#include "../../lib/ddalaira.h"

int main()
{
    int intNum;
    float floatNum;
    char charLetter;
    int random;


    /*intNum = inputInt("Ingrese un numero entero");
    floatNum = inputFloat("Ingrese un numero decimal");
    charLetter = inputChar("Ingrese una letra");*/
    random = getRandomNumber(0,10);

    /*printf("int %d: \n", intNum);
    printf("float %f: \n", floatNum);
    printf("char %c: \n", charLetter);*/
    printf("random %d: \n", random);


    return 0;
}
