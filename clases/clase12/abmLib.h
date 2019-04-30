/*
typedef struct
{
    int dia;
    int mes;
    int anno;

} eFecha;*/
typedef struct
{
    int id;
    char name[21];

} eFoodMenu;

typedef struct
{
    int id;
    int fileEmp;
    int idLaunch;
    eDate date;

} eLunch;

typedef struct
{
    char name[51];
    char lastName[51];
    char sex;
    int file;
    int idSector;
    int isEmpty;
    float salary;
    eDate date;

} eEmployee;


int initEmployees(eEmployee list[], int length);
int initFoodMenu(eFoodMenu list[], int length);
int hardcodeEmployees(eEmployee list[], int length, int hc);
int hardcodeFoodMenu(eFoodMenu list[], int length);
int calcTotalActiveEmployees(eEmployee list[], int length);
void swapEmployees(eEmployee list[], int i, int j);
int sortEmployees(eEmployee list[], int length, int order);
void printTableHeader();
void printTableEmployee(eEmployee item);
void printEmployees(eEmployee list[], int length);
void printTableHeaderFoodMenu();
void printTableFoodItem(eFoodMenu item);
void printFoodMenu(eFoodMenu list[], int length);
int secInforms(eEmployee listEmp[], int length, eFoodMenu listFood, int lenFood);
