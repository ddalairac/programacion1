

int displayMenu(){
    int option;
    system("cls");
    //printf(" ALUMNO: Diego Anibal Dalairac\n");
    printf("**********************************************\n");
    printf("**                                          **\n");
    printf("**                   ADMIN                  **\n");
    printf("**            Nomina de empleados           **\n");
    printf("**                                          **\n");
    printf("**********************************************\n\n");
    printf("** Menu de opciones: **\n");
    printf("1. ALTAS \n");
    printf("2. MODIFICAR \n");
    printf("3. BAJA \n");
    printf("4. INFORMAR \n");
    option = inputInt("Seleccione una opcion");
    printf("\n");
    return option;
}


int inputInt(char message[]){
    int number;
    printf("%s: ",message);
    scanf("%d", &number);
    return number;
}
