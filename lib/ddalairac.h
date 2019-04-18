
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

/** \brief Generar numero aleatorio
 *
 * \param desde
 * \param hasta
 * \param init: time fue inicializado
 * \return numero aleatorio
 *
 */
int getRandomNumber(int from, int to, int init);

/** \brief Genera un caracter aleatorio
 *
 * \param init: time fue inicializado
 * \return char
 *
 */
char getRandomChar( int init);

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

float calcAverage(int total, int amount);

int calcTotal(int vec[], int length);

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

/** \brief Funcion de pausa con leyenda en español
 *
 * \return char
 *
 */
void pause();
