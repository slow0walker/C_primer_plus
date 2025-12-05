#include <stdio.h>

char *remove_spaces(char *s)
{
    char *p = s;
    while (*s)
    {
        if (*s != ' ')
        {
            *p = *s;
            p++;
        }
        s++;
    }
    *p = '\0';
    return p;
}

int main(void)
{
    char line[100];

    while (1)
    {
        printf("Enter a line (empty line to quit):\n");
        if (!fgets(line, sizeof line, stdin) || line[0] == '\n')
            break;

        remove_spaces(line);
        printf("Without spaces: %s", line);
    }
    return 0;
}