#include "matrix.h"
#include "about.h"

void s_keyboard_matrix(int **matrix, int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = input_elem();
}

void s_print_matrix(int **matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
}

void s_print_file_matrix(FILE *f, int **matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            fprintf(f, "%4d", matrix[i][j]);
        fprintf(f,"\n");
    }
}

void s_sum_matrix(int **matrixS, int **matrixA, int **matrixB, int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matrixS[i][j] = matrixA[i][j] + matrixB[i][j];
}

void s_file_matrix(FILE *f, int **matrix, int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fscanf(f, "%d", &matrix[i][j]);
}

int generate_matrix(int **Matrix, int n, int m, int P){
    int d;
    int k = 0;

    if (P == 0){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                Matrix[i][j] = 0;
    }
    else{
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                d = rand() % 100 + 1;
                if (d <= P){
                    Matrix[i][j] = -15 + rand() % 16;
                    while (Matrix[i][j] == 0)
                        Matrix[i][j] = -15 + rand() % 16;
                }
                else
                    Matrix[i][j] = 0;
                if (Matrix[i][j] != 0)
                    k++;
            }
        }
    }
    return k;
}

void in_matrix(int **matrix, int n, int m, char key){
    int num = 0, I = 0, J = 0, elem = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = 0;
    printf("Number of PUSH elements in %c: ", key);
    num = input_key(1, n*m);
    for (int i = 0; i<num; i++){
        printf("Input I:");
        I = input_key(0, n-1);
        printf("Input J:");
        J = input_key(0, m-1);
        printf("Input elements:");
        elem = input_elem();
        matrix[I][J] = elem;
    }
}

int **create_matrix(int n, int m){
    int **data = calloc(n, sizeof(int*));
        if (!data)
            return NULL;

        for (int i = 0; i < n; i++){
            data[i] = malloc(m * sizeof(int));
            if (!data[i]){
                free_matrix(data, n);

                return NULL;
            }
        }

        return data;
}

void free_matrix(int **data, int n){
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}

