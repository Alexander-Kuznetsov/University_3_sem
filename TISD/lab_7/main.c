#include "methods.h"

int main(){
    FILE *f, *f_dot;
    tree *tr = (tree*)malloc(sizeof(tree));
    init_tree(tr);
    node *temp = (node*)malloc(sizeof(node));
    Hash_row **open_hashtable;
    Hash_row **closed_hashtable;
    int err = OK, check = 0, n_open, n_closed, check_rep, check_balance = 0, choice = -1, hashidx, count = 0;
    double time, time_start, time_finish;
    char keyword[20];

    f = fopen("Input.txt", "r");
    if(!f){
        printf("File not exist!\n");
        err = ERR_NO_FILE;
    }
    else{
        printf("Amount of cells Hash_Table(Open)  >> ");
        scanf("%d", &n_open);
        printf("Amount of cells Hash_Table(Close) >> ");
        scanf("%d", &n_closed);
        if(n_open <= 0 || n_closed <= 0){
            printf("Cells == 0!\n");
            choice = 0;
            err = ERR_INPUT;
        }
        else{
            open_hashtable = init_hash(n_open);
            closed_hashtable = init_hash(n_closed);         
            while(fscanf(f, "%s\n", temp->keyword) == 1){
                fgets(temp->HELP, 1000, f);
                check_rep = add(tr, temp);
                if(!check_rep){
                    add_open_hash(open_hashtable, temp, n_open);
                    err = add_closed_hash(closed_hashtable, temp, n_closed);
                    if(err == ERR_INPUT){
                        choice = 7;
                        printf("%s", "Close Hash_Table don`t have place!\n");
                        return 0;//break;
                    }
                }
                check = 1;
            }
            fclose(f);
            if(!check){
                printf("File is empty.\n");
                err = ERR_FILE_EMPTY;
            }
            else{
               about_action();
               while(choice){
                   if(err == OK){
                       choice = 0;   
                       scanf("%d", &choice);
                   }         
                   switch(choice){
                       case 1://+
                           f = fopen("Input.txt", "a");
                           printf("%s", "Input keyword: ");
                           scanf("%s", temp->keyword);
                           printf("%s", "Press HELP: \n");
                           fflush(stdin);
                           gets(temp->HELP);
                           check_rep = add(tr, temp);
                           if(!check_rep){
                               add_open_hash(open_hashtable, temp, n_open);
                               err = add_closed_hash(closed_hashtable, temp, n_closed);
                               if(err == ERR_INPUT){
                                   choice = 7;
                                   printf("%s", "Close Hash-Table do not have a place, return your Hash_Table.\n");
                                   break;
                               }
                               fprintf(f, "%s\n", temp->keyword);
                               fprintf(f, "%s\n", temp->HELP);
                           }
                           fclose(f);
                           check_balance = 0;
                       break;
                       case 2://+
                           printf("%s", "Press KeyWord >> ");
                           scanf("%s", keyword);
                           err = delete_keyword(tr, keyword);
                           if(err == ERR_DELETE){
                               printf("This keyword not exist!\n");
                               err = OK;
                               continue;
                           }
                           else
                               printf("Keyword was delete(good).\n");
                           delete_open_hash(open_hashtable, keyword, n_open);
                           //printf("The keyword has been removed from the open hash-table.\n");
                           delete_closed_hash(closed_hashtable, keyword, n_closed);
                           //printf("The keyword has been removed from the closed hash-table.\n");
                           pod();
                       break;
                       case 3://+
                           printf("%s", "BinarTree(PreOrder):\n");
                           print_tree(tr->root);
                           f_dot = fopen("DOT.gv", "w");
                           export_to_dot(f_dot, tr->root);
                           fclose(f_dot);
                           printf("+++++++++++++DOT was created++++++++++\n");
                           pod();
                       break;
                       case 4://+
                           printf("%s", "Hash-Table(Open):\n");
                           print_hashtable(open_hashtable, n_open);
                           pod();
                       break;
                       case 5://+
                           printf("%s", "Hash-Table(Close):\n");
                           print_hashtable(closed_hashtable, n_closed);
                           pod();
                       break;
                       case 6://+-
                           get_balanced_tree(tr);
                           check_balance = 1;
                           printf("%s", "Good!\n");
                       break;
                       case 7://+
                           init_tree(tr);
                           printf("Amount of cells Hash_Table(Open)  >> ");
                           scanf("%d", &n_open);
                           printf("Amount of cells Hash_Table(Close)  >> ");
                           scanf("%d", &n_closed);
                           if(n_open <= 0 || n_closed <= 0){
                               printf("Cells == 0!\n");
                               choice = 0;
                               err = ERR_INPUT;
                           }
                           else{
                               open_hashtable = init_hash(n_open);
                               closed_hashtable = init_hash(n_closed);
                               f = fopen("Input.txt", "r");
                               while(fscanf(f, "%s\n", temp->keyword) == 1){
                                   fgets(temp->HELP, 1000, f);
                                   check_rep = add(tr, temp);
                                   if(!check_rep){
                                       add_open_hash(open_hashtable, temp, n_open);
                                       err = add_closed_hash(closed_hashtable, temp, n_closed);
                                       if(err == ERR_INPUT){
                                           choice = 7;
                                           printf("%s", "Close Hash_Table don`t have place!\n");
                                           return 0;//break;
                                       }
                                   }
                                   check = 1;
                               }
                               fclose(f);
                               if(check_balance)
                                   get_balanced_tree(tr);
                           }
                           pod();
                       break;
                       case 8://+
                           printf("\n%s", "Input string: ");
                           scanf("%s", keyword);
                           count = 0;
                           temp = search(tr, keyword, &count, 0);
                           pod();
                       break;
                       case 9://+
                           printf("\n%s", "Input string: ");
                           scanf("%s", keyword);
                           printf("Hash index of the keyword(Open):  %d\n", hash(keyword, n_open));
                           count = 0;
                           open_hash_search(open_hashtable[hash(keyword, n_open)], keyword, n_open, &count, 0);
                           pod();
                       break;
                       case 10://+
                           printf("\n%s", "Input string: ");
                           scanf("%s", keyword);
                           printf("Hash index of the keyword(Сlose): %d\n", hash(keyword, n_closed));
                           count = 0;
                           closed_hash_search(closed_hashtable, keyword, n_closed, &count, 0);
                           pod();
                       break;
                       case 11://+
                           //printf("%s", "Input a keyword: ");
                           //scanf("%s", keyword);
                           printf("Word is INT\n");
                           time_start = clock();
                           for(int i = 0; i < 2000000; i++){
                               count = 0;
                               temp = search(tr, "int", &count, 1);
                           }
                           time_finish = clock();
                           time = (time_finish - time_start)/CLOCKS_PER_SEC;
                           printf("Time searches in BinarTree(ms): %f\n", time);
                           printf("Amount of comparisons: %d\n\n", count);

                           time_start = clock();
                           for(int i = 0; i < 2000000; i++){
                               count = 0;
                               open_hash_search(open_hashtable[hash("int", n_open)], "int", n_open, &count, 1);
                           }
                           time_finish = clock();
                           time = (time_finish - time_start)/CLOCKS_PER_SEC;          
                           printf("Time searches in Open Hash-Table(ms): %f\n", time);
                           printf("Hash index of the keyword: %d\n", hash("int", n_open));
                           printf("Amount of comparisons: %d\n\n", count);

                           time_start = clock();
                           for(int i = 0; i < 2000000; i++){
                               count = 0;
                               closed_hash_search(closed_hashtable, "int", n_closed, &count, 1);
                           }
                           time_finish = clock();
                           time = (time_finish - time_start)/CLOCKS_PER_SEC;     
                           printf("Time searches in Close Hash-Table(ms): %f\n", time);
                           printf("Hash index of the keyword: %d\n", hash("int", n_closed));
                           printf("Amount of comparisons: %d\n", count);
                           exit(0);
                       break;
                       case 12://+
                           about_action();
                       break;
                       case 13://+
                           exit(0);
                       case 0:
                           return err;
                   }
               }
            }
        }
    }
}
