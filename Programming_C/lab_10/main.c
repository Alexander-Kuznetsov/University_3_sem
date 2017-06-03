#include <stdio.h>
#include <stdlib.h>
#include "dekstr.h"

int main (int argc, char **argv){
    FILE *f;
    int n, num, col, val;
    int **A;

    printf("------------Dijkstra's algorithm----------\n\n");
    f = fopen (argv[1], "r");
    fscanf(f,"%d", &n);

    A = create_matrix(n);
    Node_graph nodes[n];

    while (!feof(f)){
        fscanf(f,"%d %d %d", &num, &col, &val);
        A[num][col] = val;
    }
    fclose(f);

    printf("Matrix:\n-----------\n");
    print_matrix(A, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (A[i][j] == 0)
                A[i][j] = INF;
    }
    for (int i = 0; i < n; i++){
        nodes[i].num = i;
        nodes[i].color = 0;
        nodes[i].val = INF;
    }
    deikstr(A, nodes, n, 0);

    printf("\nThe minimun disctance: \n-----------\n");
    for (int i = 0; i < n; i++){
        if (nodes[i].val == INF)
            printf("from %d to %d is - \n", nodes[0].num, nodes[i].num);
        else
            printf("from %d to %d is %d \n", nodes[0].num, nodes[i].num, nodes[i].val);
    }

    return 0;
}
