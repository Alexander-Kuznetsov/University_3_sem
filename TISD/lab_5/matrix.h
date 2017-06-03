#ifndef MATRIX_H
#define MATRIX_H
//Пт 17.25 225
//Сб
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_LEN 1000

struct Node{
    int n;  // Размер списка
    struct Node *next;  // Указатель на следующий элемент
};

//typedef struct s_node node;
typedef struct{
    struct Node *first;  // Указатель на первый элемент
    struct Node *last;  // Указатель на последний элемент
} List;

typedef struct{
    int *A;  // Массив  ненулевых элементов
    int *IA;  // Массив номеров компонент в A и JA, с которых начинается описание строки N матрицы A
    List JA;   // Массив номеров столбцов для элементов вектора A
} Matrix;

//for standart Matrix:
void s_keyboard_matrix(int **matrix, int n, int m);
void s_print_matrix(int **matrix, int n, int m);
void s_print_file_matrix(FILE *f, int **matrix, int n, int m);
void s_sum_matrix(int **matrixS, int **matrixA, int **matrixB, int n, int m);
void s_file_matrix(FILE *f, int **matrix, int n, int m);
int generate_matrix(int **Matrix, int n, int m, int P);
int **create_matrix(int n, int m);
void free_matrix(int **data, int n);


void in_matrix(int **matrix, int n, int m, char key);
//for matrix on list:
void timer2();
void push_to_list(List *lst, int x);
void pop_from_list(List *lst);
void print_list(List *lst);
void print_list_in_file(FILE *f, List *lst);
void print_special_matrix_in_file (FILE *f, Matrix sp_matrix, int len, char key);
void print_special_matrix (Matrix sp_matrix, int len, char key);
Matrix* get_special_matrix(int **matrix, int n, int m, int k);
void timer();
void timer_1();
int count_unzero(int **matrix, int n, int m);
int calculate_sparse_matrix(Matrix *M1, Matrix *M2, Matrix *Result, int m);
#endif // MATRIX_H
