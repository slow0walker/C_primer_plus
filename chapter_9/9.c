#include <stdio.h>

double power(double base, int exp)
{
    if (base == 0 && exp == 0)
    {
        printf("0^0 is undefined\n");
        return 1;
    }
    if (exp == 1)
        return 1;

    if (exp > 0)
        return base * power(base, exp - 1);
    else
        return 1 / base * power(base, exp + 1);
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
    return 0;
}