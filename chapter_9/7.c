#include <stdio.h>
#include <ctype.h>

int letter_pos(int ch)
{
    if (isalpha(ch))
    {
        return tolower(ch) - 'a' + 1;
    }
    return -1;
}

int main()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            printf("%c is at position %d\n", ch, letter_pos(ch));
        }
        else
        {
            printf("%c is not a letter\n", ch);
        }
    }
}