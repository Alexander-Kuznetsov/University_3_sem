#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    List* lst = create_list();
    int key, max, min, len, ind, el1, el2, el3, el4;
    float el5, el6;
    char el7[50];
    FILE *f_load, *f_save;
    about_list();
    while(1){
        key = input_key(0, 15);
        switch (key) {
            case 1: //load
                f_load = fopen("SalesOrderDetails.xml", "r");
                clear_list(lst);
                load_file(f_load, lst);
                fclose(f_load);
                break;
            case 2: //save
                f_save = fopen("output.txt", "w");
                save_file(f_save, lst);
                fclose(f_save);
                break;
            case 3: //print
                print_list(lst);
                break;
            case 4:  //add head
                printf("SalesOrderID: "), el1 = input_elem();
                printf("SalesOrderDetailID: "), el2 = input_elem();
                printf("OrderQty: "), el3 = input_elem();
                printf("ProductID: "), el4 = input_elem();
                printf("UnitPrice: "), el5 = input_elem_f();
                printf("UnitPriceDiscount: "), el6 = input_elem_f();;
                printf("ModifiedDate: "), scanf("%s", el7);
                add_head(lst, el1, el2, el3, el4, el5, el6, el7);
                break;
            case 5:  //add tail
                printf("SalesOrderID: "), el1 = input_elem();
                printf("SalesOrderDetailID: "), el2 = input_elem();
                printf("OrderQty: "), el3 = input_elem();
                printf("ProductID: "), el4 = input_elem();
                printf("UnitPrice: "), el5 = input_elem_f();
                printf("UnitPriceDiscount: "), el6 = input_elem_f();;
                printf("ModifiedDate: "), scanf("%s", el7);
                add_tail(lst, el1, el2, el3, el4, el5, el6, el7);
                break;
            case 6:  //pop head
                if (empty_list(lst) == ERROR) printf("list is empty\n");
                else pop_head(lst);
                break;
            case 7:  //pop tail
                if (lst -> head == NULL) printf("list is empty\n");
                else pop_tail(lst);
                break;
            case 8:  //max el
                if (empty_list(lst) == ERROR) printf("list is empty\n");
                else{
                    max = find_max(lst);
                    printf("max element(UnitPrice) in List is %d\n", max);
                }
                break;
            case 9:  //min el
                if (empty_list(lst) == ERROR) printf("list is empty\n");
                else{
                    min = find_min(lst);
                    printf("min element(UnitPrice) in List is %d\n ", min);
                }
                break;
            case 10: //empty list
                if (empty_list(lst) == ERROR) printf("list is empty\n");
                else printf("list not empty\n");
                break;
            case 11: //find 1 el
                el1 = input_elem();
                ind = find_first(lst, el1);
                switch (ind){
                    case NOT_FOUND:
                        printf("element not found in list\n");
                        break;
                    case ERROR:
                        printf("list is empty\n");
                        break;
                    default:
                        printf("First index with element(SalesOrderID) %d is %d\n", el1, ind);
                        break;
                }
                break;
            case 12: //reverse
                reverse_list(lst);
                break;
            case 13: //len list
                len = len_list(lst);
                if (len != ERROR) printf("len list is %d\n", len);
                else printf("list is empty\n");
                break;
            case 14: //clear
                clear_list(lst);
                break;
            case 15: //about
                about_list();
                break;
            case 0:
                exit(0);
                break;
        }
    }
}
