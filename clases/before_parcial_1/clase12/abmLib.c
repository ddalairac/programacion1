#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>// tolower
#include <time.h>

#ifdef __unix__
    #include <linux/string.h> // linux
    #include <termios.h> // linux
    #include <stdio_ext.h>
    #include <unistd.h>
#else
    #include <string.h>
    #include <conio.h> // input output
    #include <Windows.h> // for sleep
#endif // __unix

#include "../../lib/ddalairac.h"
#include "abmLib.h"

#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
/*
    char name[51];
    char lastName[51];
    char sex;
    int id;
    int idSector;
    int isEmpty;
    float salary;
    eDate date;
*/

int initEmployees(eEmployee list[], int length){
    int i;
    int response = -1;
    if (list != NULL && length > 0){
        response = 0;
        for(i=0; i<length;i++){
            list[i].name[0] = '\0';
            list[i].lastName[0] = '\0';
            list[i].sex = 'n';
            list[i].id = 0;
            list[i].salary = 0;
            list[i].idSector = 0;
            list[i].date.day = 0;
            list[i].date.month = 0;
            list[i].date.year = 0;
            list[i].isEmpty = TRUE;
        }
    }
    return response;
}

int hardcodeEmployees(eEmployee list[], int length, int hc){
    int i;
    int response = -1;

    initRandom();
    if (list != NULL && length > 0){
        response = 0;
        for(i = 0; i < length && i < hc; i++){
            list[i].id = i;
            getRandomName(list[i].name,10);
            getRandomLastname(list[i].lastName,10);
            strCapitalize(list[i].name);
            strCapitalize(list[i].lastName);
            list[i].sex = getRandomCharCustom("fm",1);
            list[i].salary = getRandomNumber(10000,60000);
            list[i].idSector = getRandomNumber(0,4);
            list[i].date.day = getRandomNumber(1,30);
            list[i].date.month = getRandomNumber(1,12);
            list[i].date.year = getRandomNumber(1900,2019);
            list[i].isEmpty = FALSE;
        }
    }
    return response;
}

int calcTotalActiveEmployees(eEmployee list[], int length){
    int i;
    int total = 0;
    for(i = 0; i < length; i++){
        if(list[i].isEmpty == FALSE ){
            total ++;
        }
    }
    return total;
}

void swapEmployees(eEmployee list[], int i, int j){
    eEmployee aux;
    aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}

int sortEmployees(eEmployee list[], int length, int order){
    int i,j;
    int response = -1;
    if (list != NULL){
        if(length > 0){
            if(order >= DOWN || order <= UP){
                response = 0;

                for(i = 0; i < length - 1; i++){
                    for(j = i + 1; j < length; j++){
                        if(order == DOWN){// DESC
                            if(list[i].idSector > list[j].idSector){
                                swapEmployees(list,i,j);
                            } else {
                                if( (list[i].idSector == list[j].idSector) && (strcmp(list[i].lastName, list[j].lastName) > 0) ){
                                    swapEmployees(list,i,j);
                                }
                            }

                        } else if(order == UP){// ASC
                            if(list[i].idSector < list[j].idSector){
                                swapEmployees(list,i,j);
                            } else {
                                if( (list[i].idSector == list[j].idSector) && (strcmp(list[i].lastName, list[j].lastName) < 0) ){
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

void getSectorName(char srt[], eSector list[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            strcpy(srt, list[i].name);
        }
    }
}

void getEmployeeName(char srt[], eEmployee list[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            strcpy(srt, list[i].name);
        }
    }
}

void getFoodName(char srt[], eFoodMenu list[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            strcpy(srt, list[i].name);
        }
    }
}

void printTableEmployeeHeader(){
    margen();printf("%10s | %12s | %12s | %3s | %10s | %4s | %12s \n", "Sector", "Last Name", "Name", "Sex", "Salary","id","Date");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableEmployee(eEmployee item, eSector sectors[], int length){
    char secName[21];
    getSectorName(secName, sectors, length, item.idSector);
    margen();
    //printf("%8s | %12s | %12s | %3s | %15s | %5s | %8s \n", "Sector", "Last Name", "Name", "Sex", "Salary","id","Date");
    printf("%10s | %12s | %12s | %3c | %10.2f | %4d | %4d/%2d/%4d  \n", secName, item.lastName, item.name, item.sex, item.salary,item.id,item.date.day, item.date.month, item.date.year);
}

void printEmployees(eEmployee list[], int length, eSector sectors[], int lenSec){
    int i;
    printTableEmployeeHeader();
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            printTableEmployee(list[i],sectors,lenSec);
        }
    }
}


void printTableEmployeeBySectorHeader(){
    margen();printf("%12s | %12s | %3s | %10s | %4s | %12s \n", "Last Name", "Name", "Sex", "Salary","id","Date");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableEmployeeBySector(eEmployee item, eSector sectors[], int length){
    char secName[21];
    getSectorName(secName, sectors, length, item.idSector);
    margen();
    //printf("%8s | %12s | %12s | %3s | %15s | %5s | %8s \n", "Sector", "Last Name", "Name", "Sex", "Salary","id","Date");
    printf("%10s | %12s | %12s | %3c | %10.2f | %4d | %4d/%2d/%4d  \n", secName, item.lastName, item.name, item.sex, item.salary,item.id,item.date.day, item.date.month, item.date.year);
}

void printEmployeesBySector(eEmployee listEmp[], int lenEmp, eSector sectors[], int lenSec){
    int i,result;
    char sector[21];
    result = sortEmployees(listEmp, lenEmp, DOWN);
    if(result != -1){
            printTableEmployeeBySectorHeader();
            for(i=0; i<lenEmp; i++){
                if(listEmp[i].isEmpty == FALSE){
                    printTableEmployeeBySector(listEmp[i],sectors,lenSec);
                }
            }
    } else {
        margen();printf("No se puedieron ordenar los empleados \n");
    }

}
void printTableFoodHeader(){
    margen();printf("%8s | %20s \n", "id", "Comida");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableFood(eFoodMenu item){
    margen();
    printf("%8d | %20s \n", item.id, item.name);
}

void printFood(eFoodMenu list[], int length){
    int i;
    printTableFoodHeader();
    for(i=0; i<length; i++){
        printTableFood(list[i]);
    }
}

void printTableSectorHeader(){
    margen();printf("%8s | %20s \n", "id", "Sector");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableSector(eSector item){
    margen();
    printf("%8d | %20s \n", item.id, item.name);
}

void printSector(eSector list[], int length){
    int i;
    printTableSectorHeader();
    for(i=0; i<length; i++){
        printTableSector(list[i]);
    }
}

void printTableLunchHeader(){
    margen();printf("%8s | %20s | %20s | %20s \n", "id", "Empleado", "Lunch", "Fecha");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableLunch(eLunch item, eEmployee listEmp[], int lenEmp, eFoodMenu listFood[], int lenFood){
    margen();
    char foodName[21];
    char employeeName[21];
    getEmployeeName(employeeName,listEmp,lenEmp,item.idEmp);
    getFoodName(foodName,listFood,lenFood,item.idLaunch);
    printf("%8d | %20s | %20s | %d/%d/%d \n", item.id, employeeName, foodName, item.date.day, item.date.month, item.date.year);
}

void printLunchs(eLunch lunchs[], int lenLun, eEmployee listEmp[], int lenEmp, eFoodMenu listFood[], int lenFood){
    int i;
    printTableLunchHeader();
    for(i=0; i<lenLun; i++){
        printTableLunch(lunchs[i], listEmp, lenEmp, listFood, lenFood);
    }
}

int secInforms(eEmployee listEmp[], int lenEmp, eFoodMenu listFood[], int lenFood, eSector sectors[], int lenSec,  eLunch lunchs[], int lenLun){
    int option,result;
    int response = -1;
    //int totalEmpoyees = calcTotalActiveEmployees(listEmp, lenEmp);
    char informarMenu[][100] = {
        "4. INFORMAR ",
        "Listado de los empleados ordenados alfabeticamente por Apellido y Sector.",
        "Listado de comidas",
        "Listado de sectores",
        "Listar comidas asignadas a empleados",
        "Listar sectores, y por cada sector ordenar empleados por nombre",
        "Listar todos los empleados de un sector",
        "Mostrar los datos del/los empleado/s que mas gana/n"
    };
    response = 0;
    option = displayMenu(informarMenu,7,1);
    switch(option){
        case 1:
            result = sortEmployees(listEmp, lenEmp, DOWN);
            if(result == -1){
                response = -1;
                margen();printf("No se puedieron ordenar los empleados \n");
            }
            printEmployees(listEmp, lenEmp, sectors, lenSec);
            break;

        case 2:
            printFood(listFood,lenFood);
            break;

        case 3:
            printSector(sectors,lenSec);
            break;

        case 4:
            printLunchs(lunchs,lenLun,listEmp,lenEmp,listFood,lenFood);
            break;

        case 5:
            printEmployeesBySector(listEmp, lenEmp, sectors, lenSec);
            break;

    }
    return response;
}

