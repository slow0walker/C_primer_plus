#include<stdio.h>

int main()
{
    char ch;
    int count = 0;
    printf("Enter a character (# to exit):\n");
    while((ch = getchar()) != '#')
    {
        printf("The ASCII value of '%c' is %d\n", ch, ch);
        count++;
        if(count % 8 == 0)
        printf("\n");
    }
    printf("\n");
    return 0;
}