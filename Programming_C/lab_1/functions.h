#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//Ключи ошибок
#define GOOD 0
#define NOT_FOUND -1
#define EMPTY -2
#define NOT_GOOD -3
#define NOT_INT -4
#define NOT_FLOAT -5
#define NOT_NY -6

#define LEN_TABLE 5

#include <stdio.h>

int testing(FILE *f, int *maxlen);
int testint(char *str, int lenlane);
int testfloat(char *str, int lenlane);
int testNY(char *str, int lenlane);
void getTable(FILE *f, int *maxlen);

#endif // FUNCTIONS_H
