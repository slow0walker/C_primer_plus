#include <stdio.h>

int main()
{
    int a[8];
    for(int i =0;i<8;i++)
        a[i]= 1<<i;
    
    for(int i =0;i<8;i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}