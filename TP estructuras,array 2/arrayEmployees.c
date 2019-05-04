#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "string.h"
#define E 3
#define VACIO -1
#define LLENO 1
int functionMenu(void)
{

    int opcion;
    char seguir;
    int posLibre;
    int flag=0;
    Empleado arrayEmpleado[E];

    arrayInialization(arrayEmpleado,E);


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
            if(!spaceFinderInTheArray(arrayEmpleado,E,&posLibre))
            {
               // flag=1;
                switch(employeeIncomeFunction(arrayEmpleado,E,posLibre))
                {
                    case 0:
                    printf("dato ingresado correctamente\n\n");
                  //  id++;
                    break;

                    case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            else
            {
                printf("lleno");
            }
            break;
     /*   case 2:
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

            break;*/
        }
        printf("\nQuiere volver al menu?\ns/Para continuar n/Para salir\n");
        seguir=getch();
        system("cls");
    }
    while(seguir =='s');
    return 0;

}
static int generarId(void)
{
    static int idPant=0;
    return idPant++;
}

int arrayInialization(Empleado *arrayEmpleado, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        arrayEmpleado[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int spaceFinderInTheArray(Empleado *arrayEmpleado,int cant,int *indice)
{
    int ret;
    int i;

    for(i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }

    return ret;
}
int employeeIncomeFunction(Empleado *arrayEmpleado,int cant,int posLibre)
{
     int ret=1;

 //   printf("ID es:%d",generarId(void));

    if (!getName(arrayEmpleado[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,1))
    {
      //  if (!getName(arrayEmpleado[posLibre].apellido,"ingrese un apellido: ","error, vuelva a ingresar\n\n",2,20,1))
       // {
            if (!getFloat("ingrese salario: ","error,vuelva a intentar",0,10,1,&arrayEmpleado[posLibre].salario))
            {
                if(!getInt("ingrese un sector:\n1=LCD\n2=LED\n:","\nerror,vuelva a intentar",1,2,1,&arrayEmpleado[posLibre].sector))
                {
                    arrayEmpleado[posLibre].isEmpty=0;
                    ret=0;
                  //  auxPantalla[posLibre].id=id;
                }
            }
       // }
    }
    else
        {
        ret=1;
        }
    return ret;
}
/*void modifyFields(Empleado *arrayEmpleado,int cant)
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
void employeeLow(Empleado *arrayEmpleado,int cant)
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
void alphabeticallyOrderedByLastName(Empleado *arrayEmpleado, int cant)
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
void alphabeticalOrderBySector(Empleado *arrayEmpleado, int cant)
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
void totalAndAverageSalary(Empleado *arrayEmpleado,int cant)
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
void showId(Empleado *arrayEmpleado,int cant)
{
    for(int i=0; i<cant; i++)
    {
        if(arrayEmpleado[i].isEmpty==LLENO)
        {

            printf("id:%d  nombre:%s  apellido:%s\n",arrayEmpleado[i].id,arrayEmpleado[i].nombre,arrayEmpleado[i].apellido);
        }
    }

}


*/
