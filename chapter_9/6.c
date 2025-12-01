#include <stdio.h>

void sort3(double *x, double *y, double *z)
{
    // from the mim to large
    double temp;
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if (*y > *z)
    {
        temp = *y;
        *y = *z;
        *z = temp;
    }
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}
int main()
{
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    sort3(&x, &y, &z);
    printf("%lf %lf %lf", x, y, z);
    return 0;
}