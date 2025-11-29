#include<stdio.h>

int main()
{
    int num;
    int n_even = 0, n_odd = 0;
    int sum_even = 0, sum_odd = 0;
    printf("Enter integers to analyze (0 to exit):\n");
    while((scanf("%d",&num)==1) && num != 0)
    {
        if(num % 2 == 0)
        {
            n_even++;
            sum_even += num;
        }
        else
        {
            n_odd++;
            sum_odd += num;
        }
    }
    printf("Even numbers: count = %d, average = %.2f\n", n_even, n_even ? (double)sum_even / n_even : 0.0); // Avoid division by zero
    printf("Odd numbers: count = %d, average = %.2f\n", n_odd, n_odd ? (double)sum_odd / n_odd : 0.0);
    return 0;
}