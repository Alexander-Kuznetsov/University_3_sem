#include <stdio.h>
#include "functions.h"

void print(double **matrix, double *roots, int n, int len_roots)
{
    printf("-----------------------------------------\n");
    printf("Result:\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < (n + 1); j++){
            printf("%8.3lf", matrix[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
    printf("Roots:\n");
    if (len_roots == ZERO_COLUMN)
        printf("SLAU doesn`t have solution with method GAUSS!");
    else{
        for (int i = 0; i < len_roots; i++)
            printf("root[%d] = %8.3lf\n", i+1, roots[i]);
        printf("-----------------------------------------\n");
    }
}
