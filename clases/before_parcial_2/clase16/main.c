#include <stdio.h>
#include <stdlib.h>
/**

    la memoria estatica de una maquina es una parte chica de la memoria.
    EJ: int x
    Para acceder a porciones grandes de la memoria deben ser memoria dinamica
    EJ: int *x

    El spd (Serial Presence Detect) limita la cantidad de numeros que puedo mostrar por eso una maquina con sistema 32bits solo puede tener 3 gigas de ram
    no alcanza para mapear nombres mas largos.
*/
void fVecToVec(int x[], int len);
void fPointertoPonter(int *x, int len);
typedef struct {
    int id;
    char nombre[15];
} eEmployee;

int main(){
    int x;
    int *p; // puntero a X
    int **q; // punter

    x = 5;
    p = &x;
    q = &p;

    printf("\n");
    printf("  %15s | %10x | %s \n","valor x:",      x,  "valor de x");
    printf("  %15s | %10x | %s \n","valor p:",      p,  "Valor de p, direccion de memoria de x");
    printf("  %15s | %10x | %s \n","puntero *p:",   *p, "Puntero p, = a valor de x");
    printf("  %15s | %10x | %s \n","valor q:",      q,  "Valor de q, direccion de memoria de p");
    printf("  %15s | %10x | %s \n","puntero *q:",   *q, "puntero de *q, direccion de memoria de x");
    printf("  %15s | %10x | %s \n","puntero **q:",  **q,"puntero de *(*q), = a valor de x");


    printf("\n");
    printf("  %15s | %10p | %s \n","valor x:",      x,  "valor de x");
    printf("  %15s | %10p | %s \n","valor p:",      p,  "Valor de p, direccion de memoria de x");
    printf("  %15s | %10p | %s \n","puntero *p:",   *p, "Puntero p, = a valor de x");
    printf("  %15s | %10p | %s \n","valor q:",      q,  "Valor de q, direccion de memoria de p");
    printf("  %15s | %10p | %s \n","puntero *q:",   *q, "puntero de *q, direccion de memoria de x");
    printf("  %15s | %10p | %s \n","puntero **q:",  **q,"puntero de *(*q), = a valor de x");


    int *y;
    /** 3 formas de definir el valor de un puntero*/
    y = &x;
    y = p;
    y = 0x22ff14;

    printf("\n____________________________________________________________________________\n\n");
    printf("  3 formas de definir el valor de un puntero \n");
    printf("  y = &x; \n");
    printf("  y = p; \n");
    printf("  y = 0x22ff14; \n");

    printf("\n");
    printf("  y: %x \n",y);
    printf("  *y: %x \n",*y);

    printf("\n____________________________________________________________________________\n\n");
    int vec[5] = {1,3,5,7,9};
    printf("  int vec[5] = {1,3,5,7,9}; \n\n", vec);
    printf("  vec: %x \n", vec);
    printf("  &vec[0]: %x \n", &vec[0]);
    printf("  *vec: %x \n", *vec);
    printf("  *vec+1: %x (al valor 1 le suma 1) \n", *vec+1);
    printf("  *(vec+1): %x (segundo elemento del vector) \n", *(vec+1));


    printf("\n____________________________________________________________________________\n\n");

    int a[] = {0,1,2,3,4};

    fVecToVec(a,5);
    fPointertoPonter(a,5);

    printf("\n____________________________________________________________________________\n\n");

    char cadena[] = "cadena de caracteres";
    char *c;

    /**
    c = &cadena[0];  IDEM  */
    c = cadena;

    printf("c++ lleva a la sigueinte posicion de memoria, no hace falta usar incrementador \n\n");
    while(*c != '\0'){
        printf("%c ", *c);
        c++; /** va a la posicion siguiente de memoria */
    }


    printf("\n____________________________________________________________________________\n\n");

    eEmployee emp1 = { 1234, "diego"};
    eEmployee *pEmp;
    pEmp = &emp1;

    printf("emp1 = .id: %d .nombre %s \n",emp1.id,emp1.nombre);
    printf("pEmp = ->id: %d ->nombre %s \n\n",pEmp->id, pEmp->nombre);

    printf("ingrese un numero: ");
    scanf("%d",&pEmp->id);

    printf("ingrese un nombre: ");
    scanf("%s",&pEmp->nombre);

    printf("pEmp = ->id: %d ->nombre %s \n\n",pEmp->id, pEmp->nombre);

    eEmployee emps[] = {
        { 1234, "diego"},
        { 5678, "Jorge"},
        { 9101, "Norberto"},
    };
    mostrarEmpleado(emps,3);


    printf("\n\n");
    return 0;
}

void fVecToVec(int x[], int len){
    int i;
    for(i=0; i<len;i++){
        printf("  x[%d]: %d  \n", i, x[i] );
    }
    printf("\n");
}
void fPointertoPonter(int *x, int len){
    int i;
    for(i=0; i<len;i++){
        printf("  *(x+%d): %d  \n", i, *(x+i) );
    }
    printf("\n");
}

void mostrarEmpleado(eEmployee *emps, int len){
    int i;
    for(i=0; i<len;i++){
        printf("  emp%d: %d - %s \n",i, (emps+i)->id, (emps+i)->nombre );
    }

    /*for(i=0; i<len;i++){
        printf("  emp: %d - %s \n", emps->id, emps->nombre );
        emps++;
    }*/
}
