#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "ddalairac.h"

/****************************************************
    TP3
    Diego Dalairac
*****************************************************/


int main()
{
    int option = 0;
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

    LinkedList* listaEmpleados = ll_newLinkedList();

    Employee* emp1 = employee_newParametros("1234", "Juan", "234", "25000");
    Employee* emp2 = employee_newParametros("2222", "Julia", "100", "15000");
    Employee* emp3 = employee_newParametros("1111", "Juana", "340", "35000");
    Employee* emp4 = employee_newParametros("5555", "Sofia", "210", "23000");

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


    printf("AAAAAAAAAAAAAAAAAAAAAll_get %x \n", ll_get(listaEmpleados,0) );


    displayEmployee( (Employee*) ll_get(listaEmpleados,1));

    for(int i = 0; i < ll_len(listaEmpleados); i++){
        displayEmployee( (Employee*) ll_get(listaEmpleados,i));
    }
    setPause();
    /*
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
                setPause();
                break;
            case 3:
                displayTitle("3. Alta");
                setPause();
                break;
            case 4:
                displayTitle("4. Modificacion");
                setPause();
                break;
            case 5:
                displayTitle("5. Baja");
                setPause();
                break;
            case 6:
                displayTitle("6. Listar");
                setPause();
                break;
            case 7:
                displayTitle("7. Ordenar");
                setPause();
                break;
            case 8:
                displayTitle("8. Guardar en csv");
                setPause();
                break;
            case 9:
                displayTitle("9. Guardar en binario");
                setPause();
                break;
            case 10:
                displayTitle("10. Salir");
                break;
        }
    }while(option != 10);*/
    return 0;
}
