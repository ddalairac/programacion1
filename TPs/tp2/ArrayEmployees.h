typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;


/**********************************************
*
*  Funciones custom del TP
*
***********************************************/


/**********************************************
*
*  Funciones que el TP debe tener.
*
***********************************************/

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param length int cantidad de items de la lista
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int length);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param length int cantidad de items de la lista
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int length, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int length,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int length, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int length, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int
 *
 */
int printEmployees(Employee* list, int length);


/**********************************************
*
*  Funciones custom del TP
*
***********************************************/

/** \brief imprime en pantalla el head de la tabla de empleados
 *
 * \return void
 *
 */
void printTableHeader();

/** \brief imprime en pantalla un empleado en la tabla de empleados
 *
 * \param item Employee
 * \return void
 *
 */
void printTableEmployee(Employee item);

/** \brief hace un swap de los empleados
 *
 * \param list[] Employee
 * \param i int
 * \param j int
 * \return void
 *
 */
void swapEmployees(Employee list[], int i, int j);

/** \brief busca un index en el vector de empleados que no este activo
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0 o NULL pointer] - (0 o mayor) Ok
 *
 */
int getEmptySlot(Employee list[], int length);

/** \brief genera un numero mayor al ultimo id creado
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (0) Error [length < 0 o NULL pointer] - (1 o mayor) Ok
 *
 */
int getnewID(Employee list[], int length);

/** \brief Calcula el total de empleados activos
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0 o NULL pointer] - (0 o mayor) Ok
 *
 */
int getActiveEmployees(Employee list[], int length);


/** \brief Calcula el total de empleados activos
 *
 * \param list[] Employee
 * \param length int
 * \return int
 *
 */
int calcTotalActiveEmployees(Employee list[], int length);

/** \brief Calcula el total de todoslos salarios
 *
 * \param list[] Employee
 * \param length int
 * \return int
 *
 */
int calcSalaryTotal(Employee list[], int length);

/** \brief Calcula el promedio entre el total y la cantidad ingresados
 *
 * \param total int
 * \param amount int
 * \return float
 *
 */
float calcSalaryAverage(int total, int amount);

/** \brief Calcula cuantos empleados ganan por arriba del salario promedio
 *
 * \param list[] Employee
 * \param length int
 * \param average float
 * \return int
 *
 */
int calcEmplyeesAboveAverage(Employee list[], int length, float average);

/** \brief Calcula e informa el total de salarios, el promedio y la cantidad de empleados que supera el promedio
 *
 * \param list[] Employee
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0 o NULL pointer] - (0) Ok
 *
 */
int inform2Data(Employee list[], int length);

/** \brief Contiene el flujo de creacion de un nuevo empleado
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0, NULL pointer, o falla en el proceso] - (0) Ok
 *
 */
int secNewEmployee(Employee list[], int length);

/** \brief Contiene el flujo de edicion de un empleado
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0, NULL pointer, o falla en el proceso] - (0) Ok
 *
 */
int secFindAndEditEmployee(Employee list[], int length);

/** \brief Contiene el flujo para remover un empleado
 *
 * \param list Employee*
 * \param length int cantidad de items de la lista
 * \return int Return (-1) Error [length < 0, NULL pointer, o falla en el proceso] - (0) Ok
 *
 */
int secFindAndRemoveEmployee(Employee list[], int length);

/** \brief Contiene el flujo de informes
 *
 * \param list[] Employee
 * \param length int
 * \return int
 *
 */
int secInforms(Employee list[], int length);

/** \brief llena la lista de empleados con datos aleatorios de ejemplo
 *
 * \param list[] Employee
 * \param length int cantidad de items de la lista
 * \param hc int cantidad de empleados a crear
 * \return int Return (-1) Error [length < 0 o NULL pointer] - (0) Ok
 *
 */
int hardcodeEmployees(Employee list[], int length, int hc);


