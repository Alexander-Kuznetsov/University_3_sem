#include <stdio.h>
#include "input.h"

int input(int key)
{
    int result;

    printf(">> ");
    result = func();
    while (1){
        if (result>=0 && result <= key)
            break;
        else
        {
            printf("incorrect input, please return input...\n");
            printf(">> ");
            result = func();
        }
    }
    return result;
}

float input_elem()
{
    float result;
    printf("float >> ");
    while(fscanf(stdin, "%f", &result) != 1){
        printf("incorrect input, please return input...\n");
        printf("float >> ");
        fflush(stdin);
    }
    return result;
}

int func()
{
    int result;
    while (scanf("%d",&result) != 1){
        while (getchar() != '\n');
        printf("incorrect input, please return input...\n");
        printf(">> ");
    }
    return result;
}
