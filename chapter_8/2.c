#include <stdio.h>
#include <ctype.h>

void show_char(int ch);

int main()
{
    int ch;
    int count = 0;
    printf("Enter text (ctrl+Z to end):\n");
    while ((ch = getchar()) != EOF)
    {
        show_char(ch);
        printf(" : %3d\n", ch);
        count++;
        if (ch == '\n')
            count = 0;
        if (count % 10 == 0)
        {
            putchar('\n');
            count = 0;
        }
    }
    return 0;
}

void show_char(int ch)
{
    if (ch == ' ')
        printf("' ");
    else if (ch == '\n')
        printf("'\\n'");
    else if (ch == '\t')
        printf("'\\t'");
    else if (iscntrl(ch))
        printf("^%c", ch + 64);
    else
        printf("'%c'", ch);
}