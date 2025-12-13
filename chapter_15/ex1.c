#include <stdio.h>
// bitwise operators

int main()
{
    int a = 5, b = -9;
    printf("a = %d, b = %d\n", a, b);
    printf("a & b = %d\n", a & b);   // bitwise AND
    printf("a | b = %d\n", a | b);   // bitwise OR
    printf("a ^ b = %d\n", a ^ b);   // bitwise XOR
    printf("~a = %d\n", ~a);         // bitwise NOT
    printf("b << 2 = %d\n", b << 2); // left shift
    printf("b >> 2 = %d\n", b >> 2); // right shift

    return 0;
}