#include <stdio.h>
#include <stdlib.h>

#include "base.h"
int main(){
    FILE *f;
    char tmp_str[200];
    f = fopen("XML_Products.xml", "r");
    while(!feof(f)){
        fgets(tmp_str, 300, f);
        printf("%p ", memcmp,(tmp_str, "<ProductID>", 11));
          //  printf("%s", tmp_str);
    }
    fclose(f);
    printf("1");
    return 0;
}
