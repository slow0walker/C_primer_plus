#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
#define HALT ""
void stsrt(char *strings[], int num);
char *s_gets(char *st, int n);

int main()
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;
    printf("Input up to %d lines,and I will sort them.\n", LIM);
    printf("To stop,press the Enter key on a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];
        ct++;
    }
    stsrt(ptstr, ct);
    printf("\nHere is your sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]);
    printf("Done.\n");
    return 0;
}

void stsrt(char *strings[], int num)
{
    int i, j;
    char *temp;
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
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