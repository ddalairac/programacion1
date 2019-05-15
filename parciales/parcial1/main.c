#include <stdio.h>
#include <stdlib.h>

#include "ddalairac.h"
#include "lib-brand.h"
#include "lib-car.h"
#include "lib-color.h"
#include "lib-service.h"
#include "lib-work.h"
#include "inform.h"

#define TRUE 1
#define FALSE 0
#define DESC 0
#define ASC 1
/*
# define C 100
# define W 100
# define B 5
# define H 5
# define S 4*/

# define C 22
# define W 37
# define B 5
# define H 5
# define S 4

int main(){
    int result,option,optionInf;
    int loop = TRUE;

    eBrand brands[B] = {
        { 1000, "Renault",   FALSE },
        { 1001, "Fiat",      FALSE },
        { 1002, "Ford",      FALSE },
        { 1003, "Chevrolet", FALSE },
        { 1004, "Peugeot",   FALSE }
    };
    eColor colors[H] = {
        { 5000, "Negro",  FALSE },
        { 5001, "Blanco", FALSE },
        { 5002, "Gris",   FALSE },
        { 5003, "Rojo",   FALSE },
        { 5004, "Azul",   FALSE }
    };
    eService services[S] = {
        { 20000, "Lavado",   250, FALSE },
        { 20001, "Pulido",   300, FALSE },
        { 20002, "Encerado", 400, FALSE },
        { 20003, "Completo", 600, FALSE }
    };
    initRandom();

    eCar cars[C];
    initCars(cars,C);
    harcodeCars(cars,C,20);

    eWork works[W];
    initWorks(works, W);
    harcodeWorks(works,W,cars,C,services,S,20);

    char mainMenu[][100] = {
        "ADMIN: Lavadero",
        "ALTAS AUTO",
        "BAJA AUTO",
        "MODIFICAR AUTO",
        "LISTA AUTOS ",
        "LISTA MARCAS ",
        "LISTA COLORES ",
        "LISTA SERVICIOS ",
        "ALTAS TRABAJOS ",
        "LISTA TRABAJOS ",
        "INFORMES",
        "SALIR ",
    };
    char informMenu[][100] = {
        "10. INFORMES",
        "MOSTRAR AUTOS COLOR SELECCIONADO",
        "MOSTRAR AUTOS MARCA SELECCIONADO",
        "MOSTRAR TRABAJOS DE AUTO SELECCIONADO",
        "MOSTRAR AUTOS SIN TRABAJOS",
        "INFORMAR IMPORTTE TOTAL A TRABAJOS DE UN AUTO",
        "MOSTRAR EL SERVICIO MAS PEDIDO",
        /*"MOSTRAR LA RECAUDACION EN UNA FECHA",
        "MOSTRAR AUTOS CON SERVICIO ENCERADO EN UNA FECHA",
        "MOSTRAR TRABAJOS REALIZADOS A AUTOS BLANCOS",
        "MOSTRAR TOTAL POR PULIDOS",
        "MOSTRAR MARCAS DE AUTOS CON MAS LAVADOS COMPLETOS",
        "MOSTRAR AUTOS CON TRABAJOS EN FECHA DETERMINADA",*/
        "SALIR ",
    };

    do{
        option = displayMenu(mainMenu,11,0);
        switch(option){
            case 1: // ALTAS
                displayTitle("1. ALTA AUTO");
                result = newCar(cars,C,brands,B,colors,H);
                if(result == -1){
                    margen(); printf("No se efectuo el alta. \n");
                } else {
                    margen(); printf("Alta realizada con exito. \n");
                }
                setPause();
                break;

            case 2: // BAJA
                displayTitle("2. BAJA AUTO");
                result = removeCar(cars,C,brands,B,colors,H);
                if(result == -1){
                    margen(); printf("No se efectuo la baja. \n");
                } else {
                    margen(); printf("Baja realizada con exito \n");
                }
                setPause();
                break;

            case 3: // MODIFICAR
                displayTitle("3. MODIFICAR AUTO");
                result = editCar(cars,C,brands,B,colors,H);
                if(result == -1){
                    margen(); printf("No se efectuo la edicion. \n");
                } else {
                    margen(); printf("Edicion realizada con exito \n");
                }
                setPause();
                break;

            case 4: // LISTA AUTOS
                displayTitle("4. LISTAR AUTOS");
                sortCars(cars, C,DESC);
                printCars(cars, C, brands, 5, colors, 5);
                setPause();
                break;

            case 5: // LISTA MARCAS
                displayTitle("5. LISTAR MARCAS");
                printBrands(brands, 5);
                setPause();
                break;

            case 6: // LISTA COLORES
                displayTitle("6. LISTAR COLORES");
                printColors(colors, 5);
                setPause();
                break;

            case 7: // LISTA SERVICIOS
                displayTitle("7. LISTAR SERVICIOS");
                printServices(services, 4);
                setPause();
                break;

            case 8: // ALTA TRABAJOS
                displayTitle("8. ALTA TRABAJO");
                result = newWork(works,W,cars,C,services,S);
                if(result == -1){
                    margen(); printf("No se efectuo el alta. \n");
                } else {
                    margen(); printf("Alta realizada con exito. \n");
                }
                setPause();
                break;

            case 9: // LISTA TRABAJOS
                displayTitle("9. LISTAR TRABAJOS");
                sortWorks(works,W,DESC);
                printWorks(works, W, cars, C, services, 4);
                setPause();
                break;

            case 10: // LISTA TRABAJOS
                //displayTitle("10. INFORMES");
                optionInf = displayMenu(informMenu,6,1);
                switch(optionInf){
                    case 1:
                        displayTitle("9.1 AUTOS COLOR NEGRO");
                        sortCars(cars, C,DESC);
                        infoBlackCars(cars,C,brands,B,colors,H);
                        setPause();
                        break;

                    case 2:
                        displayTitle("9.2 AUTOS DE MARACA SELECCIONADA");
                        sortCars(cars, C,DESC);
                        infoCarsFromBrand(cars,C,brands,B,colors,H);
                        setPause();
                        break;

                    case 3:
                        displayTitle("9.3 TRABAJOS POR PATENTE");
                        sortWorks(works,W,DESC);
                        informWorkFromPatent(works, W, cars, C, services,S,brands,B,colors,H);
                        setPause();
                        break;

                    case 4:
                        displayTitle("9.4 AUTOS SIN TRABAJOS");
                        sortCars(cars, C,DESC);
                        informCarsWithutWorks(works, W, cars, C, services,S,brands,B,colors,H);
                        setPause();
                        break;

                    case 5:
                        displayTitle("9.5 TOTAL DE TRABAJOS DE UN AUTOS");
                        informTotalFromPatent(works, W, cars, C, services,S,brands,B,colors,H);
                        setPause();
                        break;

                    case 6:
                        displayTitle("9.6 SERVICIO MAS REQUERIDO");
                        informServiceMoreRequested(works, W, cars, C, services,S,brands,B,colors,H);
                        setPause();
                        break;


                    default:
                        displayTitle("Error 404");
                        margen();printf("Debe elegir una opcion del menu \n");
                        setPause();
                        break;
                }
                break;


            case 11: // SALIR
                margen();printf("Esta por salir del programa \n" );
                loop = FALSE;
                break;

            default:
                displayTitle("Error 404");
                margen();printf("Debe elegir una opcion del menu \n");
                setPause();
                break;
            }

    } while(loop);
    return 0;
}



/** Datos para correcion del examen */
/*
 eService services[] ={
   {20000, "Lavado", 250},
   {20001, "Pulido", 300},
   {20002, "Encerado", 400},
   {20003, "Completo", 600},
   {20004, "Teflonado", 800}
   };

   eBrand brands[] ={
   {1000, "Renault"},
   {1001, "Fiat"},
   {1002, "Ford"},
   {1003, "Chevrolet"},
   {1004, "Peugeot"}
   };

    eColor colors[] ={
   {5000, "Negro"},
   {5001, "Blanco"},
   {5002, "Gris"},
   {5003, "Rojo"},
   {5004, "Azul"}
   };

   eCar cars[]= {
       {1, "AAA-201", 1000, 5001, 1995, 0},
       {2, "DFR-234", 1003, 5000, 2002, 0},
       {3, "GFT-564", 1002, 5003, 2007, 0},
       {4, "ACD-321", 1002, 5003, 1995, 0},
       {5, "HTD-656", 1004, 5002, 2008, 0},
       {6, "QSZ-435", 1003, 5001, 1994, 0},
       {7, "LGX-201", 1001, 5000, 2012, 0},
       {8, "SUZ-324", 1001, 5002, 1991, 0},
       {9, "HCU-762", 1000, 5003, 2008, 0},
       {10, "DYC-735", 1003, 5001, 2002, 0},
       {11, "JJK-879", 1003, 5001, 2010, 0},
       {12, "FED-322", 1004, 5002, 2006, 0},
       {13, "GHV-332", 1001, 5003, 2007, 0},
       {14, "BDE-221", 1000, 5004, 1996, 0},
       {15, "OPD-332", 1000, 5001, 2014, 0},
       {16, "PPD-121", 1002, 5001, 2015, 0},
       {17, "IIT-230", 1001, 5000, 2009, 0},
       {18, "KOD-220", 1004, 5002, 2011, 0},
       {19, "QSZ-305", 1004, 5002, 1993, 0},
       {20, "SSD-128", 1002, 5003, 1992, 0},
       {21, "SSD-240", 1003, 5004, 1992, 0},
       {22, "EDF-213", 1001, 5000, 2001, 0},
       {23, "", 0, 0, 0, 1},
       {24, "", 0, 0, 0, 1},
   };

   eWork works[] = {

       {0, "AAA-201", 20000, {12,3,2019}, 0},
       {2, "DFR-234", 20000, {2,4,2019}, 0},
       {3, "GFT-564", 20001, {7,1,2019}, 0},
       {4, "ACD-321", 20002, {9,11,2019}, 0},
       {5, "HTD-656", 20003, {12,12,2019}, 0},
       {6, "QSZ-435", 20001, {21,7,2019}, 0},
       {7, "LGX-201", 20001, {29,8,2019}, 0},
       {8, "SUZ-324", 20004, {31,5,2019}, 0},
       {9, "HCU-762", 20004, {2,2,2019}, 0},
       {10, "DYC-735", 20000, {18,2,2019}, 0},
       {11, "JJK-879", 20001, {17,3,2019}, 0},
       {12, "AAA-201", 20000, {17,4,2019}, 0},
       {13, "DFR-234", 20000, {2,6,2019}, 0},
       {14, "GFT-564", 20001, {7,3,2019}, 0},
       {15, "ACD-321", 20002, {21,7,2019}, 0},
       {16, "HTD-656", 20003, {11,9,2019}, 0},
       {17, "QSZ-435", 20001, {3,7,2019}, 0},
       {18, "LGX-201", 20001, {21,8,2019}, 0},
       {19, "SUZ-324", 20004, {28,5,2019}, 0},
       {20, "HCU-762", 20004, {2,8,2019}, 0},
       {21, "DYC-735", 20000, {8,2,2019}, 0},
       {22, "JJK-879", 20001, {17,3,2019}, 0},
       {23, "KOD-220", 20003, {17,4,2019}, 0},
       {24, "QSZ-305", 20000, {21,3,2019}, 0},
       {25, "SSD-128", 20002, {16,4,2019}, 0},
       {26, "SSD-240", 20000, {17,4,2019}, 0},
       {27, "EDF-213", 20001, {23,3,2019}, 0},
       {28, "AAA-201", 20000, {12,2,2019}, 0},
       {29, "DFR-234", 20000, {2,3,2019}, 0},
       {30, "GFT-564", 20001, {7,2,2019}, 0},
       {31, "ACD-321", 20002, {9,12,2019}, 0},
       {32, "HTD-656", 20003, {12,9,2019}, 0},
       {33, "QSZ-435", 20001, {21,5,2019}, 0},
       {34, "HTD-656", 20002, {12,2,2019}, 0},
       {35, "QSZ-435", 20000, {21,1,2019}, 0},
       {36, "", 0, {0,0,0}, 1},
       {37, "", 0, {0,0,0}, 1},
   };*/
