#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 10;
    printf("Hello world!\n\n");
    system("pause");
    sarasa();
    system("pause");
    return 0;
}
void sarasa(){
    printf("\nTamano de char : %d \n", sizeof(char));
    printf("\nTamano de int : %d \n", sizeof(int));
    printf("\nTamano de float : %d \n", sizeof(float));
    printf("\nTamano de double : %d \n", sizeof(double));
}
