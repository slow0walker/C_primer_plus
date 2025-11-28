#include<stdio.h>
int main()
{
    double money = 1000000.0;
    int years=0;

    while(money > 0.0)
    {
        money *= 1.08;
        money -= 100000.0;
        years++;
    }
    printf("It will take %d years to deplete the account.\n", years);
    return 0;
}