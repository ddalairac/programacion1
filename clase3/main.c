#include <stdio.h>
#include <stdlib.h>
void obtenerMaximoPuntero(int x, int y, int z, int* maximo);
int obtenerMaximo(int x, int y, int z);
int main(){
    int x = 5;
    int y = 10;
    int z = 12;

    printf("return maximo: %d \n", obtenerMaximo(x, y, z));

    int maximo;

    obtenerMaximoPuntero(x, y, z, &maximo);
    printf("maximo en puntero: %d \n", maximo);


    return 0;
}
// pasa variables x,y,z por VALOR
int obtenerMaximo(int x, int y, int z){
    int maximo;

    maximo = x;
    if( y > maximo){
        maximo = y;
    }
    if( z > maximo){
        maximo = z;
    }
    return maximo;
}

// pasa variables x,y,z por VALOR, y maximo por REFERENCIA
void obtenerMaximoPuntero(int x, int y, int z, int* maximo){
    *maximo = x;
    if( y > *maximo){
        *maximo = y;
    }
    if( z > *maximo){
        *maximo = z;
    }
}
