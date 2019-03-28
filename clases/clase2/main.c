#include <stdio.h>
#include <stdlib.h>

//prototipo de la funcion (si usas mal la funcion da error)
int sumar1(int,int);

// desarrollo de la funcion
int sumar1(int x, int y){
    int suma;
    suma = x + y;
    return suma;
}

void main2(){
    int x;
    int y;
    int resultado;

    printf("Ingrese un numero \n");
    scanf("%d", &x);

    printf("Ingrese otro numero \n");
    scanf("%d", &y);

    resultado = sumar1(x,y);

    printf("El resultado es %d \n",resultado);
}

int main(){

    main2();


    int numero;
    char confirm;
    int i = 0;
    int contadorPares = 0;
    int acumuladoSuma = 0;
    float promedio;
    int mayor;
    int minimo;

    do{
        // introducir numero y validarlo
        printf("Ingrese un numero positivo \n");
        scanf("%d", &numero);
        while(numero < 0){
            printf("error, ingrese un numero positivo \n");
            scanf("%d", &numero);
        }
        // contar pares
        if(numero % 2 == 0){
            contadorPares ++;
        }
        // suma para el promedio
        acumuladoSuma += numero;
        // Numero mayor y minimo
        if(i==0){
            mayor = numero;
            minimo = numero;
        } else {
            if(numero > mayor){
                mayor = numero;
            }
            if(numero < minimo){
                minimo = numero;
            }
        }

        // consultar si desea continuar
        printf("Desea contunuar \n");

        fflush(stdin); // limpia el buffer ( asegurarte que no quedo nada viejo)
        scanf("%c", &confirm);
        confirm = tolower(confirm); // Suma 32 en codigo ASCII (es la dif entre Masyusculas y minusculas)
        //confirm = getchar(); // idem
        //          getch(); //no espera enter y NO te muestra el caracter
        //          getche(); // no espera enter y te muestra el caracter

        i++;
    }while(confirm == 's' );
    promedio = (float) acumuladoSuma / i;


    printf("------------------ \n");
    printf("i = %d \n", i);
    printf("hay %d pares \n", contadorPares);
    printf("el promedio es %.1f \n", promedio);
    printf("la suma total es %d \n", acumuladoSuma);
    printf("Mayor: %d, Menor: %d \n", mayor, minimo);

    //strcpy(origen,destino); // para copiar strings

    return 0;
}


