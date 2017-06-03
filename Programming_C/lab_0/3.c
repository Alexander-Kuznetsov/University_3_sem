#include <math.h>
#include <stdio.h>
#include <conio.h>
int main()
{   
	int a, max, k = 0;
	if (scanf("%d", &a) == 1) 
	{
		max = a;
		k++;		
	}
	else 
	{
		puts("Input incorrect");
		return -1;
	}
   
	while(scanf("%d", &a) == 1)
	{		
//		if ()
		{
			if (a == max) k++;
			if (a > max) {max = a; k = 1;}	
		}
//		else
//		{  
//			
//		}
	}
    printf("Amount of maximum correct input = %d \nMaximum = %d", k, max);
//		    return -1;
	getch();
    return 0;
}