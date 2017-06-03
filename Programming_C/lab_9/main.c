#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char **argv){
    FILE *f_in;
    int n, num, col;
    int **matrix;

    f_in = fopen (argv[1], "r");
    fscanf(f_in, "%d", &n);

    Node_graph node[n];
    int V[n];

    matrix = create_matrix(n);
    while(!feof(f_in)){
        fscanf(f_in, "%d%d", &num, &col);
        matrix[num][col] = 1;
    }
    fclose(f_in);

    printf("Matrix:\n");
    print_matrix(matrix, n);
    clear_nodes(node, n);

    printf("------\nBFS:\n");
    BFS(matrix, node, n, 0);
    clear_nodes(node, n);

    printf("\n------\nDFS:\n");
    DFS(node, n, matrix, 0);
    clear_nodes(node, n);

    printf("\n------\nTop_sort:\n"); // через массив
    Top_sort(node, n, matrix, 0, V, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
