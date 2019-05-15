#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

int initWorks(eWork list[], int length);
void harcodeWorks(eWork works[], int length, eCar cars[], int lenC, eService services[], int lenS, int cant);
void printTableWorkHeader();
void printTableWork(eWork item, eCar cars[], int lenCar, eService services[], int lenSer);
void printWorks(eWork list[], int length, eCar cars[], int lenCar, eService services[], int lenSer);
int getEmptyWorkSlot(eWork list[], int length);
int getnewWorkID(eWork list[], int length);
int newWork(eWork works[], int length, eCar cars[], int lenC, eService services[], int lenS);
void swapWorks(eWork works[], int i, int j);
int sortWorks(eWork works[], int lenW, int order);
