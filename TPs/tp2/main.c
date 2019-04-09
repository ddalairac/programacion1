#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

/** Trabajo Práctico número 2
 *  Programación I – Laboratorio I.
 *  Tecnicatura Superior en Programación.
 *  UTN-FRA
 *  Alumno: Diego Anibal Dalairac
 *
 */

int main()
{
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
    }
    return 0;
}
