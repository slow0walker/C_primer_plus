#include <stdio.h>

void to_base_n(unsigned long num, int base)
{
    if (num >= base)
        to_base_n(num / base, base);
    printf("%d", num % base);
}

int main()
{
    to_base_n(129, 8); // 输出 201
    return 0;
}
