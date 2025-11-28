#include<stdio.h>

#define MINUTES_PER_HOUR 60
int main()
{
    int minutes,hours,remaining_minutes;
    printf("Enter the number of time in minutes(0 or less to quit):");
    scanf("%d",&minutes);
    while(minutes>0)
    {
        hours = minutes / MINUTES_PER_HOUR;
        remaining_minutes = minutes % MINUTES_PER_HOUR;
        printf("%d minutes is %d hours and %d minutes\n",minutes,hours,remaining_minutes);
        printf("Enter the number of time in minutes(0 or less to quit)");
        scanf("%d",&minutes);   
    }
    return 0;
}