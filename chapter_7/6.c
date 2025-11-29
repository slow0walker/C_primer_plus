#include<stdio.h>

int main()
{
    int pre_ch=0,cur_ch=0;
    int count = 0;
    printf("Enter text to analyze (# to exit):\n");
    while((cur_ch = getchar())!= '#')
    {
        if(pre_ch == 'e'&& cur_ch == 'i')
        {
            count++;
        }
        pre_ch = cur_ch;

    }
    printf("The sequence 'ei' occurred %d times.\n", count);
    return 0;   
}