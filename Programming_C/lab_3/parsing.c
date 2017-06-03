#include "parsing.h"

int func();
void pod(int width);
void pod_file(int width, FILE *f_out);

int input(int left, int key){
    int result;
    printf(">> ");
    result = func();
    while (1){
        if (result >= left && result <= key)
            break;
        else{
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

int read(char *str, char *num){
    int k = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '>'){
            i++;
            while ((str[i]!='<') && (i < strlen(str))){
                num[k] = str[i];
                k++;
                i++;

            }
            break;
        }
    }
    return k;
}
int check_int(char *num, int len_str){
    for (int i = 0; i < len_str; i++){
        if ((num[i]>= '0') && (num[i] <= '9')){
            ;
        }
        else{
            return -1;
        }
    }
    return 0;
}
int check_double(char *num, int len_str){
    int count = 0;
    for (int i = 0; i < len_str; i++){
        if (num[i] == '.'){
            count++;
            if (count > 1){
                return -1;
            }
        }
        else if ((num[i]>= '0') && (num[i] <= '9')){
            ;
        }
        else{
            return -1;
        }
    }
    return 0;
}

int merge_sort_prodid(int l, int r) {
    if(l==r) return 0;
    int mid =(l + r)/2;
    merge_sort_prodid(l, mid);
    merge_sort_prodid(mid + 1, r);
    SalesOrderDetail tmp[MAX_LEN_TABLE];
    int i=l;
    int j = mid+1;;
    for(int step=0; step<r-l+1; step++) {
        if( (j > r) || ((i <= mid) && (table[i].ProductID < table[j].ProductID)) ) {
            tmp[step] = table[i];
            i++;
        }
        else {
            tmp[step] = table[j];
            j++;
        }
    }
    for(int step=0; step < r - l + 1; step++)
        table[l + step] = tmp[step];
    return 0;
}

int merge_sort_unitprice(int l, int r) {
    if(l==r) return 0;
    int mid =(l + r)/2;
    merge_sort_unitprice(l, mid);
    merge_sort_unitprice(mid + 1, r);
    SalesOrderDetail tmp[MAX_LEN_TABLE];
    int i=l;
    int j = mid+1;;
    for(int step=0; step<r-l+1; step++) {
        if( (j > r) || ((i <= mid) && (table[i].UnitPrice < table[j].UnitPrice)) ) {
            tmp[step] = table[i];
            i++;
        }
        else {
            tmp[step] = table[j];
            j++;
        }
    }
    for(int step=0; step < r - l + 1; step++)
        table[l + step] = tmp[step];
    return 0;
}

int merge_sort_order(int l, int r) {
    if(l==r) return 0;
    int mid =(l + r)/2;
    merge_sort_order(l, mid);
    merge_sort_order(mid + 1, r);
    SalesOrderDetail tmp[MAX_LEN_TABLE];
    int i=l;
    int j = mid+1;;
    for(int step=0; step<r-l+1; step++) {
        if( (j > r) || ((i <= mid) && (table[i].OrderQty < table[j].OrderQty)) ) {
            tmp[step] = table[i];
            i++;
        }
        else {
            tmp[step] = table[j];
            j++;
        }
    }
    for(int step=0; step < r - l + 1; step++)
        table[l + step] = tmp[step];
    return 0;
}
void print_table(int len_table){
    if (len_table != 0){
        int width = 108;
        pod(width);
        printf("|No  |SalesOrderID|SalesOrderDetailID|OrderQty|ProductID| UnitPrice  |UnitPriceDiscount|    ModifiedDate   |\n");
                    // 1+12+1 +18+1+8+1+9+1+12+1+17+1+19+1
        for (int i = 0; i < len_table; i++){
            pod(width);
            printf("|%*d",4,i+1);
            printf("|%*d", 12, table[i].SalesOrderID);
            printf("|%*d", 18, table[i].SalesOrderDetailID);
            printf("|%*d", 8, table[i].OrderQty);
            printf("|%*d", 9, table[i].ProductID);
            printf("|%*lf", 12, table[i].UnitPrice);
            printf("|%*lf", 17, table[i].UnitPriceDiscount);
            printf("|%*s", 17, table[i].ModifiedDate);
            printf("|\n");
        }
        pod(width);
    }
    else
        printf("Error: table is empty!");
}

void print_table_file(int len_table, FILE *f_out){
    if (len_table != 0){
        int width = 112;
        pod_file(width, f_out);
        fprintf(f_out, "|No  |SalesOrderID|SalesOrderDetailID|OrderQty|ProductID| UnitPrice  |UnitPriceDiscount|      ModifiedDate     |\n");
                    // 1+12+1 +18+1+8+1+9+1+12+1+17+1+19+1
        for (int i = 0; i < len_table; i++){
            pod_file(width, f_out);
            fprintf(f_out,"|%*d",4,i+1);
            fprintf(f_out,"|%*d", 12, table[i].SalesOrderID);
            fprintf(f_out,"|%*d", 18, table[i].SalesOrderDetailID);
            fprintf(f_out,"|%*d", 8, table[i].OrderQty);
            fprintf(f_out,"|%*d", 9, table[i].ProductID);
            fprintf(f_out,"|%*lf", 12, table[i].UnitPrice);
            fprintf(f_out,"|%*lf", 17, table[i].UnitPriceDiscount);
            fprintf(f_out,"|%*s", 21, table[i].ModifiedDate);
            fprintf(f_out,"|\n");
        }
        pod_file(width, f_out);
    }
    else
        printf("Error: table is empty!");
}

void pod(int width){
    for (int i = 0; i < width; i++)
        printf("-");
    printf("\n");
}

void pod_file(int width,  FILE *f_out){
    for (int i = 0; i < width; i++)
        fprintf(f_out, "-");
    fprintf(f_out, "\n");
}

void about(){
    printf("--------------------------------\n");
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "input your variant",
           "1 - MergeSort ProductID",
           "2 - MergeSort UnitPrice",
           "3 - MergeSort OrderQty",
           "4 - Print your table",
           "5 - Bsearch ProductID",
           "0 - exit");
    printf("--------------------------------\n");
}
