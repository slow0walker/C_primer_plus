#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; --i, n >>= 1)
        ps[i] = (n & 1) + '0';
    ps[size] = '\0';
    return ps;
}

int bintodec(const char *binstr)
{
    int res = 0;
    while (*binstr)
    {
        res = (res << 1) | (*binstr - '0');
        binstr++;
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <binary string> <binary string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num1 = bintodec(argv[1]);
    int num2 = bintodec(argv[2]);

    char bstr1[CHAR_BIT * sizeof(int) + 1];
    char bstr2[CHAR_BIT * sizeof(int) + 1];

    printf("First binary string: %s => Decimal: %d\n", argv[1], num1);
    printf("Second binary string: %s => Decimal: %d \n", argv[2], num2);

    int res_not1 = ~num1;
    int res_not2 = ~num2;
    printf("NOT %s = %s => Decimal: %d\n", argv[1], itobs(res_not1, bstr1), res_not1);
    printf("NOT %s = %s => Decimal: %d\n", argv[2], itobs(res_not2, bstr2), res_not2);

    int res_and = num1 & num2;
    printf("%s AND %s = %s => Decimal: %d\n", argv[1], argv[2], itobs(res_and, bstr1), res_and);
    int res_or = num1 | num2;
    printf("%s OR %s = %s => Decimal: %d\n", argv[1], argv[2], itobs(res_or, bstr1), res_or);

    int res_xor = num1 ^ num2;
    printf("%s XOR %s = %s => Decimal: %d\n", argv[1], argv[2], itobs(res_xor, bstr1), res_xor);

    return 0;
}