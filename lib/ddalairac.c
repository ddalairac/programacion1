#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/** \brief Solicita introducir un numero al usuario
 *
 * \return int
 *
 */
int inputInt(char message[]){
    int number;
    //printf("Ingrese un int \n");
    printf("%s: ",message);
    scanf("%d", &number);
    return number;
}

/** \brief Solicita introducir un numero al usuario
 *
 * \return float
 *
 */
float inputFloat(char message[]){
    float number;
    //printf("Ingrese un float \n");
    printf("%s: ",message);
    fflush(stdin);// Win
    scanf("%f", &number);
    return number;
}

/** \brief Solicita introducir una letra al usuario
 *
 * \return char
 *
 */
char inputChar(char message[]){
    char character;
    //printf("Ingrese una letra \n");
    printf("%s: ",message);
    fflush(stdin);// Win
    //fpurge(stdn);// Linux OSx
    scanf("%c", &character);
    return character;
}

/** \brief Generar numero aleatorio
 *
 * \param desde
 * \param hasta
 * \param fue inicializado rand?
 * \return numero aleatorio
 *
 */
int getRandomNumber(int from, int to, int init){
    if (!init){
        srand(time(NULL));
    }
    return from + (rand() % (to + 1 - from) );
}


/** \brief Recibe 2 valores y los suma
 * \param a int
 * \param b int
 * \return int
 */
int addition(int a, int b){
    int result = a + b;
    return result;
}

/** \brief Recibe 2 valores y los resta
 * \param a int
 * \param b int
 * \return int
 */
int subtraction(int a, int b){
    int result = a - b;
    return result;
}

/** \brief Recibe 2 valores y los multiplica
 * \param a int
 * \param b int
 * \return int
 */
int multiplication(int a, int b){
    int result = a * b;
    return result;
}

/** \brief Recibe 2 valores y los divide
 * \param a int
 * \param b int
 * \return int
 */
int division(int a, int b){
    int result = a / b;
    return result;
}

/** \brief Recibe 1 valores, e imprime en pantalla sus divisores
 * \param n int
 * \return void
 */
void factoring(int number){
    int flag = 0;
    for (int i = 1; i <= number; i++){
        if(number%i == 0){
            if(flag == 0){
                flag = 1;
            } else {
                printf(",");
            }
            printf("%d", i);
		}
    }
}
