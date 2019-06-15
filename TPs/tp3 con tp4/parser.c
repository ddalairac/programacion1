#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#define TRUE 1
#define FALSE 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
    char buffer[4][30];
    int cant,response = FALSE;
    Employee* emp;
    if(pFile != NULL && pArrayListEmployee != NULL){
        while(!feof(pFile)){
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            emp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(emp != NULL && employee_isValid(emp)){
                ll_add(pArrayListEmployee,emp );
                response = TRUE;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }else{
                    response = FALSE;
                    break;
                }
            }
        }
    }

    return response;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
    int response = FALSE;
    int cant = 0;
    Employee* new;
    if(pFile != NULL && pArrayListEmployee != NULL){
        while(!feof(pFile)){
            new = employee_new();
            cant = fread(new,sizeof(Employee),1,pFile);
            if(new != NULL){
                if(employee_isValid(new) == 1){
                    ll_add(pArrayListEmployee,new);
                    response = TRUE;
                }else{
                    employee_delete(new);
                }
            }
            if(cant < 1){
                if(feof(pFile)){
                break;
                }else{
                    response = FALSE;
                    break;
                }
            }
        }
    }

    return response;
}
