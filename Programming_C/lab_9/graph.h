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


Queue_arr *create_queue_arr();
void push_arr (Queue_arr *queue, int num);
void pop_arr (Queue_arr *queue);
int **create_matrix(int n);
void BFS(int** A, Node_graph *nodes, int n, int a);
void print_matrix(int **matrix, int n);
void clear_nodes(Node_graph *nodes, int n);
void DFS(Node_graph *nodes, int n, int **A, int a);
void Top_sort(Node_graph *nodes, int n, int **A, int a, int *V, int num);


#endif // GRAPH_H
