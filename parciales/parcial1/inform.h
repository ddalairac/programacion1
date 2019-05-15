#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

void infoBlackCars(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH);
void infoCarsFromBrand(eCar cars[], int lenC, eBrand brands[], int lenB, eColor colors[], int lenH);
void informWorkFromPatent(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH);
void informCarsWithutWorks(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH);
void informTotalFromPatent(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH);
void informServiceMoreRequested(eWork works[], int lenW, eCar cars[], int lenC, eService services[], int lenS, eBrand brands[], int lenB, eColor colors[], int lenH);




