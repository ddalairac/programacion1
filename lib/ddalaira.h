
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
