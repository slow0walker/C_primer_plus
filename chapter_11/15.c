#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *s);

int main(void)
{
    char buf[80];

    while (1)
    {
        printf("Enter an integer string (empty to quit):\n");
        if (!fgets(buf, sizeof buf, stdin) || buf[0] == '\n')
            break;
        printf("my_atoi = %d\n", my_atoi(buf));
    }
    return 0;
}

int my_atoi(const char *s)
{
    int sign = 1;
    long result = 0;

    while (isspace((unsigned char)*s))
        s++;

    if (*s == '+' || *s == '-')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }

    if (!isdigit((unsigned char)*s))
        return 0; /* 不是纯数字 */

    while (*s && *s != '\n')
    {
        if (!isdigit((unsigned char)*s))
            return 0;
        result = result * 10 + (*s - '0');
        s++;
    }
    return (int)(sign * result);
}
