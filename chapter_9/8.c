#include <stdio.h>

double power(double base, int exp)
{
    if (base == 0 && exp == 0)
    {
        printf("0^0 is undefined\n");
        return -1;
    }
    if (exp == 0)
        return 1;
    int n = (exp > 0) ? exp : -exp;
    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= base;
    }
    return (exp > 0) ? result : 1 / result;
}
int main()
{
    double base;
    int exp;
    printf("Enter base and exponent: ");
    while (scanf("%lf %d", &base, &exp) == 2)
    {
        printf("%lf to the power %d is %lf\n", base, exp, power(base, exp));
        printf("Enter base and exponent(q to quit): ");
    }
}