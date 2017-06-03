#include "btree.h"
#include "parsing.h"
int func();

void about_tree(){
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "----------------------------",
           "!--#--Select Menu--#--!",
           "1 - IN DOT",
           "2 - IN STDOUT(InOrder)",
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

struct Node *search_node(struct Node *node, int key){
    if (node == NULL) return NULL;
    if (node->data->ProductID < key)  return search_node(node->right, key);
    else if (node->data->ProductID > key) return search_node(node->left, key);
    else return node;
}

struct Node *find_min(struct Node *node){
    while (node->left != NULL){
        node = node->left;
    }
    return node;
}
void predeces(struct Node *node){
    if (node->pred != NULL)
        print_node(stdout, node->pred->data);
    else
        printf("\nDon`t have predok\n");
}

void succes(struct Node *node){
    if (node->left != NULL || node->right != NULL){
       if (node->left != NULL)
            print_node(stdout, node->left->data);
       if (node->right != NULL)
            print_node(stdout, node->right->data);
    }
    else
        printf("\n This don`t have son\n");
}

struct Node *find_max(struct Node *node){
    while (node->right != NULL){
        node = node->right;
    }
    return node;
}

struct Node *load_file(FILE *f){
    struct Node *root = NULL;
    DataTree *datatree;
    char  num[100];
    int k = 1;
    while(!feof(f)){
        if (test(f, num) != ERROR){
            struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
            datatree = (DataTree*) malloc(sizeof(DataTree));
            datatree->SalesOrderID = atoi(num);
            read(f, num);
            datatree->SalesOrderDetailID = atoi(num);
            read(f, num);
            datatree->OrderQty = atoi(num);
            read(f, num);
            datatree->ProductID = atoi(num);
            read(f, num);
            datatree->UnitPrice = atof(num);
            read(f, num);
            datatree->UnitPriceDiscount = atof(num);
            read(f, num);
            strcpy(datatree->ModifiedDate, num);
            temp->data = datatree;
            if (k){
                root = Insert(root, temp);
                k = 0;
            }
            else Insert(root, temp);
           // num[0] = '\0';
        }
    }
    return root;
}
//111 досдача программиования
void PrintInorder(struct Node* node, FILE* out) {
    if (node == NULL) {
        return;
    }

    PrintInorder(node->left, out);
    print_node(out, node->data);
    PrintInorder(node->right, out);
}

struct Node *Insert(struct Node *node, struct Node *temp) {
    temp->left = NULL, temp->right = NULL, temp->pred=NULL;
    if (node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        node = temp;
        return node;
    }
    while (node != NULL){
        if (temp->data->ProductID >= node->data->ProductID){
           if (node->right != NULL)
              node = node->right;
           else{
              temp->pred = node;
              node->right = temp;
              break;
           }
        }
        else if (temp->data->ProductID <= node->data->ProductID){
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
/*Node delete(root : Node, z : T):               // корень поддерева, удаляемый ключ
  if root == null
    return root
  if z < root.key
    root.left = delete(root.left, z)
  else if z > root.key
    root.right = delete(root.right, z)
  else if root.left != null and root.right != null
    root.key = minimum(root.right).key
    root.right = delete(root.right, root.right.key)
  else
    if root.left != null
      root = root.left
    else
      root = root.right
  return root*/

struct Node* successor(struct Node *root){

    if(root->right)
        return find_min(root->right);

    struct Node *buf_root = root->pred;
    while(buf_root && (root == buf_root->right)){
        root = buf_root;
        buf_root = root->pred;
    }

    return buf_root;
}
struct Node* predecessor(struct Node *root){

    if(root->left)
        return find_max(root->left);

    struct Node *buf_root = root->pred;
    while (buf_root && (root == buf_root->left)){
        root = buf_root;
        buf_root = root->pred;
    }

    return buf_root;
}

struct Node *del_node(struct Node *node, struct Node *tmp) {
    //p = v.parent                                  // предок удаляемого элемента
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
      tmp->data  = suc->data;
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

void free_node(struct Node *node){
    free(node->data);
    free(node->left);
    free(node->right);
    free(node);
}

void print_node(FILE *f, DataTree *datatree){
    fprintf(f, "-----\n");
    fprintf(f, "%d\n", datatree->SalesOrderID);
    fprintf(f, "%d\n", datatree->SalesOrderDetailID);
    fprintf(f, "%d\n", datatree->OrderQty);
    fprintf(f, "%d\n", datatree->ProductID);
    fprintf(f, "%f\n", datatree->UnitPrice);
    fprintf(f, "%f\n", datatree->UnitPriceDiscount);
    fprintf(f, "%s\n", datatree->ModifiedDate);
    fprintf(f, "-----\n");
}

void add_in_tree(struct Node *root){
    char tmp[20];
    DataTree *datatree = (DataTree*) malloc(sizeof(DataTree));
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nSalesOrderID:");
    datatree->SalesOrderID = input_elem();
    printf("\nSalesOrderDetailID:");
    datatree->SalesOrderDetailID = input_elem();
    printf("\nOrderQty:");
    datatree->OrderQty = input_elem();
    printf("\nProductID:");
    datatree->ProductID = input_elem();
    printf("\nUnitPrice:");
    datatree->UnitPrice = input_elem_f();
    printf("\nUnitPriceDiscount:");
    datatree->UnitPriceDiscount = input_elem_f();
    printf("\n>ModifiedDate:");
    scanf("%s", tmp);
    strcpy(datatree->ModifiedDate, tmp);
    temp->data = datatree;
    Insert(root, temp);
}

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
        fprintf(f, "%d -> %d;\n", tree->data->ProductID, tree->left->data->ProductID);
    if (tree->right != NULL)
        fprintf(f, "%d -> %d;\n", tree->data->ProductID, tree->right->data->ProductID);
}

void export_to_dot(FILE *f, struct Node *node){
    fprintf(f, "digraph BINAR_TREE {\n" );
    to_dot(node, f);
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

int input_elem(){
    int result;
    printf("int >> ");
    while(fscanf(stdin, "%d", &result) != 1){
        printf("incorrect input, please return input...\n");
        printf("int >> ");
        fflush(stdin);
    }
    return result;
}

float input_elem_f(){
    float result;
    printf("float >> ");
    while(fscanf(stdin, "%f", &result) != 1){
        printf("incorrect input, please return input...\n");
        printf("float >> ");
        fflush(stdin);
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
