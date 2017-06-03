#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void getTable(FILE *f, int *maxlen)
{
    int sum = LEN_TABLE;
    int keystr = 0;
    int k = 0;
    int lane = 0;
    int lanes = 0;

    char str[40];

    for (int i = 0; i < LEN_TABLE; i++)
        sum+=maxlen[i];

    while  (fscanf(f,"%s",str) == 1)
    {
        if (keystr == 0)
        {
            for(int i = 0; i <= sum; i++)
                fprintf(stdout,"-");
            fprintf(stdout,"\n");
            keystr = 1;
        }

        k++;

        if (k == 1)
            fprintf(stdout,"|%*s",maxlen[0],str);
        if (k == 2)
            fprintf(stdout,"|%*s",-maxlen[1],str);
        if (k == 3)
            fprintf(stdout,"|%*s",-maxlen[2],str);
        if (k == 4)
        {
            if (lane == 1)
            {
                float temp = atof(str);
                fprintf(stdout,"|%*.2f",maxlen[3],temp);
            }
            else
            {
                fprintf(stdout,"|%*s",maxlen[3],str);
            }
        }
        if (k == 5)
        {
            if (lane == 0)
            {
                fprintf(stdout,"|%*s",maxlen[4],str);
            }
            else
            {
                fprintf(stdout,"|%*s%*c",(maxlen[4]+1)/2,str,maxlen[4]/2,' ');
            }
        }


        if (k == LEN_TABLE)
        {
            printf("|\n");
            k = 0;
            keystr = 0;
            lane = 1;
            lanes++;
        }
    }
    for(int i = 0; i <= sum; i++)
       fprintf(stdout,"-");
    fprintf(stdout,"\nlanes are %d", lanes-1);
}
