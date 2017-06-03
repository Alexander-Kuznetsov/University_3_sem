#include <math.h>
#include <malloc.h>
#include <stdio.h>
#include "functions.h"

double *chal_method(double **matrix, int n, int *len_roots)
{
    int i, j, p, temp = 0, s = 0, d = 0;
    double tmp = 0, *x, *y, **matrix1, **matrix2;

    x = (double*) malloc(n*sizeof(double));
    y = (double*) malloc(n*sizeof(double)); 
    matrix1 = (double**) malloc((n)*sizeof(double));
    matrix2 = (double**) malloc((n)*sizeof(double));
    for(i = 0; i < n; i++){
        matrix1[i] = (double*) malloc((n)*sizeof(double)), matrix2[i] = (double*) malloc((n)*sizeof(double));
        for(j = 0; j < (n); j++){
            matrix1[i][j] = 0, matrix2[i][j] = 0;
        }
    }
    *len_roots = n;
    //form matrix A and B
    for (i = 0; i < n; i++){
        matrix1[i][0] = matrix[i][0];

        for (j = 1; j <= i; j++){
            tmp = 0;
            if (i < j) d = i;
            if (j <= i) d = j;
            for (p = 0; p < d; p++){
                tmp+= matrix1[i][p]*matrix2[p][j];
            }
            matrix1[i][j] = matrix[i][j] - tmp;
        }
        for (j = i; j < n; j++){
            if (matrix1[i][i] == 0)
                return ZERO_COLUMN;
            if (i == 0)
                matrix2[i][j] = matrix[i][j]/matrix1[i][0];
            else{
                if (j == i)
                    matrix2[i][j] = matrix1[i][j]/matrix1[i][i];
                else
                {
                    tmp = 0;
                    if (i < j) d = i;
                    if (j <= i) d = j;
                    for (p = 0; p < d; p++){
                        tmp+= matrix1[i][p]*matrix2[p][j];
                    }
                    matrix2[i][j] = (matrix[i][j]-tmp)/matrix1[i][i];
                }
            }
        }
    }
    //y
    for (i = 0; i < n; i++){
        if (i == 0)
            y[i] = matrix[i][n]/matrix[i][i];
        else{
            tmp = 0;
            for (j = 0; j < i; j++){
                tmp+=y[j]*matrix1[i][j];
            }
            y[i] = (matrix[i][n]-tmp)/matrix1[i][i];
        }
    }
    //x
    for (i = n-1; i>=0; i--){
        if ((n-1) == i)
            x[i] = y[i];
        else{
            tmp = 0;
            temp = 0;
            for (j = i+1; j < n; j++){
                tmp+=x[j]*matrix2[i][n-1-s+temp];
                temp++;
            }
            s++;
            x[i] = y[i]-tmp;
        }
    }
/*
    //printf matrix B and C
    printf("-----------------------------------------\n");
    printf("Result:\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < (n); j++){
            printf("%8.3lf", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");
    printf("Result:\n");
    for (int i = 0; i < n; i++){
        for(int j = 0; j < (n); j++){
            printf("%8.3lf", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
*/
    free(matrix1), free(matrix2), free(y);
    return x;
}
