

/** \brief Recibe un mensaje y retorna un número.
 *
 * \param message[] char
 * \return int / Entero introducido por el usuario
 *
 */
int inputInt(char message[]);

/** \brief Calcula y retorna la suma de los numeros ingresados
 *
 * \param a int
 * \param b int
 * \return int / Resultado del cálculo
 *
 */
int addition(int a, int b);

/** \brief Calcula y retorna la resta de los numeros ingresados
 *
 * \param a int
 * \param b int
 * \return int / Resultado del cálculo
 *
 */
int subtraction(int a, int b);

/** \brief Calcula y retorna la multiplicacion de los numeros ingresados
 *
 * \param a int
 * \param b int
 * \return int / Resultado del cálculo
 *
 */
int multiplication(int a, int b);

/** \brief Calcula y retorna la division de los numeros ingresados
 *
 * \param a int
 * \param b int
 * \return float / Resultado del cálculo
 *
 */
float division(int a, int b);

/** \brief Calcula y retorna el factorial del numero ingresado
 *
 * \param number int
 * \return int / Resultado del cálculo
 *
 */
int factorial(int number);

/** \brief Imprime en pantalla el valor del operando (A o B) en caso de tener valor
 *         Caso contrario (si el flag indica que no tiene valor) muestra un caracter
 *
 * \param n int     / Valor a mostrar
 * \param flag int  / Flag que indica si el usuario introdujo un valor
 * \param undefineValue char / Caracter a mostrar en caso de que 'n' no tenga valor
 * \return void
 *
 */
void displayOperand(int n,int flag, char undefineValue);

/** \brief Imprime en pantalla el menu de opciones de la aplicación TP1
 *
 * \param a int     / Valor de A ingresado por el usuario en opcion 1
 * \param b int     / Valor de B ingresado por el usuario en opcion 2
 * \param fA int    / Flag indicando que el usuario introdujo el de A
 * \param fB int    / Flag indicando que el usuario introdujo el de B
 * \param fCalc int / Flag indicando que las operaciones fueron calculadas
 * \param results[] / float Vector con todos los valores de las operaciones
 * \param selection / int Opcion ingresada por el usuario
 * \return void     / No devuelve nada, el menu es solo informativo
 *
 */
void menu(int a,int b,int fA,int fB, int fCalc, float results[],int selection);
