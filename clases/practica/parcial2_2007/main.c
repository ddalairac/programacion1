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
        int option,optionSort;
        char menuOptions[][100]={
            "Admin Productos",
            "Alta",
            "Modificacion",
            "Baja logica",
            "Baja fisica",
            "Listar",
            "Ordenar y listar",
            "Salir"
        };
        char menuSort[][100]={
            "Ordenar",
            "Codigo",
            "Descripcion",
            "Importe",
            "Cantidad",
        };
        while(option!=7){
            option = displayMenu(menuOptions,7,0);
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
                    if(p_remove_logic(list)==TRUE){
                        printf("Baja exitosa \n");
                        if(p_saveData(list) == TRUE){
                            printf("Data guardada \n");
                        }
                    } else {
                        printf("No se produjo la baja \n");
                    }
                    setPause();
                    break;
                case 4:
                    displayTitle("4.Baja fisica");
                    if(p_remove_fisic(list)==TRUE){
                        printf("Baja exitosa \n");
                        if(p_saveData(list) == TRUE){
                            printf("Data guardada \n");
                        }
                    } else {
                        printf("No se produjo la baja \n");
                    }
                    setPause();
                    break;
                case 5:
                    displayTitle("5.Listar");
                    p_printList(list);
                    setPause();
                    break;

                case 6:
                    displayTitle("5.Ordenar");
                    optionSort = displayMenu(menuSort,4,1);
                    switch(optionSort){
                           case 1:
                               displaySubtitle("Por codigo");
                               ll_sort(list,p_sortByCode,1);
                               break;
                           case 2:
                               displaySubtitle("Por descripcion");
                               ll_sort(list,p_sortByDescription,1);
                               break;
                           case 3:
                               displaySubtitle("Por importe");
                               ll_sort(list,p_sortByImporte,1);
                               break;
                           case 4:
                               displaySubtitle("Por cantidad");
                               ll_sort(list,p_sortByCantidad,1);
                               break;
                    }
                    p_printList(list);
                    if(p_saveData(list) == TRUE){
                        printf("Data guardada \n");
                    }
                    setPause();
                    break;
            }
        }
    }

    return 0;
}
