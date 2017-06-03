#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void push_list_stack (Stack_list **head, float elem, int *size_list_stack)
{
    if ((*size_list_stack) < MAX_SIZE_LIST){
        Stack_list *tmp = (Stack_list*) malloc(sizeof(Stack_list));
        tmp->num = elem;
        tmp->next = (*head);
        (*head) = tmp;
        (*size_list_stack)++;
    }
    else{
        printf ("Error: List_Stack is overflow\n");
    }
}

void pop_list_stack (Stack_list **head, Free_list **head_free, int *size_list_stack, int z)
{
    if (*size_list_stack>0){
        Stack_list* prev = NULL;
        prev = (*head);
        (*head) = (*head)->next;

        // добавление в список свободных областей
        if (z==1){
            Free_list *tmp = (Free_list*) malloc(sizeof(Free_list));
            tmp->num = prev;
            tmp->next = (*head_free);
            (*head_free) = tmp;
        }
        free(prev);
        (*size_list_stack)--;
    }
    else{
        printf("Error: List_Stack is empty.\n");
    }
}

void print_list_stack (Stack_list *head, int size_list)
{
    Stack_list *head1 = head;
    if (size_list == 0){
        printf("List_Stack is empty.\n");
    }
    else{
        printf("Stack_List:  ");
        for (int i=0; i<size_list; i++){
            printf("%f ", head->num);
            head = head->next;
        }
        printf("\nElem_Adress: ");
        head = head1;
        for (int i=0; i<size_list; i++){
            printf("%p ", head);
            head = head->next;
        }
        printf("\n");
    }
}

void print_free (Free_list *head_free)
{
    printf("Free Adress: ");
    for ( ; head_free; head_free = head_free->next)
        printf("%p ", head_free->num);
    printf("\n");
}

struct Free_list* Check_free(struct Free_list *head, struct Stack_list *val)
{
    struct Free_list *cur, *prev = NULL;

    for (cur = head; cur; cur = cur->next){
        if (cur->num == val){
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;
            free(cur);
            return  head;
        }
        prev = cur;
    }

    return NULL;
}


void free_list_stack(Stack_list *head)
{
    Stack_list *next;

    for ( ; head; head = next){
        next = head->next;
        free(head);
    }
}

void free_free(Free_list *head)
{
    Free_list *next;

    for ( ; head; head = next){
        next = head->next;
        free(head);
    }
}

