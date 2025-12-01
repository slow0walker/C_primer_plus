#include <stdio.h>

double harmonic_averag(double a, double b);

int main()
{
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("The harmonic average of %lf and %lf is %lf\n", a, b, harmonic_averag(a, b));
    return 0;
}

double harmonic_averag(double a, double b)
{
    return (2 * a * b) / (a + b);
}
