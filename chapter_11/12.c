#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int ch;
    unsigned int word_count = 0;
    unsigned int upper_count = 0;
    unsigned int lower_count = 0;
    unsigned int punctuation_count = 0;
    unsigned int digit_count = 0;
    bool in_word = false;

    while ((ch = getchar()) != EOF)
    {
        if (isupper(ch))
            upper_count++;
        else if (islower(ch))
            lower_count++;
        else if (isdigit(ch))
            digit_count++;
        else if (ispunct(ch))
            punctuation_count++;

        if (isspace(ch))
            in_word = false;
        else if (!in_word)
        {
            word_count++;
            in_word = true;
        }
    }
    printf("Words: %u\n", word_count);
    printf("Uppercase: %u\n", upper_count);
    printf("Lowercase: %u\n", lower_count);
    printf("Digits: %u\n", digit_count);
    printf("Punctuation: %u\n", punctuation_count);
    return 0;
}