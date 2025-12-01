#include <stdio.h>

unsigned long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    unsigned long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    for (int i = 0; i <= 20; i++)
        printf("F(%d) = %llu\n", i, fibonacci(i));

    return 0;
}
