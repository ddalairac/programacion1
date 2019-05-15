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

int initCars(eCar cars[], int lenC){
    int i;
    int response = -1;
    if (cars != NULL && lenC > 0){
        response = 0;
        for(i=0; i<lenC;i++){
            cars[i].id = 0;
            cars[i].patent[0] = '\0';
            cars[i].idBrand = 0;
            cars[i].idColor = 0;
            cars[i].modelYear = 0;
            cars[i].isEmpty = TRUE;
        }
    }
    return response;
}
void harcodeCars(eCar cars[], int lenC, int cant){
    int i;
    char patentL[4];
    char patentN[4];
    for(i=0; i < lenC && i < cant; i ++){
        cars[i].id = i+1;

        getRandomString(patentL,3);
        strcat(cars[i].patent, patentL);
        //patentN[4] = '\0';
        strcat(cars[i].patent, "-");
        itoa(getRandomNumber(100,999), patentN, 10);
        strcat(cars[i].patent, patentN);

        cars[i].idBrand = getRandomNumber(999,1004);
        cars[i].idColor = getRandomNumber(4999,5004);
        cars[i].modelYear = getRandomNumber(1980,2019);
        cars[i].isEmpty = FALSE;
    }
};
void printTableCarHeader(){
    margen();printf("%5s | %10s | %10s | %10s | %10s  \n", "Id", "Patente", "Marca", "Color", "Anio");
    margen();printf("-------------------------------------------------------------\n");
}
void printTableCar(eCar item, eBrand brands[], int lenB, eColor colors[], int lenH){
    char brand[21];
    char color[21];
    getBrandName(brand, brands, lenB, item.idBrand);
    getColorName(color, colors, lenH, item.idColor);
    margen();
    printf("%5d | %10s | %10s | %10s | %10d  \n", item.id, item.patent, brand, color, item.modelYear);
}
void printCars(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i;
    printTableCarHeader();
    for(i=0; i<lenC; i++){
        if(cars[i].isEmpty == FALSE){
            printTableCar(cars[i], brands, lenB, colors, lenH );
        }
    }
}

int getCarEmptySlot(eCar cars[], int lenC){
    int i;
    int index = -1;
    for(i=0; i<lenC; i++){
        if(cars[i].isEmpty == TRUE ){
            index = i;
            break;
        }
    }
    return index;
}
int setCarID(eCar cars[], int lenC){
    int i;
    int id = 0;
    for(i=0; i<lenC; i++){
        if(cars[i].id > id ){
            id = cars[i].id;
        }
    }
    id = id + 1;
    return id;
}

int newCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int index,indexB,indexH;
    index = getCarEmptySlot(cars,lenC);
    if(index != -1){

        cars[index].id = setCarID(cars,lenC);
        inputPatent("Introduzca la patente (AAA-NNN):",cars[index].patent);

        printMenuBrands(brands,lenB);
        indexB = inputValidInt("Seleccione una Marca",lenB-1);
        cars[index].idBrand = brands[indexB].id;

        printMenuColors(colors,lenH);
        indexH = inputValidInt("Seleccione un color",lenH-1);
        cars[index].idColor = colors[indexH].id;

        cars[index].modelYear = inputValidInt("Introduzca el anio de patentamiento",2019);
        cars[index].isEmpty = FALSE;
    } else {
        margen();
        printf("La lista esta completa \n");
    }
    return index;
}

int removeCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,id,index,confirm;
    int response = -1;

    printCars(cars, lenC, brands, lenB, colors, lenH);
    margen();

    id = inputValidInt("Seleccione el ID del auto a remover ",0);
    for(i=0; i<lenC; i++){
        if(cars[i].id == id && cars[i].isEmpty == FALSE){
            index = i;
            response = i;
            break;
        }
    }
    if(response != -1){
        margen();printf("Esta por remover este item de la lista de autos \n\n");
        printTableCarHeader();
        printTableCar(cars[i],brands,lenB,colors,lenH);
        confirm = displayMenuConfirmacion();
        if(confirm == TRUE){
            cars[index].isEmpty = TRUE;
        } else {
            response = -1;
            margen();printf("Baja cancelada \n");
        }
    } else {
        margen();printf("Error, el ID no existe o no ya no se encuentra activo\n");
    }
    return response;
}
int editCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH){
    int i,id,index,option,indexAux;
    int response = -1;
    char mainMenu[][100] = {
        "OPCIONES Edicion",
        "COLOR",
        "MODELO",
        "SALIR ",
    };

    printCars(cars, lenC, brands, lenB, colors, lenH);
    margen();
    id = inputValidInt("Seleccione el ID del auto a editar ",0);
    for(i=0; i<lenC; i++){
        if(cars[i].id == id && cars[i].isEmpty == FALSE){
            index = i;
            response = i;
            break;
        }
    }
    if(response != -1){
        printTableCarHeader();
        printTableCar(cars[index],brands,lenB,colors,lenH);
        option = displayMenu(mainMenu,3,2);
        switch(option){
            case 1:
                displaySubtitle("Editar Color");
                printMenuColors(colors,lenH);
                indexAux = inputValidInt("Seleccione un color",lenH-1);
                cars[index].idColor = colors[indexAux].id;
                break;
            case 2:
                displaySubtitle("Editar Modelo");
                printMenuBrands(brands,lenB);
                indexAux = inputValidInt("Seleccione una Marca",lenB-1);
                cars[index].idBrand = brands[indexAux].id;
                break;
            case 3:
                response = -1;
                break;
        }
    } else {
        margen();printf("Error, el ID no existe o no ya no se encuentra activo\n");
    }
    return response;
}

void swapCars(eCar cars[], int i, int j){
    eCar aux;
    aux = cars[i];
    cars[i] = cars[j];
    cars[j] = aux;
}
int sortCars(eCar* cars, int lenC, int order){
    int i,j;
    int response = -1;
    if(order >= DESC || order <= ASC){
        response = 0;
        for(i = 0; i < lenC - 1; i++){
            for(j = i + 1; j < lenC; j++){
                /** Descendente*/
                if(order == DESC){
                    if(cars[i].patent > cars[j].patent){
                        swapCars(cars,i,j);
                    }/* else {
                        if( (cars[i].sector == cars[j].sector) && (strcmp(cars[i].lastName, cars[j].lastName) > 0) ){
                            swapCars(cars,i,j);
                        }
                    }*/

                /** Acendente*/
                } else if(order == ASC){
                    if(cars[i].patent < cars[j].patent){
                        swapCars(cars,i,j);
                    } /*else {
                        if( (cars[i].sector == cars[j].sector) && (strcmp(cars[i].lastName, cars[j].lastName) < 0) ){
                            swapCars(cars,i,j);
                        }
                    }*/
                }
            }
        }
    }
    return response;
}
