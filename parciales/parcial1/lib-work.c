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

#include "ddalairac.h"
#include "lib-brand.h"
#include "lib-car.h"
#include "lib-color.h"
#include "lib-service.h"
#include "lib-work.h"

#define DESC 0
#define ASC 1
int initWorks(eWork list[], int length){
    int i;
    int response = -1;
    if (list != NULL && length > 0){
        response = 0;
        for(i=0; i<length;i++){
            list[i].id = 0;
            list[i].patent[0] = '\0';
            list[i].idService = 0;
            list[i].date.day = 0;
            list[i].date.month = 0;
            list[i].date.year = 0;
            list[i].isEmpty = TRUE;
        }
    }
    return response;
}

void harcodeWorks(eWork works[], int length, eCar cars[], int lenC, eService services[], int lenS, int cant){
    int i;
    for(i=0; i < length && i < cant; i ++){
        works[i].id = i+1;
        strcpy(works[i].patent, cars[getRandomNumber(1,5)].patent);
        works[i].idService = getRandomNumber(20000,20003);
        works[i].date.day = getRandomNumber(1,28);
        works[i].date.month = getRandomNumber(1,12);
        works[i].date.year = getRandomNumber(1980,2019);
        works[i].isEmpty = FALSE;
    }
};


void printTableWorkHeader(){
    margen();printf("%5s | %10s | %10s | %s \n", "Id" ,"Patente", "Servicio", "Fecha");
    margen();printf("---------------------------------------------\n");
}
void printTableWork(eWork item, eCar cars[], int lenCar, eService services[], int lenSer){
    char service[26];
    char dateF[11];
    setDateFormat(dateF,item.date.day, item.date.month, item.date.year);
    getServiceDescription(service, services, lenSer, item.idService);
    margen();
    //printf("%5d | %10s | %10s | %d/%d/%d  \n", item.id, item.patent, service, item.date.day, item.date.month, item.date.year);
    printf("%5d | %10s | %10s | %s  \n", item.id, item.patent, service, dateF);
}
void printWorks(eWork list[], int length, eCar cars[], int lenCar, eService services[], int lenSer){
    int i;
    printTableWorkHeader();
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            printTableWork(list[i], cars, lenCar, services, lenSer );
        }
    }
}

int getWorkEmptySlot(eWork works[], int lenW){
    int i;
    int index = -1;
    for(i=0; i<lenW; i++){
        if(works[i].isEmpty == TRUE ){
            index = i;
            break;
        }
    }
    return index;
}
int setWorkID(eWork works[], int lenW){
    int i;
    int id = 0;
    for(i=0; i<lenW; i++){
        if(works[i].id > id ){
            id = works[i].id;
        }
    }
    id = id + 1;
    return id;
}
int newWork(eWork works[], int length, eCar cars[], int lenC, eService services[], int lenS){
    int index,i,option,indexS;
    int response = -1;
    int loop = TRUE;
    char auxPatente[8];
    index = getWorkEmptySlot(works,length);
    if(index != -1){
        do{
            inputPatent("Introduzca la patente (AAA-NNN):",auxPatente);
            for(i=0; i<lenC; i++){
                if(strcmp(auxPatente,cars[i].patent) == 0){
                    response = i;
                    loop = FALSE;
                    break;
                }
            }
            if(response == -1){
                printf("Error, la patente no se encuentra en el listado de autos. \n");
                printf("Desea introducir una nueva patente?. \n");
                option = displayMenuConfirmacion();
                if(option == 0){
                    loop = FALSE;
                } else {
                    // nuevo intento
                }
            }
        }while(loop == TRUE);

        if(response != -1){
            works[index].id = setWorkID(works,length);
            strcpy(works[index].patent, auxPatente);
            printMenuServices(services,lenS);
            indexS = inputValidInt("Seleccione un servicio",lenS-1);
            works[index].idService = services[indexS].id;
            inputValidDate("Ingrese fecha del trabajo: ",&works[index].date.day,&works[index].date.month,&works[index].date.year);
            works[index].isEmpty = FALSE;
        }
    } else {
        margen();
        printf("La lista esta completa \n");
    }
    return response;
}


void swapWorks(eWork works[], int i, int j){
    eWork aux;
    aux = works[i];
    works[i] = works[j];
    works[j] = aux;
}
int sortWorks(eWork works[], int lenW, int order){
    int i,j;
    int response = -1;
    if(order >= DESC || order <= ASC){
        response = 0;
        for(i = 0; i < lenW - 1; i++){
            for(j = i + 1; j < lenW; j++){
                /** Descendente*/
                if(order == DESC){
                    if(works[i].date.year > works[j].date.year){
                        swapWorks(works,i,j);
                    } else {
                        if( (works[i].date.year == works[j].date.year) && (works[i].date.month > works[j].date.month) ){
                            swapWorks(works,i,j);
                        } else {
                            if( (works[i].date.month == works[j].date.month) && (works[i].date.day > works[j].date.day) ){
                                swapWorks(works,i,j);
                            }
                        }
                    }

                /** Acendente*/
                } else if(order == ASC){
                    if(works[i].date.year < works[j].date.year){
                        swapWorks(works,i,j);
                    } else {
                        if( (works[i].date.year == works[j].date.year) && (works[i].date.month < works[j].date.month) ){
                            swapWorks(works,i,j);
                        } else {
                            if( (works[i].date.month == works[j].date.month) && (works[i].date.day < works[j].date.day) ){
                                swapWorks(works,i,j);
                            }
                        }
                    }
                }
            }
        }
    }
    return response;
}
