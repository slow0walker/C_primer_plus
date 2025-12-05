#include <stdio.h>
#define SIZE 15
void getn_chars(char *arr, int n)
{
    int ch;
    // read n characters one by one
    for (int i = 0; i < n; i++)
    {
        if ((ch = getchar()) != EOF)
        {
            arr[i] = ch;
        }
        else
        {
            arr[i] = '\0';
            break;
        }
    }
    // arr[n] = '\0';
    if (n > 0 && arr[n - 1] != '\0')
        arr[n] = '\0';
}
// test
int main()
{
    char arr[SIZE + 1];

    printf("Enter at least 15 characters (including spaces/tabs/newlines):\n");
    getn_chars(arr, SIZE);

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