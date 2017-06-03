#include "btree.h"

int func();

void about_start(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "-----------------------------",
           "!---------Start Menu---------!",
           "-----------------------------",
           "1 - Operating with Questions",
           "2 - Operating with Binar_Tree",
           "3 - Time test",
           "0 - exit",
           "-----------------------------");
}

void about_quest(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "-----------------------------",
           "!---------Quest Menu---------!",
           "-----------------------------",
           "1 - Search first char in word",
           "2 - Import to DOT",
           "0 - exit",
           "-----------------------------");
}

void about_tree(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "-----------------------------",
           "!---------Select Menu--------!",
           "-----------------------------",
           "1 - IN DOT",
           "2 - IN STDOUT(PreOrder)",
           "3 - search",
           "4 - minimum",
           "5 - maximum",
           "6 - predecessor",
           "7 - successor",
           "8 - insert",
           "9 - delete",
           "10 - about",
           "0 - exit",
           "----------------------------");
}

struct Node *search_node(struct Node *node, char *str){
    if (node == NULL) return NULL;
    if (strcmp(node->string, str) < 0)  return search_node(node->right, str);
    else if (strcmp(node->string, str) > 0) return search_node(node->left, str);
    else return node;
}

void SearchInorder(FILE *f, struct Node *node, char ch, int *size) {
    if (node == NULL) return;

    SearchInorder(f, node->left, ch, size);
    if (node->string[0] == ch){
        fprintf(f, "%s ", node->string);
        (*size)++;
    }
    SearchInorder(f, node->right, ch, size);
}

struct Node *successor(struct Node *root){

    if(root->right)
        return find_min(root->right);

    struct Node *buf_root = root->pred;
    while(buf_root && (root == buf_root->right)){
        root = buf_root;
        buf_root = root->pred;
    }

    return buf_root;
}
struct Node *predecessor(struct Node *root){

    if(root->left)
        return find_max(root->left);

    struct Node *buf_root = root->pred;
    while (buf_root && (root == buf_root->left)){
        root = buf_root;
        buf_root = root->pred;
    }

    return buf_root;
}

void predeces(struct Node *node){
    if (node->pred != NULL)
        print_node(stdout, node);
    else
        printf("\nDon`t have parent!\n");
}

void succes(struct Node *node){
    if (node->left != NULL || node->right != NULL){
       if (node->left != NULL)
            print_node(stdout, node->left);
       if (node->right != NULL)
            print_node(stdout, node->right);
    }
    else
        printf("\n This don`t have son\n");
}

struct Node *find_max(struct Node *node){
    if (node == NULL)  return NULL;

    while (node->right != NULL){
        node = node->right;
    }

    return node;
}

struct Node *find_min(struct Node *node){
    if (node == NULL)  return NULL;

    while (node->left != NULL){
        node = node->left;
    }

    return node;
}

void add_in_tree(struct Node *root){
    char tmp[100];
    printf("\n>Input your string: ");
    if(scanf("%s", tmp)){
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->string = (char*) malloc(sizeof(char)*(strlen(tmp)+1));
        strcpy(node->string, tmp);
        Insert(root, node);
    }
}

struct Node *del_node(struct Node *node, struct Node *tmp){
    if (tmp->left == NULL && tmp->right == NULL){         // первый случай: удаляемый элемент - лист
      if (tmp->pred->left == tmp)
        tmp->pred->left = NULL;
      if (tmp->pred->right == tmp)
        tmp->pred->right = NULL;
    }
    else if (tmp->left == NULL || tmp->right == NULL){     // второй случай: удаляемый элемент имеет одного потомка
        if (tmp->left == NULL){
            if (tmp->left == tmp)
              tmp->pred->left = tmp->right;
            else
              tmp->pred->right = tmp->right;
            tmp->right->pred = tmp->pred;
        }
        else{
            if (tmp->pred->left == tmp)
                tmp->pred->left = tmp->left;
            else
                tmp->pred->right = tmp->left;
            tmp->left->pred = tmp->pred;
        }
    }
    else{                                          // третий случай: удаляемый элемент имеет двух потомков
      struct Node *suc; //= (struct Node*)malloc(sizeof(struct Node));
      suc = successor(tmp);
      tmp->string  = suc->string;
      if (suc->pred->left == suc){
        suc->pred->left = suc->right;
        if (suc->right != NULL)
          suc->right->pred = suc->pred;
      }
      else{
        suc->pred->right = suc->right;
        if (suc->right != NULL)
          suc->right->pred = suc->pred;
      }
    }

    return NULL;
}

struct Node *read_file(FILE *f){
    struct Node *root = NULL, *node;
    char tmp[100];
    int k = 1;

    while(!feof(f)){
        if(fscanf(f, "%s", tmp)){
            node = (struct Node*) malloc (sizeof(struct Node));
            node->string = (char*) malloc(sizeof(char)*(strlen(tmp)+1));

            strcpy(node->string, tmp);

            if (k)  { root = Insert(root, node), k = 0; }
            else  Insert(root, node);
        }
    }

    return root;
}

void PrintInorder(FILE *out, struct Node *node) {
    if (node == NULL) return;

    PrintInorder(out, node->left);
    print_node(out, node);
    PrintInorder(out, node->right);
}

void InorderPR(FILE *out, struct Node *node) {
    PrintInorder(out, node->left);
    print_node(out, node);
    PrintInorder(out, node->right);
}

void preorderPrint(FILE *out, struct Node *node){
    if (node) {
        print_node(out, node);
        preorderPrint(out, node->left);
        preorderPrint(out, node->right);
    }
}

void print_node(FILE *out, struct Node *node){
    fprintf(out, "%s\n", node->string);
    fprintf(out, "-----\n");
}


struct Node *Insert(struct Node *node, struct Node *temp) {
    temp->left = NULL, temp->right = NULL, temp->pred=NULL;

    if (node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        node = temp;

        return node;
    }
    while (node != NULL){
        if (strcmp(temp->string, node->string) > 0){
           if (node->right != NULL)
              node = node->right;
           else{
              temp->pred = node;
              node->right = temp;
              break;
           }
        }
        else if (strcmp(temp->string, node->string) <= 0){
           if (node->left != NULL)
              node = node->left;
           else{
              temp->pred = node;
              node->left = temp;
              break;
           }
        }
    }

    return NULL;
}

void free_node(struct Node *node){
    free(node->string);
    free(node->left);
    free(node->right);
    free(node);
}


void timer(struct Node *node){
    FILE *f;
    char str[100];
    int count = 0;
    node = NULL;


    clock_t ftime_start = 0, ftime_end = 0, ttime_start = 0, ttime_end = 0;
    for(int i = 0; i < 1000000; i++){
        count = 0;
        ttime_start += clock();
        SearchInorder(stdin, node, 'a', &count);
        //search_node(node, "aircraft");
        ttime_end += clock();


        f = fopen("datatmp.txt", "r");
        count = 0;
        ftime_start += clock();
        while(feof(f)){
            fscanf(f, "%s", str);
            if (str[0] ==  'a')
                count++;
        }
        ftime_end += clock();
        fclose(f);
    }
    printf("time (clocks) TreeSearch: %lf\n", (double) (ttime_end-ttime_start));
    printf("time (clocks) FileSearch: %lf\n", (double) (ftime_end-ftime_start));
}



//Work with DOT
void to_dot(struct Node *tree, FILE *f){
    if (tree == NULL) {
        return;
    }
    to_dot(tree->left, f);
    print_dot(f, tree);
    to_dot(tree->right, f);
}

void print_dot(FILE *f, struct Node *tree){
    if (tree->left != NULL)
        fprintf(f, "%s -> %s;\n", tree->string, tree->left->string);
    if (tree->right != NULL)
        fprintf(f, "%s -> %s;\n", tree->string, tree->right->string);
}

void export_to_dot(FILE *f, struct Node *node){
    fprintf(f, "digraph BINAR_TREE {\n" );
    to_dot(node, f);
  //  fprintf(f, "aircraft [color=red];");
    fprintf(f, "}\n");
}

void export_to_dot_color(FILE *f, FILE *data_search, struct Node *node){
    char str[100];
    fprintf(f, "digraph BINAR_TREE {\n" );
    to_dot(node, f);
    while(!feof(data_search)){
        fscanf(data_search,"%s", str);
        fprintf(f, "%s [color=red];\n", str);
    }
    fprintf(f, "}\n");
}


//Action with input!!!
int input_key(int key1, int key2){
    int result;
    printf(">> ");
    result = func();
    while (1){
        if (result >= key1 && result <= key2)
            break;
        else
        {
            printf("incorrect input, please return input...\n");
            printf(">> ");
            result = func();
        }
    }
    return result;
}

int func(){
    int result;
    while (scanf("%d",&result) != 1){
        while (getchar() != '\n');
        printf("incorrect input, please return input...\n");
        printf(">> ");
    }
    return result;
}
