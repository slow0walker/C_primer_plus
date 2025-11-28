#include <stdio.h>
int main()
{
    int friends = 5;
    int week = 1;

    while(friends <=150)
    {
        friends -=week;
        if(friends <0)
        friends =0;

        friends *=2;
        printf("week %d: %d friends\n", week, friends);
        week++;
    }
    return 0;
}