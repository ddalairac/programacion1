#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ddalairac.h"
#include "dominio.h"

#define TRUE 1
#define FALSE 0

int main()
{

    int option = 0;
    char fileName[50];
    LinkedList* list = ll_newLinkedList();
    char menuOptions[][100] = {
        "MENU PRINCIPAL",
        "Cargar Datos",
        "Lista",
        "",
        "",
        "",
        "Salir",
    };
    setPause();
     do{
        option = displayMenu(menuOptions,6,0);
        switch(option)
        {
            case 1:
                displayTitle("1. Cargar Datos");
                inputValidAlphaNumericString("Igrese el nombre del archivo:",fileName,50);
                d_loadFromText("datos1.csv",list);
                setPause();
                break;
            case 2:
                displayTitle("2. Lista");
                d_printList(list);
                setPause();
                break;
            case 3:
                displayTitle("3. Baja");
                setPause();
                break;
            case 4:
                displayTitle("3. Lista");
                setPause();
                break;
        }
    }while(option != 6);

    return 0;
}
