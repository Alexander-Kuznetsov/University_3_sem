#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    FILE *f;
    f = fopen(argv[1], "r");
    int W, H, p, p1, p2, ind = 0; //W - width; H - height, p - key
    int colonies[20][2];
    int r = 0, l = 0, d = 0, u = 0, ur = 0, ul = 0, dr = 0, dl = 0;
    int **dna;

    fscanf(f, "%d", &H);
    fscanf(f, "%d", &W);

    dna = (int**) malloc(H*sizeof(int));
    for(int i = 0; i < H; i++){
        dna[i] = (int*) malloc((W)*sizeof(int));
        for(int j = 0; j < W; j++){
            fscanf(f,"%d", &dna[i][j]);
        }
    }

    printf("%d %d\n", W, H);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++)
            printf("%d ", dna[i][j]);
        printf("\n");
    }

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++){
            if(dna[i][j] == 1){
                p = i;
                while (p != 0){
                    if(dna[p][j] == 1) u++;
                    else break;
                    p--;
                }
                p = j;
                while (p != 0){
                    if(dna[i][p] == 1) l++;
                    else break;
                    p--;
                }
                p = i;
                while (p != (H-1)){
                    if(dna[p][j] == 1) d++;
                    else break;
                    p++;
                }
                p = j;
                while (p != (W-1)){
                    if(dna[i][p] == 1) r++;
                    else break;
                    p++;
                }
                if (u == d &&  l == r && u == l){
                    p1 = i, p2 = j;
                    while (p1 != 0 && p2 != 0){

                        if(dna[p1][p2] == 1) ul++;
                        else break;
                        p1--;
                        p2--;
                    }
                    p1 = i, p2 = j;
                    while (p1 != 0 && p2 != (W-1)){
                        if(dna[p1][p2] == 1) ur++;
                        else break;
                        p1--;
                        p2++;
                    }
                    p1 = i, p2 = j;
                    while (p1 != (H-1) && p2 != 0){
                        if(dna[p1][p2] == 1) dl++;
                        else break;
                        p1++;
                        p2--;
                    }
                    p1 = i, p2 = j;
                    while (p1 != (H-1) && p2 != (W-1)){
                        if(dna[p1][p2] == 1) dr++;
                        else break;
                        p1++;
                        p2++;
                    }
                    if (dr == dl && ur == ul && dr == ur){
                        colonies[ind][0] = i;
                        colonies[ind][1] = j;
                        ind++;
                    }
                }

            }
            u = d = l = r = dr = dl = ul = ur = 0;
        }

    for (int i = 0; i < ind; i++){
        printf("\nNumber of healthy colonies: %d\n", i+1);
        printf("Colony: %d %d\n", colonies[i][0], colonies[i][0]);
    }
    if (ind == 0)
        printf("\nNot exist healthy colonies!");

    //free memory
    for(int i = 0; i < H; i++)
        free(dna[i]);
    free(dna);

    fclose(f);
}
