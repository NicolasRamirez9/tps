#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#define E 3
#define VACIO -1
#define LLENO 1



void functionMenu(sEmpleado arrayEmpleado[])
{

    int opcion;
    char seguir;
    int indice;
    int flag=0;


    do
    {
        system("color F0");
        printf(":::::::::::::::::::::::::::\n");
        printf(": 1) ALTAS    2)MODIFICAR :\n");
        printf(": 3) BAJA     4)INFORMAR  :\n");
        printf(":::::::::::::::::::::::::::\n");


        printf("elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            flag=1;
            indice=spaceFinderInTheArray(arrayEmpleado,E);
            if(indice!=VACIO)
            {
                employeeIncomeFunction(arrayEmpleado, E,indice);
            }
            else
            {
                printf("no hay espacio en el array\n");
            }
            break;


        case 2:
            if(flag==0)
            {
                printf("debe cargar al empleado primero");
            }
            else
            {
                showId(arrayEmpleado,E);
                printf("\ningrese un id para modificar\n");
                modifyFields(arrayEmpleado,E);

            }

            break;



        case 3:
            if(flag==0)
            {

                printf("debe cargar al empleado primero");

            }
            else
            {
                showId(arrayEmpleado,E);
                printf("\ningrese un id para dar de baja\n");
                employeeLow(arrayEmpleado,E);
            }


            break;

        case 4:
            if(flag==0)
            {

                printf("debe cargar al empleado primero");

            }
            else
            {
                alphabeticallyOrderedByLastName(arrayEmpleado,E);
                alphabeticalOrderBySector(arrayEmpleado,E);
                totalAndAverageSalary(arrayEmpleado,E);

            }

            break;
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }
    while(seguir =='s');

}
int functionIdAutomatic(sEmpleado arrayEmpleado[],int cant)
{
    int i ;
    for( i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==VACIO)
        {
            arrayEmpleado[i].id=i+1;
            break;
        }

    }
    return i;
}

void arrayInialization(sEmpleado arrayEmpleado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        arrayEmpleado[i].isEmpty=VACIO;
    }

}
int spaceFinderInTheArray(sEmpleado arrayEmpleado[],int cant)
{
    int aux=VACIO;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==VACIO)
        {
            aux=i;
            break;
        }
    }

    return aux;
}
void employeeIncomeFunction(sEmpleado arrayEmpleado[],int cant,int i)
{

    int n;
    int a;
    int flagNombre=0;
    int flagApellido=0;

    printf("ID es:%d",functionIdAutomatic(arrayEmpleado,E));

    printf("\ningrese nombre: ");
    do
    {
        flagNombre= 0;
        fflush(stdin);
        gets(arrayEmpleado[i].nombre);
        for(n=0; n<strlen(arrayEmpleado[i].nombre); n++)
        {
            if((arrayEmpleado[i].nombre[n] < 'a' || arrayEmpleado[i].nombre[n] > 'z') &&
                    (arrayEmpleado[i].nombre[n] < 'A' || arrayEmpleado[i].nombre[n] > 'Z'))
            {
                printf("reingrese nombre: ");
                flagNombre = LLENO;
                break;
            }
        }
    }
    while(flagNombre);

    printf("\ningrese apellido: ");
    do
    {
        flagApellido= 0;
        fflush(stdin);
        gets(arrayEmpleado[i].apellido);
        for(a=0; a<strlen(arrayEmpleado[i].apellido); a++)
        {
            if((arrayEmpleado[i].apellido[a] < 'a' || arrayEmpleado[i].apellido[a] > 'z') &&
                    (arrayEmpleado[i].apellido[a] < 'A' || arrayEmpleado[i].apellido[a] > 'Z'))
            {
                printf("reingrese apellido: ");
                flagApellido = LLENO;
                break;
            }
        }
    }
    while(flagApellido);





    printf("\ningrese salario: ");
    scanf("%f", & arrayEmpleado[i].salario);
    while(arrayEmpleado[i].salario<0)
    {
        printf("\nreingrese salario: ");
        scanf("%f", & arrayEmpleado[i].salario);

    }

    printf("\ningrese sector: ");
    scanf("%d", & arrayEmpleado[i].sector);
    while(arrayEmpleado[i].sector<0)
    {
        printf("\nreingrese sector: ");
        scanf("%d", & arrayEmpleado[i].sector);

    }

    arrayEmpleado[i].isEmpty=LLENO;


}
void modifyFields(sEmpleado arrayEmpleado[],int cant)
{

    int aceptar2;
    int i;
    int auxId;
    int flag =0;
    char modificacion;
    int flagNombre2=0;
    int flagApellido2=0;

    printf("\ningrese ID para modificar : ");
    scanf("%d",&auxId);

    for(i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty!=VACIO && auxId==arrayEmpleado[i].id)
        {
            do
            {
                system("cls");
                printf("--------------\n");
                printf("-5) NOMBRE   -\n");
                printf("-6) APELLIDO -\n");
                printf("-7) SALARIO  -\n");
                printf("-8) SECTOR   -\n");
                printf("--------------\n");

                printf("ingrese el campo a modificar: ");
                scanf("%d",&aceptar2);
                system("cls");
                switch(aceptar2)
                {
                case 5:
                    printf("ingrese un nuevo nombre: ");
                    do
                    {
                        flagNombre2= 0;
                        fflush(stdin);
                        gets(arrayEmpleado[i].nombre);
                        for(int n=0; n<strlen(arrayEmpleado[i].nombre); n++)
                        {
                            if((arrayEmpleado[i].nombre[n] < 'a' || arrayEmpleado[i].nombre[n] > 'z') &&
                                    (arrayEmpleado[i].nombre[n] < 'A' || arrayEmpleado[i].nombre[n] > 'Z'))
                            {
                                printf("\nreingrese nuevo nombre: ");
                                flagNombre2 = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagNombre2);
                    break;

                case 6:
                    printf("\ningrese nuevo apellido: ");
                    do
                    {
                        flagApellido2= 0;
                        fflush(stdin);
                        gets(arrayEmpleado[i].apellido);
                        for(int a=0; a<strlen(arrayEmpleado[i].apellido); a++)
                        {
                            if((arrayEmpleado[i].apellido[a] < 'a' || arrayEmpleado[i].apellido[a] > 'z') &&
                                    (arrayEmpleado[i].apellido[a] < 'A' || arrayEmpleado[i].apellido[a] > 'Z'))
                            {
                                printf("\nreingrese nuevo apellido: ");
                                flagApellido2 = LLENO;
                                break;
                            }
                        }
                    }
                    while(flagApellido2);
                    break;

                case 7:
                    printf("\ningrese nuevo salario: ");
                    scanf("%f", & arrayEmpleado[i].salario);
                    while(arrayEmpleado[i].salario<0)
                    {
                        printf("\nreingrese nuevo salario: ");
                        scanf("%f", & arrayEmpleado[i].salario);

                    }
                    break;

                case 8:
                    printf("\ningrese nuevo sector: ");
                    scanf("%d", & arrayEmpleado[i].sector);
                    while(arrayEmpleado[i].sector<0)
                    {
                        printf("\nreingrese nuevo sector: ");
                        scanf("%d", & arrayEmpleado[i].sector);

                    }
                    break;

                }
                printf("\nquiere modificar otro campo?\ns/para continuar n/para salir\n");
                modificacion=getch();
                system("cls");
            }
            while(modificacion=='s');


            flag=LLENO;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nNo existe el ID vuelva a ingresarlo\n");
    }
}
void employeeLow(sEmpleado arrayEmpleado[],int cant)
{

    int flag=0;
    int aceptar1;
    int auxId2;
    printf("\nIngrese ID para dar de baja: ");
    scanf("%d", & auxId2);

    for(int i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty!=VACIO && auxId2==arrayEmpleado[i].id)
        {
            flag=1;
            printf("\ndesea dar de baja a este empleado?\n s/para continuar n/para salir\n");
            aceptar1=getch();
            if(aceptar1 =='s')
            {
                printf("\nse ha dado de baja a este empleado.\n");
                arrayEmpleado[i].isEmpty=VACIO;
                break;
            }
            else if (aceptar1!='s')
            {
                printf("\nprecione s para volver al menu\n");
            }

        }

    }

    if(flag==0)
    {
        printf("\nNo existe el ID vuelva a ingresarlo\n");
    }
}
void alphabeticallyOrderedByLastName( sEmpleado arrayEmpleado[], int cant)
{
    int i;
    int j;
    sEmpleado aux;
    printf("  ordenado alfabeticamente por apellido:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(stricmp(arrayEmpleado[i].apellido,arrayEmpleado[j].apellido)>0)
            {
                aux=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==LLENO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[i].nombre,arrayEmpleado[i].apellido,arrayEmpleado[i].salario,arrayEmpleado[i].sector);
        }

    }

}
void alphabeticalOrderBySector( sEmpleado arrayEmpleado[], int cant)
{
    int i;
    int j;
    sEmpleado aux2;
    printf("\n  ordenado alfabeticamente por sector:\n");
    for(i=0; i< cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(arrayEmpleado[i].sector>arrayEmpleado[j].sector)
            {
                aux2=arrayEmpleado[i];
                arrayEmpleado[i]=arrayEmpleado[j];
                arrayEmpleado[j]=aux2;

            }
        }
    }
    for (i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==LLENO)
        {
            printf("  nombre:%s  apellido:%s  salario:%.2f  sector:%d\n",arrayEmpleado[i].nombre,arrayEmpleado[i].apellido,arrayEmpleado[i].salario,arrayEmpleado[i].sector);
        }

    }
}
void totalAndAverageSalary(sEmpleado arrayEmpleado[],int cant)
{
    int i;
    float acum=0;
    float prom;
    float cont=0;
    int contDeProm=0;
    for(i=0; i<cant; i++)
    {
        acum=acum+arrayEmpleado[i].salario;
        if(arrayEmpleado[i].isEmpty==LLENO)
        {
            cont++;
        }

    }

    prom=acum/cont;
    if(arrayEmpleado[i].isEmpty>prom)
    {
        contDeProm++;
    }
    printf("\n  el salario total es:%.2f y el promedio es:%.2f\n",acum,prom);
    printf("\n  los empleados que superaron el salario son:%d\n",contDeProm);
}
void showId(sEmpleado arrayEmpleado[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==LLENO)
        {

            printf("id:%d  nombre:%s  apellido:%s\n",arrayEmpleado[i].id,arrayEmpleado[i].nombre,arrayEmpleado[i].apellido);
        }
    }

}



