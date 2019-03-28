#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"

int main()
{
    float operando1;
    float operando2;
    int opcion;
    char respuesta = 's';
    do
    {
        system("color 0C");
        printf ("***************************************\n");
        printf ("*  1)INGRESE PRIMER OPERANDO A:%.2f   *\n", operando1);
        printf ("*  2)INGRESE SEGUNDO OPERANDO B:%.2f  *\n", operando2);
        printf ("*  3)CALCULE OPERACIONES              *\n");
        printf ("*    SUMA: A:%.2f + B:%.2f            *\n",operando1,operando2);
        printf ("*    RESTA:  A:%.2f - B:%.2f          *\n",operando1,operando2);
        printf ("*    DIVISION:  A:%.2f / B:%.2f       *\n",operando1,operando2);
        printf ("*    MULTIPLICACION:  A:%.2f * B:%.2f *\n",operando1,operando2);
        printf ("*    FACTORIAL:  A:%.2f ! B:%.2f      *\n",operando1,operando2);
        printf ("*  4)INFORME DE TODOS LOS RESULTADOS  *\n");
        printf ("*  5)SALIR                            *\n");
        printf ("***************************************\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            operando1=numero1();
            break;



        case 2:
            system("cls");
            operando2=numero2();
            break;

        case 3:

            system("cls");
            printf("CALCULNDO OPERACIONES\nVUELVA AL MENU Y PRECIONE 4 PARA SABER LOS RESULTADOS ");
            break;

        case 4:

            system("cls");
            printf("LA SUMA ES: %.2f\n", sumar(operando1,operando2));
            printf("LA RESTA ES: %.2f\n", restar(operando1,operando2));
            dividir(operando1,operando2);
            printf("\nLA MULTIPLICACION ES: %.2f\n", multiplicar(operando1,operando2));
            factorial_a(operando1);
            factorial_b(operando2);
            break;






        case 5:
            system("cls");
            printf("PRECIONE n PARA SALIR DE LA CALCULADORA");
            break;
        }
        printf("\nQUIERE VOLVER AL MENU? s/n :");
        fflush(stdin);
        scanf("%c", & respuesta);
        system("cls");
    }
    while(respuesta== 's');
    return 0;
}
