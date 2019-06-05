#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/ddalairac.h"


char* inputDynamicString(char* msj);

int main(){

    char* pName = inputDynamicString("Ingrese su nombre:");

    printf("Nombre: %s \n",pName);

    free(pName);
    setPause();

    return 0;
}

char* inputDynamicString(char* msj){
    int len;
    char* pString = (char*) malloc(sizeof(char) * 1024);

    printf("%s",msj);
    scanf("%1023s", pString);
    len = strlen(pString);
    pString = (char*) realloc(pString, sizeof(char) * (len + 1)); // +1 por el \0

    return pString;
}
