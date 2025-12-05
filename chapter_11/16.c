#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int mode = 'p';
    if (argc > 1)
    {
        if (strcmp(argv[1], "-u") == 0)
            mode = 'u';
        else if (strcmp(argv[1], "-l") == 0)
            mode = 'l';
        else
            mode = 'p';
    }

    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (mode == 'u')
            ch = toupper(ch);
        else if (mode == 'l')
            ch = tolower(ch);
        putchar(ch);
    }
    return 0;
}