#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define INF -1

typedef struct{
    int num;
    int color;
    int val;
}Node_graph;

void about_start();
void print_matrix(int **matrix, int n);
int input_key(int key1, int key2);
int **create_matrix(int n);
void deikstr (int** A, Node_graph *nodes, int n, int a);
int maximum (Node_graph *nodes, int n);
void export_to_dot(FILE *f, int **matrix, int n);
void pod();

#endif // GRAPH_H
