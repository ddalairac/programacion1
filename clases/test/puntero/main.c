#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[20];
    int num;
} Persona;
void pInt(int*num);
void pIntInsidePInt(int*num);
void pChar(char *name);
void pStruct(Persona *list,int *num);
void printStruct(Persona *list,int *num);

int main(){
    int *num = 1;
    char name[20] = "Diego";
//    Persona* list = (Persona*) malloc(sizeof(Persona));
    Persona list[] = {{"Diego",1},{"Anibal",1},{"Julia",1},{"Maria",1}};


    printf("num: %d | name: %s \n",num,name);
    printStruct(list,&num);

    printf("\n\n_________________________\n\n");
    pInt(&num);
    pChar(name);
    printf("num: %d | name: %s \n",num,name);


    pStruct(list,&num);
    printStruct(list,&num);



    return 0;
}
void pInt(int*num){
    printf("num: %d \n",*num);
    *num = 3;
    pIntInsidePInt(&num);
    //*num = num;
    printf("pInt: %d \n",num);
}
void pIntInsidePInt(int*num){
    *num = 5;
    printf("pIntInsidePInt: %d \n",*num);
}
void pChar(char *name){
    strcpy(name,"Anibal");
}
void pStruct(Persona *list,int *num){
    strcpy( (list+0)->name, "Alberto");
    (list+0)->num = 2;
}
void printStruct(Persona *list,int *num){
    int i;
    printf("\n");
    printf("%10s | %2s \n","Nombre","Nu");
    printf("---------------\n");
    for(i=0;i<*num;i++){
        printf("%10s | %2d \n",(list+i)->name,(list+i)->num );
    }
}
