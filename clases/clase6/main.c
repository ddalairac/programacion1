#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/ddalaira.h"

int main()
{
    userNameInput();

    return 0;
}
void userNameInput(){
    char name[20];
    char surname[25];
    char fullName[46]; //19+25+2

    inputStr("Ingrese su nombre", name);
    inputStr("Ingrese su nombre", surname);

    // puts(name);
    // puts(surname);

    strcpy(fullName, surname);
    strcat(fullName, ", ");
    strcat(fullName, name);

    // Convertir a letra capital
    strCapitalize(fullName);



    puts(fullName);


}
