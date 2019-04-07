int inputInt(char message[]){
    int number;
    printf("%s: ",message);
    scanf("%d", &number);
    return number;
}

int addition(int a, int b){
    int result = a + b;
    return result;
}

int subtraction(int a, int b){
    int result = a - b;
    return result;
}

int multiplication(int a, int b){
    int result = a * b;
    return result;
}

float division(int a, int b){
    float result = (float) a / b;
    return result;
}

int factorial(int number){
    int result = 1;
    int i;
    for (i=number;i>0;i--){
        result = result*i;
    }
    return result;
}


void displayOperand(int n,int flag, char undefineValue){
    if(flag){
        printf("%d",n);
    } else {
        printf("%c",undefineValue);
    }
}

void menu(int a,int b,int fA,int fB, int fCalc, float results[],int selection){

    system("cls");

    printf(" ALUMNO: Diego Anibal Dalairac\n");
    printf("**********************************************\n");
    printf("**          _______   __                    **\n");
    printf("**             |     |   \\   /||            **\n");
    printf("**             |     |___|    ||            **\n");
    printf("**             |     |        ||            **\n");
    printf("**             |     |       _||_           **\n");
    printf("**                                          **\n");
    printf("**********************************************\n\n");
    printf("** Menu de opciones: **\n");
    printf("1. Ingresar 1er operando (A="); displayOperand(a,fA,'x'); printf(") \n");
    printf("2. Ingresar 2do operando (B="); displayOperand(b,fB,'y'); printf(") \n");
    printf("3. Calcular todas las operaciones" );
    if(fCalc){
        printf(" (valores calculados)" );
    }
    printf("\n" );
    printf("\t a) Calcular la suma (");            displayOperand(a,fA,'A'); printf("+" );   displayOperand(b,fB,'B'); printf(") \n" );
    printf("\t b) Calcular la resta (");           displayOperand(a,fA,'A'); printf("-" );   displayOperand(b,fB,'B'); printf(") \n" );
    printf("\t c) Calcular la division (");        displayOperand(a,fA,'A'); printf("/" );   displayOperand(b,fB,'B'); printf(") \n");
    printf("\t d) Calcular la multiplicacion (");  displayOperand(a,fA,'A') ;printf("*" );   displayOperand(b,fB,'B'); printf(") \n");
    printf("\t e) Calcular el factorial de ");     displayOperand(a,fA,'A'); printf("! y "); displayOperand(b,fB,'B'); printf("! \n");
    printf("4. Informar resultados \n");
    if(selection >= 4 && fCalc){
        printf("\t a) El resultado de %d+%d es: %.f \n", a,b,results[0]);
        printf("\t b) El resultado de %d-%d es: %.f \n", a,b,results[1]);
        printf("\t c) El resultado de %d/%d es: ", a,b);
        if(a == 0 || b == 0){
            printf("No es posible dividir por cero \n");
        } else {
            printf("%.2f \n", results[2]);
        }
        printf("\t d) El resultado de %d*%d es: %.f \n", a,b,results[3]);
        printf("\t e) El factorial de %d es: %.f y El factorial de %d es: %.f \n", a, results[4], b, results[5] );
    } else {
        printf("\t a) El resultado de "); displayOperand(a,fA,'A'); printf("+" ); displayOperand(b,fB,'B');printf(" es: r \n");
        printf("\t b) El resultado de "); displayOperand(a,fA,'A'); printf("-" ); displayOperand(b,fB,'B');printf(" es: r \n");
        printf("\t c) El resultado de "); displayOperand(a,fA,'A'); printf("/" ); displayOperand(b,fB,'B');printf(" es: r \n");
        printf("\t d) El resultado de "); displayOperand(a,fA,'A'); printf("*" ); displayOperand(b,fB,'B');printf(" es: r \n");
        printf("\t e) El factorial de "); displayOperand(a,fA,'A'); printf(" es: r1 y El factorial de " ); displayOperand(b,fB,'B');printf(" es: r2 \n");
    }

    printf("5. Salir \n" );
    printf(" \n");

}

