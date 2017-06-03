#include "dekstr.h"

int **create_matrix(int n){
    int **matrix = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;

    return matrix;
}

void print_matrix(int **matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%4d ", matrix[i][j]);
        printf("\n");
    }
}

void deikstr (int** A, Node_graph* nodes, int n, int a){
    int min;

    nodes[a].val = 0;
    nodes[a].color = 1;

    for (int i = 0; i < n; i++)
        if (A[a][i] != 0 && i != a)
            nodes[i].val = A[a][i];

    for (int i = 1; i < n; i++){
        min = minimum (nodes,n);
        if (min == INF)
            break;
        for (int j = 0; j < n; j++){
            if (A[min][j] + nodes[min].val < nodes[j].val)
                nodes[j].val = A[min][j] + nodes[min].val;
        }
        nodes[min].color = 1;
    }
}

int minimum (Node_graph* nodes, int n){
    int min = INF;
    int min_i = INF;

    for (int i = 0; i < n; i++){
        if (nodes[i].val < min && nodes[i].color == 0){
            min = nodes[i].val;
            min_i = i;
        }
    }

    return min_i;
}
