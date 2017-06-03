#include <stdio.h>
int fibo(int a)
{
	int prev = 1;
	int cur = 1; 
	int temp = 0;

	if (a == 1){
		return 1;
	}
	while (cur < a){
	    temp = cur;
	    cur += prev;
	    prev = temp;
	}
	if (cur == a){
		return 1;
    }
	return 0;
}

int main()
{
    int k = 0;
    int chislo;
    puts("input chisla:");
    while (scanf("%d",&chislo) == 1){
	    k += fibo(chislo);
    }
    printf("kolvo chisel fibonachi = %d", k);
    return 0;
}
