#include <stdio.h>
#include <stdlib.h>
#include "ddalairac.h"
#include "LinkedList.h"
#include "products.h"

#define TRUE 1
#define FALSE 0
int main(){

    LinkedList *list = ll_newLinkedList();
    if(list != NULL){
        p_loadData(list);
        int option;
        char menuOptions[][100]={
            "Admin Productos",
            "Alta",
            "Modificacion",
            "Baja logica",
            "Baja fisica",
            "Listar",
            "Salir"
        };
        while(option!=6){
            option = displayMenu(menuOptions,6,0);
            switch(option){
                case 1:
                    displayTitle("1.Alta");
                    if(p_add(list)==TRUE){
                        printf("Alta exitosa \n");
                        if(p_saveData(list) == TRUE){
                            printf("Data guardada \n");
                        }
                    } else {
                        printf("Error en alta \n");
                    }
                    setPause();
                    break;
                case 2:
                    displayTitle("2.Modificacion");
                    if(p_edit(list)==TRUE){
                        printf("Modificacion exitosa \n");
                        if(p_saveData(list) == TRUE){
                            printf("Data guardada \n");
                        }
                    } else {
                        printf("No se produjo modificion \n");
                    }
                    setPause();
                    break;
                case 3:
                    displayTitle("3.Baja logica");
                    p_remove_logic(list);
                    setPause();
                    break;
                case 4:
                    displayTitle("4.Baja fisica");
                    p_remove_fisic(list);
                    setPause();
                    break;
                case 5:
                    displayTitle("5.Listar");
                    p_printList(list);
                    setPause();
                    break;
            }
        }
    }

    return 0;
}
