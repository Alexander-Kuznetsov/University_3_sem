#ifndef STACK_LIST_H
#define STACK_LIST_H
#define MAX_SIZE_LIST 50000000

typedef struct Stack_list{
    float num;
    struct Stack_list *next;
} Stack_list;

typedef struct Free_list{
    Stack_list *num;
    struct Free_list *next;
} Free_list;

void push_list_stack (Stack_list **head, float elem, int *size_list_stack);
void pop_list_stack (Stack_list **head, Free_list **head_free, int *size_list_stack, int z);
void print_list_stack (Stack_list *head, int size_list);
void free_list_stack(Stack_list *head);
void print_free (Free_list *head_free);
struct Free_list* Check_free(struct Free_list *head, struct Stack_list *val);
void free_free(Free_list *head);

#endif // STACK_LIST_H
