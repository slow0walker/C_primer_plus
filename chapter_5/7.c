#include <stdio.h>

double cube(double x);

int main()
{
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("The cube of %.2f is %.2f\n", num, cube(num));
    return 0;
}

double cube(double x)
{
    return x * x * x;
}