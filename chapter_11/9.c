#include <stdio.h>
#include <string.h>

char *string_versed(char *s)
{
    int len = strlen(s);
    char *start = s;
    char *end = s + len - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return s;
}
int main(void)
{
    char str[80];

    while (1)
    {
        printf("Enter a string to reverse (empty to quit):\n");
        if (!fgets(str, sizeof str, stdin) || str[0] == '\n')
            break;

        string_versed(str);
        printf("Reversed: %s\n", str);
    }
    return 0;
}
