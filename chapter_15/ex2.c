#include <stdio.h>
#include <limits.h>
char *itobs(int n, char *ps);
void show_bstr(const char *str);

int main()
{
    char bin_str[CHAR_BIT * sizeof(double) + 1];
    double number;

    puts("Enter double and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%lf", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%lf is: ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");
    return 0;
}
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(double);
    for (i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}
void show_bstr(const char *str)
{
    int i = 0;
    while (str[i])
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i])
            putchar(' ');
    }
}