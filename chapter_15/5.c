#include <stdio.h>
#include <limits.h>
#define INT_SIZE (CHAR_BIT * sizeof(unsigned int))

unsigned int rotate_l(unsigned int x, int n)
{
    if (n == 0)
        return x;
    else
        return (x << n) | (x >> (INT_SIZE - n));
}

char *itobs(unsigned int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(unsigned int);
    for (i = size - 1; i >= 0; --i, n >>= 1)
        ps[i] = (n & 1) + '0';
    ps[size] = '\0';
    return ps;
}

int main()
{
    unsigned int number;
    int positions;
    printf("Enter an unsigned integer: ");
    scanf("%u", &number);
    while (getchar() != '\n')
        ;

    printf("Enter number of positions to rotate left: ");
    scanf("%d", &positions);
    while (getchar() != '\n')
        ;
    char bstr[CHAR_BIT * sizeof(unsigned int) + 1];
    printf("Binary representation of %u is: %s\n", number, itobs(number, bstr));

    unsigned int result = rotate_l(number, positions % INT_SIZE);
    printf("Result after rotating %u left by %d positions is: %u\n", number, positions, result);
    printf("Binary representation of result is: %s\n", itobs(result, bstr));

    return 0;
}