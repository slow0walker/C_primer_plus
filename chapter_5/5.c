#include <stdio.h>

int main()
{
    int days,sum=0;
    printf("Enter number of days: ");
    scanf("%d",&days);
    while(days>0)
    {
        sum += days;
        days--;
    }
    printf("The tatal sum for %d days is %d\n",days,sum);
    return 0;
}