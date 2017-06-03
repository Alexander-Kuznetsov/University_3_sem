#include <stdio.h>
#include <stdlib.h>
#include "about.h"
#include "matrix.h"
#include <time.h>

int main(){
    int key_about = 0, key_action = 0, percent1 = 0, percent2 = 0;
    int **matrixA, **matrixB, **matrixS;
    int n, m, pr_file, k1_elem, k2_elem, len = 0;
 //   int numbA = 0, numbB = 0;
  //  int *AindI, *AindJ, *BindI, *BindJ, *elements;
    char letters[3] = {'A', 'B', 'S'};
    FILE *f_in, *f_out;
    Matrix* SmatrixA, *SmatrixB;
    Matrix *SmatrixS = malloc(sizeof(Matrix));

    srand(time(NULL));
    about_start();
    key_about = input_key(0, 4);

    switch(key_about){
        case 1:
            about_action();
            key_action = input_key(0, 4);
            switch(key_action){
                case 1:
                    f_in = fopen("Input.txt", "r");
                    fscanf(f_in, "%d", &n);
                    fscanf(f_in, "%d", &m);
                    if (n > 0 && n <= MAX_LEN && m > 0 && m <= MAX_LEN){
                        matrixA = create_matrix(n, m);
                        matrixB = create_matrix(n, m);
                        matrixS = create_matrix(n, m);
                        s_file_matrix(f_in, matrixA, n, m);
                        s_file_matrix(f_in, matrixB, n, m);
                        fclose(f_in);
                        s_sum_matrix(matrixS, matrixA, matrixB, n, m);
                        printf("Print in file? (1 - Yes; 0 - No)\n");
                        pr_file = input_key(0, 1);
                        if (pr_file){
                            f_out = fopen("Output.txt", "w");
                            fprintf(f_out, "Matrix A:\n");
                            s_print_file_matrix(f_out, matrixA, n, m);
                            fprintf(f_out, "Matrix B:\n");
                            s_print_file_matrix(f_out, matrixB, n, m);
                            fprintf(f_out, "Summa A + B:\n");
                            s_print_file_matrix(f_out, matrixS, n, m);
                            fclose(f_out);
                        }
                        else{
                            printf("Matrix A:\n");
                            s_print_matrix(matrixA, n, m);
                            printf("Matrix B:\n");
                            s_print_matrix(matrixB, n, m);
                            printf("Summa A + B:\n");
                            s_print_matrix(matrixS, n, m);
                        }
                        free_matrix(matrixA, n);
                        free_matrix(matrixB, n);
                        free_matrix(matrixS, n);
                    }
                    else{
                        printf("uncorrect size of matrix!");
                        exit(0);
                    }
                    break;
                case 2:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);
                    matrixS = create_matrix(n, m);
                    printf("--------------------------------------\n");
                    printf("Input elements to matrix A: \n");
                    s_keyboard_matrix(matrixA, n, m);
                    printf("--------------------------------------\n");
                    printf("Input elements to matrix B: \n");
                    s_keyboard_matrix(matrixB, n, m);
                    printf("--------------------------------------\n");
                    s_sum_matrix(matrixS, matrixA, matrixB, n, m);
                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "Summa A + B:\n");
                        s_print_file_matrix(f_out, matrixS, n, m);
                        fclose(f_out);
                    }
                    else{
                        printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);
                        printf("Summa A + B:\n");
                        s_print_matrix(matrixS, n, m);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    free_matrix(matrixS, n);
                    break;
                case 3:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);
                    matrixS = create_matrix(n, m);
                    printf("Input percent NON-zero elements for matrix A:");
                    percent1 = input_elem();
                    printf("Input percent NON-zero elements for matrix B:");
                    percent2 = input_elem();
                    generate_matrix(matrixA, n, m, percent1);
                    generate_matrix(matrixB, n, m, percent2);
                    s_sum_matrix(matrixS, matrixA, matrixB, n, m);
                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "Summa A + B:\n");
                        s_print_file_matrix(f_out, matrixS, n, m);
                        fclose(f_out);
                    }
                    else{
                        printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);
                        printf("Summa A + B:\n");
                        s_print_matrix(matrixS, n, m);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    free_matrix(matrixS, n);
                    break;
                case 4:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);

                    in_matrix(matrixA, n, m, letters[0]);
                    in_matrix(matrixB, n, m, letters[1]);

                    k1_elem = count_unzero(matrixA, n, m);
                    k2_elem = count_unzero(matrixB, n, m);
                    SmatrixA = get_special_matrix(matrixA, n, m, k1_elem);
                    SmatrixB = get_special_matrix(matrixB, n, m, k2_elem);
                    //-------------------
                    if ((k2_elem+k1_elem) < n*m)
                    {
                        SmatrixS->A = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                        SmatrixS->IA = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                    }
                    else
                    {
                        SmatrixS->A = (int *)calloc(n*m, sizeof(int));
                        SmatrixS->IA = (int *)calloc(n*m, sizeof(int));
                    }
                    SmatrixS->JA.last = 0;
                    SmatrixS->JA.first = 0;
                    //--------------------
                    len = calculate_sparse_matrix(SmatrixA, SmatrixB, SmatrixS, m);
                    SmatrixS->A = (int *)realloc(SmatrixS->A, len*sizeof(int));
                    SmatrixS->IA = (int *)realloc(SmatrixS->IA, len*sizeof(int));

                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "--------------------------------------\n");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "--------------------------------------\n");
                        print_special_matrix_in_file(f_out, *SmatrixA, k1_elem, letters[0]);
                        print_special_matrix_in_file(f_out, *SmatrixB, k2_elem, letters[1]);
                        print_special_matrix_in_file(f_out, *SmatrixS, len, letters[2]);
                        fclose(f_out);
                    }
                    else{
                        printf("--------------------------------------\n");
                    /*    printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);
                        printf("--------------------------------------\n");*/
                        print_special_matrix(*SmatrixA, k1_elem, letters[0]);
                        print_special_matrix(*SmatrixB, k2_elem, letters[1]);
                        print_special_matrix(*SmatrixS, len, letters[2]);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    break;
                default:
                    exit(0);
                    break;
            }
            break;
        case 2:
            about_action();
            key_action = input_key(0, 4);
            switch(key_action){
                case 1:
                    f_in = fopen("Input.txt", "r");
                    fscanf(f_in, "%d", &n);
                    fscanf(f_in, "%d", &m);
                    if (n > 0 && n <= MAX_LEN && m > 0 && m <= MAX_LEN){
                        matrixA = create_matrix(n, m);
                        matrixB = create_matrix(n, m);
                        s_file_matrix(f_in, matrixA, n, m);
                        s_file_matrix(f_in, matrixB, n, m);
                        fclose(f_in);
                        k1_elem = count_unzero(matrixA, n, m);
                        k2_elem = count_unzero(matrixB, n, m);
                        SmatrixA = get_special_matrix(matrixA, n, m, k1_elem);
                        SmatrixB = get_special_matrix(matrixB, n, m, k2_elem);
                        //-------------------
                        if ((k2_elem+k1_elem) < n*m)
                        {
                            SmatrixS->A = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                            SmatrixS->IA = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                        }
                        else
                        {
                            SmatrixS->A = (int *)calloc(n*m, sizeof(int));
                            SmatrixS->IA = (int *)calloc(n*m, sizeof(int));
                        }
                        SmatrixS->JA.last = 0;
                        SmatrixS->JA.first = 0;
                        //--------------------
                        len = calculate_sparse_matrix(SmatrixA, SmatrixB, SmatrixS, m);
                        SmatrixS->A = (int *)realloc(SmatrixS->A, len*sizeof(int));
                        SmatrixS->IA = (int *)realloc(SmatrixS->IA, len*sizeof(int));

                        printf("Print in file? (1 - Yes; 0 - No)\n");
                        pr_file = input_key(0, 1);
                        if (pr_file){
                            f_out = fopen("Output.txt", "w");
                            fprintf(f_out, "--------------------------------------\n");
                            fprintf(f_out, "Matrix A:\n");
                            s_print_file_matrix(f_out, matrixA, n, m);
                            fprintf(f_out, "Matrix B:\n");
                            s_print_file_matrix(f_out, matrixB, n, m);
                            fprintf(f_out, "--------------------------------------\n");
                            print_special_matrix_in_file(f_out, *SmatrixA, k1_elem, letters[0]);
                            print_special_matrix_in_file(f_out, *SmatrixB, k2_elem, letters[1]);
                            print_special_matrix_in_file(f_out, *SmatrixS, len, letters[2]);
                            fclose(f_out);
                        }
                        else{
                       /*     printf("--------------------------------------\n");
                            printf("Matrix A:\n");
                            s_print_matrix(matrixA, n, m);
                            printf("Matrix B:\n");
                            s_print_matrix(matrixB, n, m);*/
                            printf("--------------------------------------\n");
                            print_special_matrix(*SmatrixA, k1_elem, letters[0]);
                            print_special_matrix(*SmatrixB, k2_elem, letters[1]);
                            print_special_matrix(*SmatrixS, len, letters[2]);
                        }
                        free_matrix(matrixA, n);
                        free_matrix(matrixB, n);
                        free_matrix(matrixA, n);
                        free_matrix(matrixB, n);
                    }
                    else{
                        printf("uncorrect size of matrix!");
                        exit(0);
                    }
                    break;
                case 2:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);
                    printf("--------------------------------------\n");
                    printf("Input elements to matrix A: \n");
                    s_keyboard_matrix(matrixA, n, m);
                    printf("--------------------------------------\n");
                    printf("Input elements to matrix B: \n");
                    s_keyboard_matrix(matrixB, n, m);
                    printf("--------------------------------------\n");
                    k1_elem = count_unzero(matrixA, n, m);
                    k2_elem = count_unzero(matrixB, n, m);
                    SmatrixA = get_special_matrix(matrixA, n, m, k1_elem);
                    SmatrixB = get_special_matrix(matrixB, n, m, k2_elem);
                    //-------------------
                    if ((k2_elem+k1_elem) < n*m)
                    {
                        SmatrixS->A = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                        SmatrixS->IA = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                    }
                    else
                    {
                        SmatrixS->A = (int *)calloc(n*m, sizeof(int));
                        SmatrixS->IA = (int *)calloc(n*m, sizeof(int));
                    }
                    SmatrixS->JA.last = 0;
                    SmatrixS->JA.first = 0;
                    //--------------------
                    len = calculate_sparse_matrix(SmatrixA, SmatrixB, SmatrixS, m);
                    SmatrixS->A = (int *)realloc(SmatrixS->A, len*sizeof(int));
                    SmatrixS->IA = (int *)realloc(SmatrixS->IA, len*sizeof(int));

                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "--------------------------------------\n");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "--------------------------------------\n");
                        print_special_matrix_in_file(f_out, *SmatrixA, k1_elem, letters[0]);
                        print_special_matrix_in_file(f_out, *SmatrixB, k2_elem, letters[1]);
                        print_special_matrix_in_file(f_out, *SmatrixS, len, letters[2]);
                        fclose(f_out);
                    }
                    else{
                        printf("--------------------------------------\n");
                    /*    printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);
                        printf("--------------------------------------\n");*/
                        print_special_matrix(*SmatrixA, k1_elem, letters[0]);
                        print_special_matrix(*SmatrixB, k2_elem, letters[1]);
                        print_special_matrix(*SmatrixS, len, letters[2]);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    break;
                case 3:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);;
                    printf("Input percent NON-zero elements for matrix A:");
                    percent1 = input_key(0, 100);
                    printf("Input percent NON-zero elements for matrix B:");
                    percent2 = input_key(0, 100);

                    k1_elem = generate_matrix(matrixA, n, m, percent1);
                    k2_elem = generate_matrix(matrixB, n, m, percent2);

                    SmatrixA = get_special_matrix(matrixA, n, m, k1_elem);
                    SmatrixB = get_special_matrix(matrixB, n, m, k2_elem);
                    //-------------------
                    if ((k2_elem+k1_elem) < n*m)
                    {
                        SmatrixS->A = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                        SmatrixS->IA = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                    }
                    else
                    {
                        SmatrixS->A = (int *)calloc(n*m, sizeof(int));
                        SmatrixS->IA = (int *)calloc(n*m, sizeof(int));
                    }
                    SmatrixS->JA.last = 0;
                    SmatrixS->JA.first = 0;
                    //--------------------
                    len = calculate_sparse_matrix(SmatrixA, SmatrixB, SmatrixS, m);
                    SmatrixS->A = (int *)realloc(SmatrixS->A, len*sizeof(int));
                    SmatrixS->IA = (int *)realloc(SmatrixS->IA, len*sizeof(int));

                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "--------------------------------------\n");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "--------------------------------------\n");
                        print_special_matrix_in_file(f_out, *SmatrixA, k1_elem, letters[0]);
                        print_special_matrix_in_file(f_out, *SmatrixB, k2_elem, letters[1]);
                        print_special_matrix_in_file(f_out, *SmatrixS, len, letters[2]);
                        fclose(f_out);
                    }
                    else{
                     /*   printf("--------------------------------------\n");
                        printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);*/
                        printf("--------------------------------------\n");
                        print_special_matrix(*SmatrixA, k1_elem, letters[0]);
                        print_special_matrix(*SmatrixB, k2_elem, letters[1]);
                        print_special_matrix(*SmatrixS, len, letters[2]);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    break;
                case 4:
                    printf("MATRIX: N - height, M - width:\n");
                    printf("Input N: "); n = input_key(1, MAX_LEN);
                    printf("Input M: "); m = input_key(1, MAX_LEN);
                    matrixA = create_matrix(n, m);
                    matrixB = create_matrix(n, m);

                    in_matrix(matrixA, n, m, letters[0]);
                    in_matrix(matrixB, n, m, letters[1]);

                    k1_elem = count_unzero(matrixA, n, m);
                    k2_elem = count_unzero(matrixB, n, m);
                    SmatrixA = get_special_matrix(matrixA, n, m, k1_elem);
                    SmatrixB = get_special_matrix(matrixB, n, m, k2_elem);
                    //-------------------
                    if ((k2_elem+k1_elem) < n*m)
                    {
                        SmatrixS->A = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                        SmatrixS->IA = (int *)calloc(k2_elem+k1_elem, sizeof(int));
                    }
                    else
                    {
                        SmatrixS->A = (int *)calloc(n*m, sizeof(int));
                        SmatrixS->IA = (int *)calloc(n*m, sizeof(int));
                    }
                    SmatrixS->JA.last = 0;
                    SmatrixS->JA.first = 0;
                    //--------------------
                    len = calculate_sparse_matrix(SmatrixA, SmatrixB, SmatrixS, m);
                    SmatrixS->A = (int *)realloc(SmatrixS->A, len*sizeof(int));
                    SmatrixS->IA = (int *)realloc(SmatrixS->IA, len*sizeof(int));

                    printf("Print in file? (1 - Yes; 0 - No)\n");
                    pr_file = input_key(0, 1);
                    if (pr_file){
                        f_out = fopen("Output.txt", "w");
                        fprintf(f_out, "--------------------------------------\n");
                        fprintf(f_out, "Matrix A:\n");
                        s_print_file_matrix(f_out, matrixA, n, m);
                        fprintf(f_out, "Matrix B:\n");
                        s_print_file_matrix(f_out, matrixB, n, m);
                        fprintf(f_out, "--------------------------------------\n");
                        print_special_matrix_in_file(f_out, *SmatrixA, k1_elem, letters[0]);
                        print_special_matrix_in_file(f_out, *SmatrixB, k2_elem, letters[1]);
                        print_special_matrix_in_file(f_out, *SmatrixS, len, letters[2]);
                        fclose(f_out);
                    }
                    else{
                        printf("--------------------------------------\n");
                    /*    printf("Matrix A:\n");
                        s_print_matrix(matrixA, n, m);
                        printf("Matrix B:\n");
                        s_print_matrix(matrixB, n, m);
                        printf("--------------------------------------\n");*/
                        print_special_matrix(*SmatrixA, k1_elem, letters[0]);
                        print_special_matrix(*SmatrixB, k2_elem, letters[1]);
                        print_special_matrix(*SmatrixS, len, letters[2]);
                    }
                    free_matrix(matrixA, n);
                    free_matrix(matrixB, n);
                    break;
                default:
                    exit(0);
                    break;
            }
            break;
        case 3:
            timer();
            break;
        case 4:
            timer2();
            break;
        default:
            exit(0);
            break;
    }

    return 0;
}
