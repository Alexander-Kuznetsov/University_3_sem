#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsing.h"

int funccmp(const void * x1, const void * x2){
  return ( *(int*)x1 - *(int*)x2 );
}

void search(int size, int key, FILE *f_out){
    for (int i = 0; i < size; i++){
        if (table[i].ProductID == key){
            fprintf(f_out,"|%d\n",  table[i].SalesOrderID);
            fprintf(f_out,"|%d\n",  table[i].SalesOrderDetailID);
            fprintf(f_out,"|%d\n",  table[i].OrderQty);
            fprintf(f_out,"|%d\n",  table[i].ProductID);
            fprintf(f_out,"|%lf\n",  table[i].UnitPrice);
            fprintf(f_out,"|%lf\n",  table[i].UnitPriceDiscount);
            fprintf(f_out,"|%s\n", table[i].ModifiedDate);
            fprintf(f_out,"\n");
            return;
        }
    }

    printf("This ID %d NOT exist\n", key);
}

int main(int argc, char **argv){
    FILE *f, *f_out;
    int len_str = 0;
    int len_table = 0;
    int size = 0;


    if (argc != 2)
        printf("Argument not found!");
    else
    {    
        int i = 0;
        int key = 0;
        char str[80];
        char num[20];

        f = fopen(argv[1], "r");
        for (int i = 0; i < 2; i++){
            fgets(str,70,f);
        }
        while(!(feof(f))){
            str[0] = 0;
            fgets(str,70,f);
            len_str = read(str, num);
            key++;

            if (key>=1 && key <=4){
                if (check_int(num, len_str) == -1){
                    printf("Value incorrect!(int)");
                    exit(0);
                }
                else{
                    switch(key){
                        case 1:
                            table[i].SalesOrderID = atoi(num);
                            break;
                        case 2:
                            table[i].SalesOrderDetailID = atoi(num);
                            break;
                        case 3:
                            table[i].OrderQty = atoi(num);
                            break;
                        case 4:
                            table[i].ProductID = atoi(num);
                            break;
                    }
                }
            }
            else if (key>=5 && key <=6){
                if (check_double(num, len_str) == -1){
                    printf("Value incorrect!(double)");
                    exit(0);
                }
                else{
                    switch(key){
                        case 5:
                            table[i].UnitPrice = atof(num);
                            break;
                        case 6:
                            table[i].UnitPriceDiscount = atof(num);
                            break;
                    }
                }
            }
            else{
                size++;
                strcpy(table[i].ModifiedDate, num);
                for (int i = 0; i < 2; i++){
                    fgets(str,70,f);
                }
                key = 0;
                i++;
                len_table++;
            }
        }
        fclose(f);
        about();
        while(1){
            key = input(0, 5); //input принимает количество значений about()
            switch(key){
                case 1: //Сортировка ProductID
                    merge_sort_prodid(0, len_table-1);
                    break;
                case 2: //Сортировка UnitPrice
                    merge_sort_unitprice(0, len_table-1);
                    break;
                case 3: //Сортировка OrderQty
                    merge_sort_order(0, len_table-1);
                    break;
                case 4: //Вывод таблицы
                    f_out = fopen("Result.txt", "w");
                    print_table_file(len_table, f_out);
                    fclose(f_out);
                    break;
                case 5: //bsearch ProductId
                    printf("Input productID which you want search: \n(0...10000000)");
                    int key = input(0, 10000000);
                   // int * ptrItem = (int*) bsearch(&key, &(table->ProductID), len_table, sizeof (int), funccmp);
                    search(size, key, stdout);
                    break;
                case 0:
                    exit(0);
                    break;
            }
        }
    }
}
