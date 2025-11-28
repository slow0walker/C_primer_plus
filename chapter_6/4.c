#include<stdio.h>
/*
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/

int main()
{
    int row = 6,col = 6;
    for(int i =0;i<row;i++)
    {
        char ch = 'A'+ i*(i+1)/2;
        for(int j =0;j < i+1;j++)
        {
            printf("%c",ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}