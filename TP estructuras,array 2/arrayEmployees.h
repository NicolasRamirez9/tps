#ifndef ARRAYEMPLOYEES_H
#define ARRAYEMPLOYEES_H

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;

} Empleado;

/**\brief muestra las opciones del menu
 *\param ingresa a la opcion que ejecute el usuario
 * \return retorna void
 */
int functionMenu(void);


/**\brief recorre el array
 *\param incrementa cada vez que se ingresa un empleado
 * \return retorna i
 */
static int generarId(void);


/**\brief recorre el array
 *\param inicializa el array en VACIO
 * \return retorna void
 */
int arrayInialization(Empleado *arrayEmpleado, int cant);


/**\brief recorre el array
 *\param busca VACIO para cambiarlo a LLENO
 * \return retorna aux
 */
int spaceFinderInTheArray(Empleado *arrayEmpleado,int cant,int *indice);

/**\brief ingreso de los campos
 *\param validacion de los campos
 * \return retorna void
 */
int employeeIncomeFunction(Empleado *arrayEmpleado,int cant,int posLibre);


/**\brief se ingresa id para modificar los campos
 *\param si el id es correcto se modifican y si no sale del programa
 * \return retorna void
 */
void modifyFields(Empleado,int);


/**\brief se ingresa id para dar de baja a un empleado
 *\param si el id es correcto se da de baja y si no sale del programa
 * \return retorna void
 */
void employeeLow(Empleado[],int);


/**\brief se recorre el array
 *\param se hace un hintecambio de posicion hasta que quede ordenado el apellido
 * \return retorna void
 */
void alphabeticallyOrderedByLastName(Empleado[],int);


/**\brief se recorre el array
 *\param se hace un hintecambio de posicion hasta que quede ordenado el sector
 * \return retorna void
 */
void alphabeticalOrderBySector(Empleado[],int);


/**\brief  recorre el array
 *\param saca el salario total ,el primedio y se fija que empleado
 * \param supera el promedio del salario
 * \return retorna void
 */
void totalAndAverageSalary(Empleado[],int);


/**\brief  recorre el array
 *\param muestra el id,el nombre y el apellido
 * \param y los muestra en la parte de modificar y dar de baja
  * \param para que el usuario sepa que id quiere modificar o dar de baja
 * \return retorna void
 */
void showId(Empleado[],int);


#endif

