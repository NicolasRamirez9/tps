#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define E 3
#include "arrayEmployees.h"

int main()
{
    sEmpleado arrayEmpleado[E];
    arrayInialization(arrayEmpleado,E);
    functionMenu(arrayEmpleado);
    functionIdAutomatic(arrayEmpleado,E);
    return 0;
}
