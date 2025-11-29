#include<stdio.h>

int main()
{
    int ch;
    int count = 0;
    printf("Enter text to analyze (# to exit):\n");
    while((ch=getchar())!= '#')
    {
        switch (ch)
        {
        case '.':printf("!");count++; break;
        case '!':printf("!!");count++; break;      
        default:
            putchar(ch);
            break;
        }
    }
    printf("\nTotal substitutions made: %d\n", count);
    return 0;
}