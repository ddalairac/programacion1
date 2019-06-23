#include <stdio.h>
#include <stdlib.h>
#define U 3

typedef struct{
    char name[20];
    int id;
    int serial;
}User;

int main(){
    User userList[U];
    char buffer[3][50];
    int cant,i=0,total = 0;

    FILE* pFile;
    pFile = fopen("data.txt","r");
    if(pFile != NULL && userList!= NULL){
        while(!feof(pFile)){
            cant = fscanf(pFile," %[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2]);
            printf("name %s \n",buffer[0] );
//            cant = fread(&user,sizeof(User),1,pFile);

            strcpy(userList[i].name, buffer[0]);
            userList[i].id = atoi(buffer[1]);
            userList[i].serial = atoi(buffer[2]);
            i++;
            total++;

            if(cant < 3){
                printf("fread error \n");
                break;
//                if(feof(pFile)){
//                    break;
//                }else{
//                    break;
//                }
            }
        }
    }
    fclose(pFile);

    printf("Total %d\n",total);
    for(i=0;i<U && i<total;i++){
        printf("%10s | %2d | %5d \n",userList[i].name,userList[i].id,userList[i].serial);
    }
    return 0;
}
