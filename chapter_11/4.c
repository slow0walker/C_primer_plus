#include <stdio.h>
#include <ctype.h>
#define SIZE 5
void get_first_word_n(char *word, int n)
{
    int ch;
    while ((ch = getchar()) != EOF && isspace(ch))
        ;
    int i = 0;
    while (ch != EOF && !isspace(ch) && i < n - 1)
    {
        word[i++] = (char)ch;
        ch = getchar();
    }
    word[i] = '\0';

    while (ch != EOF && ch != '\n')
        ch = getchar();
}
int main()
{
    char word[SIZE];
    printf("Enter the length %d of the word:", SIZE);
    get_first_word_n(word, SIZE + 1);
    printf("%s\n", word);
    return 0;
}
