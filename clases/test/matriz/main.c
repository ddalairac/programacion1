#include <stdio.h>
#include <stdlib.h>
#include "../../../lib/ddalairac.h"
#define ALUM 40

//void printNotas(int *notas,int tam);
//void sortNotas(int notas[],int tam);
int main()
{
//    printf("Hello world!\n");
    int notas[40][3];
    int i;

    for(i=0; i<ALUM; i++){
        notas[i][0] = getRandomNumber(0,10);
        notas[i][1] = getRandomNumber(0,10);
        notas[i][2] = getRandomNumber(0,10);
    }
//    printNotas(notas, ALUM);

    printf("Notas: \n");
    for(i=0; i<ALUM; i++){
        printf("%3d | %3d | %3d \n",notas[i][0],notas[i][1],notas[i][2]);
    }
    setPause();

//    sortNotas(notas, ALUM);
//    printNotas(notas, ALUM);
    int j,aux;
    for(i=0;i<ALUM-1;i++){
        for(j=i+1;j<ALUM;j++){
            if(notas[i][2] < notas[j][2] ){
                /** Swap */
                aux = notas[i][0];
                notas[i][0] = notas[j][0];
                notas[j][0] = aux;

                aux = notas[i][1];
                notas[i][1] = notas[j][1];
                notas[j][1] = aux;

                aux = notas[i][2];
                notas[i][2] = notas[j][2];
                notas[j][2] = aux;
            }
        }
    }
    printf("Notas: \n");
    for(i=0; i<ALUM; i++){
        printf("%3d | %3d | %3d \n",notas[i][0],notas[i][1],notas[i][2]);
    }
    setPause();


    return 0;
}
//
//void printNotas(int *notas,int tam){
//    int i;
//    printf("Notas: \n");
//    for(i=0; i<tam; i++){
//        printf("%3d | %3d | %3d \n",notas[i][0],notas[i][1],notas[i][2]);
//    }
//}
//void sortNotas(int notas[],int tam){
//    int i,j,aux;
//    for(i=o;i<tam-1;i++){
//        for(j=i+1;j<tam;j++){
//            if(notas[i][2] < notas[j][2] ){
//                /** Swap */
//                aux = notas[i][0];
//                notas[i][0] = notas[j][0];
//                notas[j][0] = aux;
//
//                aux = notas[i][1];
//                notas[i][1] = notas[j][1];
//                notas[j][1] = aux;
//
//                aux = notas[i][2];
//                notas[i][2] = notas[j][2];
//                notas[j][2] = aux;
//            }
//        }
//    }
//}
