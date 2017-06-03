#include "table.h"

void pod(int width);

void init(int *len_table, int *len_column, FILE *f){
    //заполнение заголовков таблицы
    for(int i = 0; i < LEN_HEAD; i++){
        fscanf(f,"%s", head[i].header);
    }
    //инициализация
    while (!feof(f)){
        fscanf(f,"%s", table[*len_table].surname);
        fscanf(f,"%s", table[*len_table].book);
        fscanf(f,"%s", table[*len_table].publishing);
        fscanf(f,"%s", table[*len_table].num_les);
        fscanf(f,"%s", table[*len_table].typebook);
        if(strcmp(table[*len_table].typebook, "Technical") == 0){
            fscanf(f,"%s", table[*len_table].uni.tech.industry);
            fscanf(f,"%s", table[*len_table].uni.tech.national);
            fscanf(f,"%s", table[*len_table].uni.tech.translate);
            fscanf(f,"%s", table[*len_table].uni.tech.year);
        }
        else{
            fscanf(f,"%s", table[*len_table].uni.art.genre);
        }
        *len_table+=1;
    }
    *len_table-=1;

    //Определение максимальной длины столбцов
    for (int i = 0; i < LEN_HEAD; i++){
        len_column[i] = comparison(head[i].header, len_column[i]);
    }
    for (int i = 0; i < *len_table; i++){
        len_column[0] = comparison(table[i].surname, len_column[0]);
        len_column[1] = comparison(table[i].book, len_column[1]);
        len_column[2] = comparison(table[i].publishing, len_column[2]);
        len_column[3] = comparison(table[i].num_les, len_column[3]);
        len_column[4] = comparison(table[i].typebook, len_column[4]);
        if(strcmp(table[i].typebook, "Technical") == 0){
            len_column[6] = comparison(table[i].uni.tech.industry, len_column[6]);
            len_column[7] = comparison(table[i].uni.tech.national, len_column[7]);
            len_column[8] = comparison(table[i].uni.tech.translate, len_column[8]);
            len_column[9] = comparison(table[i].uni.tech.year, len_column[9]);
        }
        else{
            len_column[5] = comparison(table[i].uni.art.genre, len_column[5]);
        }
    }
}

void print_table(int len_table, int *len_column){
    if (len_table != 0){
        int width = 0;

        //width of the table
        for (int i = 0; i < LEN_HEAD; i++)
            width += (len_column[i]);
        width += (LEN_HEAD+6);
        pod(width);

        printf("|%*s",4,"No");
        for (int i = 0; i < LEN_HEAD; i++)
            printf("|%*s", len_column[i], head[i].header);
        printf("|\n");

        for (int i = 0; i < len_table; i++){
            pod(width);
            printf("|%*d",4,i+1);
            printf("|%*s", len_column[0], table[i].surname);
            printf("|%*s", len_column[1], table[i].book);
            printf("|%*s", len_column[2], table[i].publishing);
            printf("|%*s", len_column[3], table[i].num_les);
            printf("|%*s", len_column[4], table[i].typebook);
            if(strcmp(table[i].typebook, "Technical") == 0){
                printf("|%*s", len_column[5], "-");
                printf("|%*s", len_column[6], table[i].uni.tech.industry);
                printf("|%*s", len_column[7], table[i].uni.tech.national);
                printf("|%*s", len_column[8], table[i].uni.tech.translate);
                printf("|%*s", len_column[9], table[i].uni.tech.year);
            }
            else{
                printf("|%*s", len_column[5], table[i].uni.art.genre);
                printf("|%*s", len_column[6], "-");
                printf("|%*s", len_column[7], "-");
                printf("|%*s", len_column[8], "-");
                printf("|%*s", len_column[9], "-");
            }
            printf("|\n");
        }
        pod(width);
    }
    else
        printf("Error: table is empty!");
}
void pop_table(int num, int *len_table){
    int ind;

    if (*len_table == 0){
        printf("Error: table is empty!");
    }
    else{
        for (int i = (num-1); i < (*len_table-1); i++){
            table[i] = table[i+1];
        }
        //Поиск в таблице ключей индекса исходной таблицы
        for (int i = 0; i < *len_table; i++){
            if(table_keys[i].index_main == num){
                ind = i;
                break;
            }
        }
        for (int i = (ind-1); i < (*len_table-1); i++){
            table_keys[i] = table_keys[i+1];
        }

        *len_table -= 1;
    }
}

void push_table(int *len_table, int *len_column){
    if (*len_table != MAX_LEN){
        int tmp;

        printf("Input name(string): ");
        gets(table[*len_table].surname); gets(table[*len_table].surname);
        len_column[0] = comparison(table[*len_table].surname, len_column[0]);

        printf("Input book(string): ");
        gets(table[*len_table].book);
        len_column[1] = comparison(table[*len_table].book, len_column[1]);

        printf("Input publishing(string): ");
        gets(table[*len_table].publishing);
        len_column[2] = comparison(table[*len_table].publishing, len_column[2]);

        printf("Input num_les(int(1...5000)): ");
        tmp = input(1, 5000);
        itoa(tmp, table[*len_table].num_les, 10);
        len_column[3] = comparison(table[*len_table].num_les, len_column[3]);

        printf("input type of book 1)Technical or 2)Art");
        tmp = input(1, 2);
        if (tmp == 1){
            strcpy(table[*len_table].typebook, "Technical");

            printf("Input industry(string): ");
            gets(table[*len_table].uni.tech.industry); gets(table[*len_table].uni.tech.industry);
            len_column[6] = comparison(table[*len_table].uni.tech.industry, len_column[6]);

            printf("input national of book 1)Yes or 2)No");
            tmp = input(1, 2);
            if (tmp == 1) strcpy(table[*len_table].uni.tech.national, "Yes");
            else strcpy(table[*len_table].uni.tech.national, "No");

            printf("input translate of book 1)Yes or 2)No");
            tmp = input(1, 2);
            if (tmp == 1) strcpy(table[*len_table].uni.tech.translate, "Yes");
            else strcpy(table[*len_table].uni.tech.translate, "No");

            printf("Input year(int(1800...2016)): ");
            tmp = input(1800, 2016);
            itoa(tmp, table[*len_table].uni.tech.year, 10);
            len_column[9] = comparison(table[*len_table].uni.tech.year, len_column[9]);
        }
        else{
            strcpy(table[*len_table].typebook, "Art");

            printf("Input genre of Art(string): ");
            gets(table[*len_table].uni.art.genre); gets(table[*len_table].uni.art.genre);
            len_column[5] = comparison(table[*len_table].uni.art.genre, len_column[5]);
        }
        table_keys[*len_table].index_main = *len_table+1;
        table_keys[*len_table].main_less = atoi(table[*len_table].num_les);
        *len_table +=1;

    }
    else
        printf("Error: Table is overflow!(50 strings)");
}

void timer(int len_table, FILE *fsort){
    clock_t time_bubble_keys, time_bubble_table;

    //время работы сортировки таблицы пузырьком
    time_bubble_table = clock();
    bubble_sort_table(len_table);
    time_bubble_table = clock() - time_bubble_table;
    printf("Time Bubble Sort Main Table with %d elements is: %.lf ticks\n",
           len_table, (double) (time_bubble_table/C_SEC));
    //Время работы сортировки с ключом пузырьком
    time_bubble_keys = clock();
    bubble_sort_keys(len_table);
    //имитация выборки данных из основной таблицы
   /* for (int i = 0; i < len_table; i++)
        for (int j = 1; j <= len_table; j++)
            if (table_keys[i].index_main == j){
                continue;
            }*/
    time_bubble_keys = clock() - time_bubble_keys;
    printf("Time Bubble Sort Table of Keys with %d elements is: %.lf ticks\n",
           len_table, (double) (time_bubble_keys/C_SEC));

    printf("\nBubbles sort with keys quickly in %lf\n", ((double)time_bubble_table/(double)time_bubble_keys));
    printf("Keys have biggest memory relativily without keys: %d bytes\n\n", len_table*4*4*2);
}
void quick_timer(int len_table, FILE *quick_file){
    clock_t  time_quick_keys, time_quick_table;
    //время работы сортировки таблицы быстрая
    time_quick_table = clock();
    quick_sort_table(0, len_table-1);
    time_quick_table = clock() - time_quick_table;
    printf("Time Quick Sort Main Table with %d elements is: %.lf ticks\n",
           len_table, (double) (time_quick_table/C_SEC));
    //Время работы сортировки с ключом пузырьком
    time_quick_keys = clock();
    quick_sort_keys(0, len_table-1);
    //имитация выборки данных из основной таблицы
 /*   for (int i = 0; i < len_table; i++)
        for (int j = 1; j <= len_table; j++)
            if (table_keys[i].index_main == j){
                continue;
            }*/
    time_quick_keys = clock() - time_quick_keys;
    printf("Time Quick Sort Table of Keys with %d elements is: %.lf ticks\n",
           len_table, (double) (time_quick_keys/C_SEC));
    printf("\nQuick sort with keys Slowly in %lf\n", ((double)time_quick_keys/(double)time_quick_table));
    printf("Keys have biggest memory relativily without keys: %d bytes\n\n", len_table*4*4*2);
}

void search_table(int len_table){
    char industr[50];
    int y;
    int count = 0;
    printf("%s\n", "Input your industry: ");
    scanf("%s", industr);
    printf("%s\n", "Input your year: ");
    y = input(1800, 2016);
    printf("With keys(translate: Yes, industry: %s, year : < %d) FOUND: ", industr, y);
    for (int i = 0; i < len_table; i++){
        if (strcmp(table[i].typebook,"Technical") == 0 &&
        strcmp(table[i].uni.tech.industry, industr) == 0 &&
        atoi(table[i].uni.tech.year) < y){
            count++;
            printf("%s; ", table[i].book);
        }
    }
    if (count == 0)
        printf("%d", 0);
    printf("\n");
}

void init_keys(int len_table){
    for (int i = 0; i < len_table; i++){
        table_keys[i].index_main = i+1;
        table_keys[i].main_less = atoi(table[i].num_les);
    }
}

void print_keys(int len_table){
    if (len_table != 0){
        pod(20);
        printf("|%*s", 9, "ind_main");
        printf("|%*s", 8, head[3].header);
        printf("|\n");
        pod(20);
        for (int i = 0; i < len_table; i++){
            printf("|%*d", 9, table_keys[i].index_main);
            printf("|%*d", 8, table_keys[i].main_less);
            printf("|\n");
            pod(20);
        }
    }
    else
        printf("Error: table is empty");
}

/*void quick_sort_keys(int b, int c){
      int l = b, r = c;
      int piv = table_keys[(l + r) / 2].main_less;
      while (l <= r)
      {
        while (table_keys[l].main_less < piv)
          l++;
        while (table_keys[r].main_less > piv)
          r--;
        if (l <= r){
            Keys tmp;
            //tmp = table_keys[l++]; table_keys[l++] = table_keys[r--]; table_keys[r--] = tmp;
            tmp = table_keys[l]; table_keys[l] = table_keys[r]; table_keys[r] = tmp;
            l++; r--;
        }
      }
      if (b < r)
        quick_sort_keys (b, r);
      if (c > l)
        quick_sort_keys (l, c);
}*/
void quick_sort_keys(int l, int r)
{
    int x = table_keys[l + (r - l) / 2].main_less;
    int i = l;
    int j = r;
    Keys tmp;
    while(i <= j)
    {
        while(table_keys[i].main_less < x) i++;
        while(table_keys[j].main_less > x) j--;
        if(i <= j)
        {
            tmp = table_keys[i]; table_keys[i] = table_keys[j]; table_keys[j] = tmp;
            i++;
            j--;
        }
    }
    if (i<r){
        quick_sort_keys(i, r);
    }

    if (l<j){
        quick_sort_keys(l, j);
    }
}

void quick_sort_table(int l, int r)
{
    int x = atoi(table[l + (r - l) / 2].num_les);
    int i = l;
    int j = r;
    Common tmp;
    while(i <= j)
    {
        while(atoi(table[i].num_les) < x) i++;
        while(atoi(table[j].num_les) > x) j--;
        if(i <= j)
        {
            tmp = table[i]; table[i] = table[j]; table[j] = tmp;
            i++;
            j--;
        }
    }
    if (i<r){
        quick_sort_table(i, r);
    }

    if (l<j){
        quick_sort_table(l, j);
    }
}

void bubble_sort_keys(int len_table){
    Keys tmp;
    for(int i = 0; i < len_table; i++)
        for(int j = 0; j < (len_table-1); j++){
            if (table_keys[j].main_less > table_keys[j+1].main_less){
                tmp = table_keys[j];
                table_keys[j] = table_keys[j+1];
                table_keys[j+1] = tmp;
            }
        }
}

void bubble_sort_table(int len_table){
    Common tmp;
    for(int i = 0; i < len_table; i++)
        for(int j = 0; j < (len_table-1); j++){
            if (atoi(table[j].num_les) > atoi(table[j+1].num_les)){
                tmp = table[j];
                table[j] = table[j+1];
                table[j+1] = tmp;
            }
        }
}

void print_order_table(int len_table, int *len_column){
    if (len_table != 0){
        int width = 0;

        //width of the table
        for (int i = 0; i < LEN_HEAD; i++)
            width += (len_column[i]);
        width += (LEN_HEAD+6);
        pod(width);

        printf("|%*s",4,"No");
        for (int i = 0; i < LEN_HEAD; i++)
            printf("|%*s", len_column[i], head[i].header);
        printf("|\n");

        for (int i = 0; i < len_table; i++){
            pod(width);
            printf("|%*d",4,i+1);
            printf("|%*s", len_column[0], table[(table_keys[i].index_main-1)].surname);
            printf("|%*s", len_column[1], table[(table_keys[i].index_main-1)].book);
            printf("|%*s", len_column[2], table[(table_keys[i].index_main-1)].publishing);
            printf("|%*s", len_column[3], table[(table_keys[i].index_main-1)].num_les);
            printf("|%*s", len_column[4], table[(table_keys[i].index_main-1)].typebook);
            if(strcmp(table[(table_keys[i].index_main-1)].typebook, "Technical") == 0){
                printf("|%*s", len_column[5], "-");
                printf("|%*s", len_column[6], table[(table_keys[i].index_main-1)].uni.tech.industry);
                printf("|%*s", len_column[7], table[(table_keys[i].index_main-1)].uni.tech.national);
                printf("|%*s", len_column[8], table[(table_keys[i].index_main-1)].uni.tech.translate);
                printf("|%*s", len_column[9], table[(table_keys[i].index_main-1)].uni.tech.year);
            }
            else{
                printf("|%*s", len_column[5], table[(table_keys[i].index_main-1)].uni.art.genre);
                printf("|%*s", len_column[6], "-");
                printf("|%*s", len_column[7], "-");
                printf("|%*s", len_column[8], "-");
                printf("|%*s", len_column[9], "-");
            }
            printf("|\n");
        }
        pod(width);
    }
    else
        printf("Error: table is empty!");
}

int comparison(char *str, int len_column){
    if (strlen(str) > len_column)
        return (strlen(str));
    else
        return len_column;
}

void pod(int width){
    for (int i = 0; i < width; i++)
        printf("-");
    printf("\n");
}

