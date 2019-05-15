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

void printTableColorHeader(){
    margen();printf("%5s | %10s  \n", "Id", "Colores");
    margen();printf("-------------------- \n");
}
void printTableColor(eColor item){
    margen();
    printf("%5d | %10s  \n",item.id, item.nombreColor);
}
void printColors(eColor colors[], int length){
    int i;
    printTableColorHeader();
    for(i=0; i<length; i++){
        if(colors[i].isEmpty == FALSE){
            printTableColor(colors[i]);
        }
    }
}
void printMenuColors(eColor list[], int length){
    int i;
    margen();printf("Colores \n");
    margen();printf("-------------------\n");
    for(i=0; i<length; i++){
        if(list[i].isEmpty == FALSE){
            margen();printf("%2d  %s  \n", i, list[i].nombreColor);
        }
    }
}
void getColorName(char srt[], eColor colors[], int length, int id){
    int i;
    for(i=0; i<length; i++){
        if(colors[i].id == id){
            strcpy(srt, colors[i].nombreColor);
        }
    }
}
