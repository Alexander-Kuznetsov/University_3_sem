#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define ZERO_COLUMN 0
#define ZERO 0.000001

double *Gaus_method(double **matrix, int n, int *len_roots);
void print(double **matrix, double *roots, int n, int len_roots);

#endif // FUNCTIONS_H
