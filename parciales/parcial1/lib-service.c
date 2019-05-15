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

void printTableServiceHeader(){
    margen();printf("%5s | %15s | %s \n", "Id", "Descripcion", "Precio");
    margen();printf("-----------------------------------\n");
}
void printTableService(eService item){
    margen();
    printf("%5d | %15s | %c %d  \n", item.id, item.description, '$', item.price);
}
void printServices(eService list[], int length){
    int i;
    printTableServiceHeader();
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            printTableService(list[i]);
        }
    }
}

void printMenuServices(eService list[], int length){
    int i;
    margen();printf("Servicios \n");
    margen();printf("-------------------\n");
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            margen();printf("%2d  %s  \n", i, list[i].description);
        }
    }
}
void getServiceDescription(char srt[], eService list[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            strcpy(srt, list[i].description);
        }
    }
}

int getServicePrice(eService list[], int length, int id){
    int i,price;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            price = list[i].price;
            break;
        }
    }
    return price;
}


int getServiceIndex(eService list[], int length, int id){
    int i,index;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    return index;
}
