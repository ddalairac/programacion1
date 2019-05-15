#include <stdio.h>
#include <stdlib.h>

/** Anidar estructuras **/


typedef struct{
    int id;
    char descripcion[20];
} eSector;
typedef struct{
    int day;
    int month;
    int year;
} eDate;
typedef struct{
    char name[51];
    eDate birthDate;

} eRerson;

int main()
{/*
    ePerson person[] = {
        {"jose", {19,10,1982} },
        {"MArcos", {8,12,1995} }
    };


    printf("%10s %20s \n", "Nombre", "Cumpleaños");
    for(int i = 0; i < 2; i ++){
        printf("%10s  %7s  %d/%d/%d \n", person[i].name, " ",person[i].birthDate.day, person[i].birthDate.month, person[i].birthDate.year);
    }*/


    int numero[] = {4,3};
    mostrarnumero(numero);
    printf("numero: %d \n",numero[0]);

    return 0;
}


/** Usar vector con nomenclatura de puntero */
void mostrarnumero(int *numero){
/**  mostrarnumero(int numero[]){   IDEM */
/**     numero[0] = 6;              IDEM */
        *(numero + 0) = 6;
        printf("numero: %d \n", numero[0]);
    }
