#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;
    int n_lower = 0, n_upper = 0, n_other = 0;
    printf("Enter text (ctrl+Z to end):\n");
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            n_lower++;
        else if (isupper(ch))
            n_upper++;
        else
            n_other++;
    }

    printf("Lowercase letters: %d\n", n_lower);
    printf("Uppercase letters: %d\n", n_upper);
    printf("Other characters: %d\n", n_other);
    return 0;
}