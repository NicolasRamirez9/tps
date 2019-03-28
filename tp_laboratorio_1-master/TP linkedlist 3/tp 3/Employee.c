#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new(int id, char *nombre,int horasTrabajadas,int sueldo)
{
    Employee* ptr = malloc(sizeof(Employee));
    if(ptr != NULL)
        employee_newParametros(ptr ,id, nombre, horasTrabajadas, sueldo);

    return ptr;
}
Employee* employee_newParametros(Employee* this,char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id, horasTrabajadas,sueldo;

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    employee_setNombre (this, nombreStr);
    sueldo = atoi(sueldoStr);

}
int employee_setId(Employee* this,int id)
{
    if(id > 0)
        this->id = id;
    else
    return 1;
}
int employee_getId(Employee* this)
{
     return this->id;
}
int employee_setNombre(Employee* this,char* nombre)
{
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
      else
       return 1;
}
int employee_getNombre(Employee* this)
{
    return this->nombre;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(horasTrabajadas > 0)
        this->horasTrabajadas= horasTrabajadas;
    else
    return 1;
}
int employee_getHorasTrabajadas(Employee* this)
{
    return this->horasTrabajadas;
}
int employee_setSueldo(Employee* this , int sueldo)
{
    if(sueldo > 0)
        this->sueldo = sueldo;
    else
    return 1;

}
int employee_getSueldo(Employee* this)
{
     return this->sueldo;
}

