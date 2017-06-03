#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f_in, *f_clock;
    char numbers[6][52];
    char myclock[6][22];
    int similarity[10] = {0};
    int differences[10] = {0};
    int its_clock[4];
    int key_clock = 0, key_num = 0, l_num = 0, l_clock = 0, ind_max = -1, max_sim = -1;
    int count = 0;

    f_in = fopen("digits.in.txt", "r");
    for (int i = 0; i < 6; i++)
        fgets(numbers[i],52,f_in);
    fclose(f_in);

    f_clock = fopen("eclock.in3.txt", "r");
    for (int i = 0; i < 6; i++)
        fgets(myclock[i],22,f_clock);
    fclose(f_clock);

    for (int i = 0; i < 6; i++){
        printf("%s", numbers[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 6; i++){
        printf("%s", myclock[i]);
    }
    printf("\n\n");

    while(key_clock != 4){
        while(l_num != 50){
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 5; j++){
                    if (myclock[i][l_clock+j] == '#' && numbers[i][l_num+j] == '#'){
                        similarity[key_num]++;
                    }
                    if (myclock[i][l_clock+j] == '#' && numbers[i][l_num+j] == '.'){
                        differences[key_num]++;
                    }
                }
            }
            l_num+=5;
            key_num++;
        }

        for(int i = 0; i < 10; i++){
           // printf("%d %d", similarity[i], differences[i]);
            if (similarity[i] > max_sim && differences[i] == 0){
                max_sim = similarity[i];
                ind_max = i;
            }
        }

        for(int i = 0; i < 10; i++)
            if (max_sim  == similarity[i]){count++;}

        if (count > 1){
            printf("AMBIGUITY");
            return 0;
        }
        if (ind_max == -1){
            printf("ERROR");
            return 0;
        }

        its_clock[key_clock] = ind_max;
        count = 0;
        ind_max = -1;
        max_sim = -1;
        key_num = 0;
        key_clock++;
        l_clock+=5;
        l_num = 0;
        memset(similarity, 0, sizeof(similarity));
        memset(differences, 0, sizeof(differences));
    }

    for(int i = 0; i < 4; i++){
        if(i == 2)
            printf(":");
        printf("%d", its_clock[i]);
    }

    return 0;
}
