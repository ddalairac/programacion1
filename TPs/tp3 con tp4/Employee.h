#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int salary);
int employee_getSueldo(Employee* this,int* salary);

void employee_displayEmployees(LinkedList* listaEmpleados);
void employee_displayEmployee(Employee* emp);
void employee_displayEmployeeHeader();

int employee_sortBySalary(void* emp1, void* emp2);
int employee_sortByHours( void* emp1, void* emp2);
int employee_sortById( void* emp1, void* emp2);
int employee_sortByName( void* emp1, void* emp2);
int employee_isValid(Employee* emp);

Employee* employee_duplicateHours(Employee* emp);
int employee_filterHoursMayorSemana(Employee* emp);
#endif // employee_H_INCLUDED
