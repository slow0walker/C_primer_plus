#include <stdio.h>

void to_binary(unsigned int n)
{
    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    putchar(r + '0');
    return;
}
int main()
{
    unsigned int n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    printf("Binary representation: ");
    to_binary(n);
    printf("\n");
    return 0;
}