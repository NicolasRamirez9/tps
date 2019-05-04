#ifndef STRING_H
#define STRING_H
int getString(char *msg,char *msgError,int minimo,int maximo,int reintentos,char *resultado);
int isValidName(char *cadena);
int getName(char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);
#endif // STRING_H
