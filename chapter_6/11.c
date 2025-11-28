#include<stdio.h>

int main()
{
    int array[8];
    printf("Enter 8 integers: ");
    for(int i =0;i < 8;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("The integers in reverse order are:\n");
    for(int i =7;i >= 0;i--)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}