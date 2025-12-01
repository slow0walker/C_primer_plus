#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int ch;
    bool in_word = false;
    int word_count = 0, letter_count = 0;

    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch))
        {
            letter_count++;
            if (!in_word)
            {
                in_word = true;
                word_count++;
            }
        }
        else
        {
            in_word = false;
        }
    }
    if (word_count > 0)
    {
        double average = (double)letter_count / word_count;
        printf("Average number of letters per word: %.2f\n", average);
    }
    else
    {
        printf("No words were entered.\n");
    }
    return 0;
}