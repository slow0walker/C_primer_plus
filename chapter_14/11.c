#include <stdio.h>
#include <math.h>
void transform(double source[], double target[], int n, double (*fp)(double));

/* 自定义函数 */
double square(double x)
{
    return x * x;
}

double half(double x)
{
    return x / 2.0;
}

int main(void)
{
    double source[5] = {0.0, 0.5, 1.0, 1.5, 2.0};
    double target[5];

    printf("Source array:\n");
    for (int i = 0; i < 5; i++)
        printf("%.3f ", source[i]);
    printf("\n\n");

    /* 1. 调用 math.h 的 sin */
    transform(source, target, 5, sin);
    printf("Apply sin:\n");
    for (int i = 0; i < 5; i++)
        printf("%.3f ", target[i]);
    printf("\n\n");

    /* 2. 调用 math.h 的 cos */
    transform(source, target, 5, cos);
    printf("Apply cos:\n");
    for (int i = 0; i < 5; i++)
        printf("%.3f ", target[i]);
    printf("\n\n");

    /* 3. 调用自定义函数 square */
    transform(source, target, 5, square);
    printf("Apply square:\n");
    for (int i = 0; i < 5; i++)
        printf("%.3f ", target[i]);
    printf("\n\n");

    /* 4. 调用自定义函数 half */
    transform(source, target, 5, half);
    printf("Apply half:\n");
    for (int i = 0; i < 5; i++)
        printf("%.3f ", target[i]);
    printf("\n\n");

    return 0;
}

void transform(double source[], double target[], int n, double (*fp)(double))
{
    for (int i = 0; i < n; i++)
        target[i] = fp(source[i]);
}
