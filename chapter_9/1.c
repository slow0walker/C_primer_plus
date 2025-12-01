#include <stdio.h>

double min(double a, double b);

int main()
{
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The minimum of %lf and %lf is %lf\n", num1, num2, min(num1, num2));
    return 0;
}

double min(double a, double b)
{
    return (a < b) ? a : b;
}
