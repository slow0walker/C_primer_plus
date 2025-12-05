#include <stdio.h>
#include <string.h>
char *my_strchr(const char *s, int ch)
{
    while (*s)
    {
        if (*s == ch)
            return (char *)s;
        s++;
    }
    return NULL;
}

int main()
{
    char s[100];
    char ch;

    fgets(s, 100, stdin);

    printf("char to find:");
    scanf("%c", &ch);

    char *p = my_strchr(s, ch);
    if (p)
        printf("Found '%c' at position %ld\n", ch, p - s);
    else
        printf("'%c' not found.\n", ch);
    return 0;
}
