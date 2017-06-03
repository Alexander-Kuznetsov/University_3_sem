#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node{
    char *string;
    struct Node *pred;
    struct Node *right;
    struct Node *left;
};

void SearchInorder(FILE *f, struct Node *node, char ch, int *size);
struct Node *read_file(FILE *f);
struct Node *Insert(struct Node *node, struct Node *temp);
struct Node *find_max(struct Node *node);
struct Node *find_min(struct Node *node);
struct Node *search_node(struct Node *node, char *str);
struct Node *successor(struct Node *root);
struct Node *predecessor(struct Node *root);
struct Node *del_node(struct Node *node, struct Node *tmp);
void about_start();
void about_quest();
void about_tree();
void timer(struct Node *node);
void to_dot(struct Node *tree, FILE *f);
void print_dot(FILE *f, struct Node *tree);
void export_to_dot(FILE *f, struct Node *node);
void export_to_dot_color(FILE *f, FILE *data_search, struct Node *node);
void PrintInorder(FILE *out, struct Node *node);
void print_node(FILE *out, struct Node *node);
void add_in_tree(struct Node *root);
void free_node(struct Node *node);
void predeces(struct Node *node);
void succes(struct Node *node);
int input_key(int key1, int key2);

void InorderPR(FILE *out, struct Node *node);
void preorderPrint(FILE *out, struct Node *node);

#endif // BTREE_H
