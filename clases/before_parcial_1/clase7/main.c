#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/ddalaira.h"
#define VACIO 0
#define OCUPADO 1
#define T 3

//creo un nuevo tipo de estructura
typedef struct{
    // defino los campos
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;
}Eempleado; //primera letra duplicada y en mayuscula, convencion de estructura

int inputValidLegajo(char message[]);
int validNumber(char str[]);
void printNomina(Eempleado estructura[], int size);
void initEstructura(Eempleado estructura[], int size);

int main(){
    //uso el tipo que cree para crear una estructura de ese tipo
    //Eempleado emp1;
    /*
    printf("Ingrese el legajo: ");
    scanf("%d",&emp1.legajo);
    printf("\n %d ",emp1.legajo);*/

    //emp1.legajo = inputValidLegajo("Ingrese el legajo: ");
    //printf("%d \n\n",emp1.legajo);


    Eempleado nomina[T] = {
        { 1234, "Carlos", 'm', 55000 },
        { 6734, "Laura", 'f', 45000},
        { 7987, "Romina", 'f', 35000}
    };
    for(int i=0; i<T;i++){
        nomina[i].estado = 0;
        printf("estado %d \n",nomina[i].estado);
    }
    initEstructura(nomina, T);
    printNomina(nomina,T);

    return 0;
}
/*
legajo = 4 cigfras
nombre = 19 char max
sexo = m o f
sueldo = num positivo

menu: dar alta, baje, editar sueldo

*/

int inputValidLegajo(char message[]){
    int value;
    char input[100] ;
    int length;
    int valid = 1;

    do{
    inputStr(message,input);
    /*printf("%s: ",message);
    scanf ("%s", input);*/
    length = strlen (input);
    if(length == 4){
        //printf("Es un legajo de 4 caracteres \n");

        if(validNumber(input)){
            //printf("Es numero \n");
            value = atoi(input);
            valid = 0;

        } else {
            printf("Error, debe introducir numeros \n\n");
        }

    } else {
        printf("Error, Tiene que tener 4 caracteres \n\n");
    }

    }while(valid);
    return value;

}

void initEstructura(Eempleado estructura[], int size){
    for(int i=0; i<size;i++){
        estructura[i].estado = VACIO;
    }
}

void printNomina(Eempleado estructura[], int size){
    printf("%10s %19s %10s %10s %10s \n", "legajo", "nombre", "sexo", "sueldo", "estado");
    for(int i=0; i<size; i++){
        printf("%10d %19s %10c %10.2f \n", estructura[i].legajo, estructura[i].nombre, estructura[i].sexo, estructura[i].sueldo, estructura[i].estado);
    }
}
/** fgets(emp1.nombre, 19, stdin); */

/** \brief introducir caracteres sin que desborde
 *
 * \param variable que va a almacenar la info
 * \param 19 es el maximo que toma, si ingresa mas caracteres losignora
 * \param  stdin es la entrada del teclado
 * \return
 *
 */

 /**
 atoi(xxx) recive un char y retorna un int  (ascii to integer)
 sprontf(char, "%d", int) conbierte un int en un char

 */
