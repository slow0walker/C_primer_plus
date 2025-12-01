#include <stdio.h>
int main()
{
    int low = 1, high = 100;
    int guess = 50;
    char response;
    printf("Think of a number between %d and %d.\n", low, high);
    while (low <= high)
    {
        printf("Is your number %d? (h/l/c): ", guess);
        scanf(" %c", &response);
        if (response == 'c')
        {
            printf("Yay! I guessed your number %d correctly.\n", guess);
            break;
        }
        else if (response == 'h')
        {
            high = guess - 1;
        }
        else if (response == 'l')
        {
            low = guess + 1;
        }
        else
        {
            printf("Invalid input. Please enter 'h', 'l', or 'c'.\n");
            continue;
        }
        guess = (low + high) / 2;
    }
}