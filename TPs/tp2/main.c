#include <stdio.h>
#include <stdlib.h>
#include "ddalairac.h"
#include "ArrayEmployees.h"

#define T 1000
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0


/** Trabajo Práctico número 2
 *  Programación I – Laboratorio I.
 *  Tecnicatura Superior en Programación.
 *  UTN-FRA
 *  Alumno: Diego Anibal Dalairac
 *
 */



int main(){
    int option;
    int loop = TRUE;
    int result = -1;
    Employee employees[T];


    char mainMenu[][100] = {
        "ADMIN: Nomina de empleados",
        "ALTAS ",
        "MODIFICAR ",
        "BAJA ",
        "INFORMAR ",
        "SALIR ",
    };

    result = initEmployees(employees, T);
    if(result == -1){
        printf("No se inicializaron correctamente los empleados \n");
        setPause();
    }

    /** HARCODE EMPLOYEE LIST */ /*
    result = hardcodeEmployees(employees, T, 30);
    if(result == -1){
        margen();printf("No se puedieron cargar empleados de ejemplo \n");
    }*/


    do{
        option = displayMenu(mainMenu,5,0);
        switch(option){
            case 1:
                result = secNewEmployee(employees, T);
                if(result == -1){
                    margen();printf("No se puedo agregar el empleado \n");
                }
                setPause();
                break;

            case 2:
                result = secFindAndEditEmployee(employees, T);
                if(result == -1){
                    margen();printf("No se puedo editar el empleado \n");
                }
                setPause();
                break;

            case 3:
                result = secFindAndRemoveEmployee(employees, T);
                if(result == -1){
                    margen();printf("No se puedo remover el empleado \n");
                }
                setPause();
                break;

            case 4:
                result = secInforms(employees, T);
                if(result == -1){
                    margen();printf("No se puedo generar el informe \n");
                }
                setPause();
                break;

            case 5:
                margen();printf("Esta por salir del programa \n" );
                loop = FALSE;
                break;

            default:
                margen();printf("Debe elegir una opcion del menu \n");
                setPause();
                break;
        }
    } while(loop);

    return 0;
}

