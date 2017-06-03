#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct{
    //char Token[2][12] = {"<Token>", "</Token>"};
    //char Tok_categ[5][14] = {"Keyword", "Identifier", "Constant", "String-literal", "Punctuator"};
    //char Tok_name[]
}Lexic;
*/
void create_tag(char *cat, char *name, int num, int pos, int len){
    printf("    <Token>\n");
    printf("        <Category_of_token>%s</Category_of_token>\n", cat);
    printf("        <Name_of_token>%s</Name_of_token>\n", name);
    printf("        <Number_of_line>%d</Number_of_line>\n", num);
    printf("        <Position_in_line>%d</Position_in_line>\n", pos);
    printf("        <Length_name_of_token>%d</Length_name_of_token>\n", len);
    printf("    </Token>\n");
}

char *del_space(char *les){
    int k = 0;
    char *tmp = malloc(sizeof(char)*50);

    for (int i = 0; i < strlen(les); i++){
        if (les[i] != ' '){
            tmp[k] = les[i];
            k++;
        }
    }
    tmp[k] = '\0';

    return tmp;
}

typedef struct{
    char category[14];
    char name[50];
    int num_line;
    int pos_in_line;
    int length;
}Tokens;

Tokens token[1000];

int main(){
    int line = 0, count = 0;
    FILE *f_in, *f_out;
    char *str, *tmp;
    char *lexem;
    int key = 1;
    f_in = fopen("13_tok1.c", "r");
    while(!feof(f_in)){
        str = malloc(sizeof(char)*100);
        tmp = malloc(sizeof(char)*100);
        lexem = malloc(sizeof(char)*100);
        fgets(str, 100, f_in);
        ++line;
        if (!key) key = 1;
        strcpy(tmp, str);
        lexem = strtok(tmp, " ");
        while(lexem != NULL){
            lexem = del_space(lexem);
            printf("%s!!!", lexem);
            if (!strncmp(lexem, "#include", 8)){
                printf("+\n");
                key = 0;
                break;
            }

            else if (!strncmp(lexem, "/*", 3)){
                printf("OK!!!!!!!!!");
                key = -1;
            }
            if (key == -1 && (!strncmp(lexem, "*/", 2)))
                key = 0;
            lexem = strtok(NULL, " ");
           // printf("%s\n", lexem);
        }
   //     if (key)
    //        printf("%s\n", str);
//        if (!strncmp(tmp, "#include", 8))
//            printf("+");
//        else if (!strncmp(tmp, "/*", 2)){
//                count = 1;
//                printf("+");
//                while(tmp != NULL){
//                    printf("%s", tmp);
//                    tmp = strtok(NULL, " ");
//                    if (!strncmp(tmp, "*/", 2)){
//                        count = 0;
//                        break;
//                    }
//                }
//        }
//        else if (count == 1){
//                if (strncmp(tmp, "*/", 2))  count = 0;
//                printf("+");
//            }
//        else
//            printf("%s", str);
//        //return 0;
        free(str);
        free(tmp);
        free(lexem);
    }
    fclose(f_in);
   // state = 1;
    return 0;
}
