#include <stdio.h>
void large_of(double *x, double *y);

int main()
{
    double a, b;
    printf("Enter two numbers:");
    scanf("%lf %lf", &a, &b);

    printf("Before: a=%lf, b=%lf\n", a, b);
    large_of(&a, &b);

    printf("After: a=%lf, b=%lf\n", a, b);
    return 0;
}

void large_of(double *x, double *y)
{
    double max = *x > *y ? *x : *y;
    *x = *y = max;
}