#include <stdio.h>
#include <math.h>
#include <conio.h>
double fabs(double j);
double sin(double j);
double pow(double x, double y);
int main()
{   
	double y=0,x,eps;
	
	puts("Input x and eps: ");
	if (scanf("%le %le",&x,&eps)!=2) puts("Incorrect input");
	else
	{
	 double r = x;
	 int k = 1, n = 1;
	 double X=x;
	 double fact = 1; 
	 while (fabs(r) > eps)
	 {
	   if (n>2) 
	   {
	      fact = fact*n*(n-1);
          X=X*x*x;
		  r = k*X/fact;
	   }
	   y+=r;  
	   k*=(-1);
	   n+=2;
	 }
	 double g = sin(x);
	 printf("sin x = %g \ny = %g \n",g,y);
	 printf("%f",g-y);
	 return 1;
	}
}

