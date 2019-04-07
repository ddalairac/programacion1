
/** \brief Solicita introducir un numero al usuario
 *
 * \return int
 *
 */
int inputInt();


/** \brief Solicita introducir un numero al usuario
 *
 * \return float
 *
 */
float inputFloat();


/** \brief Solicita introducir una letra al usuario
 *
 * \return char
 *
 */
char inputChar();


/** \brief Generar numero aleatorio
 *
 * \param desde
 * \param hasta
 * \param fue inicializado rand?
 * \return numero aleatorio
 *
 */
int getRandomNumber(int from, int to, int init);


/** \brief Recibe 2 valores y los suma
 * \param a int
 * \param b int
 * \return int
 */
int addition(int a, int b);

/** \brief Recibe 2 valores y los resta
 * \param a int
 * \param b int
 * \return int
 */
int subtraction(int a, int b);

/** \brief Recibe 2 valores y los multiplica
 * \param a int
 * \param b int
 * \return int
 */
int multiplication(int a, int b);

/** \brief Recibe 2 valores y los divide
 * \param a int
 * \param b int
 * \return int
 */
int division(int a, int b);

/** \brief Recibe 1 valores, e imprime en pantalla sus divisores
 * \param n int
 * \return void
 */
void factoring(int number);


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
