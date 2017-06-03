#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int testing(FILE *f, int *maxlen)
{
    int k = 0;
    char str[40];
    int key = GOOD;
    int lenlane = 0;
    int keystr = 0;

    //Проверка на существование файла
    if (f == NULL)
    {
        key = NOT_FOUND;
    }
    //Проверка на пустоту файла
    else
        if (fscanf(f, "%s", str) == 1)
        {
            lenlane = strlen(str);
            k++;

            if (maxlen[k-1] < lenlane)
                maxlen[k-1] = lenlane;

            while  (fscanf(f,"%s",str) == 1)
            {
                k++;
                lenlane = strlen(str);

                if (maxlen[k-1] < lenlane)
                    maxlen[k-1] = lenlane;

                if (keystr != 0)
                {
                    if (k == 1)
                        key = testint(str, lenlane);
                    if (k == 4)
                        key = testfloat(str, lenlane);
                    if (k == 5)
                        key = testNY(str, lenlane);

                    if (key == NOT_INT || key == NOT_FLOAT || key == NOT_NY)
                        return key;
                }

                if (k == LEN_TABLE)
                {
                    k = 0;
                    keystr = 1;
                }
            }
        }
        else
            key = EMPTY;

    return key;
}

int testint(char *str, int lenlane)
{
    int key = GOOD;
    int count = 0;
    char perem[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i < lenlane; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (perem[j] == str[i])
                count++;
        }
    if (count != lenlane)
        key = NOT_INT;

    return key;
}

int testfloat(char *str, int lenlane)
{
    int key = GOOD;
    int count = 0;
    char perem[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

    for (int i = 0; i < lenlane; i++)
        for (int j = 0; j <= 10; j++)
            if (perem[j] == str[i])
                count++;

    if (count != lenlane)
        key = NOT_FLOAT;

    return key;
}

int testNY(char *str, int lenlane)
{
    int key = GOOD;
    int count = 0;
    char perem[2] = {'N','Y'};

    for (int i = 0; i < lenlane; i++)
        for (int j = 0; j <= 1; j++)
        {
            if (perem[j] == str[i])
                count++;
        }
    if (count != lenlane)
        key = NOT_NY;

    return key;
}
