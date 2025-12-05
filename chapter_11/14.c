#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s base exponent\n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exp = atoi(argv[2]);

    double result = pow(base, exp);
    printf("%g ^ %d = %g\n", base, exp, result);
    return 0;
}