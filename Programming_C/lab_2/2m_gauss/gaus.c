#include <math.h>
#include <malloc.h>
#include "functions.h"

double *Gaus_method(double **matrix, int n, int *len_roots)
{
    int i, j, max_i, p, temp = 0, b = 0, s = 0, d = 0;
    double max = 0, tmp = 0;
    double *roots;


    for (j = 0; j < (n); j++){
        //search a line with max element
        max_i = j;
        max = matrix[j][j];
        for (i = j + 1; i < n; i++){
            if (fabs(max) < fabs(matrix[i][j])){
                max_i = i;
                max = matrix[i][j];
            }
        }
        //error or shift columns
      /*  if (max < ZERO){
           return ZERO_COLUMN;
        }*/
        if(1){
            for (p = 0; p < n + 1; p++){
                tmp = matrix[j][p], matrix[j][p] = matrix[max_i][p], matrix[max_i][p] = tmp;
            }
            for (i = j; i < n; i++){
                tmp = matrix[i][j];
                if (fabs(tmp) < ZERO) continue; //next zero element
                for (p = 0; p < n + 1; p++){
                    matrix[i][p] /= tmp;
                }
                if (i == j) continue; //i!=j
                for (p = 0; p < n + 1; p++){
                    matrix[i][p] -= matrix[j][p];
                }
            }
        }
    }
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            if (fabs(matrix[i][j]) < ZERO)
                return ZERO_COLUMN;
    //liberation memory
    for (i = 0; i < n; i++)
    {
        b = 0;
        for (j = 0; j < n; j++)
            if (matrix[i][j] == 0)
                b++;
        if (b == n)
            temp++;
    }
    *len_roots = n - temp;
    roots = (double*) malloc(sizeof(double)*(*len_roots));
    //detect roots
    for (j = n - 1; j >= 0; j--){
        b = 0;
        roots[*len_roots-s-1] = matrix[j][n];
        if (fabs(matrix[j][n]) < ZERO && d <= temp)
        {
            b = 1;
            d++;
        }
        for (i = 0; i < n; i++){
            matrix[i][n] -= (matrix[i][j]*roots[*len_roots-s-1]);
        }
        if (b == 0)
            s++;
    }

    return roots;
}
