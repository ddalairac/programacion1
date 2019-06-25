#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ddalairac.h"
#include "dominio.h"

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DESC 0

int main(){
    int option = 0;
    LinkedList* list = ll_newLinkedList();
    LinkedList* autos = ll_newLinkedList();
    LinkedList* motos = ll_newLinkedList();
//    char fileName[50];
    char fileName[50] = "./datos.csv";
    d_loadFromText(fileName,list);

    char menuOptions[][100] = {
        "MENU PRINCIPAL",
        "Cargar Datos",
        "Lista",
        "",
        "",
        "",
        "Salir",
    };
     do{
        option = displayMenu(menuOptions,6,0);
        switch(option)
        {
            case 1:
                displayTitle("1. Cargar Datos");
                inputValidAlphaNumericString("Igrese el nombre del archivo:",fileName,50);
                d_loadFromText(fileName,list);
                setPause();
                break;
            case 2:
                displayTitle("2. Lista");
                if(ll_isEmpty(list)!=-1){
                    ll_sort(list,d_sortByDominio, ASC);
                    d_printList(list);
                } else {
                    printf("La lista esta vacia \n");
                }
                setPause();
                break;
            case 3:
                displayTitle("3. Setear tipo ");
                if(ll_isEmpty(list)!=-1){
                    list = ll_map(list,d_defineType);
                } else {
                    printf("La lista esta vacia \n");
                }
                setPause();
                break;
            case 4:
                displayTitle("4. ");
                if(ll_isEmpty(list)!=-1){
                } else {
                    printf("La lista esta vacia \n");
                }
                setPause();
                break;
        }
    }while(option != 6);

    return 0;
}
