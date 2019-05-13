#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
    #include <linux/string.h>
#else
    #include <string.h>
#endif // __unix

#include "ddalairac.h"
#include "ArrayEmployees.h"
//#include "../../programacion1/lib/ddalairac.h"

#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0


/**********************************************
*
*  Funciones que el TP debe tener
*
***********************************************/

int initEmployees(Employee* list, int length){
    int i;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            response = 0;
            for(i=0; i<length;i++){
                list[i].id = 0;
                list[i].name[0] = '\0';
                list[i].lastName[0] = '\0';
                list[i].salary = 0;
                list[i].sector = 0;
                list[i].isEmpty = TRUE;
            }
        } else {
            printf("Error, funcion initEmployees: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion initEmployees: NULL pointer \n");
    }
    return response;
}

int addEmployee(Employee* list, int length, int id, char name[],char lastName[],float salary,int sector){
    int i;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            response = 0;
            for(i=0; i<length; i++){
                if(list[i].isEmpty == TRUE){
                    list[i].id = id;
                    strcpy(list[i].name, name);
                    strcpy(list[i].lastName, lastName);
                    list[i].salary = salary;
                    list[i].sector = sector;
                    list[i].isEmpty = FALSE;
                    break;
                }
            }
        } else {
            printf("Error, funcion addEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion addEmployee: NULL pointer \n");
    }
    return response;
}

int findEmployeeById(Employee* list, int length,int id){
    int i;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            for(i=0; i<length;i++){
                if(list[i].id == id){
                    response = i;
                };
            }
        } else {
            printf("Error, funcion findEmployeeById: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion findEmployeeById: NULL pointer \n");
    }
    return response;
}

int removeEmployee(Employee* list, int length, int id){
    int i;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            response = 0;
            for(i=0; i<length; i++){
                if(list[i].id == id){
                    list[i].isEmpty = TRUE;
                    break;
                }
            }
        } else {
            printf("Error, funcion removeEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion removeEmployee: NULL pointer \n");
    }
    return response;
}

int sortEmployees(Employee* list, int length, int order){

    int i,j;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            if(order >= DOWN || order <= UP){
                response = 0;

                for(i = 0; i < length - 1; i++){
                    for(j = i + 1; j < length; j++){
                        if(order == DOWN){// DESC
                            if(list[i].sector > list[j].sector){
                                swapEmployees(list,i,j);
                            } else {
                                if( (list[i].sector == list[j].sector) && (strcmp(list[i].lastName, list[j].lastName) > 0) ){
                                    swapEmployees(list,i,j);
                                }
                            }

                        } else if(order == UP){// ASC
                            if(list[i].sector < list[j].sector){
                                swapEmployees(list,i,j);
                            } else {
                                if( (list[i].sector == list[j].sector) && (strcmp(list[i].lastName, list[j].lastName) < 0) ){
                                    swapEmployees(list,i,j);
                                }
                            }
                        }
                    }
                }
            } else {
                printf("Error, funcion sortEmployees: order debe ser 0 o 1 \n");
            }
        } else {
            printf("Error, funcion sortEmployees: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion sortEmployees: NULL pointer \n");
    }
    return response;
}

int printEmployees(Employee* list, int length){
    int i;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            response = 0;
            printTableHeader();
            for(i=0; i<length; i++){
                if(list[i].isEmpty == FALSE){
                    printTableEmployee(list[i]);
                    //margen(); printf("%2d %10s %10s %10.2f %10d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
                }
            }

        } else {
            printf("Error, funcion printEmployees: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion printEmployees: NULL pointer \n");
    }
    return response;
}


/**********************************************
*
*  Funciones custom del TP
*
***********************************************/

void swapEmployees(Employee list[], int i, int j){
    Employee aux;
    aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}

void printTableHeader(){
    margen();printf("%2s | %10s | %20s | %20s | %15s \n", "id", "Sector", "Apellido", "Nombre", "Salario");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableEmployee(Employee item){
    margen();
    printf("%2d | %10d | %20s | %20s | %15.2f  \n", item.id, item.sector, item.lastName, item.name, item.salary);
}

int getEmptySlot(Employee list[], int length){
    int i;
    int index = -1;
    if (list != NULL){
        if(length > 0){
            for(i=0; i<length; i++){
                if(list[i].isEmpty == TRUE ){
                    index = i;
                    break;
                }
            }
        } else {
            printf("Error, funcion getEmptySlot: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion getEmptySlot: NULL pointer \n");
    }
    return index;
}

int getnewID(Employee list[], int length){
    int i;
    int id = 0;
    if (list != NULL){
        if(length > 0){
            for(i=0; i<length; i++){
                if(list[i].id > id ){
                    id = list[i].id;
                }
            }
            id = id + 1;
        } else {
            printf("Error, funcion getnewID: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion getnewID: NULL pointer \n");
    }
    return id;
}

int getActiveEmployees(Employee list[], int length){
    int i;
    int total = 0;
    if (list != NULL){
        if(length > 0){
            for(i=0; i<length; i++){
                if(list[i].isEmpty == FALSE ){
                    total++;
                }
            }
        } else {
            total = -1;
            printf("Error, funcion getActiveEmployees: length debe ser mayor a 0 \n");
        }
    } else {
        total = -1;
        printf("Error, funcion getActiveEmployees: NULL pointer \n");
    }
    return total;
}

int findActiveEmployee(Employee list[], int length, char message[]){
    int employeeID,index,option;
    int response = -1;
    int loop = TRUE;

    if (list != NULL){
        if(length > 0){
            do{
                employeeID = inputValidInt(message, 0);
                index = findEmployeeById(list, length, employeeID);
                if(employeeID == 0){
                    margen();printf("Los id deben ser superiores a 0. \n");
                } else if(index == -1){
                    margen();printf("No se encontro el id. \n");
                } else if(list[index].isEmpty == TRUE){
                    margen();printf("El empleado que busca fue dado de baja. \n");
                } else {
                    response = index;
                    loop = FALSE;
                }
                if(response == -1){
                    printf("\n");
                    displaySubtitle("Realizar nueva busqueda de ID");
                    option = displayMenuConfirmacion();
                    if(option == 0){
                        loop = FALSE;
                    }
                }
            }while(loop == TRUE);
        } else {
            printf("Error, funcion findActiveEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion findActiveEmployee: NULL pointer \n");
    }
    return response;
}

int calcTotalActiveEmployees(Employee list[], int length){
    int i;
    int total = 0;
    for(i = 0; i < length; i++){
        if(list[i].isEmpty == FALSE ){
            total ++;
        }
    }
    return total;
}

int calcSalaryTotal(Employee list[], int length){
    int i;
    int total = 0;
    for(i = 0; i < length; i++){
        if(list[i].isEmpty == FALSE ){
            total += list[i].salary;
        }
    }
    return total;
}

float calcSalaryAverage(int total, int amount){
    float response = (float) total / amount;
    return response;
}

int calcEmplyeesAboveAverage(Employee list[], int length, float average){
    int i;
    int total = 0;
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE && list[i].salary > average){
            total++;
        }
    }
    return total;
}

int secNewEmployee(Employee list[], int length){
    float salary;
    int sector, id, index;
    int response = -1;
    int strLen = 51;
    char name[strLen];
    char lastName[strLen];

    if (list != NULL){
        if(length > 0){
            displayTitle("1. ALTAS");
            /** busca el primer espacio libre de la lista.
            Lo busco por fuera de la funcion 'addEmployee' para solo solicitar al usuario introducir datos, en el caso de que puedan guardarse.
            */
            index = getEmptySlot(list, length);
            id = getnewID(list, length);
            if(index != -1){
                if(id > 0){
                    displaySubtitle("Ingresando nuevo empleado");
                    margen();printf("id: %d \n",id);
                    margen();inputValidLetterString("Ingrese su nombre:",name,strLen);
                    margen();inputValidLetterString("Ingrese su apellido:",lastName,strLen);
                    margen();salary = inputValidFloat("Ingrese el salario:",0);
                    margen();sector = inputValidInt("Ingrese el sector:",0);
                    response = addEmployee(list,length,id,name,lastName,salary,sector);
                    if(response != -1){
                        margen();printf("Empleado agregado con exito. \n");
                    } else {
                        margen();printf("Error, no hay espacio para nuevos empleados. \n");
                    }
                } else {
                   margen(); printf("Error en generacion de id. \n");
                }
            } else {
               margen(); printf("No hay espacio para nuevos empleados. \n");
            }
        } else {
            printf("Error, funcion secNewEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion secNewEmployee: NULL pointer \n");
    }
    return response;
}

int secFindAndEditEmployee(Employee list[], int length){
    int index,option,totalEmpoyees;
    int response = -1;
    int loop = TRUE;
    char menu[][100] = {
        "Seleccione el dato que desea editar",
        "Nombre",
        "Apellido",
        "Salario",
        "Sector",
        "Salir"
    };

    if (list != NULL){
        if(length > 0){
            displayTitle("2. Modificar");
            totalEmpoyees = calcTotalActiveEmployees(list, length);
            if(totalEmpoyees == 0){
                margen();
                printf("No hay ningunn empleado en la lista \n");
                response = 0;
            } else {
                margen();
                index = findActiveEmployee(list, length, "Ingrese el ID del empleado que desea editar:");
                do{
                    if(index != -1){
                        response = 0;

                        /** Esta vista era un poco mas estetica, pro la reemplace un menu y print de empleados estandarizado*/
                        /*displaySubtitle("Menu de edicion");
                        margen();printf("1. Nombre: %s \n",list[index].name);
                        margen();printf("2. Apellido: %s \n",list[index].lastName);
                        margen();printf("3. Salario: %.2f \n",list[index].salary);
                        margen();printf("4. Sector: %d \n",list[index].sector );
                        margen();printf("5. Salir \n\n" );
                        margen();option = inputValidInt("Seleccione una opcion",5);*/

                        printf("\n");
                        printTableHeader();
                        printTableEmployee(list[index]);
                        printf("\n");
                        option = displayMenu(menu,5,2);

                        switch(option){
                            case 1:
                                margen();inputValidLetterString("Editar nombre:",list[index].name,51);
                                break;
                            case 2:
                                margen();inputValidLetterString("Editar Apellido:",list[index].lastName,51);
                                break;
                            case 3:
                                margen();list[index].salary = inputValidFloat("Ingrese el salario:",0);
                                break;
                            case 4:
                                margen();list[index].sector = inputValidInt("Ingrese el sector:",0);
                                break;
                            case 5:
                                margen();printf("Esta por salir del modo edicion \n" );
                                loop = FALSE;
                                break;
                        }
                    } else {
                        loop = FALSE;
                    }
                }while(loop == TRUE);
            }
        } else {
            printf("Error, funcion secFindAndEditEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion secFindAndEditEmployee: NULL pointer \n");
    }
    return response;
};

int secFindAndRemoveEmployee(Employee list[], int length){
    int index,option,totalEmpoyees;
    int response = -1;
    int loop = TRUE;

    if (list != NULL){
        if(length > 0){
            displayTitle("3. BAJA");
            totalEmpoyees = calcTotalActiveEmployees(list, length);
            if(totalEmpoyees == 0){
                margen();
                printf("No hay ningunn empleado en la lista \n");
                response = 0;
            } else {
                margen();
                index = findActiveEmployee(list, length, "Ingrese el ID del empleado que desea remover:");
                do{
                    if(index != -1){
                        /** Esta vista era un poco mas estetica, pro la reemplace un menu y print de empleados estandarizado*/
                        /*margen();printf("* id: %d \n",list[index].id);
                        margen();printf("* Nombre: %s \n",list[index].name);
                        margen();printf("* Apellido: %s \n",list[index].lastName);
                        margen();printf("* Salario: %.2f \n",list[index].salary);
                        margen();printf("* Sector: %d \n\n",list[index].sector );*/

                        printf("\n");
                        displaySubtitle("Datos del empleado a remover");
                        printTableHeader();
                        printTableEmployee(list[index]);
                        printf("\n");
                        printf("\n");
                        option = displayMenuConfirmacion();

                        switch(option){
                            case 0:
                                margen();printf("Eliminacion cancelada \n" );
                                response = 0;
                                loop = FALSE;
                                break;

                            case 1:
                                response = removeEmployee(list, length, list[index].id);
                                if(response != -1){
                                    margen();printf("Empleado removido con exito\n" );
                                }
                                loop = FALSE;
                                break;
                            default:
                                printf("Error en menu de confirmacion");
                                break;
                        }
                    } else {
                        loop = FALSE;
                    }
                }while(loop == TRUE);
            }
        } else {
            printf("Error, funcion secFindAndRemoveEmployee: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion secFindAndRemoveEmployee: NULL pointer \n");
    }
    return response;

};

int secInforms(Employee list[], int length){
    int option,result;
    int response = -1;
    int totalEmpoyees = calcTotalActiveEmployees(list, length);
    char informarMenu[][100] = {
        "4. INFORMAR ",
        "Listado de los empleados ordenados alfabeticamente por Apellido y Sector.",
        "Total y promedio de los salarios, y cuantos empleados superan el salario promedio."
    };

    if (list != NULL){
        if(length > 0){
            response = 0;
            if(totalEmpoyees == 0){
                displayTitle("4. INFORMAR ");
                margen();
                printf("No se pueden realizar informes, no hay ningunn empleado en la lista \n");
            } else {
                option = displayMenu(informarMenu,2,1);
                switch(option){
                    case 1:
                    result = sortEmployees(list, length, DOWN);
                    if(result == -1){
                        margen();printf("No se puedieron ordenar los empleados \n");
                    }
                    printEmployees(list, length);
                    break;

                    case 2:
                    result = inform2Data(list, length);
                    if(result == -1){
                        response = -1;
                        margen();printf("No se puedo calcular el informe de los empleados \n");
                    }
                    break;
                }
            }
        } else {
            printf("Error, funcion secInforms: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion secInforms: NULL pointer \n");
    }
    return response;
}

int inform2Data(Employee list[], int length){
    float average;
    int total,activeEmployees,employeesSalaryAboveAverage;
    int response = -1;

    if (list != NULL){
        if(length > 0){
            response = 0;
            total = calcSalaryTotal(list, length);
            activeEmployees = getActiveEmployees(list, length);
            average = calcSalaryAverage(total, activeEmployees);
            employeesSalaryAboveAverage = calcEmplyeesAboveAverage(list,length,average);
            margen();printf("Total de Salarios: %d \n", total);
            margen();printf("Promedio de Salarios: %.2f \n", average);
            margen();printf("Empleados con salario superior al promedio: %d \n", employeesSalaryAboveAverage);
        } else {
            printf("Error, funcion inform2Data: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion inform2Data: NULL pointer \n");
    }
    return response;
}

int hardcodeEmployees(Employee list[], int length, int hc){
    int i;
    int response = -1;

    initRandom();
    if (list != NULL){
        if(length > 0){
            response = 0;
            for(i = 0; i < length && i < hc; i++){
                list[i].id = i;
                getRandomName(list[i].name,10);
                getRandomLastname(list[i].lastName,10);
                strCapitalize(list[i].name);
                strCapitalize(list[i].lastName);
                list[i].salary = getRandomNumber(10000,60000);
                list[i].sector = getRandomNumber(1,4);
                list[i].isEmpty = FALSE;
            }
        } else {
            printf("Error, funcion hardcodeEmployees: length debe ser mayor a 0 \n");
        }
    } else {
        printf("Error, funcion hardcodeEmployees: NULL pointer \n");
    }
    return response;
}
