#include <stdio.h>
/*
output:
F
FE
FED
FEDC
FEDCB
FEDCBA
*/
int main()
{
   int row=6,col=6;
   for(int i=0;i<row;i++)
   {
    char ch = 'F';
    for(int j =0;j < i+1;j++)
    {
        printf("%c",ch);
        ch--;
    }    
    printf("\n");
   }
    return 0;
}