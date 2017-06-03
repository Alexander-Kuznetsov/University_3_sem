#include "graph.h"

int func();

void pod(){
    printf("\n-----------------------------\n");
}

void about_start(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "-----------------------------",
           "!---------Start Menu---------!",
           "-----------------------------",
           "1 - Load Graph from file",
           "2 - Input Graph from STDIN",
           "0 - exit",
           "-----------------------------");
}

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

void deikstr (int** A, Node_graph *nodes, int n, int a){
    int max;

    nodes[a].val = 0;
    nodes[a].color = 1;

    for (int i = 0; i < n; i++)
        if (A[a][i] != 0 && i != a)
            nodes[i].val = A[a][i];

    for (int i = 1; i < n; i++){
        max = maximum(nodes, n);
        if (max == INF)
            break;
        for (int j = 0; j < n; j++){
            if (A[max][j] + nodes[max].val > nodes[j].val)
                nodes[j].val = A[max][j] + nodes[max].val;
        }
        nodes[max].color = 1;
    }
}

int maximum (Node_graph *nodes, int n){
    int max = INF;
    int max_i = INF;

    for (int i = 0; i < n; i++){
        if (nodes[i].val > max && nodes[i].color == 0){
            max = nodes[i].val;
            max_i = i;
        }
    }

    return max_i;
}

void export_to_dot(FILE *f, int **matrix, int n){
    fprintf(f, "digraph CITY_GRAPH {\n" );
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] != INF)
                fprintf(f, "%d -> %d[label=%d];\n", i, j, matrix[i][j]);
    fprintf(f, "}\n");
}

//Action with input!!!
int input_key(int key1, int key2){
    int result;

    printf(">> ");
    result = func();
    while (1){
        if (result >= key1 && result <= key2)
            break;
        else
        {
            printf("incorrect input, please return input...\n");
            printf(">> ");
            result = func();
        }
    }

    return result;
}

int func(){
    int result;

    while (scanf("%d",&result) != 1){
        while (getchar() != '\n');
        printf("incorrect input, please return input...\n");
        printf(">> ");
    }

    return result;
}
