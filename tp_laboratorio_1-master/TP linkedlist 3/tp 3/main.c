#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int seguir;
    int option ;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf(": 1)CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)  :\n");
        printf(": 2)CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO BINARIO):\n");
        printf(": 3)ALTA DE EMPLEADO                                                          :\n");
        printf(": 4)MODIFICAR DATOS DEL EMPLEADO                                              :\n");
        printf(": 5)BAJA DE EMPLEADO                                                          :\n");
        printf(": 6)LISTAR EMPLEADOS                                                          :\n");
        printf(": 7)ORDENAR EMPLEADOS                                                         :\n");
        printf(": 8)GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO)    :\n");
        printf(": 9)GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO BINARIO)  :\n");
        printf(": 10)SALIR                                                                    :\n");
        printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

        printf("Elija una opcion: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
               controller_loadFromText("data.csv",listaEmpleados);
                 break;

            case 2:

                 break;

            case 3:

                 break;

            case 4:

                 break;

            case 5:

                 break;

            case 6:

                 break;

            case 7:

                 break;

            case 8:

                 break;

            case 9:

                 break;

            case 10:

                 break;

        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }while(seguir == 's');
    return 0;
}
