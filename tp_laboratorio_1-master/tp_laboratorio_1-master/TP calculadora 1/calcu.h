#ifndef CALCU_H
#define CALCU_H
float numero1(void);
/**\brief Pide un numero flotante
 *\param guarda el numero1
 * \return retorna el operando1
 */

float numero2(void);
/**\brief Pide un numero flotante
 *\param guarda el numero2
 * \return retorna el operando2
 */

float sumar( float operando1,float  operando2);
/**\brief recibe dos numeros flotantes
 *\param los suma
 * \return retorna el resultado de la suma
 */

float restar( float operando1,float  operando2);
/**\brief recibe dos numeros flotantes
 *\param los resta
 * \return retorna el resultado de la resta
 */

float dividir( float operando1,float  operando2);
/**\brief recibe dos numeros flotantes
 *\param se fija si el divisor es mayor a 0,
 *\param si es mayor los divide y sino cancela la operacione
 * \return retorna el resultado de la division
 */

float multiplicar( float operando1,float  operando2);
/**\brief recibe dos numeros flotantes
 *\param los multiplica
 * \return retorna el resultado de la multiplicacion
 */
float factorial_a( float operando1);
/**\brief recibe un numero flotante
 *\param se fija si el numero es mayor a 0
 *\param y si lo es lo factorea
 * \return retorna el resultado del factoreo
 */

float factorial_b( float operando2);
/**\brief recibe un numero flotante
 *\param se fija si el numero es mayor a 0
 *\param y si lo es lo factorea
 * \return retorna el resultado del factoreo
 */
#endif


