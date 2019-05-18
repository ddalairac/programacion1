

// pasa variables x,y,z por VALOR

/** \brief recibe 3 valores y devuelve el mayor
 *
 * \param x int
 * \param y int
 * \param z int
 * \return int mayor
 *
 */
int obtenerMaximo(int x, int y, int z){
    int maximo;

    maximo = x;
    if( y > maximo){
        maximo = y;
    }
    if( z > maximo){
        maximo = z;
    }
    return maximo;
}

// pasa variables x,y,z por VALOR, y maximo por REFERENCIA
/** \brief recibe 3 valores + un puntero y modifica el puntero con el mayor valor
 *
 * \param x int
 * \param y int
 * \param z int
 * \param maximo int*
 * \return void
 *
 */
void obtenerMaximoPuntero(int x, int y, int z, int* maximo){
    *maximo = x;
    if( y > *maximo){
        *maximo = y;
    }
    if( z > *maximo){
        *maximo = z;
    }
}





void menu(){

    int opcion;
    char seguir = 's';

    //////
    do{
        mostrarMenu(&opcion);
        switch (opcion){
            case 1:
            printf("opcion Alta \n");
            break;

            case 2:
            printf("opcion Baja \n");
            break;

            case 3:
            printf("opcion Modificacion \n");
            break;

            case 4:
            printf("opcion Informes \n");
            break;

            case 5:
            printf("opcion Salir \n");
            seguir = 'n';
            break;

            case 6:
            printf("opcion Ingrese opcion \n");
            break;

            default:
            printf("opcion invalida \n");
            break;

        }
        system("pause");

    } while(seguir == 's');
}


/** \brief Lista las opciones del menu y retorna la elegida
 *
 * \return int
 *
 */
void mostrarMenu(int* opcion){
    system("cls"); // limpia la pantalla
    int op;
    printf("1 - Alta \n");
    printf("2 - Baja \n");
    printf("3 - Modificacion \n");
    printf("4 - Informes \n");
    printf("5 - Salir \n");
    printf(" \n");
    printf("Ingrese opcion: ");
    scanf("%d", &op);
    *opcion = op;
    //return *opcion;
}

