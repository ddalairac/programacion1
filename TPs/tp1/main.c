#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/** Trabajo Práctico número 1
 *  Programación I – Laboratorio I.
 *  Tecnicatura Superior en Programación.
 *  UTN-FRA
 *  Alumno: Diego Anibal Dalairac
 *
 */

int main()
{
    int fA = 0; // Flag A no tiene valor
    int fB = 0; // Flag B no tiene valor
    int fCalc = 0; // Flag No se realizaron los calculos
    int a; // Input operando A
    int b; // Input operando B
    int selection = 0; // Input Opción del menu
    char loop = 'y';
    float results[6]; // Almacena los resultados de las operaciones

    do{
        menu(a,b,fA,fB,fCalc,results,selection);

        selection = inputInt("Ingrese una opcion: ");

        if(selection == 1){
            a = inputInt("Ingresar 1er operando A");
            fA = 1;

        } else if(selection == 2){
            b = inputInt("Ingresar 2do operando B");
            fB = 1;

        } else if (selection == 3){
            // Validacion para poder realiar las operaciones
            if(!fA && !fB){
                printf("Debe introducir el valor de A y B \n");
                system("pause");
            } else if(!fA){
                printf("Debe introducir el valor de A \n");
                system("pause");
            } else if(!fB){
                printf("Debe introducir el valor de B \n");
                system("pause");
            } else {
                results[0] = addition(a,b);
                results[1] = subtraction(a,b);
                results[2] = division(a,b);
                results[3] = multiplication(a,b);
                results[4] = factorial(a);
                results[5] = factorial(b);
                fCalc = 1;
            }

        } else if (selection == 4){
            // Validacion para poder mostrar los resultados
            if(!fCalc){
                printf("Debe calcular las operaciones antes de ver los resultados \n");
                system("pause");
            }

        } else if (selection == 5){
            printf("Saliendo de la aplicación \n");
            loop = 'n';
        }

        // Validar que el numero sea una opcion valida del menu
        if(selection < 1 || selection > 5){
            printf("Error, %d no es una opcion valida \n",selection);
            system("pause");
        }

    } while(loop == 'y');


    return 0;
}
