#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "ddalairac.h"

#define TRUE 1
#define FALSE 0

Employee* employee_new(){
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL){
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
        this = employee_new();
        if( this != NULL){
            if( !employee_setId(this, atoi(idStr))||
                !employee_setNombre(this, nombreStr) ||
                !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||
                !employee_setSueldo(this, atoi(sueldoStr))){
                    free(this);
                    this = NULL;
            }
        }
    }
    return this;
}
void employee_delete(){

}

int employee_setId(Employee* this,int id){
    int response = FALSE;
    if(this != NULL && id > 0){
        this->id = id;
        response = TRUE;
    }
    return response;
}
int employee_getId(Employee* this,int* id){
    int response = FALSE;
    if(this != NULL && id != NULL){
        *id = this->id;
        response = TRUE;
    }
    return response;
}

int employee_setNombre(Employee* this,char* nombre){
    int response = FALSE;
    if(this != NULL && nombre != NULL && strlen(nombre) > 3){
        strcpy(this->nombre, nombre);
        response = TRUE;
    }
    return response;
}
int employee_getNombre(Employee* this,char* nombre){
    int response = FALSE;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        response = TRUE;
    }
    return response;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int response = FALSE;
    if(this != NULL && horasTrabajadas >= 0){
        this->horasTrabajadas = horasTrabajadas;
        response = TRUE;
    }
    return response;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int response = FALSE;
    if(this != NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        response = TRUE;
    }
    return response;
}

int employee_setSueldo(Employee* this,int salary){
    int response = FALSE;
    if(this != NULL && salary > 0){
        this->sueldo = salary;
        response = TRUE;
    }
    return response;
}
int employee_getSueldo(Employee* this,int* salary){
    int response = FALSE;
    if(this != NULL && salary != NULL){
        *salary = this->sueldo;
        response = TRUE;
    }
    return response;
}

void employee_displayEmployees(LinkedList* listaEmpleados){
    int i;
    if(listaEmpleados != NULL){
         employee_displayEmployeeHeader();
        for(i = 0; i < ll_len(listaEmpleados); i++){
            employee_displayEmployee( (Employee*) ll_get(listaEmpleados,i));
        }
    }
}
void employee_displayEmployeeHeader(){
    printf("%8s | %15s | %20s | %10s \n", "id", "nombre", "horas trabajadas", "sueldo");
    margen();
    printf("------------------------------------------------------------- \n");
}
void employee_displayEmployee(Employee* emp){
    if(emp != NULL){
        printf("%8d | %15s | %20d | %10d \n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    } else {
        printf("NULL pointer \n");
    }
}

int employee_sortBySalary(void* emp1, void* emp2){
    int response = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL ){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo){
            response = 1;
        } else if(p1->sueldo < p2->sueldo){
            response = -1;
        } else {
            response = 0;
        }
    }
    return response;
}
int employee_sortByHours( void* emp1, void* emp2){
    int response = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if( p1->horasTrabajadas > p2->horasTrabajadas){
            response = 1;
        } else if( p1->horasTrabajadas < p2->horasTrabajadas){
            response = -1;
        } else{
            response = 0;
        }
    }

    return response;
}

int employee_sortById( void* emp1, void* emp2){
    int response = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if( p1->id > p2->id){
            response = 1;
        } else if( p1->id < p2->id){
            response = -1;
        } else{
            response = 0;
        }
    }

    return response;
}
int employee_sortByName( void* emp1, void* emp2){
    int response = 0;
    Employee* p1;
    Employee* p2;

    if( emp1 != NULL && emp2 != NULL){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if( strcmp(p1->nombre, p2->nombre) > 0){
            response = 1;
        } else if( strcmp(p1->nombre, p2->nombre) < 0){
            response = -1;
        } else{
            response = 0;
        }
    }

    return response;
}

int employee_isValid(Employee* emp){
    int id,hours,salary;
    int response = 0;
    char name[50];

    if(emp != NULL){
        employee_getId(emp,&id);
        employee_getHorasTrabajadas(emp,&hours);
        employee_getSueldo(emp,&salary);
        employee_getNombre(emp,name);

        if(id > 0 && hours > 0 && salary > 0 && name != NULL){
            response=1;
        }
    }
    return response;
}


Employee* employee_duplicateHours(Employee* emp){
    Employee* auxEmp;
    if(emp != NULL){
        auxEmp->horasTrabajadas = emp->horasTrabajadas * 2;
    }
    return auxEmp;
}

int employee_filterHoursMayorSemana(Employee* emp){
    int response = 0;
    if(emp != NULL){
        if(emp->horasTrabajadas > 40){
            response = 1;
        }
    }
    return response;
}

