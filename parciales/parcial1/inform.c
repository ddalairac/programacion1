
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
#include "inform.h"

#define FALSE 0
#define TRUE 1
#define DESC 0
#define ASC 1

void infoBlackCars(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,indexC;
    printMenuColors(colors,lenH);
    indexC = inputValidInt("Seleccione una Marca",lenB-1);

    printTableCarHeader();
    for(i=0;i<lenC;i++){
        if( cars[i].idColor == colors[indexC].id && cars[i].isEmpty == FALSE) {
            printTableCar(cars[i],brands,lenB,colors,lenH);
        }
    }
}

void infoCarsFromBrand(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,indexB;

    printMenuBrands(brands,lenB);
    indexB = inputValidInt("Seleccione una Marca",lenB-1);

    printTableCarHeader();
    for(i=0;i<lenC;i++){
        if(cars[i].idBrand == brands[indexB].id  && cars[i].isEmpty == FALSE){
            printTableCar(cars[i],brands,lenB,colors,lenH);
        }
    }
}

void informWorkFromPatent(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,option;
    int cont = 0;
    int response = -1;
    int loop = TRUE;
    char auxPatente[8];
    printCars(cars, lenC, brands, lenB, colors, lenH);
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
        printf("\n\n");
        printTableWorkHeader();
        for(i=0;i<lenC;i++){
            if(strcmp(works[i].patent,auxPatente) == 0  && works[i].isEmpty == FALSE){
                printTableWork(works[i], cars, lenC, services, lenS );
                cont = cont + 1;
            }
        }
        if(cont == 0){
            margen();
            printf("No hay trabajos con esa patente \n");
        }


    }

}

void informCarsWithutWorks(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,j;
    int flag;

    printTableCarHeader();
    for(i=0;i<lenC;i++){
        flag = TRUE;
        for(j=0;j<lenW;j++){
            if(strcmp(works[j].patent,cars[i].patent) == 0  && works[j].isEmpty == FALSE  && cars[i].isEmpty == FALSE){
                flag = FALSE;
                break;
            }
        }
        if(flag == TRUE){
            printTableCar(cars[i],brands,lenB,colors,lenH);
        }
    }
}

void informTotalFromPatent(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,option;
    int cont = 0;
    int total = 0;
    int response = -1;
    int loop = TRUE;
    char auxPatente[8];
    printCars(cars, lenC, brands, lenB, colors, lenH);
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
        printf("\n\n");

        for(i=0;i<lenW;i++){
            if(strcmp(works[i].patent,auxPatente) == 0  && works[i].isEmpty == FALSE){
                total = total + getServicePrice(services,lenS,works[i].idService);
                cont = cont + 1;
            }
        }
        if(cont == 0){
            margen();
            printf("No hay trabajos con esa patente \n");
        } else {
            margen();
            printf("El total con esa patente es $ %d \n",total);
        }


    }

}

void informServiceMoreRequested(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,indexS,max;
    int serviceRequest[lenS];

    for(i=0; i<lenS; i++){
        serviceRequest[i] = 0;
    }

    for(i=0;i<lenW;i++){
        if(works[i].isEmpty == FALSE){
            indexS = getServiceIndex(services,lenS,works[i].idService);
            serviceRequest[indexS] = serviceRequest[indexS] +1;
        }
    }

    for(i=0; i<lenS; i++){
        if(i==0){
            max = serviceRequest[i];
            indexS = i;
        } else if(max < serviceRequest[i]){
            max = serviceRequest[i];
            indexS = i;
        }
    }

    printf("\n   Servicio/s requerido/s %d veces: \n\n",max);
    printTableServiceHeader();
    for(i=0; i<lenS; i++){
        if(serviceRequest[i] == max){
            printTableService(services[i]);
            //printf("- serviceRequest: %d \n\n" ,serviceRequest[i]);
        }
    }

}
