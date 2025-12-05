#include <stdio.h>
#include <ctype.h>
#define SIZE 15
void getn_non_chars(char *arr, int n)
{
    int ch;
    for (int i = 0; i < n; i++)
    {
        if ((ch = getchar()) == EOF)
        {
            arr[i] = '\0';
            break;
        }
        if (isspace(ch))
        {
            arr[i] = '\0';
            break;
        }
        arr[i] = ch;
        if (i == n - 1)
            arr[i + 1] = '\0';
    }
}

int main()
{
    char arr[SIZE + 1];

    printf("Enter at least 15 characters (including spaces/tabs/newlines):");
    getn_non_chars(arr, SIZE);

    printf("\nRead %d characters:\n", SIZE);
    for (int i = 0; i < SIZE && arr[i] != '\0'; i++)
    {
        if (arr[i] == '\n')
            printf("\\n\n");
        else if (arr[i] == '\t')
            printf("\\t\n");
        else if (arr[i] == ' ')
            printf("\\s\n");
        else
            printf("%c\n", arr[i]);
    }
    printf("\nDone.\n");
    return 0;
}