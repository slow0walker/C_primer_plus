#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s_gets(char *st, int n);

int main()
{
    int n;
    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    getchar(); // eat newline

    char **words = malloc(n * sizeof(char *)); // pointer t0 a pointer to char
    char temp[100];
    int count = 0;

    printf("Enter %d words now:\n", n);
    for (int i = 0; i < n; i++)
    {
        s_gets(temp, 100);
        words[i] = malloc(strlen(temp) + 1);

        if (!words[i])
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        strcpy(words[i], temp);
        count++;
    }

    printf("Here are your words:\n");
    for (int i = 0; i < count; i++)
    {
        puts(words[i]);
        free(words[i]);
    }
    free(words);
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
