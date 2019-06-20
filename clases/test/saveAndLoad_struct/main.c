#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ddalairac.h"

typedef struct {
    char name[16];
    int id;
} ePersona;

void* new_persona();
ePersona* alta_persona(ePersona *list,int *len);
void printPersona(ePersona *list,int len);
void saveAsBinary(char* path, ePersona *list,int *len);
ePersona *loadFromBinary(char* path, ePersona *list,int *len);

void saveAsText(char* path, ePersona *list,int *len);
ePersona *loadFromText(char* path, ePersona *list,int *len);

ePersona* add_persona(ePersona *list,int len,char *name,char id);
int add_persona2(ePersona *list,int *len,char *name);

int main(){
    int len = 0;
    ePersona *list = new_persona();
    int options;
    char menuOptions[][100]={
        "Menu",
        "Alta Persona",
        "Listar personas",
        "Guardar bin",
        "Cargar bin",
        "Guardar txt",
        "Cargar txt",
        "salir"
    };
    do{
        options = displayMenu(menuOptions,7,0);
        switch(options){
            case 1:
                displayTitle("Alta persona");
                list = alta_persona(list,&len);
                setPause();
                break;
            case 2:
                displayTitle("Listar personas");
                printPersona(list,len);
                setPause();
                break;
            case 3:
                displayTitle("Guardar binario");
                saveAsBinary("data.bin",list,&len);
                setPause();
                break;
            case 4:
                displayTitle("Cargar binario");
                list = loadFromBinary("data.bin",list,&len);
                setPause();
                break;
            case 5:
                displayTitle("Guardar archivo de texto");
                saveAsText("data.txt", list,&len);
                setPause();
                break;
            case 6:
                displayTitle("Cargar archivo de texto");
                list = loadFromText("data.txt", list,&len);
                setPause();
                break;
            case 7:
                displayTitle("Salir");
                break;
        }

    } while(options!=7);

    return 0;
}
void* new_persona(){
    ePersona *list = (ePersona*) calloc(1,sizeof(ePersona));
    printf("list %p - sizeof: %d\n",list,(sizeof(ePersona)) );
    return list;
}
ePersona* alta_persona(ePersona *list,int *len){
    int memSize = 0;
    int i;
    ePersona* auxList = (ePersona*)calloc((*len+1),sizeof(ePersona));
    if(list != NULL){
        if(*len >= 0){
            if (auxList != NULL){

                (auxList+(*len))->id =*len+1;
                printf("Ingrese su nombre: ");
                scanf("%s",(auxList+(*len))->name);

                for(i=0; i < *len; i++){
                    strcpy( (auxList+i)->name, (list+i)->name );
                    (auxList+i)->id = (list+i)->id;
                }
                *len = *len+1;

                printPersona(auxList,*len);
                free(list);
            } else {
                printf("Ups!, error en new: new \n");
            }
        } else {
            printf("Ups!, error en new persona: len \n");
        }
    } else {
        printf("Ups!, error en new persona: list \n");
    }
    return auxList; //len;
}
void printPersona(ePersona *list,int len){
//    printf("Len: %d  -  list: %p\n",len,list);
    printf("id  |  Persona \n");
    printf("---------------\n");
    for(int i=0; i<(len); i++){
        printf("%2d  |  %s \n",(list+i)->id, (list+i)->name);
    }
}
void saveAsBinary(char* path, ePersona *list,int *len){
    FILE* pFile;
    ePersona* persona;
    int i;
    if(path != NULL && list != NULL && *len >=0){

        pFile = fopen(path,"wb");
        if(pFile!=NULL){
            for(i=0; i<*len; i++){
//                printf("persona %p \n",(list+i));
                persona = (list+i);
                if(persona != NULL){
                    fwrite(persona,sizeof(ePersona),1,pFile);
                } else {
                    printf("persona == NULL");
                    break;
                }
            }
        }
        fclose(pFile);
    }

    /** feedback*/
    if(i == *len){
        printf("Data Guardada \n");
    } else {
        printf("Error al Guardar");
    }
}
ePersona *loadFromBinary(char* path , ePersona *list,int *len){
    FILE* pFile;
    int cant,i;
    ePersona* auxList = NULL;
    ePersona* new;
    int response = 0;

    if(path != NULL && list != NULL){
        pFile = fopen(path,"rb");
        if(pFile!=NULL){

            while(!feof(pFile)){
                new = (ePersona*)calloc(1,sizeof(ePersona));
                cant = fread(new,sizeof(ePersona),1,pFile);
//                printf("cant: %d \n",cant);
                if(new != NULL){
                    if(cant < 1){
//                        printf("error al leer %s, cant: %d \n",path,cant);
                        break;
                    } else {
//                        printf("%s | %d \n",new->name,new->id);
                        auxList = (ePersona*)calloc((*len+1),sizeof(ePersona));

                        /** insert list int aux*/
                        for(i=0; i < *len; i++){
                            strcpy( (auxList+i)->name, (list+i)->name );
                            (auxList+i)->id = (list+i)->id;
                        }
                        /** ingresar dato de archivo */
                        strcpy( (auxList+(*len))->name,new->name );
                        (auxList+(*len))->id = new->id;

                        *len = *len + 1;
                        free(list);
                        free(new);
                        list = auxList;
                        response = 1;
                    }
                }
            }

        }
//        printf("len %d %d %d",len,*len,&len);
//        printPersona(list,*len);
        fclose(pFile);
    }
    /** feedback*/
    if(response == 1){
        printf("Data Cargada \n");
        printPersona(auxList,*len);
    } else {
        printf("Error al cargar");
    };
    return auxList;
}


void saveAsText(char* path, ePersona *list,int *len){
    int i;
    FILE *pFile;

    if(*len > 0){
        pFile = fopen(path,"w");
        if(pFile != NULL && list != NULL){
//            printf("Salvar \n");
            for(i=0;i<*len;i++){
                fprintf(pFile,"%s,%d\n",list[i].name,list[i].id);
            }
        }
        fclose(pFile);
//    } else {
//        printf("len =< 0 \n");
    }

    /** feedback*/
    if(i == *len){
        printf("Data Guardada \n");
    } else {
        printf("Error al Guardar");
    }
}
ePersona *loadFromText(char* path, ePersona *list,int *len){
    FILE *pFile;
    char buffer[2][30];
    int cant,i;
    ePersona* auxList = NULL;
    pFile = fopen(path,"r");
    int response = 1;

    if(pFile != NULL){
        printf("Data Cargada \n");
        while(!feof(pFile)){
            cant = fscanf(pFile," %[^,],%[^\n],\n",buffer[0],buffer[1]);

            if(cant < 2){
                printf("error al leer %s \n",path);
                break;
                response = 0;
            } else {
                auxList = (ePersona*)calloc((*len+1),sizeof(ePersona));

                /** insert list int aux*/
                for(i=0; i < *len; i++){
                    strcpy( (auxList+i)->name, (list+i)->name );
                    (auxList+i)->id = (list+i)->id;
                }
                /** ingresar dato de archivo */
                strcpy( (auxList+(*len))->name,buffer[0] );
                (auxList+(*len))->id = atoi(buffer[1]);

                *len = *len + 1;
                free(list);
                list = auxList;
            }
        }
    }
    /** feedback*/
    if(response == 1){
        printf("Data Cargada \n");
        printPersona(auxList,*len);
    } else {
        printf("Error al cargar");
    }
    return auxList;
}

