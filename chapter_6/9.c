#include <stdio.h>

double calc(double a, double b)
{
    return (a - b) / (a * b);
}

int main()
{
    double num1, num2;

    printf("Enter two numbers(q to quit): ");
    while (scanf("%lf %lf", &num1, &num2) == 2)
    {
        printf("The result of their difference divided by their product is: %.4f\n", calc(num1, num2));
        printf("Enter two numbers(q to quit): ");
    }
    return 0;
}