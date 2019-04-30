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
    int file;
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
            list[i].file = 0;
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
            list[i].file = i;
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

void printTableHeader(){
    margen();printf("%10s | %12s | %12s | %3s | %10s | %4s | %12s \n", "Sector", "Last Name", "Name", "Sex", "Salary","file","Date");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableEmployee(eEmployee item, eSector sectors[], int length){
    char secName[21];
    getSectorName(secName, sectors, length, item.idSector);
    margen();
    //printf("%8s | %12s | %12s | %3s | %15s | %5s | %8s \n", "Sector", "Last Name", "Name", "Sex", "Salary","file","Date");
    printf("%10s | %12s | %12s | %3c | %10.2f | %4d | %4d/%2d/%4d  \n", secName, item.lastName, item.name, item.sex, item.salary,item.file,item.date.day, item.date.month, item.date.year);
}

void printEmployees(eEmployee list[], int length, eSector sectors[], int lenSec){
    int i;
    printTableHeader();
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            printTableEmployee(list[i],sectors,lenSec);
        }
    }
}

void printTableHeaderFoodMenu(){
    margen();printf("%8s | %20s \n", "id", "Comida");
    margen();printf("--------------------------------------------------------------------------------\n");
}

void printTableFoodItem(eFoodMenu item){
    margen();
    printf("%8d | %20s \n", item.id, item.name);
}

void printFoodMenu(eFoodMenu list[], int length){
    int i;
    printTableHeaderFoodMenu();
    for(i=0; i<length; i++){
        printTableFoodItem(list[i]);
    }
}


int secInforms(eEmployee listEmp[], int length, eFoodMenu listFood[], int lenFood, eSector sectors[], int lenSec){
    int option,result;
    int response = -1;
    //int totalEmpoyees = calcTotalActiveEmployees(listEmp, length);
    char informarMenu[][100] = {
        "4. INFORMAR ",
        "Listado de los empleados ordenados alfabeticamente por Apellido y Sector.",
        "Menu de comidas",
        "Comidas asignadas a empleados"
    };
    if (listEmp != NULL && length > 0){
        response = 0;
        option = displayMenu(informarMenu,3,1);
        switch(option){
            case 1:
                result = sortEmployees(listEmp, length, DOWN);
                if(result == -1){
                    response = -1;
                    margen();printf("No se puedieron ordenar los empleados \n");
                }
                printEmployees(listEmp, length, sectors, lenSec);
                break;

            case 2:
                printFoodMenu(listFood,lenFood);
                break;
        }
    }
    return response;
}

