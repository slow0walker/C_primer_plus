#include <stdio.h>

int main()
{
    char ch,start = 'A';
    printf("Enter an uppercase letter: ");
    scanf("%c",&ch);

    for(char row =start;row <=ch;row++)
    {
        //handling spaces
        for(char space = ch;space > row;space--)
        {
            printf(" ");
        }
        //printing letters in ascending order
        for(char asc = start;asc<=row;asc++)
        {
            printf("%c",asc);
        }
        //printing letters in descending order
        for(char desc = row - 1;desc >= start;desc--)
        {
            printf("%c",desc);
        }
        printf("\n");
    }
    return 0;
}