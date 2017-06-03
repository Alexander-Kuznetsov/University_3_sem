#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int num;
    int color; //0 - white //1 - black
}Node_graph;

typedef struct{
    int data;
    int size_queue_arr; // р-р массива
    int size_data_arr; // стенка
}Queue_arr;

typedef struct{
    int leaf;
    int root;
    int check_root;
    int check_leaf;
}Root_leaf;

Queue_arr *create_queue_arr();
void push_arr (Queue_arr *queue, int num);
void pop_arr (Queue_arr *queue);
int **create_matrix(int n);
void BFS(int** A, Node_graph *nodes, int n, int a);
void print_matrix(int **matrix, int n);
void clear_nodes(Node_graph *nodes, int n);
void DFS(Node_graph *nodes, int n, int **A, int a);
void Top_sort(Node_graph *nodes, int n, int **A, int a, int *V, int num);

int find_leaf(Root_leaf *rleaf, int **A, int n);
int find_root(Node_graph *node, int **A, int n);
int cycle(Node_graph *nodes, Queue_arr *queue, int n, int **matrix);
void clear_rleaf(Root_leaf *rleaf, int n);
int rec_cycle(Node_graph *nodes, Queue_arr *queue, int n, int **matrix, int key);
#endif // GRAPH_H
