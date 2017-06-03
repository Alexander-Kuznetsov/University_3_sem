#include <stdio.h>
#include <stdlib.h>
#include "stack_mas.h"

void init(Stack_mas *stk1, Stack_mas *stk2)
{
    stk1->top1 = 0;
    stk2->top2 = MAX_SIZE_MAS - 1;
}

void push_mas_stack(Stack_mas *stk1, Stack_mas *stk2, float elem, int key)
{
    if(key == 1){
        if(stk1->top1 < (MAX_SIZE_MAS/2)){
            stk1->mas[stk1->top1] = elem;
            stk1->top1++;
          }
        else
            printf("Error: Mas_Stack1 is overflow!: %d !\n", stk1->top1);
    }
    else{
        if(stk2->top2 >= MAX_SIZE_MAS/2){
            stk2->mas[stk2->top2] = elem;
            stk2->top2--;
          }
        else
            printf("Error: Mas_Stack2 is overflow!: %d !\n", stk2->top2);
    }
}

void pop_mas_stack(Stack_mas *stk1, Stack_mas *stk2, int key)
{
    if (key == 1){
        if((stk1->top1) > 0) {
            stk1->top1--;
           // stk1->mas[stk1->top1];
        }
        else {
            printf("Error: Mas_Stack1 is empty!\n");
        }
    }
    else{
        if((stk2->top2) < (MAX_SIZE_MAS - 1)) {
            stk2->top2++;
         //   stk2->mas[stk2->top2];
        }
        else {
            printf("Error: Mas_Stack2 is empty!\n");
        }
    }
}

void print_mas_stack(Stack_mas *stk1, Stack_mas *stk2, int key)
{
    int i;
    if(key == 1){
        i=stk1->top1;
        if(isempty(stk1)==1){
            printf("Mas_Stack1 is empty!\n");
            return;
        }
        printf("Stack_Array1: ");
        do {
            i--;
            printf("%5.2f ", stk1->mas[i]);
        }while(i > 0);
        printf("\n");
    }
    else{
        i = stk2->top2;
        if(isempty2(stk2)==1){
            printf("Mas_Stack2 is empty!\n");
            return;
        }
        printf("Stack_Array2: ");
        do {
            i++;
            printf("%5.2f ", stk2->mas[i]);
        }while(i < (MAX_SIZE_MAS-1));
        printf("\n");
    }
}

int isempty(Stack_mas *stk1) {
  if((stk1->top1) == 0)
      return(1);
  else
      return(0);
}

int isempty2(Stack_mas *stk2) {
  if((stk2->top2) == MAX_SIZE_MAS-1)
      return(1);
  else
      return(0);
}

void free_mas_stack(Stack_mas *stk1, Stack_mas *stk2)
{
    // освобождаем массив
    if (stk1->top1 != 0)
        free(stk1->mas);
    if (stk2->top2 != 0)
        free(stk2->mas);

    // освобождаем структуру
    free(stk1);
    free(stk2);
}

