#include<stdio.h>

int main()
{
    int low,upper;
    printf("Enter lower and upper integer limits: ");
    scanf("%d %d",&low,&upper);

    for(int i =low;i <= upper;i++)
    {
        printf("%3d %3d %3d\n",i,i*i,i*i*i);
    }
    return 0;
}