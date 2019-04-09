#define NULL 0
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;


int displayMenu(){
    int option;
    system("cls");
    //printf(" ALUMNO: Diego Anibal Dalairac\n");
    printf("**********************************************\n");
    printf("**                                          **\n");
    printf("**                   ADMIN                  **\n");
    printf("**            Nomina de empleados           **\n");
    printf("**                                          **\n");
    printf("**********************************************\n\n");
    printf("** Menu de opciones: **\n");
    printf("1. ALTAS \n");
    printf("2. MODIFICAR \n");
    printf("3. BAJA \n");
    printf("4. INFORMAR \n");
    printf("5. SALIR \n");
    option = inputInt("Seleccione una opcion");
    printf("\n");
    return option;
}

int inputInt(char message[]){
    int number;
    printf("%s: ",message);
    scanf("%d", &number);
    return number;
}


//r = initEmployees(arrayEmployees, ELEMENTS);
int initEmployees(Employee* list, int len){
    for(int i=0; i<len;i++){
        list[i].isEmpty = TRUE;
    }
 return 0;
 /** \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*/
}
// r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
 return -1;
}
// int index = findEmployeeById(arrayEmployees, ELEMENTS,9);
int findEmployeeById(Employee* list, int len,int id){
 return NULL;
}
// r = removeEmployee(arrayEmployees, ELEMENTS,20);
int removeEmployee(Employee* list, int len, int id){
 return -1;
}
// r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
int sortEmployees(Employee* list, int len, int order){
 return 0;
}
// r = printEmployees(arrayEmployees, ELEMENTS);
int printEmployees(Employee* list, int length){
    printf("%10s %10s %10s %10s %10s %10s \n", "id", "name", "lastName", "salary", "sector", "isEmpty");
    for(int i=0; i<length; i++){
        printf("%10d %10s %10s %10.2f %10d %10d \n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector, list[i].isEmpty);
    }
    /** Para que retorna un int???? */
 return 0;
}













