#include <stdio.h>

int main()
{
    const int rows  = 5;
    const int cols  = 5;
    for(int i =0;i<rows;i++)
    {
        for(int j =0;j<i+1;j++)
        {
            printf("$");
        }
        printf("\n");
    }
    return 0;
}