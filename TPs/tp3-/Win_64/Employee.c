#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#define true 1
#define false 0

Employee* employee_new(){
    Employee* this = (Employee*) malloc(sizeof(Employee));
    if(this != NULL){
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* this;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
        this = employee_new();

        if(this != NULL ){
            if(!employee_setId(this, atoi(idStr)) ||
               !employee_setNombre(this, nombreStr) ||
               !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||
               !employee_setSueldo(this, atoi(sueldoStr)) ){
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
    int response = false;
    if(this != NULL && id < 0){
        this->id = id;
        response = true;
    }
    return response;
}
int employee_getId(Employee* this,int* id){
    int response = false;
    if(this != NULL && id != NULL){
        *id = this->id;
        response = true;
    }
    return response;
}

int employee_setNombre(Employee* this,char* nombre){
    int response = false;
    if(this != NULL && nombre != NULL && strlen(nombre) > 3){

        response = true;
    }
    return response;
}
int employee_getNombre(Employee* this,char* nombre){
    int response = false;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        response = true;
    }
    return response;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int response = false;
    if(this != NULL && horasTrabajadas < -1){
        this->horasTrabajadas = horasTrabajadas;
        response = true;
    }
    return response;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int response = false;
    if(this != NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        response = true;
    }
    return response;
}

int employee_setSueldo(Employee* this,int sueldo){
    int response = false;
    if(this != NULL && sueldo < -1){
        this->sueldo = sueldo;
        response = true;
    }
    return response;
}
int employee_getSueldo(Employee* this,int* sueldo){
    int response = false;
    if(this != NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        response = true;
    }
    return response;
}

/*
void displayEmployees(Employee* emp, int len){
    int i;
    for(i=0;i<len;i++){
         displayEmployee( (Employee*) ll_get(listaEmpleados,i) );
    }
}*/
void displayEmployee(Employee* emp){
    if(emp != NULL){
        printf("%d | %10s | %10d | %10d \n", emp->id, emp->nombre, emp->sueldo, emp->horasTrabajadas);
    } else {
        printf("NULL pointer \n");
    }
}

int sortXSalary(void* emp1, void* emp2){
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL ){
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo){
            retorno = 1;
        } else if(p1->sueldo < p2->sueldo){
            retorno = 1;
        } else {
            retorno = 0;
        }
    }
    return retorno;
}
