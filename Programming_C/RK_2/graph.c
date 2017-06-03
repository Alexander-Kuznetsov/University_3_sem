#include "graph.h"

int find_leaf(Root_leaf *rleaf, int **A, int n){
    int k = 0, res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (A[i][j] == 0)
                k++;
        }
        if (k == n){
            rleaf[i].leaf = 1;
            res = 1;
        }
        k = 0;
    }
    return res;
}

int find_root(Node_graph *node, int **A, int n){
    int k = 0;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(A[i][j] && !(node[j].color)){
                node[j].color = 1;
                k++;
            }
        }
    }
    if (k == n) return 0;
    else return 1;
}

int cycle(Node_graph *nodes, Queue_arr *queue, int n, int **matrix){
    int key;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(matrix[i][j] == 1){
                nodes[i].color = 1;
                push_arr(queue, i);
                key = rec_cycle(nodes, queue, n, matrix, j);
                if (key)   return 1;
                clear_nodes(nodes, n);
                queue->size_data_arr = 0;
                queue->size_queue_arr = 0;
                free(queue);
                queue = create_queue_arr();
            }
        }
    }
    return 0;
}

int rec_cycle(Node_graph *nodes, Queue_arr *queue, int n, int **matrix, int key){
    nodes[key].color = 1;
    push_arr(queue, key);
    for (int i = 0; i < n; i++){
        if(matrix[key][i] == 1 && nodes[key].color == 1){
            if (nodes[i].color)    return 1;
            else  if (rec_cycle(nodes, queue, n, matrix, i)) return 1;
        }
    }
    nodes[key].color = 0;
    (queue->size_queue_arr)--;
    return 0;

}



Queue_arr *create_queue_arr(){
    Queue_arr *queue = (Queue_arr*) malloc(sizeof(Queue_arr)*1000); // выделение памяти под очередь

    queue->size_data_arr = 0;
    queue->size_queue_arr = 0;

    return queue;
}

void push_arr (Queue_arr *queue, int num){
  //  if (queue->size_queue_arr < queue->size_data_arr){
  //      queue[queue->size_queue_arr].data = num;
  //      (queue->size_queue_arr)++;
  //  }
   // else{
//        queue->size_data_arr = ((queue->size_data_arr+1)*2); // новая граница стенки
//        queue = realloc (queue, (sizeof(Queue_arr) * (queue->size_data_arr))); // подвинули стенку
//        queue[queue->size_queue_arr].data = num;
//        (queue->size_queue_arr)++;
   // }
    //queue->size_data_arr = ((queue->size_data_arr+1)*2); // новая граница стенки
    queue[queue->size_queue_arr].data = num;
    (queue->size_queue_arr)++;
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
    printf("%d ", nodes[a].num+1);
    for (int i = n ; i!=0 ; i--){
        if (nodes[i].color == 0 && A[nodes[a].num][i] == 1)
            DFS(nodes, n, A, i);
        if (i == 1){
            printf(" +%d+ ", nodes[a].num+1);
        }
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

void clear_rleaf(Root_leaf *rleaf, int n){
    for (int i = 0; i < n; i++){
        rleaf[i].root = 0;
        rleaf[i].leaf = 0;
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
