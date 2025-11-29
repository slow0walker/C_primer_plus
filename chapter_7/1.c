#include <stdio.h>
// This program counts spaces, newlines, and other characters in the input until '#' is encountered.

int main()
{
    int n_spaces=0,n_newlines = 0,n_other = 0;
    char ch;
    printf("Enter text to analyze(# to exit):\n");
    while((ch = getchar()) != '#')
    {
        if(ch==' ')
            n_spaces++;
        else if(ch=='\n')
            n_newlines++;
        else
            n_other++;
    }
    printf("Spaces: %d\nNewlines: %d\nOther characters: %d\n", n_spaces, n_newlines, n_other);
    return 0;
}