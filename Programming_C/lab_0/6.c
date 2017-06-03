#include <stdio.h>
 
void times(int t, int *sec, int *min, int *h)
{ 
	 *h = t / 3600;
	 t%= 3600;
	 *min = t/60;
	 *sec = t%60;
}
int main()
{
	int sec,min,h;
	int t;
	puts("input seconds");
	if (scanf("%d", &t) != 1){
		puts("Inputs incorrect");
	}
	else{
		printf("you input time  = %d ", t);
		times(t, &sec, &min, &h);
		printf("\nResult\nhour = %d\nminutes = %d\nseconds = %d", h, min, sec);
	}
  
}