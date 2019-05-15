#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

int initCars(eCar list[], int length);
void harcodeCars(eCar cars[], int lenC, int cant);
void printTableCarHeader();
void printTableCar(eCar item, eBrand brands[], int lenBrand, eColor colors[], int lenColor);
void printCars(eCar list[], int length, eBrand brands[], int lenBrand, eColor colors[], int lenColor);
int getCarEmptySlot(eCar cars[], int length);
int setCarID(eCar cars[], int length);
int newCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH);
int removeCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH);
int editCar(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH);
int sortCars(eCar* cars, int lenC, int order);
void swapCars(eCar cars[], int i, int j);
