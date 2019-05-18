#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
    /*
    int x = 5;
    int y = 10;
    int z = 12;*/

    printf("return maximo: %d \n", obtenerMaximo(5, 10, 12));

    int maximo;

    obtenerMaximoPuntero(15, 20, 5, &maximo);
    printf("maximo en puntero: %d \n", maximo);

    system("pause");

    menu();

    return 0;
}

