#include<stdio.h>

int main()
{
    double num1[8];
    printf("Enter 8 double numbers:\n");
    for(int i=0;i<8;i++)
        scanf("%lf",&num1[i]);

    double num2[8]={0.0};
    double sum=0.0;
    for(int i =0;i <8;i++)
    {
        sum += num1[i];
        num2[i] = sum;
    }
    
    printf("Cumulative sums are:\n");
    for(int i =0;i<8;i++)
        printf("num2[%d] = %.2lf\n", i, num2[i]);

    return 0;
}