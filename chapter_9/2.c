#include <stdio.h>

void chline(char ch, int row, int col);

int main()
{
    int i, j;
    printf("Enter the number of rows and columns:");
    scanf("%d %d", &i, &j);
    getchar();
    int ch;
    printf("Enter the character:");
    scanf("%c", &ch);
    chline(ch, i, j);
    return 0;
}

void chline(char ch, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}