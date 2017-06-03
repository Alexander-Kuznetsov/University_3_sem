#include "methods.h"

Hash_row **init_hash(int n){
    Hash_row **hashtable = (Hash_row**)malloc(n*sizeof(Hash_row*));
    for(int i = 0; i < n; i++)
        hashtable[i] = NULL;
    return hashtable;
}

int hash(char *keyword, int n){
    int hashidx = 0, i = 0;

    while(keyword[i] != '\0'){
        hashidx += keyword[i];
        i++;
    }
    hashidx %= n;

    return hashidx;
}

void add_open_hash(Hash_row **hashtable, node *temp, int n){
    Hash_row *buff = (Hash_row*)malloc(sizeof(Hash_row));
    strcpy(buff->keyword, temp->keyword);
    strcpy(buff->HELP, temp->HELP);
    int hashidx = hash(temp->keyword, n);
    if(hashtable[hashidx] == NULL){
        buff->next = NULL;
        hashtable[hashidx] = buff;
    }
    else{
        buff->next = hashtable[hashidx];
        hashtable[hashidx] = buff;
    }
}

int add_closed_hash(Hash_row **hashtable, node *temp, int n){
    Hash_row *buff = (Hash_row*)malloc(sizeof(Hash_row));
    strcpy(buff->keyword, temp->keyword);
    strcpy(buff->HELP, temp->HELP);
    buff->next = NULL;
    int hashidx = hash(temp->keyword, n), idx, l_idx, r_idx, check = 0;
    if(hashtable[hashidx] == NULL){
        hashtable[hashidx] = buff;
        check = 1;
    }
    else{
        l_idx = r_idx = hashidx;
        l_idx--;
        r_idx++;
        while((l_idx >= 0 && l_idx < n) || (r_idx >= 0 && r_idx < n)){
            if(l_idx >= 0 && l_idx < n)
                if(hashtable[l_idx] == NULL){
                    hashtable[l_idx] = buff;
                    check = 1;
                    break;
                }
            if(r_idx >= 0 && r_idx < n)
                if(hashtable[r_idx] == NULL){
                    hashtable[r_idx] = buff;
                    check = 1;
                    break;
                }
            l_idx--;
            r_idx++;
        }
    }
    if(!check)
        return ERR_INPUT;
    else
        return OK;
}

void print_hashtable(Hash_row **hashtable, int n){
    Hash_row *buff = (Hash_row*)malloc(sizeof(Hash_row));

    for(int i = 0; i < n; i++){
        printf("[%d] =  ", i);
        buff = hashtable[i];
        while(buff != NULL){
            printf("%s   ", buff->keyword);
            buff = buff->next;
        }
        printf("%s", "\n");
    }
    free(buff);
}

void delete_open_hash(Hash_row **hashtable, char *keyword, int n){
    int hashidx = hash(keyword, n), count = 0;
    Hash_row *buff = (Hash_row*)malloc(sizeof(Hash_row));
    buff = hashtable[hashidx];

    if(buff->next == NULL)
    {
        if(!strcmp(buff->keyword, keyword))
                hashtable[hashidx] = NULL;
    }
    while(buff != NULL)
    {
        if(count == 0 && !strcmp(buff->keyword, keyword))
        {
            hashtable[hashidx] = buff->next;
            break;
        }
        else if(!strcmp(buff->keyword, keyword))
        {
            buff = hashtable[hashidx];
            for(int i = 0; i < count - 1; i++)
                buff = buff->next;
            if(buff->next->next == NULL)
                buff->next = NULL;
            else
                buff->next = buff->next->next;
        }
        else
        {
            count++;
            buff = buff->next;
        }
    }
}

void delete_closed_hash(Hash_row **hashtable, char *keyword, int n){
    int count = 0;
    int idx = closed_hash_search(hashtable, keyword, n, &count, 1);
    if(idx >= 0)
        hashtable[idx] = NULL;
}

void open_hash_search(Hash_row *hashtable, char *keyword, int n, int *count, int mode){
    int check = 0, question;
    Hash_row *buff;

    buff = hashtable;

    while(buff != NULL){
        *count = *count + 1;
        if(!strcmp(buff->keyword, keyword)){
            check = 1;
            if(!mode){
                printf("Amount comparisons in Hash-Table(open): %d\n", *count);
                printf("%s", "The keyword has been found.\n");
                printf("HELP: %s\n", buff->HELP);
                /*printf("%s", "Rewrite HELP description?\n");
                printf("%s", "1 - Yes\n");
                printf("%s", "2 - No\n");
                scanf("%d", &question);
                if(question == 1)
                {
                    printf("%s", "Input HELP description:\n");
                    fflush(stdin);
                    gets(buff->HELP);
                }*/
            }
            break;
        }
        else
            buff = buff->next;
    }
    if(!mode && !check){
        printf("Amount comparisons in Hash-Table(open): %d\n", *count);
        printf("%s", "The keyword was not found.\n");
    }
}

int closed_hash_search(Hash_row **hashtable, char *keyword, int n, int *count, int mode){
    int hashidx = hash(keyword, n), idx, l_idx, r_idx, check = 0, question = 0;

    *count = *count + 1;

    if(!strcmp(hashtable[hashidx]->keyword, keyword)){
        idx = hashidx;
        check = 1;
    }
    else{
        idx = l_idx = r_idx = hashidx;
        l_idx--;
        r_idx++;
        while((l_idx >= 0 && l_idx < n) || (r_idx >= 0 && r_idx < n)){
            *count = *count + 1;
            if(l_idx >= 0 && l_idx < n)
                if(!strcmp(hashtable[l_idx]->keyword, keyword)){
                    idx = l_idx;
                    check = 1;
                    break;
                }
            *count = *count + 1;
            if(r_idx >= 0 && r_idx < n)
                if(!strcmp(hashtable[r_idx]->keyword, keyword)){
                    idx = r_idx;
                    check = 1;
                    break;
                }
            l_idx--;
            r_idx++;
        }
    }
    if(!mode && !check){
        printf("Amount comparisons in Hash-Table(close): %d\n", *count);
        printf("%s", "The keyword was not found.\n");
        idx = -1;
    }
    else if(!mode){
        printf("Amount comparisons in Hash-Table(close): %d\n", *count);
        printf("%s", "The keyword was found.\n");
        printf("HELP: %s\n", hashtable[idx]->HELP);
        /*printf("%s", "Rewrite HELP description?\n");
        printf("%s", "1 - Yes\n");
        printf("%s", "2 - No\n");
        scanf("%d", &question);
        if(question == 1)
        {
            printf("%s", "Input HELP description:\n");
            fflush(stdin);
            gets(hashtable[idx]->HELP);
        }*/
    }

    return idx;
}

