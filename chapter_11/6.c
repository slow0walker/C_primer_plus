#include <stdio.h>
#include <stdbool.h>

bool is_within(const char *s, char ch)
{
    while (*s)
    {
        if (*s == ch)
            return true;
        s++;
    }
    return false;
}
int main()
{
    char *s = "test string";
    int ch;
    while (1)
    {
        printf("Enter a character (q to quit): ");
        ch = getchar();
        while (getchar() != '\n')
            ;
        if (ch == 'q')
            break;
        if (is_within(s, ch))
            printf("%c is in %s\n", ch, s);
        else
            printf("%c is not in %s\n", ch, s);
    }
    return 0;
}