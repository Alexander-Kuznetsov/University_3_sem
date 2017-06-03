#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "input.h"
#include "stack_list.h"
#include "stack_mas.h"

#define C_SEC 1000.0

void timer(){
    int i;
    int size_list_stack = 0;
    clock_t time_m_push = 0, time_m_pop = 0, time_l_push = 0, time_l_pop = 0;
    //Stack_mas
    Stack_mas *stk1 = (Stack_mas*) malloc(sizeof(Stack_mas));
    Stack_mas *stk2 = (Stack_mas*) malloc(sizeof(Stack_mas));
    //Stack_list
    Stack_list *head = NULL;// *node;
    Free_list *head_free = NULL;

    //time with 1kk elements
    init(stk1, stk2);
    //----------------------------------------------push elements array
    time_m_push = clock();
    for(i = 0; i < (MAX_SIZE_MAS/2); i++)
        push_mas_stack(stk1, stk2, 1.0, 1);
    for(i = (MAX_SIZE_MAS/2); i < MAX_SIZE_MAS; i++)
        push_mas_stack(stk1, stk2, 1.0, 2);
    time_m_push = clock() - time_m_push;
    printf("Push massiv with %d elements have %lf seconds\n", MAX_SIZE_MAS, (double) (time_m_push/C_SEC));
    //------------------------------------------------------------
    //----------------------------------------------pop elements array
    time_m_pop = clock();
    for(i = 0; i < (MAX_SIZE_MAS/2); i++)
        pop_mas_stack(stk1, stk2, 1);
    for(i = (MAX_SIZE_MAS/2); i < MAX_SIZE_MAS; i++)
        pop_mas_stack(stk1, stk2, 2);
    time_m_pop = clock() - time_m_pop;
    printf("Pop massiv with %d elements have %lf seconds\n", MAX_SIZE_MAS, (double) (time_m_pop/C_SEC));
    //------------------------------------------------------------
    //----------------------------------------------push elements list
    time_l_push = clock();
    for(i = 0; i < MAX_SIZE_LIST; i++)
        push_list_stack (&head, 1.0, &size_list_stack);
    time_l_push = clock() - time_l_push;
    printf("Push list with %d elements have %lf seconds\n", MAX_SIZE_LIST, (double) (time_l_push/C_SEC));
    //----------------------------------------------------------------
    //----------------------------------------------pop elements list
    time_l_pop = clock();
    for(i = 0; i < MAX_SIZE_LIST; i++)
        pop_list_stack (&head, &head_free, &size_list_stack, 1);
    time_l_pop = clock() - time_l_pop;
    printf("Pop list with %d elements have %lf seconds\n", MAX_SIZE_LIST, (double) (time_l_pop/C_SEC));
    //------------------------------------------------------------
    //%
    if (time_l_push > time_m_push)
        printf("\ntime of push list < time of push array on %4.2lf%%\n",(double)(fabs(time_l_push/10 - time_m_push/10)));
    else
        printf("\ntime of push list > time of push array on %4.2lf%%\n",(double)(fabs(time_l_push/10 - time_m_push/10)));
    if (time_l_pop > time_m_pop)
        printf("time of pop list < time of pop array on %4.2lf%%\n",(double)(fabs(time_l_pop/10 - time_m_pop/10)));
    else
        printf("time of pop list > time of pop array on %4.2lf%%\n",(double)(fabs(time_l_pop/10 - time_m_pop/10)));

}

