#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "ddalairac.h"

#define true 1
#define false 0
#define T 5

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main(){
    int option = 0;
    int i;
    LinkedList* listaEmpleados = ll_newLinkedList();




    //int loop = TRUE;
    //int result = -1;
    //Employee employees[T];

    char mainMenu[][100] = {
        "ADMIN: Nomina de empleados",
        "Cargar los datos de los empleados desde el archivo data.csv (modo texto)",
        "Cargar los datos de los empleados desde el archivo data.bin (modo binario)",
        "Alta de empleado",
        "Modificar datos de empleado",
        "Baja de empleado",
        "Listar empleados",
        "Ordenar empleados",
        "Guardar los datos de los empleados en el archivo data.csv (modo texto)",
        "Guardar los datos de los empleados en el archivo data.bin (modo binario)",
        "Salir"
    };

    Employee* emp1 = employee_newParametros("1234","Juan","24","25000");
    Employee* emp2 = employee_newParametros("2345","Pedro","100","20000");
    Employee* emp3 = employee_newParametros("3456","Julia","240","50000");

    if(ll_add(listaEmpleados,emp1)==0){
        printf("Se ha agregado un empleado \n");
        printf("Cantidad de elementos: %d \n", ll_len(listaEmpleados));
    }
    if(ll_add(listaEmpleados,emp2)==0){
        printf("Se ha agregado un empleado \n");
        printf("Cantidad de elementos: %d \n", ll_len(listaEmpleados));
    }
    if(ll_add(listaEmpleados,emp3)==0){
        printf("Se ha agregado un empleado \n");
        printf("Cantidad de elementos: %d \n", ll_len(listaEmpleados));

    }

    do{

        option = displayMenu(mainMenu,10,0);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                setPause();
                break;

            case 2:
                //displayEmployees(listaEmpleados,ll_len(listaEmpleados));
                //mostrarEmpleado( (Employee*) ll_get(listaEmpleados,1);
                for(i = 0; i < ll_len(listaEmpleados); i++){
                    displayEmployee( (Employee*) ll_get(listaEmpleados,i) );
                }
                setPause();
                break;

             case 3: // ordenar
                ll_sort(listaEmpleados,sortXSalary,1);
                break;
        }
    }while(option != 10);


    return 0;
}
