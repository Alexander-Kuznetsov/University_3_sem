#include <stdio.h>

int func();

int input(int left, int key){
    int result;
    printf(">> ");
    result = func();
    while (1){
        if (result >= left && result <= key)
            break;
        else{
            printf("incorrect input, please return input...\n");
            printf(">> ");
            result = func();
        }
    }
    return result;
}
int func(){
    int result;
    while (scanf("%d",&result) != 1){
        while (getchar() != '\n');
        printf("incorrect input, please return input...\n");
        printf(">> ");
    }
    return result;
}
