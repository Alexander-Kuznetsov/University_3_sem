#include <stdio.h>
#include "graph.h"

#define SIZE_SHORT_INT 65535

int main(int argc, char **argv){
    int key_start, n, m, column, line, **matrix, vertex, min_val;
    unsigned short val;
    FILE *f, *f_dot;

    about_start();
    key_start = input_key(0, 2);

    if(key_start == 1){
        int dd = 0;

        f = fopen (argv[1], "r");
        fscanf(f,"%d", &n);
        matrix = create_matrix(n);
        Node_graph nodes[n];
        while (!feof(f)){
            fscanf(f,"%d %d %hd", &line, &column, &val);
            matrix[line][column] = val;
            matrix[column][line] = val;
        }
        fclose(f);

        pod();
        printf("Your matrix of graph:\n");
        print_matrix(matrix, n);
        pod();
        printf("Input Your Main City:\n");
        vertex = input_key(0, n-1);
        pod();
        printf("Input T weight: (0 < ? < short):\n");
        min_val = input_key(1, SIZE_SHORT_INT);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][j] = INF;
        }
        for (int i = 0; i < n; i++){
            nodes[i].num = i;
            nodes[i].color = 0;
            nodes[i].val = INF;
        }
        deikstr(matrix, nodes, n, vertex);

        pod();
        printf("FOUND City to main city: ");
        pod();
        for (int i = 0; i < n; i++){
            if (i != vertex && min_val < nodes[i].val){
                if (nodes[i].val == INF)
                    printf("from %d to %d discance is INF \n", nodes[i].num, nodes[vertex].num);
                else
                    printf("from %d to %d distance is %d \n", nodes[i].num, nodes[vertex].num, nodes[i].val);
                dd++;
            }
        }
        if(!dd)
            printf("zero!\n");
        else{
            f_dot = fopen("dot.gv", "w");
            printf("\n++++DOT file was created!++++\n");
            export_to_dot(f_dot, matrix, n);
            fclose(f_dot);
        }
    }
    else if(key_start == 2){
        int dd = 0;

        printf("Input amount of city the graph( > 1): \n");
        n = input_key(2, 100000);
        pod();
        printf("Input amount of the distance of the cities(min(1)):\n");
        m = input_key(1, SIZE_SHORT_INT);
        pod();
        matrix = create_matrix(n);
        Node_graph nodes[n];
        for(int i = 0; i < m; i++){
            printf("\nInput From(OUT) city (0 <= city < %d): \n", n);
            line = input_key(0, n-1);
            printf("\nInput To(IN) city (0 <= city < %d): \n", n);
            column = input_key(0, n-1);
            while(column == line){
                printf("ERROR: from city != in city, try again: \n");
                column = input_key(0, n-1);
            }
            printf("\ninput distance:(0 < distance < (short int)) \n");
            val = input_key(1, SIZE_SHORT_INT);
            matrix[line][column] = val;
            matrix[column][line] = val;
            pod();
        }

        pod();
        printf("Your matrix of graph:\n");
        print_matrix(matrix, n);
        pod();
        printf("Input Your Main City:\n");
        vertex = input_key(0, n-1);
        pod();
        printf("Input T weight: (0 < ? < short):\n");
        min_val = input_key(1, SIZE_SHORT_INT);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][j] = INF;
        }
        for (int i = 0; i < n; i++){
            nodes[i].num = i;
            nodes[i].color = 0;
            nodes[i].val = INF;
        }

        deikstr(matrix, nodes, n, vertex);
        pod();
        printf("FOUND City to main city: ");
        pod();
        for (int i = 0; i < n; i++){
            if (i != vertex && min_val < nodes[i].val){
                if (nodes[i].val == INF)
                    printf("from %d to %d discance is INF \n", nodes[i].num, nodes[vertex].num);
                else{
                    printf("from %d to %d distance is %d \n", nodes[i].num, nodes[vertex].num, nodes[i].val);
                    dd++;
                }
            }
        }
        if(!dd)
            printf("zero!\n");
        else{
            f_dot = fopen("dot.gv", "w");
            printf("\n++++++++++++DOT file was created!++++++++++++\n");
            export_to_dot(f_dot, matrix, n);
            fclose(f_dot);
        }
    }
    else
        exit(0);

    return 0;
}
