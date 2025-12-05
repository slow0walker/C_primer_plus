#include <stdio.h>

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    // if the source string is shorter than n,fill the rest of the dest with '\0'
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }
    return dest;
}
int main(void)
{
    char dest[20];

    while (1)
    {
        char src[20];
        printf("Enter a string (empty line to quit):\n");
        if (!fgets(src, sizeof src, stdin) || src[0] == '\n')
            break;

        mystrncpy(dest, src, 5);
        printf("Copied (n=5): \"%s\"\n", dest);
    }
    return 0;
}