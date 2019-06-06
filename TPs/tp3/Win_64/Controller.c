#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "ddalairac.h"

#define TRUE 1
#define FALSE 0
#define ASC 1
#define DESC 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (0 error, 1 exito)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){

    FILE* pFile;
    int response = 0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"r");
        if(pFile!=NULL){
            //parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            response = 1;
        }else{
            response = 0;
        }
    }
    return response;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief imprimir un empleado
 *
 * \param emp Employee*
 * \return int
 *
 */
int controller_printEmployee(Employee* emp){
    int response = 0;
    if(emp != NULL){
        printf("%6d | %15s | %20d | %10d \n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
        response = 1;
    } /* else {
        printf("NULL pointer \n");
    }*/
    return response;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int i,response = 0;
    if(pArrayListEmployee != NULL){
        printf("%6s | %15s | %20s | %10s \n", "id", "nombre", "horas trabajadas", "sueldo");
        printf("-------------------------------------------------------------- \n");
        for(i = 0; i < ll_len(pArrayListEmployee); i++){
            controller_printEmployee( (Employee*) ll_get(pArrayListEmployee,i));
        }
        response = 1;
    }
    return response;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int sortOption = 0;
    char menuSort[][100] = {
        "Por",
        "Horas",
        "Nombre",
        "Salario"
    };

    sortOption = displayMenu(menuSort,3,2);
    switch(sortOption){
        case 1:
            ll_sort(pArrayListEmployee,sortByHours, ASC);
            break;
        case 2:
            ll_sort(pArrayListEmployee,sortByName, ASC);
            break;
        case 3:
            ll_sort(pArrayListEmployee,sortBySalary, ASC);
            break;
    }
    controller_ListEmployee(pArrayListEmployee);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

