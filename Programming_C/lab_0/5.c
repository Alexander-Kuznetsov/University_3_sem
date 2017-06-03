#include <stdio.h>
void swap(double *a,double *b)
{
	int temp;
	temp = *a, *a = *b, *b = temp;
}

int main()
{
	double a, b;

	puts("input a and b");
	if (scanf("%le %le",&a, &b) != 2){
		puts("input incorrect");
	}
	else{  
		printf("your input: \na = %f \nb =  %f",a, b);
		swap(&a, &b);
        printf("\nresult: \na = %f \nb =  %f",a, b);
	}
    return 0;
}