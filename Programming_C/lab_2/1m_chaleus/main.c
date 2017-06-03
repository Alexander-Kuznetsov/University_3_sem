#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "functions.h"

int main(void)
{
    double **matrix, *roots;
    int n, len_roots = 0;

    printf("Input a mount of elements the matrix: ");
    if ((scanf("%d", &n) == 1) && ((n >= 2) && (n <= 100))){
        matrix = (double**) malloc(n*sizeof(double));

        for(int i = 0; i < n; i++){
            matrix[i] = (double*) malloc((n+1)*sizeof(double));
            for(int j = 0; j < (n + 1); j++){
                printf("m[%d.%d] = ", i, j);
                scanf("%lf", &matrix[i][j]);
            }
        }
        roots = chal_method(matrix, n, &len_roots);
        print(matrix, roots, n, len_roots);
        //release memory
        free(roots);
        free(matrix);
    }
    else
        printf("data incorrect");

    return 0;
}
