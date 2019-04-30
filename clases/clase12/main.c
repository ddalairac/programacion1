#include <stdio.h>
#include <stdlib.h>

#include "../../lib/ddalairac.h"
#include "abmLib.h"

#define TRUE 1
#define FALSE 0
#define SiEm 10
#define SiFo 5

int main(){
    eFoodMenu menuFoods[] = {
        {0,"Hamburguesa & fritas"},
        {1,"Ensalada Cesar"},
        {2,"Pastas con fileto"},
        {3,"Milanesa & Fritas"},
        {4,"Pizza"},
    };
    eSector sectors[]  = {
        {0,"RRHH"},
        {1,"Frontend"},
        {2,"Backend"},
        {3,"Funcional"},
        {4,"PO"},
    };
    //eLunch alm[SiEm];

    eEmployee employees[SiEm];

    int option;
    int result;
    int loop = TRUE;

    char mainMenu[][100] = {
        "ADMIN: Comidas",
        "ALTAS ",
        "MODIFICAR ",
        "BAJA ",
        "INFORMAR ",
        "SALIR ",
    };

    result = initEmployees(employees, SiEm);
    //result = initFoodMenu(menuFoods, SiFo);


    /** HARCODE LISTS */
    result = hardcodeEmployees(employees, SiEm, SiEm);
    if(result == -1){
        margen();printf("No se puedieron cargar empleados de ejemplo \n");
        setPause();
    }
    /*result = hardcodeFoodMenu(menuFoods, SiFo, SiFo);
    if(result == -1){
        margen();printf("No se puedieron cargar comidas de ejemplo \n");
        setPause();
    }*/

    do{
        option = displayMenu(mainMenu,5,0);
        switch(option){/*
            case 1:
                result = secNewEmployee(employees, SiEm);
                if(result == -1){
                    margen();printf("No se puedo agregar el empleado \n");
                }
                setPause();
                break;

            case 2:
                result = secFindAndEditEmployee(employees, SiEm);
                if(result == -1){
                    margen();printf("No se puedo editar el empleado \n");
                }
                setPause();
                break;

            case 3:
                result = secFindAndRemoveEmployee(employees, SiEm);
                if(result == -1){
                    margen();printf("No se puedo remover el empleado \n");
                }
                setPause();
                break;*/

            case 4:
                result = secInforms(employees, SiEm, menuFoods, SiFo, sectors, SiFo);


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

