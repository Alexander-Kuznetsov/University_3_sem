#include "parsing.h"

void r(char *str, char *num){
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
    num[k] = '\0';
}

void read(FILE *f, char *num){
    char str[100];
    fgets(str, 100, f);
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
    num[k] = '\0';
}

int test(FILE *f, char *num){
    int k = 0;
    char str[100];
    fgets(str, 100, f);
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '>'){
            i++;
            while ((str[i]!='<') && (i < strlen(str))){
                k++;
                i++;
            }
            break;
        }
    }
    if (k <= 1) return -1;
    else{
        r(str, num);
        return k;
    }
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
