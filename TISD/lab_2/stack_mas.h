#ifndef STACK_MAS_H
#define STACK_MAS_H
#define MAX_SIZE_MAS 50000000
//10000000

typedef struct stack_mas{
    float mas[MAX_SIZE_MAS];
    int top1;
    int top2;
} Stack_mas;

void init(Stack_mas *stk1, Stack_mas *stk2);
void push_mas_stack(Stack_mas *stk1, Stack_mas *stk2, float elem, int key);
void pop_mas_stack(Stack_mas *stk1, Stack_mas *stk2, int key);
void print_mas_stack(Stack_mas *stk1, Stack_mas *stk2, int key);
void free_mas_stack(Stack_mas *stk1, Stack_mas *stk2);

int isempty(Stack_mas *stk1);
int isempty2(Stack_mas *stk2);


#endif // STACK_MAS_H
