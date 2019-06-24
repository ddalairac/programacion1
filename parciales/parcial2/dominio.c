#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ddalairac.h"
#include "dominio.h"

#define TRUE 1
#define FALSE 0


Dominio* d_new(){
    Dominio* this = (Dominio*) malloc(sizeof(Dominio));
    if( this != NULL){
        d_setId(this,0);
        d_setDominio(this,"");
        d_setAnio(this,0);
        d_setTipo(this,' ');
//        printf("exito \n");
    }
    return this;
}
Dominio* d_newParametros(char* idStr,char* dominioStr,char* anioStr, char* tipoStr){
    Dominio* this;
    if (idStr != NULL && dominioStr != NULL && anioStr != NULL && tipoStr != NULL){
        this = d_new();
        if( this != NULL){
            int id = d_setId(this, atoi(idStr));
            int dom = d_setDominio(this, dominioStr);
            int a = d_setAnio(this, atoi(anioStr));
            int t = d_setTipo(this, tipoStr[0]);
//            printf("%d %d %d %d \n",id,dom,a,t);
//            if( !d_setId(this, atoi(idStr))||
//                !d_setDominio(this, dominioStr) ||
//                !d_setAnio(this, atoi(anioStr)) ||
//                !d_setTipo(this, tipoStr[0])){
//                    //free(this);
//                    //this = NULL;
//                    printf("Error\n");
//            } else {
//                    printf("correcto\n");
//            }
        }
    }
    return this;
}

int d_setId(Dominio* this,int id){
    int response = FALSE;
    if(this != NULL && id > 0){
        this->id = id;
        response = TRUE;
    }
    return response;
}
int d_getId(Dominio* this,int* id){
    int response = FALSE;
    if(this != NULL && id != NULL){
        *id = this->id;
        response = TRUE;
    }
    return response;
}

int d_setDominio(Dominio* this,char* dominio){
    int response = FALSE;
    if(this != NULL && dominio != NULL && strlen(dominio) == 6){
        strcpy(this->dominio, dominio);
        response = TRUE;
    }
    return response;
}
int d_getDominio(Dominio* this,char* dominio){
    int response = FALSE;
    if(this != NULL && dominio != NULL){
        strcpy(dominio, this->dominio);
        response = TRUE;
    }
    return response;
}

int d_setAnio(Dominio* this,int anio){
    int response = FALSE;
    if(this != NULL && anio > 0){
        this->anio = anio;
        response = TRUE;
    }
    return response;
}
int d_getAnio(Dominio* this,int* anio){
    int response = FALSE;
    if(this != NULL && anio != NULL){
        *anio = this->anio;
        response = TRUE;
    }
    return response;
}

int d_setTipo(Dominio* this,int tipo){
    int response = FALSE;
    if(this != NULL && tipo > 0){
        this->tipo = tipo;
        response = TRUE;
    }
    return response;
}
int d_getTipo(Dominio* this,int* tipo){
    int response = FALSE;
    if(this != NULL && tipo != NULL){
        *tipo = this->tipo;
        response = TRUE;
    }
    return response;
}

void d_printHeader(){
    printf("%8s | %15s | %20s | %10s \n", "id", "dominio", "anio", "tipo");
    margen();
    printf("------------------------------------------------------------- \n");
}
void d_printDominio(Dominio* dom){
    if(dom != NULL){
        printf("%8d | %15s | %20d | %10d \n", dom->id, dom->dominio, dom->anio, dom->tipo);
    } else {
        printf("NULL pointer \n");
    }
}
void d_printList(LinkedList* list){
    int i;
    if(list != NULL){
         d_printHeader();
        for(i = 0; i < ll_len(list); i++){
            d_printDominio( (Dominio*) ll_get(list,i));
        }
    }
}
int d_loadFromText(char* path , LinkedList* list){
    FILE* pFile;
    char buffer[3][30];
    int cant,response = FALSE;
    Dominio* dom;

    if(path != NULL && list != NULL){
        pFile = fopen(path,"r");
        if(pFile!=NULL){
            //  parser
            while(!feof(pFile)){
                cant = fscanf(pFile," %[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2]);
//                printf("%s %s %s \n",buffer[0],buffer[1],buffer[2]);

                dom = d_newParametros(buffer[0],buffer[1],buffer[2],"n");


                if(dom != NULL ){//&& d_isValid(dom)
                    ll_add(list,dom );
//                    d_printDominio(dom);
                    response = TRUE;
                }
                if(cant < 3){
                    if(feof(pFile)){
                        break;
                    }else{
                        response = FALSE;
                        break;
                    }
                }
            }
            // end parser
            response = 1;
        }else{
            response = TRUE;
        }
        fclose(pFile);
    }

    if(response == TRUE){
        margen(); printf("Datos cargados con exito \n");
    } else {
        margen(); printf("Ups!, ocurrio un error al cargar los datos \n");
    }
    return response;
}
