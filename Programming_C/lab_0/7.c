//Программа высчитывает площадь треугольника по 3м сторонам
#include <stdio.h>
#include <math.h>
double pow(double x, double y);
int main(){
    double a,b,c,p,s;
    puts("input three hand of triangle(a, b, c)");
    if (scanf("%le %le %le",&a, &b, &c) == 3){
        if ((a < b+c) && (b < a+c) && (c < a+b)){
            p = (a+b+c)/2;
            s = pow((p*(p-a)*(p-b)*(p-c)),0.5);
            printf("Area of trianle is = %f",s);
        }
        else{
            puts("Triangle is not exist");
        }
    }
    else{
        puts("Data is incorrect");
    }
    return 0;
}
