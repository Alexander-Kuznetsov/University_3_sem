#include <stdio.h>
#include "btree.h"

int main(){
    int key_start, key_quest, key_action, size_search = 0;
    char str[100], s = ' ';
    struct Node *root, *tmp;
    FILE *f_in, *f_dot, *f_data_search;

    f_in = fopen("data.txt", "r");
    root = read_file(f_in);
    fclose(f_in);
    about_start();
    key_start = input_key(0, 3);
    //1 - Your questions; 2 - Action with Binar Tree; 3 - Timer work read binar tree & File
    switch(key_start){
        case 1:
            about_quest();
            while(1){
                key_quest = input_key(0, 2);
                if (key_quest == 1){
                    size_search = 0;
                    f_data_search = fopen("data_search.txt", "w");
                    printf("Input char for searching words: ");
                    fscanf(stdin, "%s", &s);
                    SearchInorder(f_data_search, root, s, &size_search);
                    fclose(f_data_search);
                    printf("\nFOUND %d words with first letter is %c\n", size_search, s);
                }
                else if(key_quest == 2){
                    f_data_search = fopen("data_search.txt", "r");
                    f_dot = fopen("DOT.gv", "w");
                    export_to_dot_color(f_dot, f_data_search, root);
                    fclose(f_data_search);
                    fclose(f_dot);
                }
                else exit(0);
            }
            break;
        case 2:
            about_tree();
            while (1){
                key_action = input_key(0, 10);
                switch (key_action){
                    case 1:
                        f_dot = fopen("DOT.gv", "w");
                        export_to_dot(f_dot, root);
                        fclose(f_dot);
                        break;
                    case 2:
                        //InorderPR(stdout, root);
                        preorderPrint(stdout, root);
                      //  PrintInorder(stdout, root);
                        break;
                    case 3:
                        printf("Input your string: ");
                        scanf("%s", str);
                        tmp = search_node(root, str);
                        if (tmp != NULL)   print_node(stdout, tmp);
                        else   printf("This string is not exist!\n");
                        break;
                    case 4:
                        tmp = find_min(root);
                        if (tmp != NULL)    print_node(stdout, tmp);
                        else    printf("Minimum not found!\n");
                        break;
                    case 5:
                        tmp = find_max(root);
                        if (tmp != NULL)    print_node(stdout, tmp);
                        else    printf("Maximum not found!\n");
                        break;
                    case 6:
                        printf("Input your string: ");
                        scanf("%s", str);
                        tmp = search_node(root, str);
                        if (tmp != NULL)   predeces(tmp);
                        else   printf("This string is not exist!\n");
                        break;
                    case 7:
                        printf("Input your string: ");
                        scanf("%s", str);
                        tmp = search_node(root, str);
                        if (tmp != NULL)   succes(tmp);
                        else   printf("This string is not exist!\n");
                        break;
                    case 8:
                        add_in_tree(root);
                        break;
                    case 9:
                        printf("Input your string: ");
                        scanf("%s", str);
                        tmp = search_node(root, str);
                        if (tmp != NULL)  del_node(root, tmp);
                        else   printf("This string is not exist!\n");
                        break;
                    case 10:
                        about_tree();
                        break;
                    default:
                        free_node(root);
                        exit(0);
                        break;
                }
            }

            break;
        case 3:
            root = NULL;
            f_dot = fopen("datatmp.txt", "r");
            root = read_file(f_dot);
            fclose(f_dot);

            f_dot = fopen("DOT.gv", "w");
            export_to_dot(f_dot, root);
            fclose(f_dot);
            timer(root);
            break;
        default:
            exit(0);
            break;
    }


    return 0;
}
