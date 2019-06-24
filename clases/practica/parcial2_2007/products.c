#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ddalairac.h"
#include "LinkedList.h"
#include "products.h"
#define TRUE 1
#define FALSE 0
#define BAJA 1
#define ALTA 0

static Prod *findFromCode(LinkedList* list, int code);
static Prod *findFromCode(LinkedList* list, int code){
    int i;
    Prod *aux = p_new();
    if(aux != NULL && list != NULL){
        for(i=0;i<ll_len(list);i++){
            aux = ll_get(list,i);
            if(aux->codigo == code && aux->activo == ALTA){
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
        aux->activo = ALTA;

        if(ll_add(list,aux) != -1){
            response = TRUE;
        }
    }
    return response;
}
void p_printHeader(){
    printf("%8s | %20s | %8s | %5s \n","Codigo","Descripcion","Importe","Cantidad");
}
void p_printProd(Prod* p){
    printf("%8d | %20s | %8d | %5d \n",p->codigo,p->descripcion,p->importe,p->cantidad);
}
void p_printList(LinkedList* list){
    int i,cant = 0;
    Prod * p;
    if(list != NULL && ll_len(list) > 1){
        p_printHeader();
        for(i=0;i<ll_len(list);i++){
            p = ll_get(list,i);
            if(p->activo == ALTA){
                p_printProd(p);
                cant ++;
            }
        }
    }
    if(cant == 0) {
        printf("No hay productos en la lista \n");
    }
}
int p_saveData(LinkedList* list){
    FILE *f = fopen("data.bin","wb");
    int cant,i,response = TRUE;
    if(f!= NULL && list !=NULL){
        for(i=0;i<ll_len(list);i++){
            cant = fwrite(ll_get(list,i),sizeof(Prod),1,f);
            if(cant < 1){
                response = FALSE;
            }
        }
    };
    fclose(f);
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
    fclose(f);
    return response;
}
int p_edit(LinkedList* list){
    int option,response = TRUE;
    int code;
    Prod *aux;
    char menu[][100] = {
        "Edicion",
        "Descripcion",
        "Importe",
        "Cantidad",
        "cancelar"
    };

    if(list != NULL && ll_len(list) > 0){
        code = inputValidId("Ingrese el codigo de producto (1-1000):",1001);
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
        } else {
            printf("Codigo sin producto activo\n");
            response = FALSE;
        }
    } else {
        printf("La lista esta vacia \n");
        response = FALSE;
    }
    return response;
}
int p_remove_logic(LinkedList* list){
    int response = TRUE;
    int code;
    int option;
    Prod *aux;
    if(list != NULL && ll_len(list) > 0){
        code = inputValidId("Ingrese el codigo de producto (1-1000):",1001);
        aux = findFromCode(list,code);
        if(aux != NULL){
            printf("\n");
            displaySubtitle("Producto");
            p_printHeader();
            p_printProd(aux);
            printf("\n");
            option = displayMenuConfirmacion();
            switch(option){
                case 0:
                    response = FALSE;
                    break;
                case 1:
                    aux->activo = BAJA;
                    break;
            }
        } else {
            printf("Codigo sin producto activo\n");
            response = FALSE;
        }
    } else {
        printf("La lista esta vacia \n");
        response = FALSE;
    }
    return response;
}
int p_remove_fisic(LinkedList* list){
    int response = TRUE;
    int code,index;
    int option;
    Prod *aux;
    if(list != NULL && ll_len(list) > 0){
        code = inputValidId("Ingrese el codigo de producto (1-1000):",1001);
        aux = findFromCode(list,code);
        if(aux != NULL){
            printf("\n");
            displaySubtitle("Producto");
            p_printHeader();
            p_printProd(aux);
            printf("\n");
            option = displayMenuConfirmacion();
            switch(option){
                case 0:
                    response = FALSE;
                    break;
                case 1:
                    //aux->activo = BAJA;
                    index = ll_indexOf(list,aux);
                    ll_remove(list,index);
                    break;
            }
        } else {
            printf("Codigo sin producto activo\n");
            response = FALSE;
        }
    } else {
        printf("La lista esta vacia \n");
        response = FALSE;
    }
    return response;
}
int p_sortByCode(void *v1, void *v2){
    int response = 0;
    Prod *p1;
    Prod *p2;
    if( v1 != NULL && v2 != NULL){
        p1 = (Prod*) v1;
        p2 = (Prod*) v2;
        if(p1->codigo > p2->codigo ){
            response = 1;
        } else if(p1->codigo < p2->codigo ){
            response = -1;
        }
    }
    return response;
}
int p_sortByDescription(void *v1, void *v2){
    int response = 0;
    Prod *p1;
    Prod *p2;
    if( v1 != NULL && v2 != NULL){
        p1 = (Prod*) v1;
        p2 = (Prod*) v2;
        if(strcmp(p1->descripcion,p2->descripcion) > 0){
            response = 1;
        } else if(strcmp(p1->descripcion,p2->descripcion) < 0){
            response = -1;
        }
    }
    return response;
}
int p_sortByImporte(void *v1, void *v2){
    int response = 0;
    Prod *p1;
    Prod *p2;
    if( v1 != NULL && v2 != NULL){
        p1 = (Prod*) v1;
        p2 = (Prod*) v2;
        if(p1->importe > p2->importe ){
            response = 1;
        } else if(p1->importe < p2->importe ){
            response = -1;
        }
    }
    return response;
}
int p_sortByCantidad(void *v1, void *v2){
    int response = 0;
    Prod *p1;
    Prod *p2;
    if( v1 != NULL && v2 != NULL){
        p1 = (Prod*) v1;
        p2 = (Prod*) v2;
        if(p1->cantidad > p2->cantidad ){
            response = 1;
        } else if(p1->cantidad < p2->cantidad ){
            response = -1;
        }
    }
    return response;
}
