#ifndef PARSING_H
#define PARSING_H
#define MAX_LEN_TABLE 5000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
}SalesOrderDetail;

SalesOrderDetail table[MAX_LEN_TABLE];

int read(char *str, char *num);
int check_int(char *num, int len_str);
int check_double(char *num, int len_str);
int merge_sort_prodid(int l, int r);
int merge_sort_unitprice(int l, int r);
int merge_sort_order(int l, int r);
int input(int left, int key);
void print_table(int len_table);
void print_table_file(int len_table, FILE *f_out);
void about();

#endif // PARSING_H
