#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
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
    }

    if(response == TRUE){
        margen(); printf("Datos cargados con exito");
    } else {
        margen(); printf("Ups!, ocurrio un error al cargar los datos");
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

    if(response == TRUE){
        margen(); printf("Datos cargados con exito");
    } else {
        margen(); printf("Ups!, ocurrio un error al savar los datos");
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
    int auxId,auxSalary,auxWorkHours;
    char auxName[128];
    Employee* new;

    if(pArrayListEmployee != NULL){
        auxId = inputValidId("Ingrese el id: ");
        inputValidLetterString("Ingrese el nombre: ",auxName,128);
        auxSalary = inputValidInt("Ingrese el Sueldo: ",0);
        auxWorkHours = inputValidInt("Ingrese las horas trabajadas: ",0);

        new = employee_new();
        if(new != NULL){
            if( employee_setId(new,auxId) == TRUE &&
                employee_setNombre(new,auxName) == TRUE &&
                employee_setHorasTrabajadas(new,auxWorkHours) == TRUE &&
                employee_setSueldo(new,auxSalary) == TRUE ){
                    ll_add(pArrayListEmployee,new);
                    response = TRUE;
            }
        }
    }

    if(response == TRUE){
        margen(); printf("Empleado agregado con exito");
    } else {
        margen(); printf("Ups!, ocurrio un error al dar de alta");
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
    int state,id,auxId,length,i,options,auxInt;
    char auxName[128];
    Employee* emp;
    char menuOptions[][100] = {
        "Edicion",
        "Nombre",
        "Horas",
        "Sueldo"
    };
    /** Find employee */
    if(pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            margen();
            id = inputValidId("Ingrese el id: ");
            for(i=0; i < length; i++){
                emp = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(emp,&auxId);
                state = -2;
                if(id == auxId){
                    state = 1;
                    break;
                }
            }
        } else {
            state = -1;
        }
    } else {
        state = 0;
    }
    /** Edit employee */
    if(state == 1){
        printf(" \n");
        displaySubtitle("Datos del empleado");
        employee_displayEmployeeHeader();
        employee_displayEmployee(emp);

        printf(" \n");
        options = displayMenu(menuOptions,3,2);
        switch(options){
            case 1:
                margen();
                inputValidLetterString("Ingrese nuevo nombre: ",auxName,128);
                employee_setNombre(emp,auxName);
                break;
            case 2:
                margen();
                auxInt = inputValidInt("Ingrese nuevas horas trabajadas: ",0);
                employee_setHorasTrabajadas(emp,auxInt);
                break;
            case 3:
                margen();
                auxInt = inputValidInt("Ingrese nuevo sueldo: ",0);
                employee_setSueldo(emp,auxInt);
                break;
        }
        response = TRUE;
    }

    /** Print Feedback*/
    printf("\n");
    switch(state){
        case 1:
            margen(); printf("Datos editados con exito");
            break;
        case 0:
            margen(); printf("Ups!, ocurrio un error");//Null pointer
            break;
        case -1:
            margen(); printf("Ups!, la lista esta vacia. No hay datos que editar");
            break;
        case -2:
            margen(); printf("Ups!, no se encontro el ID");
            break;
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
    int length,state,id,auxId,i,option;
    Employee* emp;

    /** Find employee */
    if(pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            margen();
            id = inputValidId("Ingrese el id: ");
            for(i=0; i < length; i++){
                emp = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(emp,&auxId);
                state = -2;
                if(id == auxId){
                    state = 1;
                    break;
                }
            }
        } else {
            state = -1;
        }
    } else {
        state = 0;
    }
    /** Edit employee */
    if(state == 1){
        printf(" \n");
        displaySubtitle("Datos del empleado a remover");
        employee_displayEmployeeHeader();
        employee_displayEmployee(emp);
        printf(" \n");
        option = displayMenuConfirmacion();
        if(option == TRUE){
            ll_remove(pArrayListEmployee,i);
        } else {
            state = -3;
        }
    }
    /** Print Feedback*/
    printf("\n");
    switch(state){
        case 1:
            margen(); printf("Baja realizada con exito");
            break;
        case 0:
            margen(); printf("Ups!, ocurrio un error");//Null pointer
            break;
        case -1:
            margen(); printf("Ups!, la lista esta vacia. No es posible realizar bajas");
            break;
        case -2:
            margen(); printf("Ups!, no se encontro el ID");
            break;
        case -3:
            margen(); printf("Baja cancelada");
            break;
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
    int length;
    if(pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            employee_displayEmployees(pArrayListEmployee);
        } else {
            margen();
            printf("Ups!, la lista esta vacia. No hay empleados que listar");
        }
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
        "Salario",
        "Id"
    };
    int response = FALSE;
    int length;

    if(pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            sortOption = displayMenu(menuSort,4,2);
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
                case 4:
                    ll_sort(pArrayListEmployee,employee_sortById, ASC);
                    break;
            }
            controller_ListEmployee(pArrayListEmployee);
        } else {
            margen();
            printf("Ups!, la lista esta vacia. No hay empleados que ordenar");
        }
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
    FILE* file;
    Employee* emp;
    int length = -1;
    int id,salary,hours,i;
    char name[50];

    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            file = fopen(path,"w");
            if(file!=NULL){
                for(i=0;i<length;i++){
                    emp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(emp,&id);
                    employee_getNombre(emp,name);
                    employee_getHorasTrabajadas(emp,&hours);
                    employee_getSueldo(emp,&salary);
                    fprintf(file,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(file);
                if(i == length){
                    response = TRUE;
                }
            }
        }
    }
    if(response == TRUE){
        margen(); printf("Datos salvados con exito");
    } else {
        if(length == 0){
            margen(); printf("Ups!, la lista esta vacia. No hay datos que guardar");
        } else {
            margen(); printf("Ups!, ocurrio un error al savar los datos");
        }
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
    FILE* file;
    Employee* emp;
    int length,i;
    int response = FALSE;

    if(path != NULL && pArrayListEmployee != NULL){
        length = ll_len(pArrayListEmployee);
        if(length > 0){
            file = fopen(path,"w");
            if(file!=NULL){
                for(i=0;i<length;i++){
                    emp = ll_get(pArrayListEmployee,i);
                    if(emp != NULL){
                        fwrite(emp,sizeof(Employee),1,file);
                    }
                }
                fclose(file);
                if(i == length){
                    response = TRUE;
                }
            }
        }
    }
    if(response == TRUE){
        margen(); printf("Datos salvados con exito");
    } else {
        if(length == 0){
            margen(); printf("Ups!, la lista esta vacia. No hay datos que guardar");
        } else {
            margen(); printf("Ups!, ocurrio un error al savar los datos");
        }
    }
    return response;
}

