#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;
}eEmpleado;

void mostrarEmpleados(eEmpleado* lista, int tam);
void mostrarEmpleado(eEmpleado* emp);
void altaEmpleado(eEmpleado* lista, int tam);
void inicializarEmpleados(eEmpleado* lista, int tam);
void imprimirEmpleados(eEmpleado* lista, int tam);
void guardarEmpleadosBinario(eEmpleado* lista, int tam);
void cargarEmpleados(eEmpleado* lista, int tam);
int menu();
int buscarLibre(eEmpleado* lista, int tam);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);

int main()
{
    char seguir='s';
    eEmpleado* lista=(eEmpleado*)malloc(sizeof(eEmpleado)*TAM);

    if(lista==NULL){
        printf("No se consiguio memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    inicializarEmpleados(lista,TAM);

    do{
        switch(menu()){
        case 1:
            //printf("Opcion 1\n");
            cargarEmpleados(lista,TAM);
            system("pause");
            break;
        case 2:
            //printf("Opcion 2\n");
            altaEmpleado(lista,TAM);
            system("pause");
            break;
        case 3:
            //printf("Opcion 3\n");
            mostrarEmpleados(lista,TAM);
            system("pause");
            break;
        case 4:
            //printf("Opcion 4\n");
            guardarEmpleadosBinario(lista,TAM);
            system("pause");
            break;
        case 5:
            //printf("Opcion 5\n");
            imprimirEmpleados(lista,TAM);
            system("pause");
            break;
        case 6:
            printf("Opcion 6\n");
            seguir='n';
            system("pause");
            break;
        }
    }while(seguir=='s');

    free(lista);

    return 0;
}

void inicializarEmpleados(eEmpleado* lista, int tam){
    for(int i=0;i<tam;i++){
        (lista+i)->estado=0;
    }

    printf("Empleados inicializados\n\n");
}

eEmpleado* newEmpleado(){
    eEmpleado* emp=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(emp!=NULL){
        emp->id=0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo=0;
        emp->estado=0;
    }
    return emp;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo){
    eEmpleado* emp=(eEmpleado*)malloc(sizeof(eEmpleado));
    if(emp!=NULL){
        emp->id=id;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo=sueldo;
        emp->estado=1;
    }
    return emp;
}

int buscarLibre(eEmpleado* lista, int tam){
    int indice=-1;

    if(lista!=NULL && tam>0){
        for(int i=0;i<tam;i++){
            if((lista+i)->estado==0){
                indice=i;
                break;
            }
        }
    }
    return indice;
}

void mostrarEmpleados(eEmpleado* lista, int tam){
    if(lista!=NULL && tam>0){
        printf("ID Nombre Apellido Sueldo\n");
        for(int i=0;i<tam;i++){
            if((lista+i)->estado==1){
                mostrarEmpleado(lista+i);
            }
        }
    }
}

void mostrarEmpleado(eEmpleado* emp){
    if(emp!=NULL){
        printf("%d %s %s %.2f\n",emp->id,emp->nombre,emp->apellido,emp->sueldo);
    }
}

int menu(){
    int opcion;

    system("cls");
    printf("Menu de opciones\n\n");
    printf("1_ Cargar empleado\n");
    printf("2_ Alta empleado\n");
    printf("3_ listar empleados\n");
    printf("4_ Guardar empleados archivo\n");
    printf("5_ Imprimir empleados\n");
    printf("6_ Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void altaEmpleado(eEmpleado* lista, int tam){
    int indice;
    int auxInt;
    char auxString[20];
    char auxString2[20];
    float auxFloat;

    indice=buscarLibre(lista,tam);

    if(indice==-1){
        printf("No hay lugar\n");
    }else{
        //aca deberia buscar si ya existe el id pero no lo hacemos en este ejemplo
        printf("Ingrese id: ");
        scanf("%d",&auxInt);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxString);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxString2);

        printf("Ingrese sueldo: ");
        scanf("%f",&auxFloat);

        //Recalco que lo creo adentro del else
        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt,auxString,auxString2,auxFloat);

        if(nuevoEmpleado!=NULL){
            /*
                *)lista+i) habla de la ESTRUCTURA en ese indice
                *NuevoEmpleado es la NUEVA estructura que se creo, lo use como un buffer de entrada
            */
            *(lista+indice) = *nuevoEmpleado;

            //limpio el que use de buffer
            free(nuevoEmpleado);
        }
    }
}

void imprimirEmpleados(eEmpleado* lista, int tam){
    FILE* f;

    if(lista!=NULL && tam>0){
        f=fopen("./listaEmpleados.txt","w");
        if(f!=NULL){
            fprintf(f,"ID Nombre Apellido Sueldo\n");
            for(int i=0;i<tam;i++){
                if((lista+i)->estado==1){
                    fprintf(f,"%d %s %s %.2f\n",(lista+i)->id,(lista+i)->nombre,(lista+i)->apellido,(lista+i)->sueldo);
                }
            }
        }
        fprintf(f,"\n\n");
    }
    fclose(f);
}

void guardarEmpleadosBinario(eEmpleado* lista, int tam){
    FILE* f;

    if(lista!=NULL && tam>0){
        f=fopen("./empleados.bin","wb");
        if(f!=NULL){
            for(int i=0;i<tam;i++){
                /*
                Cada vez que encuentro un empleado
                con el estado en OCUPADO (1), lo guardo
                en el archivo binario
                */
                if((lista+i)->estado==1){
                    fwrite((lista+i),sizeof(eEmpleado),1,f);
                }
            }
        }
    }
    fclose(f);
}

void cargarEmpleados(eEmpleado* lista, int tam){
    int indice;
    int cant;
    FILE* f;

    f=fopen("./empleados.bin","rb");

    /*
        Cada vez q leo un empleado, me fijo si llego al final del fichero
    */
    while(!feof(f)){
        //busco lugar libre y lo cargo ahi
        indice=buscarLibre(lista,tam);
        cant = fread((lista+indice),sizeof(eEmpleado),1,f);

        if(cant<1){//porque leo de a uno
            if(feof(f)){
                break;
            }else{
                printf("Problemas para leer el archivo\n");
            }
        }
    }

    fclose(f);
}
