#include "about.h"

int func();

void about_start(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "--------------------------------------",
           "Would you have doing?",
           "--------------------------------------",
           "1 - Work with standart matrix",
           "2 - Work with special matrix(list)",
           "3 - Time test(with const SIZE)",
           "4 - Time test(with const NON-zero elements)",
           "0 - Exit",
           "--------------------------------------");
}

void about_action(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "--------------------------------------",
           "What action do you have?",
           "--------------------------------------",
           "1 - Load from file",
           "2 - Get matrix from keyboard",
           "3 - Random matrix",
           "4 - Get matrix from keyboard with special index!",
           "0 - Exit",
           "--------------------------------------");
}

//Action with input!!!
int input_key(int key1, int key2){
    int result;
    printf("(int)>> ");
    result = func();
    while (1){
        if (result >= key1 && result <= key2)
            break;
        else{
            printf("incorrect input, please return input...\n");
            printf(">> ");
            result = func();
        }
    }
    return result;
}

int input_elem(){
    int result;
    printf("int >> ");
    while(fscanf(stdin, "%d", &result) != 1){
        printf("incorrect input, please return input...\n");
        printf("int >> ");
        fflush(stdin);
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
