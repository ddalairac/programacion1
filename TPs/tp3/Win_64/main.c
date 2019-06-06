#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "ddalairac.h"

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DESC 0

/****************************************************
    TP3
    Diego Dalairac
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char menuOptions[][100] = {
        "MENU PRINCIPAL",
        "Cargar los datos de los empleados desde el archivo data.csv (modo texto).",
        "Cargar los datos de los empleados desde el archivo data.bin (modo binario).",
        "Alta de empleado",
        "Modificar datos de empleado",
        "Baja de empleado",
        "Listar empleados",
        "Ordenar empleados",
        "Guardar los datos de los empleados en el archivo data.csv (modo texto).",
        "Guardar los datos de los empleados en el archivo data.bin (modo binario).",
        "Salir"
    };

    /** harcodeo */
    Employee* emp1 = employee_newParametros("1234", "Diego", "234", "25000");
    Employee* emp2 = employee_newParametros("2222", "Marcelo", "100", "55000");
    Employee* emp3 = employee_newParametros("1111", "Juana", "340", "35000");
    Employee* emp4 = employee_newParametros("5555", "Sofia", "210", "23000");

    ll_add(listaEmpleados, emp1);
    ll_add(listaEmpleados, emp2);
    ll_add(listaEmpleados, emp3);
    ll_add(listaEmpleados, emp4);
    /*
    // Muestro la cantida de elementos dentro de la lista ----> 0
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
    // agrego un empleado a la lista
    if(ll_add(listaEmpleados, emp1)== 0){
        printf("Se ha agregado el empleado con exito a la lista\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
    if(ll_add(listaEmpleados, emp2)== 0){
        printf("Se ha agregado el empleado con exito a la lista\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));
    if(ll_add(listaEmpleados, emp3)== 0){
        printf("Se ha agregado el empleado con exito a la lista\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    controller_ListEmployee(listaEmpleados);*/
    /** end harcodeo */

    //setPause();

    do{
        option = displayMenu(menuOptions,10,0);
        switch(option)
        {
            case 1:
                displayTitle("1. Cargar desde csv");
                controller_loadFromText("data.csv",listaEmpleados);
                setPause();
                break;
            case 2:
                displayTitle("2. Cargar desde binario");
                //controller_loadFromBinary();
                setPause();
                break;
            case 3:
                displayTitle("3. Alta");
                //controller_addEmployee();
                setPause();
                break;
            case 4:
                displayTitle("4. Modificacion");
                //controller_editEmployee();
                setPause();
                break;
            case 5:
                displayTitle("5. Baja");
                //controller_removeEmployee();
                setPause();
                break;
            case 6:
                displayTitle("6. Listar");
                controller_ListEmployee(listaEmpleados);
                setPause();
                break;
            case 7:
                displayTitle("7. Ordenar");
                controller_sortEmployee(listaEmpleados);
                setPause();
                break;
            case 8:
                displayTitle("8. Guardar en csv");
                //controller_saveAsText();
                setPause();
                break;
            case 9:
                displayTitle("9. Guardar en binario");
                setPause();
                break;
            case 10:
                displayTitle("10. Salir");
                printf("Esta saliendo del programa \n");
                break;
        }
    }while(option != 10);
    return 0;
}
