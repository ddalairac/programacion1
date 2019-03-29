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
