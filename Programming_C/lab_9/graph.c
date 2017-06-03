#include "graph.h"

Queue_arr *create_queue_arr(){
    Queue_arr *queue = (Queue_arr*) malloc(sizeof(Queue_arr)); // выделение памяти под очередь

    queue->size_data_arr = 0;
    queue->size_queue_arr = 0;

    return queue;
}

void push_arr (Queue_arr *queue, int num){
    if (queue->size_queue_arr < queue->size_data_arr){
        queue[queue->size_queue_arr].data = num;
        (queue->size_queue_arr)++;
    }
    else{
        queue->size_data_arr = ((queue->size_data_arr+1)*2); // новая граница стенки
        queue = realloc (queue, (sizeof(Queue_arr) * (queue->size_data_arr))); // подвинули стенку
        queue[queue->size_queue_arr].data = num;
        (queue->size_queue_arr)++;
    }
}

void pop_arr (Queue_arr *queue){
    if (queue->size_queue_arr == 0){
        return;
    }
    else{
        for (int i = 1; i < queue->size_data_arr; i++)
            queue[i-1].data = queue[i].data;
        (queue->size_queue_arr)--;
    }
}

void BFS(int** A, Node_graph *nodes, int n, int a){
    Queue_arr *queue = create_queue_arr();
    int node;

    nodes[a].color = 1;
    push_arr(queue, a);

    for (int i = 0; i < n; i++){
        node = queue[0].data;
        printf("%d ", queue[0].data);
        pop_arr(queue);
        for (int j = 0; j < n; j++){
            if (nodes[j].color == 0 && A[node][nodes[j].num] == 1){
                push_arr(queue, j);
                nodes[j].color = 1;
            }
        }
    }
    free(queue);
}

void DFS(Node_graph *nodes, int n, int **A, int a){
    nodes[a].color = 1;
    printf("%d ", nodes[a].num);
    for (int i = n ; i!=0 ; i--){
        if (nodes[i].color == 0 && A[nodes[a].num][i] == 1)
             DFS(nodes, n, A, i);
    }
}

void Top_sort(Node_graph *nodes, int n, int **A, int a, int *V, int num){
    nodes[a].color = 1;
    V[num++] = nodes[a].num;
    for (int i = n ; i!=0 ; i--)
        if (nodes[i].color == 0 && A[nodes[a].num][i] == 1)
             Top_sort(nodes, n, A, i, V, num);
}

void clear_nodes(Node_graph *nodes, int n){
    for (int i = 0; i < n; i++){
        nodes[i].num = i;
        nodes[i].color = 0;
    }
}

int **create_matrix(int n){
    int **matrix = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;

    return matrix;
}

void print_matrix(int **matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
