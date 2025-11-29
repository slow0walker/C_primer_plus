#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    printf("Give me a letter of the alphabet, and I will give an animal name\n");
    printf("beginning with that letter: ");

    printf("Please enter a letter;type # end my act.\n");
    while((ch=getchar())!= '#')
    {
        if(ch== '\n')
            continue;
        if(islower(ch))
        {
            switch(ch)
            {
                case 'a': printf("antelope\n"); 
                case 'b': printf("bear\n"); 
                case 'c': printf("cat\n"); break;
                case 'd': printf("dog\n");
                case 'e': printf("elephant\n"); break;
                case 'f': printf("fox\n"); break;
                case 'g': printf("goat\n"); break;
                case 'h': printf("hippopotamus\n"); break;
                case 'i': printf("impala\n"); 
                case 'j': printf("jaguar\n"); break;
                case 'k': printf("kangaroo\n"); break;
                case 'l': printf("lion\n"); 
                case 'm': printf("monkey\n"); break;
                case 'n': printf("newt\n"); break;
                default:  printf("That's not a letter of the alphabet.\n");
            }
        }
        else
        {
            printf("Please enter a lowercase letter.\n");
        }
        while(getchar() != '\n')
            continue;
        printf("Please enter another letter or a # to end my act.\n");

    }
    printf("Bye!\n");
    return 0;
}