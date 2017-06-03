#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char **argv)
{
    FILE *f;
    int result;
    int maxlen[LEN_TABLE] = {0, 0, 0, 0, 0};

    if (argc < 2)
    {
        fprintf(stdout,"Argument not found");
    }
    else
    {
        f = fopen(argv[1], "r");
        result = testing(f, maxlen);
        fclose(f);

        switch (result) {
        case NOT_FOUND:
            fprintf(stdout,"File not found!");
            break;
        case EMPTY:
            fprintf(stdout,"File is empty");
            break;
        case NOT_INT:
            fprintf(stdout,"First column has inadmissible symbol");
            break;
        case NOT_FLOAT:
            fprintf(stdout,"Fourth column has inadmissible symbol");
            break;
        case NOT_NY:
            fprintf(stdout,"Fifth column has inadmissible symbol");
            break;
        case GOOD:
            f = fopen(argv[1], "r");
            getTable(f, maxlen);
            fclose(f);
        }
    }

    return 0;
}





