#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int num = 10;
    //printf("Hello world!\n\n");
    //pesosDeTipos();
    //mascaras();
    //system("pause");
    //proptEj();
    proptSuma();

    return 0;
}
void pesosDeTipos(){
    printf("Tamano de char : %d \n", sizeof(char)); // %d es decimal
    printf("Tamano de int : %d \n", sizeof(int));
    printf("Tamano de float : %d \n", sizeof(float));
    printf("Tamano de double : %d \n", sizeof(double));
}
void mascaras(){
    int numVoid;
    int num = 10;
    char letra = 'a';
    float decimal = 3.1681;

    printf("d: mostrar numVoid %d (valor que tiene la memoria, antes que inicialice la variablñe)\n", numVoid );
    printf("d: mostrar num %d \n", num );
    printf("d: mostrar %d \n", decimal );
    printf("f: mostrar todo el numero %f \n", decimal );
    printf(".1f: Mostrar 1 decimal (redondea) %.1f \n", decimal );
}
void proptEj(){
    char nombre [20];
    int edad;
    printf("Ingrese su nombre ");
    scanf("%s", nombre); // %s es string
    printf("Ingrese su edad ");
    scanf("%d", &edad);
    printf("Ud se llama %s y tiene %d ", nombre, edad);

}


void proptSuma(){
    int num1,num2 ;
    float promedio;

    printf("Ingrese un numero ");
    scanf("%d", &num1);
    printf("Ingrese otro numero ");
    scanf("%d", &num2);
    printf("\n La suma de %d y %d es %d", num1, num2, num1+num2);

    promedio = (float) (num1+num2)/2;

    printf("\n El promedio de %d y %d es %.2f", num1, num2, promedio);

}
