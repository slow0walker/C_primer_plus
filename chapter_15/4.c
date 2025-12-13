#include <stdio.h>

int check_bit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}

int main()
{
    int number, position;
    printf("Enter an integer: ");
    scanf("%d", &number);
    while (getchar() != '\n')
        ;

    printf("Enter the bit position to check (0-indexed): ");
    scanf("%d", &position);
    while (getchar() != '\n')
        ;

    if (check_bit(number, position))
        printf("Bit at position %d is 1 in the binary representation of %d.\n", position, number);
    else
        printf("Bit at position %d is 0 in the binary representation of %d.\n", position, number);

    return 0;
}
