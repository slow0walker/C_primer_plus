#include<stdio.h>

int calc(int lower,int upper)
{
    int sum=0;
    for(int i =lower;i<=upper;i++)
    {
        sum += i*i;
    }
    return sum;
}

int main()
{
    int lower,upper;
    printf("Enter lower and upper integer limits: ");

    while(scanf("%d %d",&lower,&upper) == 2 && lower < upper)
    {
        printf("The sum of the squares from %d to %d is %d\n",lower*lower,upper*upper,calc(lower,upper));
        printf("Enter next set of limits: ");
    }
    printf("Done\n");
    return 0;
}