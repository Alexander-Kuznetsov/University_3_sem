#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

typedef struct{
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
}DataTree;

struct Node{
    DataTree *data;
    struct Node *pred;
    struct Node *right;
    struct Node *left;
};
void predeces(struct Node *node);
void succes(struct Node *node);

void about_tree();
struct Node *Insert(struct Node *node, struct Node *temp);
struct Node *load_file(FILE *f);
//Operation with input
int input_key(int key1, int key2);
int input_elem();
void add_in_tree(struct Node *root);
float input_elem_f();
struct Node* predecessor(struct Node *root);
struct Node* successor(struct Node *root);
struct Node *search_node(struct Node *node, int key);
void print_node(FILE *f, DataTree *datatree);
void PrintInorder(struct Node* node, FILE* out);
struct Node *find_max(struct Node *node);
struct Node *find_min(struct Node *node);
void to_dot(struct Node *tree, FILE *f);
void print_dot(FILE *f, struct Node *tree);
struct Node *del_node(struct Node *node, struct Node *tmp);
void free_node(struct Node *node);

void export_to_dot(FILE *f, struct Node *node);


#endif // BTREE_H
