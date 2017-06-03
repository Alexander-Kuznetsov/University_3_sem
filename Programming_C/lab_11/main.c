#include <stdio.h>
#include "btree.h"

void init_tree(struct Node *t){
    t = NULL;
}

int main(){
    struct Node *root, *tmp;
    FILE *f_in, *f_dot;
    int key, ID;

    f_in = fopen("SalesOrderDetails.xml", "r");
    root = load_file(f_in);
    fclose(f_in);

    about_tree();
    while (1){
        key = input_key(0, 10);
        switch (key){
            case 1:
                f_dot = fopen("DOT.gv", "w");
                export_to_dot(f_dot, root);
                fclose(f_dot);
                break;
            case 2:
                printf("\n____________________________________________________\n");
                PrintInorder(root, stdout);
                break;
            case 3:
                ID = input_elem();
                tmp = search_node(root, ID);
                if (tmp != NULL)
                    print_node(stdout, tmp->data);
                else
                    printf("This ID not exist!\n");
                break;
            case 4:
                tmp = find_min(root);
                print_node(stdout, tmp->data);
                break;
            case 5:
                tmp = find_max(root);
                print_node(stdout, tmp->data);
                break;
            case 6:
                ID = input_elem();
                tmp = search_node(root, ID);
                if (tmp!= NULL){
                    predeces(tmp);
                }
                else
                printf("This ID not exist!\n");

                //print_node(stdout, essor(root)->data);
                break;
            case 7:
                ID = input_elem();
                tmp = search_node(root, ID);
                if (tmp!= NULL){
                    succes(tmp);
                }
                else
                printf("This ID not exist!\n");

                break;
            case 8:
                add_in_tree(root);
                break;
            case 9:
                ID = input_elem();
                tmp = search_node(root, ID);
                if (tmp!= NULL){
                    del_node(root, tmp);
                }
                else
                    printf("This ID not exist!\n");
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

    return 0;
}
