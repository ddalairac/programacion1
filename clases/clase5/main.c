#include <stdio.h>
#include <stdlib.h>

#include "../../lib/ddalaira.h"

/** Sorting
* por bubujeo:
* compara de a pares (primero al ultimo), si no cumple la condicion hace el SWAP
* por insercion
* se toma en el final, buscar en apunte
*/
int pairCounter(int arr[], int size);
void bubbleSort (int arr[], int size);
void printArr(int arr[], int size);
void eje5();
int main()
{

    int nums[] = {2,6,9,34,32,54,98,13,45,3,89};
    int pairs = pairCounter(nums,10);
    printf("Cantidad de pares = %d \n", pairs);

    printArr(nums, 10);
    bubbleSort (nums, 10);
    printArr(nums, 10);
    printf("\n\n");

    eje5();





    return 0;

}

int pairCounter(int arr[], int size){
    int pairCount = 0;
    int i;

    for(i=0; i<size;i++){
        if (arr[i] % 2 == 0){
            pairCount++;
        }
    }
    return pairCount;
}
void bubbleSort (int arr[], int size){
    int i;
    int j;
    int aux;
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(arr[i]>arr[j]){// ASC
                //printf("reordena");
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void printArr(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void eje5(){
    int tam = 5;
    int i;
    /*int legajos[tam];
    int nota1;
    int nota2[tam];
    char sexo[tam];*/
    float promedio[tam];


    int legajos[] = {321,345,765,789,543};
    int nota1[] = {2,6,5,8,9};
    int nota2[] = {5,8,3,9,7};
    char sexo[] = {'m','m','f','m','f',};



    for(i=0;i<tam;i++){
        /*legajos[i] = inputInt("introduzca legajo");
        sexo[i] = inputChar("introduzca sexo");
        nota1[i] = inputInt("introduzca nota1");
        nota2[i] = inputInt("introduzca nota2");*/
        promedio[i] = (float) (nota1[i] + nota2[i])/2;
        //printf("\n");
    }

    printf("leajo   sexo    nota1   nota2   promedio \n");
    for(i=0;i<tam;i++){
        printf("%d      %d      %d      %d      %.1f\n",legajos[i],sexo[i],nota1[i],nota2[i],promedio[i]);
    }
    printf("\n");

    //int i;
    int j;
    int aux;
    for(i=0; i<tam-1; i++){
        for(j=i+1; j<tam; j++){
            if(promedio[i]>promedio[j]){// ASC
                aux = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = aux;

                aux = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = aux;

                aux = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = aux;

                aux = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = aux;

                aux = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = aux;
            }
        }
    }


    printf("leajo   sexo    nota1   nota2   promedio \n");
    for(i=0;i<tam;i++){
        printf("%d      %d      %d      %d      %.1f\n",legajos[i],sexo[i],nota1[i],nota2[i],promedio[i]);
    }
    printf("\n");

}
