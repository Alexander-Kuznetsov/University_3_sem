#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"

#define ERROR -1
#define NOT_FOUND -2

struct Node{
    //int num;
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
    struct Node *next;
    struct Node *prev;
};

typedef struct{
    struct Node *head, *tail;
    int size;
}List;

//Operation with input
int input_key(int key1, int key2);
int input_elem();

//Operation with list
List *create_list();
void print_list(List *lst), reverse_list(List *lst), about_list(), pop_tail(List *lst), pop_head(List *lst), clear_list(List *lst);
void load_file(FILE *f, List *lst), save_file(FILE *f, List *lst);
void add_head(List *lst, int k1, int k2, int k3, int k4, float k5, float k6, char *k7);
void add_tail(List *lst, int k1, int k2, int k3, int k4, float k5, float k6, char *k7);
int find_max(List *lst), find_min(List *lst), len_list(List *lst), empty_list(List *lst), find_first(List *lst, int key);
float input_elem_f();

#endif // LIST_H
