#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0, n = 0, l, r, k = 0, i = 0; //m - число досок в заборе || n - число дней
    scanf("%d%d", &m, &n);
    if ((m >= 1 && m <= 10000) && (n >= 1 && n <= 1000)){
        int *zabor;
        zabor = calloc(m+1,sizeof(int));
        while(k != n){
            scanf("%d%d", &l, &r);
            if(l >= 1 && l <= r && r <= m){
                for(i = l; i <= r; i++){
                    zabor[i] = 1;
                }
                k++;
            }
            else{
                printf("input incorrect!");
                return 0;
            }
        }
        for (i = 1; i <= m; i++){
            if (zabor[i] == 0){
                printf("NO");
                return 0;
            }
        }
        printf("YES");
        free(zabor);
    }
    else{
        printf("input incorrect!");
    }
    return 0;
}
