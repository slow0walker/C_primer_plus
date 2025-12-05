#include <stdio.h>
#include <ctype.h>

void get_first_word(char *word)
{
    int ch;
    while ((ch = getchar()) != EOF && isspace(ch))
        ;

    word[0] = ch;
    int i = 1;
    while ((ch = getchar()) != EOF && !isspace(ch))
    {
        word[i++] = (char)ch;
    }
    word[i] = '\0';

    while ((ch = getchar()) != EOF && ch != '\n')
        ;
}
int main()
{
    char word[100];
    get_first_word(word);
    printf("%s\n", word);
    return 0;
}