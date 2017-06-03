#include "matrix.h"
#include "about.h"
//17.25  225
//12.00 513
//Add

void push_to_list(List *lst, int x){
    struct Node *node = malloc(sizeof(struct Node));

    node->n = x;
    node->next = 0;
    if ((lst->first == 0) && (lst->last == 0)){
        lst->last = node;
        lst->first = lst->last;
    }
    else{
        lst->last->next = node;
        lst->last = lst->last->next;
    }
}
void pop_from_list(List *lst){
    struct Node *temp;
    if (lst->first == 0){
        // lst->first->next = 0;
         lst->last = 0;
         return;
    }

    temp = lst->first;
    lst->first = lst->first->next;
    temp->next = NULL;
    free(temp);
}

// Delete
/*void pop_from_list(List *lst){
    struct Node *temp;

    temp = lst->first;
    lst->first = lst->first->next;
    if (lst->first == 0)
        lst->last = 0;
    free(temp);
}
*/
// Print
void print_list(List *lst){
    struct Node *h;
  //  for(h = lst->first; h != NULL; h = h->next)
   //     printf("%5d ", h->n);
    int i = 0, t = 0;

    printf("| J element in matrix |");
    for(h = lst->first; h != lst->last; h = h->next)
    {
        if (h->n != h->next->n)
        {
            printf("%5d |", i);
            t++;
        }
        i++;
    }

    printf("\n--------------------------");
    for (int j = 0; j < t; j++)
        printf("-------");
    printf("\n| Element  in  List   |");

    for(h = lst->first; h != lst->last; h = h->next)
    {
        if (h->n != h->next->n)
            printf("%5d |", h->n);
    }
    printf("\n");
}

// Print in file
void print_list_in_file(FILE *f, List *lst){
    struct Node *h;
    int i = 0, t = 0;

    fprintf(f, "| J element in matrix |");
    for(h = lst->first; h != lst->last; h = h->next)
    {
        if (h->n != h->next->n)
        {
            fprintf(f, "%5d |", i);
            t++;
        }
        i++;
    }

    fprintf(f, "\n--------------------------");
    for (int j = 0; j < t; j++)
        printf("-------");
    fprintf(f, "\n| Element  in  List   |");

    for(h = lst->first; h != lst->last; h = h->next)
    {
        if (h->n != h->next->n)
            fprintf(f, "%5d |", h->n);
    }
    fprintf(f, "\n");
}

//print special matrix
void print_special_matrix (Matrix sp_matrix, int len, char key){
    if (len){
        printf("--------------------------------------\n");
        printf("%c:\n", key);
        for (int i = 0; i < len; i++){
            printf("%5d ", sp_matrix.A[i]);
            if ((i+1) % 10 == 0 && (i != len-1))
                printf("\n");
        }

        printf("\nI%c:\n", key);
        for (int i = 0; i < len; i++){
            printf("%5d ", sp_matrix.IA[i]);
            if (((i+1) % 10 == 0) && (i != len-1))
                printf("\n");
        }

        printf("\nJ%c:\n", key);
        print_list(&sp_matrix.JA);
    }
    else{
        printf("\n\n%c is empty!", key);
        printf("\nJ%c is empty!", key);
        printf("\nI%c is empty!", key);
    }
    printf("\n");
    printf("--------------------------------------\n");
}

//print special matrix in file
void print_special_matrix_in_file (FILE *f, Matrix sp_matrix, int len, char key){
    if (len){
        fprintf(f, "--------------------------------------\n");
        fprintf(f, "%c:\n", key);
        for (int i = 0; i < len; i++){
            fprintf(f, "%5d ", sp_matrix.A[i]);
            if ((i+1) % 100 == 0 && (i != len-1))
                fprintf(f, "\n");
        }

        fprintf(f, "\nI%c:\n\n", key);
        for (int i = 0; i < len; i++){
            fprintf(f, "%5d ", sp_matrix.IA[i]);
            if (((i+1) % 100 == 0) && (i != len-1))
                fprintf(f, "\n");
        }

        fprintf(f, "\nJ%c:\n\n", key);
        print_list_in_file(f, &sp_matrix.JA);
    }
    else
    {
        fprintf(f, "\n%c is empty!", key);
        fprintf(f, "\nJ%c is empty!", key);
        fprintf(f, "\nI%c is empty!", key);
    }
    fprintf(f, "\n");
    fprintf(f, "--------------------------------------\n");
}

int calculate_sparse_matrix(Matrix *M1, Matrix *M2, Matrix *Result, int m)
{
    int len = 0;
    int count;
    int *Buff_A;
    int *Buff_IA;
    int *toggle;

    struct Node *h1;
    struct Node *h2;
    for (h1= M1->JA.first, h2 = M2->JA.first; h1->next != 0; h1 = h1->next, h2 = h2->next)
    {
        toggle = (int *)calloc(m, sizeof(int));
        Buff_A = (int *)calloc(m, sizeof(int));
        Buff_IA = (int *)calloc(m, sizeof(int));
        count = 0;

        for (int i = h1->n; i < h1->next->n; i++)
        {
            Buff_A[count] = M1->A[i];
            Buff_IA[count] = M1->IA[i];
            count++;
            toggle[M1->IA[i]] = count;
        }

        for (int i = h2->n; i < h2->next->n; i++)
        {
            int ind = M2->IA[i];
            if (toggle[ind])
                Buff_A[toggle[ind]-1] += M2->A[i];

            else
            {
                Buff_IA[count] = ind;
                Buff_A[count] = M2->A[i];
                count++;
            }
        }

        push_to_list(&Result->JA, len);

        for (int i = 0; i < count; i++)
        {
            if (Buff_A[i])
            {
                Result->A[len] = Buff_A[i];
                Result->IA[len] = Buff_IA[i];
                len++;
            }
        }

        free(Buff_A);
        free(Buff_IA);
        free(toggle);
    }

    push_to_list(&Result->JA, len);
    return len;
}

// Sparse from normal
Matrix* get_special_matrix(int **matrix, int n, int m, int k){
    Matrix *M = malloc(sizeof(Matrix));
    M->A = malloc(sizeof(int)*k);
    M->IA = malloc(sizeof(int)*k);
    M->JA.last = 0;
    M->JA.first = 0;
    int l = 0;

    for (int j = 0; j < m; j++){
        push_to_list(&M->JA, l);
        for (int i = 0; i < n; i++){
            if (matrix[i][j] != 0){
                M->A[l] = matrix[i][j];
                M->IA[l] = i;
                l++;
            }
        }
    }
    push_to_list(&M->JA, l);

    return M;
}

int count_unzero(int **matrix, int n, int m){
    int result = 0;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if (matrix[i][j] != 0)
                result++;
    return result;
}

void timer(){
    int k1, k2;
    int n = 1000; int m = 1000;

    int **Matrix1, **Matrix2, **Result;

    Matrix1 = create_matrix(n, m);
    Matrix2 = create_matrix(n, m);
    Result = create_matrix(n, m);


    Matrix *M1, *M2;
    Matrix *Result_s = malloc(sizeof(Matrix));
    float begin1 = 0, end1 = 0;
    float begin2 = 0, end2 = 0;
    //float memory;

    int P[11] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int i = 0; i < 11; i++){
        begin1=0; end1=0; begin2=0; end2=0;
        for (int j = 0; j < 10; j++){
            k1 = generate_matrix(Matrix1, n, m, P[i]);
            k2 = generate_matrix(Matrix2, n, m, P[i]);

            begin1 += clock()/(float)CLOCKS_PER_SEC;
            s_sum_matrix(Result, Matrix1, Matrix2, n, m);
            end1 += clock()/(float)CLOCKS_PER_SEC;

            M1 = get_special_matrix(Matrix1, n, m, k1);
            M2 = get_special_matrix(Matrix2, n, m, k2);

            if ((k2+k1) < n*m){
                Result_s->A = (int *)calloc(k2+k1, sizeof(int));
                Result_s->IA = (int *)calloc(k2+k1, sizeof(int));
            }
            else{
                Result_s->A = (int *)calloc(n*m, sizeof(int));
                Result_s->IA = (int *)calloc(n*m, sizeof(int));
            }

            Result_s->JA.first = 0;
            Result_s->JA.last = 0;

            begin2 += clock()/(float)CLOCKS_PER_SEC;
            calculate_sparse_matrix(M1, M2, Result_s, m);
            end2 += clock()/(float)CLOCKS_PER_SEC;

            for (int i = 0; i < n; i++){
                pop_from_list(&Result_s->JA);
                pop_from_list(&M1->JA);
                pop_from_list(&M2->JA);
            }

            free(Result_s->A);
            free(Result_s->IA);
            free(M1->A);
            free(M1->IA);
            free(M2->A);
            free(M2->IA);
            free(M1);
            free(M2);
           // for (int i = 0; i < n; i++) free(Result[i]);
            free(Result);
        }
        printf("-----------------------------------------------\n");
        printf("Percent NON-zero elemens matrix: %d\n", P[i]);
        printf("Time to sum with normal   method (ms): %0.2f\n", \
               (float)(end1 - begin1)*100);
        printf("Time to sum special(list) method (ms): %0.2f\n", \
               (float)(end2 - begin2)*100);
        printf("-----------------------------------------------\n");
    }
    free(Result_s);
    free_matrix(Matrix1, n);
    free_matrix(Matrix2, n);
}
void timer2(){
    int k1, k2;
    //int n = 1000; int m = 1000;

    int **Matrix1, **Matrix2, **Result;




    Matrix *M1, *M2;

    float begin1 = 0, end1 = 0;
    float begin2 = 0, end2 = 0;
    //float memory;

    int P[11] = {10, 50, 100, 200, 400, 800, 1000};

    for (int i = 0; i < 7; i++){


        begin1=0; end1=0; begin2=0; end2=0;
        for (int j = 0; j < 10; j++){
            Matrix *Result_s = malloc(sizeof(Matrix));
            Matrix1 = create_matrix(P[i], P[i]);
            Matrix2 = create_matrix(P[i], P[i]);
             Result = create_matrix(P[i], P[i]);
            k1 = generate_matrix(Matrix1, P[i], P[i], 50);
            k2 = generate_matrix(Matrix2, P[i], P[i], 50);

            begin1 += clock()/(float)CLOCKS_PER_SEC;
            s_sum_matrix(Result, Matrix1, Matrix2, P[i], P[i]);
            end1 += clock()/(float)CLOCKS_PER_SEC;

            M1 = get_special_matrix(Matrix1,  P[i],  P[i], k1);
            M2 = get_special_matrix(Matrix2,  P[i],  P[i], k2);

            if ((k2+k1) <  P[i]* P[i]){
                Result_s->A = (int *)calloc(k2+k1, sizeof(int));
                Result_s->IA = (int *)calloc(k2+k1, sizeof(int));
            }
            else{
                Result_s->A = (int *)calloc( P[i]* P[i], sizeof(int));
                Result_s->IA = (int *)calloc( P[i]* P[i], sizeof(int));
            }

            Result_s->JA.first = 0;
            Result_s->JA.last = 0;

            begin2 += clock()/(float)CLOCKS_PER_SEC;
            calculate_sparse_matrix(M1, M2, Result_s,  P[i]);
            end2 += clock()/(float)CLOCKS_PER_SEC;

            for (int i = 0; i <  P[i]; i++){
                pop_from_list(&Result_s->JA);
                pop_from_list(&M1->JA);
                pop_from_list(&M2->JA);
            }

            free(Result_s->A);
            free(Result_s->IA);
            free(M1->A);
            free(M1->IA);
            free(M2->A);
            free(M2->IA);
            free(M1);
            free(M2);
           // for (int i = 0; i < n; i++) free(Result[i]);
            free(Result);
            free(Result_s);
            free_matrix(Matrix1, P[i]);
            free_matrix(Matrix2, P[i]);
        }
        printf("-----------------------------------------------\n");
        printf("Percent NON-zero elemens matrix: 50%% and matrix %dx%d\n", P[i], P[i]);
        printf("Time to sum with normal   method (ms): %0.2f\n", \
               (float)(end1 - begin1)*100);
        printf("Time to sum special(list) method (ms): %0.2f\n", \
               (float)(end2 - begin2)*100);
        printf("-----------------------------------------------\n");
    }

}

/*void timer_1(){
    int k1, k2;
    float begin1 = 0, end1 = 0, begin2 = 0, end2 = 0;
    int **Matrix1, **Matrix2, **Result;
    Matrix *M1, *M2;
    int P[7] = {10, 50, 100, 200, 400, 800, 1000};
    for (int i = 0; i < 7; i++){
       Matrix1 = create_matrix(P[i], P[i]);
       Matrix2 = create_matrix(P[i])
    }
} */

/*void timer_1(){
    int k1, k2, tmp;
    int **Matrix1, **Matrix2, **Result;
    Matrix *M1, *M2;

    float begin1 = 0, end1 = 0, begin2 = 0, end2 = 0;
    int P[7] = {1000, 50, 100, 200, 400, 800, 1000};

    for (int i = 0; i < 1; i++){
        Matrix1 = create_matrix(P[i], P[i]);
        Matrix2 = create_matrix(P[i], P[i]);
        Result = create_matrix(P[i], P[i]);

        begin1=0; end1=0; begin2=0; end2=0;
        for (int j = 0; j < 10; j++){
            Matrix *Result_s = malloc(sizeof(Matrix));
            Matrix1 = create_matrix(P[i], P[i]);
            Matrix2 = create_matrix(P[i], P[i]);

            Result = create_matrix(P[i], P[i]);
            k1 = generate_matrix(Matrix1, P[i], P[i], 50);
            k2 = generate_matrix(Matrix2, P[i], P[i], 50);
            printf("K1 %d\n", k1);
            printf("K2 %d\n", k2);

            begin1 += clock()/(float)CLOCKS_PER_SEC;
            s_sum_matrix(Result, Matrix1, Matrix2, P[i], P[i]);
            end1 += clock()/(float)CLOCKS_PER_SEC;

            M1 = get_special_matrix(Matrix1, P[i], P[i], k1);
            M2 = get_special_matrix(Matrix2, P[i], P[i], k2);


            if ((k2+k1) < P[i]*P[i]){
                tmp = k2+k1;
                Result_s->A = (int *)calloc(k2+k1, sizeof(int));
                Result_s->IA = (int *)calloc(k2+k1, sizeof(int));
            }
            else{
                tmp = P[i]*P[i];
                Result_s->A = (int *)calloc(P[i]*P[i], sizeof(int));
                Result_s->IA = (int *)calloc(P[i]*P[i], sizeof(int));
            }

            Result_s->JA.first = 0;
            Result_s->JA.last = 0;

            begin2 += clock()/(float)CLOCKS_PER_SEC;
            calculate_sparse_matrix(M1, M2, Result_s, tmp);
            end2 += clock()/(float)CLOCKS_PER_SEC;

            for (int kk = 0; kk < k1-1; kk++){
                 pop_from_list(&M1->JA);
            }
            for (int kk = 0; kk < k2-1; kk++){
                 pop_from_list(&M2->JA);
            }
            for (int kk = 0; kk < tmp-1; kk++){
                pop_from_list(&Result_s->JA);
            }

            free(Result_s->A);
            free(Result_s->IA);
            free(M1->A);
            free(M1->IA);
            free(Result_s);
            free(M2->A);
            free(M2->IA);
            free(M1);
            free(M2);
          //  for (int kk = 0; kk < P[i]; kk++) free(Result[kk]);
            free(Result);
        }
        printf("-----------------------------------------------\n");
        printf("Percent NON-zero elemens matrix: 50%% and matrix %dx%d\n", P[i], P[i]);
        printf("Time to sum with normal   method (ms): %0.2f\n", \
               (float)(end1 - begin1)*100);
        printf("Time to sum special(list) method (ms): %0.2f\n", \
               (float)(end2 - begin2)*100);
        printf("-----------------------------------------------\n");

        free_matrix(Matrix1, P[i]);
        free_matrix(Matrix2, P[i]);
    }

}*/
