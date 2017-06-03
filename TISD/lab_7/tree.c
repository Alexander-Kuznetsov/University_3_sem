#include "methods.h"

void init_tree(tree *tr){
    tr->root = NULL;
}

void init_node(node *temp){
    temp->left = NULL;
    temp->right = NULL;
    temp->par = NULL;
}

void init_root(tree *tr){
    node *temp = (node*)malloc(sizeof(node));
    init_node(temp);
    tr->root = temp;
}

void pod(){
    printf("%s", "-----------------------------------------------------------------\n");
}

void about_action(){
    printf("%s", "-----------------------------------------------------------------\n");
    printf("%s", "-----------------------------Main menu---------------------------\n");
    printf("%s", "-----------------------------------------------------------------\n");
    printf("%s", "1  - Insert keyword in Tree && Has_Table(Open && Close).\n");
    printf("%s", "2  - Pop keyword from BinarTree and Hash_Table.\n");
    printf("%s", "3  - Print the BinarTree.\n");
    printf("%s", "4  - Print the open hash-table.\n");
    printf("%s", "5  - Print the closed hash-table.\n");
    printf("%s", "6  - Balance BinarTree.\n");
    printf("%s", "7  - Change a cells Hash_table(Open && Close).\n");
    printf("%s", "8  - Search and help from BinarTree.\n");
    printf("%s", "9  - Search and help from (Open) Hash-Tables.\n");
    printf("%s", "10 - Search and help from (Close) Hash-Tables.\n");
    printf("%s", "11 - Time test.\n");
    printf("%s", "12 - About main menu.\n");
    printf("%s", "13 - Exit.\n");
    printf("%s", "-----------------------------------------------------------------\n");
}

//?????
int add(tree *tr, node *data){
    node *temp1 = NULL;
    node *temp2 = tr->root;
    int res = 0;

    while (temp2 != NULL){
        temp1 = temp2;
        if (strcmp(data->keyword, temp2->keyword) > 0)
            temp2 = temp2->left;
        else if(strcmp(data->keyword, temp2->keyword) < 0)
            temp2 = temp2->right;
        else{
            printf("Tree have %s this do not add\n", data->keyword);
            res = 1;
            break;
        }
    }
    if (temp1 == NULL && res != 1){
        init_root(tr);
        strcpy(tr->root->keyword, data->keyword);
        strcpy(tr->root->HELP, data->HELP);
    }
    else if ((strcmp(temp1->keyword, data->keyword) >= 0 )&& res != 1){
        node *temp = (node*)malloc(sizeof(node));
        init_node(temp);
        strcpy(temp->keyword, data->keyword);
        strcpy(temp->HELP, data->HELP);
        temp1->right = temp;
        temp->par = temp1;
    }
    else if(res != 1){
        node *temp = (node*)malloc(sizeof(node));
        init_node(temp);
        strcpy(temp->keyword, data->keyword);
        strcpy(temp->HELP, data->HELP);
        temp1->left = temp;
        temp->par = temp1;
    }

    return res;
}

node* search(tree *tr, char *keyword, int* count, int mode){
    node *temp = tr->root;
    int check = 0, question;

    while (temp != NULL){
        *count = *count + 1;
        if (strcmp(keyword, temp->keyword) == 0){
            check = 1;
            if(!mode){
                printf("Amount comparisons in BinarTree: %d\n", *count);
                printf("%s", "The keyword was found.\n");
                printf("HELP: %s\n", temp->HELP);
                /*printf("%s", "Rewrite HELP description?\n");
                printf("%s", "1 - Yes\n");
                printf("%s", "2 - No\n");
                scanf("%d", &question);
                if(question == 1){
                    printf("%s", "Input HELP description:\n");
                    fflush(stdin);
                    gets(temp->HELP);
                }*/
             }
             break;
        }
        if (strcmp(keyword, temp->keyword) > 0)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(!mode && !check){
        printf("Amount comparisons in BinarTree: %d\n", *count);
        printf("%s", "The keyword was not found.\n");
    }

    return temp;
}

//???
int delete_keyword(tree *tr, char *keyword){
    node *temp;
    int count = 0;
    temp = search(tr, keyword, &count, 1);
    if (temp == NULL)
        return ERR_DELETE;
    if (temp != tr->root)
    {
        if ((temp->left == NULL)*(temp->right == NULL))
        {
            if (is_left(temp))
                temp->par->left = NULL;
            else
                temp->par->right = NULL;
        }
        else if ((temp->left == NULL)*(temp->right != NULL))
        {
            if (is_left(temp))
            {
                temp->par->left = temp->right;
                temp->right->par = temp->par;
            }
            else
            {
                temp->par->right = temp->right;
                temp->right->par = temp->par;
            }
        }
        else if ((temp->right == NULL)*(temp->left != NULL))
        {
            if (is_left(temp))
            {
                temp->par->left = temp->left;
                temp->left->par = temp->par;
            }
            else
            {
                temp->par->right = temp->left;
                temp->left->par = temp->par;
            }
        }
        else
        {
            node *temp2 = temp->right;
            while (temp2->left != NULL)
            {
                temp2 = temp2->left;
            }
            if (is_left(temp))
            {
                temp->par->left = temp2;
                temp2->par = temp->par;
            }
            else
            {
                temp->par->right = temp2;
                temp2->par = temp->par;
            }

            temp2->left = temp->left;
            temp->left->par = temp2;
        }
    }
    else
    {
        if ((tr->root->left == NULL)*(tr->root->right == NULL))
            tr->root = NULL;
        else if ((tr->root->left == NULL)*(tr->root->right != NULL))
        {
            tr->root->right->par = NULL;
            tr->root = tr->root->right;
        }
        else if ((tr->root->left != NULL)*(tr->root->right == NULL))
        {
            tr->root->left->par = NULL;
            tr->root = tr->root->left;
        }
        else
        {
            node *temp2 = tr->root->right;
            while (temp2->left != NULL)
            {
                temp2 = temp2->left;
            }
            temp2->left = tr->root->left;
            tr->root->left->par = temp2;
            tr->root = tr->root->right;
            tr->root->par = NULL;
        }
    }
    return OK;
}

void print_tree(struct node_s * nod){
    if(nod){
        printf("%s\n", nod->keyword);
        print_tree(nod->left);
        print_tree(nod->right);
    }
}

int count(node *nod){
    int res = 0;
    if (nod != NULL)
        res = 1 + count(nod->left) + count(nod->right);
    return res;
}

node* min(node *root){
    node *temp = root;
    if (temp){
        while (temp->left != NULL)
            temp = temp->left;
    }
    return temp;
}

node* max (node *root){
    node *temp = root;
    if (temp){
        while (temp->right != NULL)
            temp = temp->right;
    }
    return temp;
}

int is_left (node *nod){
    int res = 0;
    if (nod->par)
        if (nod->par->left)
            if (strcmp(nod->keyword, nod->par->left->keyword) == 0)
                res = 1;
    return res;
}

int is_right (node *nod){
    int res = 0;
    if (nod->par)
        if (nod->par->right)
            if (strcmp(nod->keyword, nod->par->right->keyword) == 0)
                res = 1;
    return res;
}

node* next(node *temp){
    node *res = temp;
    if (res == NULL)
        return NULL;
    if (res->right != NULL){
        res = min(res->right);
    }
    else{
        while (res != NULL){
            if (is_left(res)){
                res = res->par;
                break;
            }
            else
                res = res->par;
        }
    }
    return res;
}

node* balance(node *nod){
    int l = count(nod);
    int i;
    node *temp = min(nod);
    node *temp1 = (node*)malloc(sizeof(node));
    node *temp2 = (node*)malloc(sizeof(node));
    tree *sub1 = (tree*)malloc(sizeof(tree));
    tree *sub2 = (tree*)malloc(sizeof(tree));

    init_tree(sub1);
    init_tree(sub2);
    node *res = (node*)malloc(sizeof(node));
    res = nod;
    if (l > 2){
        for (i = 0; i < l/2; i++){
            add(sub1, temp);
            temp = next(temp);
        }
        res = temp;
        temp = next(temp);
        for (i = l/2; i < l-1; i++){
            add(sub2, temp);
            temp = next(temp);
        }
        temp1 = balance(sub1->root);
        temp2 = balance(sub2->root);
        res->left = temp1;
        res->right = temp2;
        temp1->par = res;
        temp2->par = res;
    }
    return res;
}

void get_balanced_tree(tree *tr){
    node *temp = balance(tr->root);
    if (is_left(temp)){
        temp->par->left = NULL;
        temp->par = NULL;
    }
    if (is_right(temp)){
        temp->par->right = NULL;
        temp->par = NULL;
    }
    tr->root = temp;
}

//Work with DOT
void to_dot(struct node_s *tree, FILE *f){
    if (tree == NULL) {
        return;
    }
    to_dot(tree->left, f);
    print_dot(f, tree);
    to_dot(tree->right, f);
}

void print_dot(FILE *f, struct node_s *tree){
    if (tree->left != NULL)
        fprintf(f, "%s -> %s;\n", tree->keyword, tree->left->keyword);
    if (tree->right != NULL)
        fprintf(f, "%s -> %s;\n", tree->keyword, tree->right->keyword);
}

void export_to_dot(FILE *f, struct node_s *node){
    fprintf(f, "digraph BINAR_TREE {\n" );
    to_dot(node, f);
    fprintf(f, "}\n");
}



