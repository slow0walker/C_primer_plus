#include <stdio.h>
#include <ctype.h>

char get_first(void)
{
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch)) // 非空白
            return ch;
    }
    return '\0';
}

int main(void)
{
    printf("Enter a line: ");
    char c = get_first();
    printf("First non-space char: %c\n", c);
    return 0;
}
