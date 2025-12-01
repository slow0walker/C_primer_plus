#include <stdio.h>

void print_char(char ch, int col, int row);

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    int col, row;
    printf("Enter the number of columns and rows: ");
    scanf("%d %d", &col, &row);
    print_char(ch, col, row);
    return 0;
}
void print_char(char ch, int col, int row)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}