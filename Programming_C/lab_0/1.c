#include <math.h>
#include <stdio.h>
int main()
{
	float a,b,c,d,x1,x2;

	puts("Input equation coefficients:");

	if 	(scanf("%f %f %f",&a,&b,&c) != 3)  puts("Input not correct");	
	else
	{
	   if (a == 0)
	   {
	       if (b == 0) puts("Equation don`t have roots");
	       else
	       {
	          x1=-c/b;
	          printf("Root equation x = %f",x1);
	       }
	   }
	   else
	   {
		   d = b*b-4*a*c;

		   if (d==0)
		   {
		      x1 = -b/(2*a);
		      printf("Exist only 1 root x = %f", x1);
		   }
		   if (d > 0)
	       {
		      d = sqrt(d);
		      x1 = (-b+d)/(2*a);
		      x2 = (-b-d)/(2*a);
		      printf("x1 = %f\nx2 = %f", x1, x2);
	       } 
		  if (d < 0) puts("Equation don`t have roots because D<0");
	  }
   }
   return 0;
}