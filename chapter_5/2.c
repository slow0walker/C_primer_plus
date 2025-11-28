#include <stdio.h>
#define L 5
int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int N_L = num + L;
    while(num <= N_L)
    {
        printf("%d\n", num);
        num++;
    }
    return 0;
}