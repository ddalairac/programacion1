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
    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"r");
        if(pFile!=NULL){
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            response = 1;
        }else{
            response = TRUE;
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile;
    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        if(pFile!=NULL){
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            fclose(pFile);
            response = 1;
        }else{
            response = TRUE;
        }
    }
    return response;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
    int response = FALSE;

    if(pArrayListEmployee != NULL){
        response = TRUE;
    }
    return response;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
    int response = FALSE;

    if(pArrayListEmployee != NULL){
        response = TRUE;
    }
    return response;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int response = FALSE;

    if(pArrayListEmployee != NULL){
        response = TRUE;
    }
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
    int response = FALSE;

    if(pArrayListEmployee != NULL){
        employee_displayEmployees(pArrayListEmployee);
        response = TRUE;
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
    int response = FALSE;

    if(pArrayListEmployee != NULL){
        sortOption = displayMenu(menuSort,3,2);
        switch(sortOption){
            case 1:
                ll_sort(pArrayListEmployee,employee_sortByHours, ASC);
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_sortByName, ASC);
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_sortBySalary, ASC);
                break;
        }
        controller_ListEmployee(pArrayListEmployee);
        response = TRUE;
    }
    return response;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        response = TRUE;
    }
    return response;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        response = TRUE;
    }
    return response;
}

