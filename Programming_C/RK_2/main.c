#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char **argv){
    FILE *f_in;
    int n, num, col;
    int **matrix;
    int i = 0, j = 0;

    f_in = fopen (argv[1], "r");
    fscanf(f_in, "%d", &n);

    Node_graph node[n];
    Root_leaf rleaf[n];
    Queue_arr *queue = create_queue_arr();

    matrix = create_matrix(n);
    while(!feof(f_in)){

        if (i == n || j == n)
            break;

        fscanf(f_in, "%d", &matrix[i][j]);

        j++;
        if (j == n){
            j = 0; i++;
        }
    }
    fclose(f_in);

    printf("Matrix:\n");
    print_matrix(matrix, n);
    clear_nodes(node, n);

    printf("\nleaf: ");
    clear_rleaf(rleaf, n);
    if(find_leaf(rleaf, matrix, n)){
        for (int i = 0; i < n; i++)
            if(rleaf[i].leaf)
                printf("%d ", i+1);
    }
    else printf("none");

    printf("\nroot: ");
    if(find_root(node, matrix, n)){
        for (int i = 0; i < n; i++){
            if (!node[i].color)
                printf("%d ", i+1);
        }
    }
    else printf("none");
    clear_nodes(node, n);

    if (cycle(node, queue, n, matrix))  {
        printf("\ndigraph is not acyclic: ");
        for (int i = 0; i <= queue->size_queue_arr; i++)
            printf("%d ", queue[i].data+1);
    }
    else printf("\ndigraph is acyclic");

    clear_nodes(node, n);
}
