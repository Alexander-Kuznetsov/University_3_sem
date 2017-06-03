#ifndef TABLE_H
#define TABLE_H
#define MAX_LEN_TABLE 5000
#define MAX_LEN 50
#define LEN_HEAD 10
#define MAX_STRING 51
#define C_SEC 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "input.h"

struct Head_s{
    char header[40];
} head[LEN_HEAD];

typedef struct {
    char industry[30];
    char national[4];
    char translate[4];
    char year[8];//int
}Technical;

typedef struct {
    char genre[10];
}Art;

typedef union{
    Technical tech;
    Art art;
}Type;

typedef struct{
    char surname[20];
    char book[40];
    char publishing[20];
    char num_les[6];
    char typebook[10];
    Type uni;  //union
} Common;

typedef struct{
    int index_main;
    int main_less;
} Keys;

Common table[MAX_LEN_TABLE];
Keys table_keys[MAX_LEN_TABLE];

void init(int *len_table, int *len_column, FILE *f);
int comparison(char *str, int len_column);
void print_table(int len_table, int *len_column);
void pop_table(int num, int *len_table);
void init_keys(int len_table);
void print_keys(int len_table);
void bubble_sort_keys(int len_table);
void print_order_table(int len_table, int *len_column);
void search_table(int len_table);
void timer(int len_table, FILE *fsort);
void bubble_sort_table(int len_table);
void quick_sort_keys(int b, int c);
void push_table(int *len_table, int *len_column);
void quick_sort_table(int l, int r);
void quick_timer(int len_table, FILE *quick_file);

#endif // TABLE_H
