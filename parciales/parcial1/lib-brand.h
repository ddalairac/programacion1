#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

void printTableBrandHeader();
void printTableBrand(eBrand item);
void printBrands(eBrand list[], int length);
void printMenuBrands(eBrand list[], int length);
void getBrandName(char srt[], eBrand list[], int length, int id);
