#include <stdio.h>

int main()
{
    int days,week,reminder_days;
    printf("Enter number of days(0 or less to quit):");
    scanf("%d",&days);
    while(days > 0)
    {
        week =days / 7;
        reminder_days = days % 7;
        printf("%d days are %d weeks and %d days\n",days,week,reminder_days);
        printf("Enter number of days(0 or less to quit):");
        scanf("%d",&days);
    }
    return 0;
}