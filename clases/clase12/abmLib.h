
typedef struct
{
    int id;
    char name[21];

} eSector;

typedef struct
{
    int id;
    char name[21];

} eFoodMenu;

typedef struct
{
    int id;
    int idEmp;
    int idLaunch;
    eDate date;

} eLunch;

typedef struct
{
    char name[51];
    char lastName[51];
    char sex;
    int id;
    int idSector;
    int isEmpty;
    float salary;
    eDate date;

} eEmployee;


int initEmployees(eEmployee list[], int length);
int initFoodMenu(eFoodMenu list[], int length);
int hardcodeEmployees(eEmployee list[], int length, int hc);
int hardcodeFoodMenu(eFoodMenu list[], int length, int hc);
int calcTotalActiveEmployees(eEmployee list[], int length);
void swapEmployees(eEmployee list[], int i, int j);
int sortEmployees(eEmployee list[], int length, int order);
void getSectorName(char srt[], eSector list[], int length, int id);
void printTableEmployeeHeader();
void printTableEmployee(eEmployee item, eSector sectors[], int length);
void printEmployees(eEmployee list[], int length, eSector sectors[], int lenSec);
void printTableFoodHeader();
void printTableFood(eFoodMenu item);
void printFood(eFoodMenu list[], int length);
int secInforms(eEmployee listEmp[], int lenEmp, eFoodMenu listFood[], int lenFood, eSector sectors[], int lenSec,  eLunch lunchs[], int lenLun);
