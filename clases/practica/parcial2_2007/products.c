#include <stdio.h>
#include <stdlib.h>
#include "ddalairac.h"
#include "LinkedList.h"
#include "products.h"
#define TRUE 1
#define FALSE 0

static Prod *findFromCode(LinkedList* list, int code);
static Prod *findFromCode(LinkedList* list, int code){
    int i;
    Prod *aux = p_new();
    if(aux != NULL && list != NULL){
        for(i=0;i<ll_len(list);i++){
            aux = ll_get(list,i);
            if(aux->codigo == code){
                break;
            }
        }
        if(i == ll_len(list)){
            aux = NULL;
        }
    }
    return aux;
}
Prod *p_new(){
    Prod * aux = (Prod*)malloc(sizeof(Prod));
    return aux;
}
int p_add(LinkedList* list){
    int response = FALSE;
    Prod *aux = p_new();
    if(aux != NULL && list != NULL){
        aux->codigo = inputValidId("Ingrese el codigo de producto (1-1000):",1001);
        inputValidLetterString("Ingrese la descripcion:",aux->descripcion,50);
        aux->importe = inputValidId("Ingrese el importe (1-10000):",10000);
        aux->cantidad = inputValidInt("Ingrese la cantidad:",0);
        aux->activo = 1;

        if(ll_add(list,aux) != -1){
            response = TRUE;
        }
    }
    return response;
}
void p_printHeader(){
    printf("%8s | %20s | %8s | %5s \n","Codigo","Descripcion","Inporte","Cantidad");
}
void p_printProd(Prod* p){
    printf("%8d | %20s | %8d | %5d \n",p->codigo,p->descripcion,p->importe,p->cantidad);
    //printf("p: %d \n",&p);
}
void p_printList(LinkedList* list){
    int i;
    p_printHeader();
    for(i=0;i<ll_len(list);i++){
       p_printProd(ll_get(list,i));
    }
}
int p_saveData(LinkedList* list){
    FILE *f = fopen("data.bin","wb");
    int cant,i,response = TRUE;
    if(f!= NULL && list !=NULL){
        for(i=0;i<ll_len(list);i++){
//            p_printProd(ll_get(list,i));
            cant = fwrite(ll_get(list,i),sizeof(Prod),1,f);
            if(cant < 1){
                response = FALSE;
            }
        }
    }
    return response;
}
int p_loadData(LinkedList* list){
    FILE *f = fopen("data.bin","rb");
    int cant,response = TRUE;
    Prod *aux;
    if(f!= NULL && list !=NULL){
        while(!feof(f)){
            aux = p_new();
            cant = fread(aux,sizeof(Prod),1,f);
            if(cant < 1){
                response = FALSE;
            } else {
                if(ll_add(list,aux) == -1){
                    response = FALSE;
                    printf("Error load");
                    setPause();
                } else {
                    p_printProd(ll_get(list,ll_len(list)-1));
                }
                //setPause();
            }
        }
    }free(aux);
    return response;
}
int p_edit(LinkedList* list){
    int option,response = TRUE;
    int code = inputValidId("Ingrese el codigo de producto (1-1000):",1001);
    Prod *aux;
    char menu[][100] = {
        "Edicion",
        "Descripcion",
        "Importe",
        "Cantidad",
        "cancelar"
    };

    if(list != NULL){
        aux = findFromCode(list,code);
        if(aux != NULL){
            printf("\n");
            displaySubtitle("Producto");
            p_printHeader();
            p_printProd(aux);
            printf("\n");
            option = displayMenu(menu,4,1);
            switch(option){
                case 1:
                    inputValidLetterString("Ingrese la descripcion:",aux->descripcion,50);
                    break;
                case 2:
                    aux->importe = inputValidId("Ingrese el importe (1-10000):",10000);
                    break;
                case 3:
                    aux->cantidad = inputValidInt("Ingrese la cantidad:",0);
                    break;
                case 4:
                    response = FALSE;
                    break;
            }
            p_printProd(aux);
            printf("\n");
        }
    } else {
        response = FALSE;
    }
    return response;
}
int p_remove_logic(LinkedList* list){
    int response = TRUE;
    int code;
    return response;
}
int p_remove_fisic(LinkedList* list){
    int response = TRUE;
    int code;
    return response;
}
