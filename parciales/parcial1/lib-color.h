#ifndef SH
    #define SH
    #include "structs.h"
#endif // SH

void printTableColorHeader();
void printTableColor(eColor item);
void printColors(eColor list[], int length);
void printMenuColors(eColor list[], int length);
void getColorName(char srt[], eColor list[], int length, int id);
