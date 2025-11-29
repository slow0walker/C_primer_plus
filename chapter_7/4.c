#include<stdio.h>

int main()
{
    int ch;
    int count = 0;
    printf("Enter text to analyze (# to exit):\n");
    while((ch=getchar())!= '#')
    {
        if(ch == '.')
        {
            putchar('!');
            count++;
        }
        else if(ch== '!')
        {
            putchar('!');
            putchar('!');
            count++;
        }
        else{
            putchar(ch);
        }
    }
    printf("\nTotal substitutions made: %d\n", count);
    return 0;
}