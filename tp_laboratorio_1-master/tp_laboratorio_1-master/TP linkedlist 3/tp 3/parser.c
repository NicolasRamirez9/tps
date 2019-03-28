#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

        int r,i=0;
        char idStr[50],horasStr[50],nombreStr[50],sueldoStr[50];


        if(pFile == NULL && pArrayListEmployee !=NULL)
        {
            return -1;
        }

      //  r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,horasStr,nombreStr,sueldoStr);
       do
        {

            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,horasStr,nombreStr,sueldoStr);
            if(r==4)
            {
               employee_newParametros(&Employee[i], idStr, nombreStr, horasStr, sueldoStr);

                i++;
            }
            else
                break;
        }
        while( !feof(pFile)  );


        return i;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
