#include <stdio.h>
#include <stdlib.h>
#include "calcu.h"

float numero1 (void)
{
    float operando1;
    printf ("INGRESE PRIMER OPERANDO: ");
    scanf("%f", &operando1);
    return operando1;

}
float numero2 (void)
{
    float operando2;
    printf ("INGRESE SEGUNDO OPERANDO: ");
    scanf("%f", &operando2);
    return operando2;
}

float sumar(float numero1, float numero2)
{
    return numero1+numero2;
}
float restar(float numero1, float numero2)
{
    return  numero1-numero2;
}
float dividir(float numero1, float numero2)
{
    float divi;

    if(numero2!=0)
    {
        divi= numero1/numero2;

        return printf("LA DIVISION ES: %.2f\n",divi );

    }
    else
    {
        return printf("NOSE PUEDE DIVIDIR POR 0.\nVUELVE A INGRESAR EL DIVISOR");
    }


}
float multiplicar(float numero1, float numero2)
{
    return numero1*numero2;
}
float factorial_a (float numero1)
{

    float factor_a=1;

    float i_a=1;

    if(numero1>0)
    {

        for(i_a; i_a<=numero1; i_a++)
        {
            factor_a=factor_a*i_a;

        }
        printf("EL FACTOR A ES: %.2f \n",factor_a);
    }
    else
    {
        return printf("NO SE PUEDE SACAR EL FACTORIAL DE 0 Y NUMEROS NEGATIVOS");
    }
}
float factorial_b (float numero2)
{

    float factor_b=1;

    float i_b=1;

    if(numero2>0)
    {

        for(i_b; i_b<=numero2; i_b++)
        {
            factor_b=factor_b*i_b;

        }
        printf("EL FACTOR B ES: %.2f \n",factor_b);
    }
    else
    {
        return printf("NO SE PUEDE SACAR EL FACTORIAL DE 0 Y NUMEROS NEGATIVOS");
    }



}


