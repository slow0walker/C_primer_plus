#include <stdio.h>

// returns the number of 1 bits in the binary representation of n
int count_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
}

int main()
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    while (getchar() != '\n')
        ;

    int count = count_set_bits(number);
    printf("Number of \"on\" bits in binary representation of %d is: %d\n", number, count);
    return 0;
}