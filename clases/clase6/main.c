#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/ddalaira.h"

int main()
{
    //ejemploOrderBy();
    userNameInput();
    return 0;
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
