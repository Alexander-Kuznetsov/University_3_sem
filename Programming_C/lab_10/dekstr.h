#ifndef DEKSTR_H
#define DEKSTR_H

#include <stdio.h>
#include <stdlib.h>

#define INF 10000

typedef struct{
    int num;
    int color;
    int val;
}Node_graph;

void deikstr (int** A, Node_graph* nodes, int n, int a);
int minimum (Node_graph* nodes, int n);
int **create_matrix(int n);
void print_matrix(int **matrix, int n);

#endif // DEKSTR_H
