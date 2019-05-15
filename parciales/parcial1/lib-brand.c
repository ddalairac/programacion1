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

void printTableBrandHeader(){
    margen();printf("%5s | %10s  \n", "Id", "Marcas");
    margen();printf("----------------------\n");
}
void printTableBrand(eBrand item){
    margen();
    printf("%5d | %10s  \n", item.id, item.description);
}
void printBrands(eBrand list[], int length){
    int i;
    printTableBrandHeader();
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            printTableBrand(list[i]);
        }
    }
}

void printMenuBrands(eBrand list[], int length){
    int i;
    margen();printf("Marcas \n");
    margen();printf("-------------------\n");
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            margen();printf("%2d  %s  \n", i, list[i].description);
        }
    }
}
void getBrandName(char srt[], eBrand list[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(list[i].id == id){
            strcpy(srt, list[i].description);
        }
    }
}
