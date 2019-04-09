#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 1000
//#define NULL 0
#define TRUE 1
#define FALSE 0
//#define UP 1
//#define DOWN 0
/** Trabajo Práctico número 2
 *  Programación I – Laboratorio I.
 *  Tecnicatura Superior en Programación.
 *  UTN-FRA
 *  Alumno: Diego Anibal Dalairac
 *
 */



int main()
{
    Employee employees[T];
    initEmployees(employees, T);
    int loop = TRUE;

    do{
        int option = displayMenu();

        if(option == 1){
            //Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
        } else if(option == 2){
            // Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector
        } else if(option == 3){
            // Se ingresará el Número de Id y se eliminará el empleado del sistema.
        } else if(option == 4){
            printf("   INFORMAR:\n");
            printf("\t 1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n");
            printf("\t 2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \n");

            printEmployees(employees, 10);

        } else if(option == 5){
            loop = FALSE;
        }
        system("pause");
    } while(loop);

    return 0;
}
