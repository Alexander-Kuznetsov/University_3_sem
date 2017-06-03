#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "stack_mas.h"
#include "stack_list.h"

int main()
{
    int size_list_stack = 0; // размер списка
    int key_stack, key_m_stack, key_l_stack;
    float elem;
    //Stack_mas
    Stack_mas *stk1 = (Stack_mas*) malloc(sizeof(Stack_mas));
    Stack_mas *stk2 = (Stack_mas*) malloc(sizeof(Stack_mas));
    //Stack_list
    Stack_list *head = NULL;// *node;
    Free_list *head_free = NULL;


    about(1); //about принимает номер help`a для отображения действий
    key_stack = input(3); //input принимает количество значений about()

    switch(key_stack){
        case 1: //действия над массивом
            init(stk1, stk2); //инициализация stack`oв массива
            about(2);
            while(1){
                key_m_stack = input(6);
                switch(key_m_stack){
                    case 1: //вставка элемента в Stack1
                        elem = input_elem();
                        push_mas_stack(stk1, stk2, elem, 1);
                        break;
                    case 2: //вставка элемента в Stack2
                        elem = input_elem();
                        push_mas_stack(stk1, stk2, elem, 2);
                        break;
                    case 3: //удаление элемента из Stack1
                        pop_mas_stack(stk1, stk2, 1);
                        break;
                    case 4: //удаление элемента из Stack2
                        pop_mas_stack(stk1, stk2, 2);
                        break;
                    case 5: //распечатать Stack1
                        print_mas_stack(stk1, stk2, 1);
                        break;
                    case 6: //распечатать Stack2
                        print_mas_stack(stk1, stk2, 2);
                        break;
                    case 0: //выход
                        exit(0);
                        break;
                }
            }
            break;
        case 2: //действие над списком
            about(3);
            while(1){
                key_l_stack = input(3);
                switch(key_l_stack){
                    case 1: //вставка элемента в stack
                        elem = input_elem();
                        push_list_stack (&head, elem, &size_list_stack);
                        head_free = Check_free(head_free, head);
                        break;
                    case 2: //удаление элемента из списка
                        pop_list_stack (&head, &head_free, &size_list_stack, 1);
                        break;
                    case 3: //распечатать элемент из stack
                        print_list_stack(head, size_list_stack);
                        print_free(head_free);
                        break;
                    case 0:
                        exit(0);
                        break;
                }
            }
            break;
        case 3: //время работы стэков
            timer();
            break;
    }
    //освобождение памяти массива_стек
    free_mas_stack(stk1, stk2);
    //лист_стек
    free_list_stack(head);
    free_free(head_free);

    return 0;
}
