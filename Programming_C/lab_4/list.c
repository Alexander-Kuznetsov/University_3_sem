#include "list.h"

void store(List *lst, struct Node *node);
void swap_address(struct Node **a, struct Node **b);
int func();

List *create_list(){
    List *list = (List*) malloc(sizeof(List));
    list -> size = 0;
    list -> head = NULL, list -> tail = NULL;
    return list;
}

void about_list(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "----------------------------",
           "!--#--Select Menu--#--!",
           "1 - load from file",
           "2 - save into file",
           "3 - print list",
           "4 - add in start list",
           "5 - add in end list",
           "6 - pop in start list",
           "7 - pop in end list",
           "8 - search max element(UnitPrice)",
           "9 - search min element(UnitPrice)",
           "10 - test empty list",
           "11 - find first element(SalesOrderID)",
           "12 - reverse list",
           "13 - len list",
           "14 - clear list",
           "15 - about",
           "0 - exit",
           "----------------------------");
}

void load_file(FILE *f, List *lst){
    struct Node *node;
    char  num[100];
    while(!feof(f)){
        if (test(f, num) != ERROR){
            node = (struct Node*) malloc(sizeof(struct Node));
            store(lst, node);
            node -> SalesOrderID = atoi(num);
            read(f, num), node -> SalesOrderDetailID = atoi(num);
            read(f, num), node -> OrderQty = atoi(num);
            read(f, num), node -> ProductID = atoi(num);
            read(f, num), node -> UnitPrice = atof(num);
            read(f, num), node -> UnitPriceDiscount = atof(num);
            read(f, num), strcpy(node -> ModifiedDate, num);
            lst -> size += 1;
        }
    }
}

void save_file(FILE *f, List *lst){
    struct Node *node = lst -> head;
    while(node){
        fprintf(f, "SalesOrderID %d\n", node -> SalesOrderID);
        fprintf(f, "SalesOrderDetailID %d\n", node -> SalesOrderDetailID);
        fprintf(f, "OrderQty %d\n", node -> OrderQty);
        fprintf(f, "ProductID %d\n", node -> ProductID);
        fprintf(f, "UnitPrice %.4f\n", node -> UnitPrice);
        fprintf(f, "UnitPriceDiscount %.4f\n", node -> UnitPriceDiscount);
        fprintf(f, "ModifiedDate %s\n\n", node -> ModifiedDate);
        node = node -> next;
    }
}

void store(List *lst, struct Node *node){
    if (lst -> head == NULL){
        node -> next = node -> prev = NULL;
        lst -> tail = lst -> head = node;
    }
    else{
        lst -> tail -> next = node;
        node -> next = NULL;
        node -> prev = lst -> tail;
        lst -> tail = node;
    }
}

void print_list(List *lst){
    struct Node *node = lst -> head;
    while(node){
        printf("SalesOrderID %d\n", node -> SalesOrderID);
        printf("SalesOrderDetailID %d\n", node -> SalesOrderDetailID);
        printf("OrderQty %d\n", node -> OrderQty);
        printf("ProductID %d\n", node -> ProductID);
        printf("UnitPrice %.4f\n", node -> UnitPrice);
        printf("UnitPriceDiscount %.4f\n", node -> UnitPriceDiscount);
        printf("ModifiedDate %s\n\n", node -> ModifiedDate);
        node = node -> next;
    }
    if (empty_list(lst) == ERROR)
        printf("list is empty");
    printf("\n");
}

int find_max(List *lst){
    int max;
    struct Node *node = lst -> head;
    while(node){
        if (node == lst -> head)
            max = node -> UnitPrice;
        else
            if(max < (node -> UnitPrice))
                max = node -> UnitPrice;
        node = node -> next;
    }
    return max;
}

int find_min(List *lst){
    int min;
    struct Node *node = lst -> head;
    while(node){
        if (node == lst -> head)
            min = node -> UnitPrice;
        else
            if(min > (node -> UnitPrice))
                min = node -> UnitPrice;
        node = node -> next;
    }
    return min;
}

int len_list(List *lst){
    if (lst -> size != 0)
        return lst -> size;
    else
        return ERROR;
}

int find_first(List *lst, int key){
    struct Node *node = lst -> head;
    int ind = 0;
    while(node){
        if (key == (node -> SalesOrderID)){
            return ind;
        }
        node = node -> next;
        ++ind;
    }
    if (empty_list(lst) == ERROR)
        return ERROR;
    else
        return NOT_FOUND;
}

int empty_list(List *lst){
    if (lst -> head == NULL) return ERROR;
    else return 0;
}

void reverse_list(List *lst){
    struct Node *tmp, *node = lst -> head;
    tmp = lst -> head, lst -> head = lst -> tail, lst -> tail = tmp;
    for(int i = 0; i < (lst -> size); i++){
        tmp = node -> next;
        swap_address(&(node -> next), &(node -> prev));
        node = tmp;
    }
}

void pop_tail(List *lst){
        struct Node *node;

        if (lst -> size > 1){
            node = lst -> tail -> prev;
            free(lst -> tail);
            lst -> tail = node;
            lst -> tail -> next = NULL;
        //node -> next = NULL;
        }
        else{
            node = lst -> tail;
            lst -> head = NULL;
            free(node);
        }
        lst -> size -= 1;
}

void pop_head(List *lst){
        struct Node *node;
        node = lst -> head -> next;
        free(lst -> head);
        lst -> head = node;
       // lst -> tail -> prev = NULL;
        if(lst -> head != NULL) node -> prev = NULL;
        lst -> size -= 1;
}

void add_head(List *lst, int k1, int k2, int k3, int k4, float k5, float k6, char *k7){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node -> SalesOrderID = k1;
    node -> SalesOrderDetailID = k2;
    node -> OrderQty = k3;
    node -> ProductID = k4;
    node -> UnitPrice = k5;
    node -> UnitPriceDiscount = k6;
    strcpy(node -> ModifiedDate, k7);
    lst -> size += 1;
    if (empty_list(lst) != ERROR){
        lst -> head -> prev = node;
        node -> prev = NULL, node -> next = lst -> head;
        lst -> head = node;
    }
    else{
        node -> prev = NULL, node -> next = NULL;
        lst -> head = node;
        lst -> tail = node;
    }
}

void add_tail(List *lst, int k1, int k2, int k3, int k4, float k5, float k6, char *k7){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node -> SalesOrderID = k1;
    node -> SalesOrderDetailID = k2;
    node -> OrderQty = k3;
    node -> ProductID = k4;
    node -> UnitPrice = k5;
    node -> UnitPriceDiscount = k6;
    strcpy(node -> ModifiedDate, k7);
    lst -> size += 1;
    store(lst, node);
}

void clear_list(List *lst){
    if (lst -> head != NULL){
        struct Node *node = lst -> head;
        while(node){
            if (node != (lst -> head)) free(node -> prev);
            node = node -> next;
        }
        free(node);
        lst -> size = 0;
        lst -> head = lst -> tail = NULL;
    }
}

void swap_address(struct Node **a, struct Node **b){
    struct Node *tmp;
    tmp = *a, *a = *b, *b = tmp;
}

//Action with input!!!
int input_key(int key1, int key2){
    int result;
    printf(">> ");
    result = func();
    while (1){
        if (result >= key1 && result <= key2)
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

float input_elem_f(){
    float result;
    printf("float >> ");
    while(fscanf(stdin, "%f", &result) != 1){
        printf("incorrect input, please return input...\n");
        printf("float >> ");
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
