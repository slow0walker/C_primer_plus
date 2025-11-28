#include<stdio.h>

int main()
{
    double num1,num2;

    printf("Enter two numbers(q to quit): ");
    while(scanf("%lf %lf",&num1,&num2)==2)
    {
        printf("The result of their diffence divided by their roduct is: %.4f\n",(num1 - num2)/(num1 * num2));
        printf("Enter two numbers(q to quit): ");
    }
    return 0;
}