#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/ddalairac.h"
typedef struct {
    char name[21];
    int id;
} ePersona;



void escribirArchivoInexistente();
void escribirArchivo();
void escribirArchivoBinario();
void leerArchivo();
void leerArchivoBinario();

int main()
{
    escribirArchivoInexistente();
    escribirArchivo();
    escribirArchivoBinario();
    leerArchivo();
    leerArchivoBinario();

    return 0;
}

void escribirArchivoInexistente(){
    printf("\n escribirArchivoInexistente() \n\n");
    /** FILE* fopen(const char* Path_al_archivo, const char* modo);*/

    FILE* pFile;
    pFile = fopen("./banco1.txt","rb");
    if(pFile == NULL){
        printf("El archivo no puede ser abierto\n");
        //exit(1);
    }
    fclose(pFile);

    setPause();
}

void escribirArchivo(){
    printf("\nescribirArchivo() \n\n");
    int cant, len;
    char text[] = "Hola mundo!";
    FILE* pFile;

    pFile = fopen("./banco.txt","w");
    if(pFile == NULL){
        printf("El archivo no puede ser abierto\n");
        //exit(1);
    } else {
        len = strlen(text);
        cant = fwrite(text,sizeof(char),len,pFile );

        if(cant < len){
            printf("Error al escribir el archivo\n");
        } else {
            printf("archivo banco.txt modificado\n");
        }
    }


    fclose(pFile);

    setPause();
}

void escribirArchivoBinario(){
    printf("\n escribirArchivoBinario() \n\n");

    int cant;
    ePersona persona = {"Diego", 29747505};
    FILE* pFile;


    pFile = fopen("./banco.bin","wb");
    if(pFile == NULL){
        printf("El archivo no puede ser abierto");
        //exit(1);
    } else {
        cant = fwrite(&persona,sizeof(ePersona),1,pFile );

        if(cant < 1){
            printf("Error al escribir el archivo\n");
        } else {
            printf("archivo banco.bin modificado\n");
        }
    }


    fclose(pFile);

    setPause();
}

void leerArchivo(){
    printf("\n leerArchivo() \n\n");

    int len = 50;
    char text[50];
    FILE* pFile;

    pFile = fopen("./banco_r.txt","r");
    if(pFile != NULL){
        while(!feof(pFile)){
            fread(text,sizeof(char),len, pFile);
            printf("Texto del archivo: %s \n", text);
        }
    }

    fclose(pFile);
    setPause();
}

void leerArchivoBinario(){
    printf("\n leerArchivoBinario() \n\n");

    int cant;
    ePersona persona;
    FILE* pFile;

    pFile = fopen("./banco.bin","rb");
    if(pFile != NULL){
        while(!feof(pFile)){
            cant = fread(&persona,sizeof(ePersona),1, pFile);
            if(cant == 1){
                printf("Nombre: %s \n", persona.name);
                printf("id: %d \n", persona.id);
            }
        }
    } else {
        printf("NULL pointer \n");
    }

    fclose(pFile);
    setPause();
}
