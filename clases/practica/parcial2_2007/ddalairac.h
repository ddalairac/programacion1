#ifndef ddalairac_H_INCLUDED
#define ddalairac_H_INCLUDED
/*typedef struct{
    int day;
    int month;
    int year;
} eDate;*/

/**********************************************
*
*  Libreria de funciones genericas.
*
***********************************************/

/** \brief Funcion de pausa con leyenda en español
 *
 * \return char
 *
 */
void setPause();

/** \brief Limpia la pantalla dependiendo del OS
 *
 * \return void
 *
 */
void clear();

/** \brief Imprime espacios en pantalla
 * \return void
 */
void margen();


/** \brief Validar que la cadena ingresada sea solo numerica
 *
 * \param cadena a validar
 * \return int 0=false  1=true
 *
 */
int validNumber(char str[]);

/** \brief Validar que la cadena ingresada  contenga solo numeros y un punto como maximo. Si hay un punto, debe haber por lo menos 2 numeros.
 *
 * \param cadena a validar
 * \return int 0=false  1=true
 *
 */
int validFloat(char str[]);

/** \brief Validar que la cadena ingresada sea letras (' ', a-z, A-Z)
 *
 * \param str[] char
 * \return int 0=false  1=true
 *
 */
int validLetter(char str[]);

/** \brief Validar que la cadena ingresada sea alfanumerica (' ', a-z, A-Z, 0-9)
 *
 * \param str[] char
 * \return int 0=false  1=true
 *
 */
int validAlphaNumeric(char str[]);

/** \brief Recive 3 cadenas (dia, mes año) y las valida
 *
 * \param cdd[] char, Dia
 * \param cmm[] char, Mes
 * \param cyy[] char, Año
 * \return int, 1 fecha valida, !=1 error (0 no numerico, -1 dia invalido, -2 mes invalido, -3 año invalido)
 *
 */
int validDate(char cdd[],char cmm[],char cyy[]);

/** \brief Validar que la cadena ingresada sea un numero valido (+54 345-2345)
 *
 * \param str[] char, cadena a validar
 * \return int, 1 telefono valido, !=1 error (0 caracter incorrecto, -1 mas de 2 guiones, -2 mas de un simbolo +)
 *
 */
int validPhone(char str[]);

/** \brief Solicita introducir un numero al usuario
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
 * \return int
 *
 */
int inputInt(char message[]);

/** \brief Solicita introducir un numero al usuario
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
 * \return float
 *
 */
float inputFloat(char message[]);

/** \brief Solicita introducir una letra al usuario
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
 * \return char
 *
 */
char inputChar(char message[]);

/** \brief Solicita introducir una cadena al usuario, recibe un vector y lo modifica
 *
 * \param message[] char / mensaje que se imprime en pantalla al solicitar informacion al usuario
 * \param str[] char
 * \return void
 *
 */
void inputStr(char message[],char str[]);

/** \brief Solicita introducir un entero al usuario y lo valida
 *
 * \param message[] char, mensaje custom
 * \param max int, numero maximo a validar (0 no valida maximo)
 * \return int, numero entero validado
 *
 */
int inputValidInt(char message[], int max);

/** \brief Solicita introducir un entero al usuario y lo valida
 *
 * \param message[] char, mensaje custom
 * \return int, numero entero validado mayor a 1;
 *
 */
int inputValidId(char message[],int max);

/** \brief Solicita introducir un flotante al usuario y lo valida
 *
 * \param message[] char, mensaje custom
 * \param max int, numero maximo a validar (0 no valida maximo)
 * \return int, numero flotante validado
 *
 */
float inputValidFloat(char message[], int max);

/** \brief Solicita introducir una cadera al usuario y la valida (solo letras)
 *
 * \param message[] char, mensaje custom
 * \param name[] char, cadena donde se copiara el resultado validado
 * \param length int, index maximo de la cadena a validar
 * \return void
 *
 */
void inputValidLetterString(char message[], char str[],int length);

/** \brief Solicita introducir una cadera al usuario y la valida (solo letras y umeros)
 *
 * \param message[] char, mensaje custom
 * \param name[] char, cadena donde se copiara el resultado validado
 * \param length int, index maximo de la cadena a validar
 * \return void
 *
 */
void inputValidAlphaNumericString(char message[], char str[],int length);


/** \brief Solicita introducir una telefono al usuario y la valida
 *
 * \param message[] char
 * \param str[] char, cadena donde se copiara el te,efono validado
 * \param length int, index maximo de la cadena a validar
 * \return void
 *
 */
void inputValidPhone(char message[], char str[],int length);

/** \brief Inicializa "srand(time(NULL))" para poder utilizar rand()
 *
 * \return void
 *
 */
void initRandom();

/** \brief Generar numero aleatorio
 *
 * \param from int, desde
 * \param to int, hasta
 * \param init int: time fue inicializado
 * \return numero aleatorio
 *
 */
int getRandomNumber(int from, int to);

/** \brief Genera un caracter aleatorio
 *
 * \param init int: time fue inicializado
 * \return char
 *
 */
char getRandomChar();

/** \brief Selecciona un caracter de la cadena recibida aleatoreamente
 *
 * \param options[] char, cadena de donde se obtiene el caracter random
 * \param size int, Ultimo index de la cadena introducida
 * \return char
 *
 */
char getRandomCharCustom(char options[], int size);

/** \brief Genera una cadena aleatoria
 *
 * \param string[] char, vector donde se va a copiar la cadena generada
 * \param size int, cantidad de caracteres a generar menos 1 (el ultimo sera \0)
 * \param init int: time fue inicializado
 * \return void
 *
 */
void getRandomString(char string[], int size);

/** \brief Copia en la cadena introducida un nombre seleccionado al azar de una lista
 *
 * \param string[] char
 * \param size int, maximo de caracteres del nombre
 * \return int, 1 si encontro un nombre con esa cantidad de caracteres, 0 si no lo encontro
 *
 */
int getRandomName(char string[],int size);

/** \brief Copia en la cadena introducida un apellido seleccionado al azar de una lista
 *
 * \param string[] char
 * \param size int, maximo de caracteres del apellido
 * \return int, 1 si encontro un apellido con esa cantidad de caracteres, 0 si no lo encontro
 *
 */
int getRandomLastname(char string[],int size);

/** \brief Pausa la ejecusion por la cantidad de milisegundos ingresados
 *
 * \param ms int
 * \return void
 *
 */
void setSleep(int ms);

/** \brief Recibe 2 valores y los suma
 * \param a int
 * \param b int
 * \return int
 */
int calcAddition(int a, int b);

/** \brief Recibe 2 valores y los resta
 * \param a int
 * \param b int
 * \return int
 */
int calcSubtraction(int a, int b);

/** \brief Recibe 2 valores y los multiplica
 * \param a int
 * \param b int
 * \return int
 */
int calcMultiplication(int a, int b);

/** \brief Recibe 2 valores y los divide
 * \param a int
 * \param b int
 * \return int
 */
float calcDivision(int a, int b);

/** \brief Calcula y retorna el factorial del numero ingresado
 *
 * \param number int
 * \return int / Resultado del cálculo
 *
 */
int calcFactorial(int number);

/** \brief Recibe 1 valores, e imprime en pantalla sus divisores
 * \param n int
 * \return void 1 is prime, 0 has dividers
 */
int calcPrime(int number);

/** \brief Recibe 2 numeros (total y cantidad) y saca el promedio
 *
 * \param total int
 * \param amount int
 * \return float
 *
 */
float calcAverage(int total, int amount);

/** \brief Recibe un vector y suma el contenido de todos sus indices
 *
 * \param vec[] int
 * \param length int
 * \return int
 *
 */
int calcTotal(int vec[], int length);

/** \brief Recibe un vector y calcula cual es el valor maximo de sus indices
 *
 * \param vec[] int
 * \param length int
 * \return int
 *
 */
int calcMax(int vec[], int length);

/** \brief Recibe un vector y calcula cual es el valor minimo de sus indices
 *
 * \param vec[] int
 * \param length int
 * \return int
 *
 */
int calcMin(int vec[], int length);

/** \brief Recibe un numero entero para buscar en el contenido de un vector.
 * Si no encuentra retorna -1, caso positivo retorna el indice
 *
 * \param num int
 * \param vec[] int
 * \param vecSize int
 * \return int
 *
 */
int findInt(int num, int vec[], int vecSize);

/** \brief Ordena el vector recibido (ascendente o descendente) por tecnica de insercion:
 * Compara un indice del vector con sus predecesores, y de ser necesario mueve sus predecesores hacia adelante para insertar el indice en su posicion correcta.
 * \param vec[] int
 * \param size int
 * \param order char
 * \return void
 *
 */
void sortIntVectorByInsertion(int vec[], int size, char order);

/** \brief Ordena el vector recibido (ascendente o descendente) por tecnica de burbujeo:
 * Compara un indice del vector con sus predecesores, y de ser necesario los intercambia
 *
 * \param vec[] int
 * \param size int
 * \param order char
 * \return void
 *
 */
void sortIntVector(int vec[],int size, char order);

/** \brief Recibe una cadena de caracteres y comierte la primer letra de cada palabra a mayuscula y el resto a minuscula
 *
 * \param vec[] char
 * \return void
 *
 */
void strCapitalize(char vec[]);

/** \brief Formatea el mensaje introducido en forma de titulo
 *
 * \param message[] char
 * \return void
 *
 */
void displayTitle(char message[]);

/** \brief Formatea el mensaje introducido en forma de sub-titulo
 *
 * \param message[] char
 * \return void
 *
 */
void displaySubtitle(char message[]);

/** \brief Muestra en pantalla un menu y solicita al usuario introducir una opcion
 *
 * \param menuOptions[][100] char, el index 0 es el titulo, los demas elementos son opciones del menu
 * \param size int, cantidad de items del menu
 * \param type int, 0 menu principal, 1 menu secundario
 * \return int, retorna la opcion valida introducida por el usuario
 *
 */
int displayMenu(char menuOptions[][100], int size, int type);

/** \brief Muestra en pantalla un menu con opciones de cancelar y aceptar, y solicita al usuario seleccionar una
 *
 * \return int, rerorna opcion seleccionada
 *
 */
int displayMenuConfirmacion();

#endif // ddalairac_H_INCLUDED

