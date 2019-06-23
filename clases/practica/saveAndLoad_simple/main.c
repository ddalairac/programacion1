#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadFile(path,action);
void readFile(path,action);
int main(){
//    loadFile();
//    abrir();
    loadFile("./data.bin","wb");
    readFile("./data.bin","rb");

    loadFile("./data.txt","w");
    readFile("./data.txt","r");
    return 0;
}

void readFile(path,action){
    printf("readFile::  \npath: %s | action: %s \n",path,action);
    FILE* pFile;
    int cant,len = 20;
    //char *text = (char*)malloc(sizeof(char)*len);
    char text[len];

    pFile = fopen(path,action);
    if(pFile != NULL){
        while(!feof(pFile)){
            cant = fread(text,sizeof(char),len,pFile);
            printf("%s - %d\n",text,cant);
        }
    } else {
        printf("No se puede abrir el archivo \n");
    }
    fclose(pFile);
    printf("\n----------------- \n\n");
}
void loadFile(path,action){
    printf("loadFile::  \npath: %s | action: %s \n",path,action);
//    char *text = "Hola mundo\n";
    char text[] = "Hola mundo!";
    int len,cant;

    len = strlen(text);
    printf("Text: %s \n",text);
    printf("len: %d \n",len);

    FILE* pFile;
    pFile = fopen(path,action);
    if(pFile == NULL){
        printf("No se puede abrir el archivo \n");
    }else{
        printf("Archivo encontrado \n");
        cant = fwrite(text,sizeof(char),len, pFile);
        if(cant == len){
            printf("datos guardados - cant %d\n",cant);
        } else if(cant<len){
            printf("Error al loadFile \n");
        } else {
            printf("UPS! surgio un imprevisto \n");
        }
    }
        printf("\n----------------- \n\n");
    fclose(pFile);
}



