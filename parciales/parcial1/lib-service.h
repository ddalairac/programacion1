#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

void printTableServiceHeader();
void printTableService(eService item);
void printServices(eService list[], int length);
void printMenuServices(eService list[], int length);
void getServiceDescription(char srt[], eService list[], int length, int id);
int getServicePrice(eService list[], int length, int id);
int getServiceIndex(eService list[], int length, int id);
