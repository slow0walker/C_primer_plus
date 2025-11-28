#include<stdio.h>

int main()
{
    double sum1 = 0.0,sum2=0.0;

    int num_term;
    printf("Enter the number of terms: ");
    scanf("%d", &num_term);
    while(num_term >0)
    {
        for(int i =1; i<=num_term;i++)
        {
            sum1 += 1.0/i;
        }
        printf("sum of series 1 + 1/2 + ... + 1/%d = %.6f\n", num_term, sum1);

        for(int i =1;i<=num_term;i++)
        {
            if(i%2 ==0)
                sum2 -= 1.0/i;
            else
                sum2 += 1.0/i;
        }
        printf("sum of series 1 - 1/2 + 1/3 - ... + = %.6f\n", num_term, num_term, sum2);

        printf("Enter the number of terms (0 to quit): ");
        scanf("%d", &num_term);
    }
    return 0;
}