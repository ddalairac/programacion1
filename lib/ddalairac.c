#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//#include <conio.h>

/**********************************************
*
*  Libreria de funciones genericas.
*
***********************************************/

/** \brief Solicita introducir un numero al usuario
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
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
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
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
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
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

/** \brief Solicita introducir una cadena al usuario, recibe un vector y lo modifica
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
 * \param str[] char
 * \return void
 *
 */
void inputStr(char message[],char str[]){

    printf("%s: ",message);
    fflush(stdin);// Win
    //fpurge(stdn);// Linux OSx
    //gets(str);
    scanf("%s",str);
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
int calcAddition(int a, int b){
    int result = a + b;
    return result;
}
/** \brief Recibe 2 valores y los resta
 * \param a int
 * \param b int
 * \return int
 */
int calcSubtraction(int a, int b){
    int result = a - b;
    return result;
}
/** \brief Recibe 2 valores y los multiplica
 * \param a int
 * \param b int
 * \return int
 */
int calcMultiplication(int a, int b){
    int result = a * b;
    return result;
}

/** \brief Recibe 2 valores y los divide
 * \param a int
 * \param b int
 * \return int
 */
float calcDivision(int a, int b){
    float result = (float)a / b;
    return result;
}

/** \brief Calcula y retorna el factorial del numero ingresado
 *
 * \param number int
 * \return int / Resultado del cálculo
 *
 */
int calcFactorial(int number){
    int result = 1;
    int i;
    for (i=number;i>0;i--){
        result = result*i;
    }
    return result;
}

/** \brief Recibe 1 valores, e imprime en pantalla sus divisores
 * \param n int
 * \return void 1 is prime, 0 has dividers
 */
int calcPrime(int number){
    int i;
    int flag = 0;
    int isPrime = 1;
    for (i = 1; i <= number; i++){
        if(number%i == 0){
            if(flag == 0){
                flag = 1;
            } else {
                printf(",");
            }
            printf("%d", i);
            isPrime = 0;
		}
    }
    return isPrime;
}

/** \brief Recibe un numero entero para buscar en el contenido de un vector.
 * Si no encuentra retorna -1, caso positivo retorna el indice
 *
 * \param num int
 * \param vec[] int
 * \param vecSize int
 * \return int
 *
 */
int findInt(int num, int vec[], int vecSize){
    int i;
    int index = -1;
    for(i=0; i< vecSize; i++){
        if( num == vec[i])
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Ordena el vector recibido (ascendente o descendente) por tecnica de insercion:
 * Compara un indice del vector con sus predecesores, y de ser necesario mueve sus predecesores hacia adelante para insertar el indice en su posicion correcta.
 * \param vec[] int
 * \param size int
 * \param order char
 * \return void
 *
 */
void sortIntVectorByInsertion(int vec[], int size, char order){
    // Insertion technique
    int i,j,aux;
    for (i = 1; i < size; i++) {
        aux = vec[i];
        if(order == 'd'){// DESC
            for (j = i - 1; j >= 0 && vec[j] < aux; j = j - 1) {
                vec[j + 1] = vec[j];
            }
        } else {// ASC
            for (j = i - 1; j >= 0 && vec[j] > aux; j = j - 1) {
                vec[j + 1] = vec[j];
            }
        }
        vec[j + 1] = aux;
    }
}

/** \brief Ordena el vector recibido (ascendente o descendente) por tecnica de burbujeo:
 * Compara un indice del vector con sus predecesores, y de ser necesario los intercambia
 *
 * \param vec[] int
 * \param size int
 * \param order char
 * \return void
 *
 */
void sortIntVector(int vec[],int size, char order){
    // Bubbling technique
    int i,j,aux;
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if(order == 'd'){
                if(vec[i] < vec[j]){// DESC
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            } else {
                if(vec[i] > vec[j]){// ASC
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

/** \brief Recibe una cadena de caracteres y comierte la primer letra de cada palabra a mayuscula y el resto a minuscula
 *
 * \param vec[] char
 * \return void
 *
 */
void strCapitalize(char vec[]){
    int i = 0;
    strlwr(vec);
    vec[0] = toupper(vec[0]);
    while( vec[i] != '\0'){
        if( vec[i] == ' '){
            vec[i + 1] = toupper(vec[i+1]);
        }
        i++;
    }
}

/** \brief Validar que la cadena ingresada sea solo numerica
 *
 * \param cadena a validar
 * \return int 0=false  1=true
 *
 */
int validNumber(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if(str[i] < '0' || str[i] > '9'){
           validation = 0;
        }
       i++;
   }
   return validation;
}

/** \brief Validar que la cadena ingresada  contenga solo numeros y un punto como maximo. Si hay un punto, debe haber por lo menos 2 numeros.
 *
 * \param cadena a validar
 * \return int 0=false  1=true
 *
 */
int validFloat(char str[]){
    int i=0;
    int validation = 1;
    int contDot = 0;
    int contNum = 0;
    while(str[i] != '\0'){
        if(str[i] < '0' || str[i] > '9' ){
            if( str[i] != '.'){
                validation = 0;
            } else if( str[i] == '.'){
                contDot++;
            }
        } else {
            contNum++;
        }
        i++;
    }
    if(contDot > 1){
        validation = 0;
    }
    if(contDot == 1 && contNum < 2){
        validation = 0;
    }
    return validation;
}

/** \brief Validar que la cadena ingresada sea letras (' ', a-z, A-Z)
 *
 * \param str[] char
 * \return int 0=false  1=true
 *
 */
int validLetter(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')){
           validation = 0;
        }
       i++;
   }
   return validation;
}

/** \brief Validar que la cadena ingresada sea alfanumerica (' ', a-z, A-Z, 0-9)
 *
 * \param str[] char
 * \return int 0=false  1=true
 *
 */
int validAlphaNumeric(char str[]){
   int i=0;
   int validation = 1;
   while(str[i] != '\0'){
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){
           validation = 0;
       }
       i++;
   }
   return validation;
}

/** \brief Funcion de pausa con leyenda en español
 *
 * \return char
 *
 */
void pause(){
    printf("\nPresione cualquier tecla para continuar");
    getche();

    //system("pause");
}

