#include<stdio.h>
#include<string.h>
int main()
{
    char line[256];
    printf("Enter a line of text:\n");
    fgets(line, sizeof(line), stdin);
    printf("You entered: %s", line);

    printf("The reverse of the line is:\n");
    int len =strlen(line);
    for(int i=len-1;i>=0;i--)
        putchar(line[i]);
    return 0;
}