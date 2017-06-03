#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "input.h"
#include "table.h"

int main(int argc, char **argv) {
    int key, num_pop_str;
    int *len_column = (int*) calloc(LEN_HEAD, sizeof(int));
    int len_table = 0;
    FILE *f, *f2, *f3, *f4;
    //инициализация структуры
    if (argc < 2){
        fprintf(stdout,"Argument not found");
    }
    else{
        f = fopen(argv[1], "r");
        if (f == NULL){
            printf("file not exist!");
        }
        else{
            init(&len_table, len_column, f);
            init_keys(len_table);
            fclose(f);
            about(); //возвращает подсказку о возможных операциях
            while(1){
                key = input(0, 9); //input принимает количество значений about()
                switch(key){
                    case 1: //Вставка последней строки в таблицу
                        push_table(&len_table, len_column);
                        break;
                    case 2: //Удаление строки из таблицы
                        printf("input num str for POP:\n");
                        num_pop_str = input(1, len_table);
                        pop_table(num_pop_str, &len_table);
                        printf("string delete is good\n");
                        break;
                    case 3: //Сортировка и Печать таблицы ключей сортировки
                        //printf("Table of keys:\n");
                        //print_keys(len_table);
                        //quick_sort_keys(0, len_table-1);
                        bubble_sort_keys(len_table);
                        printf("BUBBLE Sort table of keys:\n");
                        printf("Ordered main table: \n");
                        print_order_table(len_table, len_column);
                        //print_keys(len_table);
                        break;
                    case 4: //Печать основной таблицы
                        print_table(len_table, len_column);
                        break;
                    case 5: //Упорядоченная основная таблица
                         f3 = fopen(argv[1], "r");
                         len_table = 0;
                         init(&len_table, len_column, f3);
                         init_keys(len_table);
                        fclose(f3);
                        break;
                    case 6: //Поиск по ключам в исходной таблице
                        search_table(len_table);
                        break;
                    case 7: //Время работы сортировки
                        len_table = 0;
                        f2 = fopen("SortTable.txt", "r");
                        init(&len_table, len_column, f2);
                        init_keys(len_table);
                        timer(len_table, f2);
                        fclose(f2);
                        //-----
                        len_table = 0;
                        f4 = fopen("SortTable.txt", "r");
                        init(&len_table, len_column, f4);
                        init_keys(len_table);
                        quick_timer(len_table, f4);
                        break;
                    case 8: //показать подсказку
                        about();
                        break;
                    case 9: //Печать основной таблицы
                        //bubble_sort_table(len_table);
                        quick_sort_table(0, len_table-1);
                        print_table(len_table, len_column);
                        break;
                    case 0: //выход
                        exit(0);
                        break;
                }
            }
        }
    }
    return 0;
}

