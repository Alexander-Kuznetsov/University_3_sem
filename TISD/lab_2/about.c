#include <stdio.h>

void about(int key)
{
    switch(key){
    case 1:
        printf("--------------------------------\n");
        printf("%s\n%s\n%s\n%s\n%s\n", "input your variant", "1 - massiv_stack",
               "2 - list_stack", "3 - time working are stacks", "0 - exit");
        break;
    case 2:
        printf("--------------------------------\n");
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "input your variant",
               "1 - push element stack1", "2 - push element stack2", "3 - pop element stack1",
                    "4 - pop element stack2", "5 - print stack1", "6 - print stack2", "0 - exit");
        break;
    case 3:
        printf("--------------------------------\n");
        printf("%s\n%s\n%s\n%s\n%s\n", "input your variant",
           "1 - push element in list_stack", "2 - pop element out list_stack", "3 - print list_stack",
                "0 - exit");
        break;
    }
}
