#include <stdio.h>
#include <stdlib.h>
#include "../../lib/ddalairac.h"


void menuTest();
void randomTest();

int main(){

    //setSleep(3000);

    // randomTest();
    // menuTest();
    // maximoyminimo();

    //char an[50];
    //inputValidAlphaNumericString("input  Valid AlphaNumeric String",an,50);*/

    eDate anydate ;
    inputValidDate("Ingrese la fecha: ",&anydate.day, &anydate.month, &anydate.year);
    printf("date %d %d %d",anydate.day,anydate.month,anydate.year);

    //char phone[20];
    //inputValidPhone("Ingrese su telefono", phone, 13);

    return 0;
}

void menuTest(){
    // menu test
    char mainMenu[][100] = {
        "ADMIN: Nomina de empleados",
        "ALTAS ",
        "MODIFICAR ",
        "BAJA ",
        "INFORMAR ",
        "SALIR ",
    };
    displayMenu(mainMenu,5,0);
    displayMenu(mainMenu,5,1);
    displayMenu(mainMenu,5,2);
}

void randomTest(){
    // random test
    char someString[10];

    initRandom();

    printf("someNumber: %d \n",getRandomNumber(10, 20));
    printf("someNumber: %d \n",getRandomNumber(0, 9));

    printf("someChar %c \n",getRandomChar());
    printf("someChar %c \n",getRandomChar());

    printf("someSex %c \n",getRandomCharCustom("FM", 1));
    printf("someSex %c \n",getRandomCharCustom("FM", 1));
    printf("someSex %c \n",getRandomCharCustom("FM", 1));
    printf("someSex %c \n",getRandomCharCustom("FM", 1));

    getRandomString(someString, 9);
    printf("someString %s \n",someString);

    getRandomString(someString, 2);
    printf("someString %s \n",someString);
}

void maximoyminimo (){
    int vec[]={2,6,3,56,4,98,1};
    printf("maximo %d: \n",calcMax(vec,7));
    printf("minimo %d: \n",calcMin(vec,7));
}
