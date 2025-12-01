#include <stdio.h>
#include <stdbool.h>
// validate that input is an integer
long get_long(void);
// validate that range limits are valid
bool bad_limits(long begin, long end, long low, long high);
// calculate the sum of squares from a through b
double sum_squares(long a, long b);
int main(void)
{
    const long MIN = -1000000L;
    const long MAX = 1000000L;
    long start;
    long stop;
    double answer;

    printf("This program computes the sum of the squares of"
           " integers in a range.\nThe lower bound should not"
           " be less than %ld and\nthe upper bound should not"
           " be more than %ld.\n",
           MIN, MAX);
    printf("Enter the limits (enter 0 for both limits to quit):\n");
    printf("Lower limit: ");
    start = get_long();
    printf("Upper limit: ");
    stop = get_long();
    while (start != 0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of the squares from %ld to %ld is %g\n",
                   start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both limits to quit):\n");
        printf("Lower limit: ");
        start = get_long();
        printf("Upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");
    return 0;
}
long get_long(void)
{
    long input;
    char ch;

    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value: ");
    }
    return input;
}
bool bad_limits(long begin, long end, long low, long high)
{
    bool bad = false;
    if (begin > end)
    {
        printf("%ld is not smaller than %ld.\n", begin, end);
        bad = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        bad = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %ld or less.\n", high);
        bad = true;
    }
    return bad;
}
double sum_squares(long a, long b)
{
    double total = 0;
    long i;
    for (i = a; i <= b; i++)
        total += (double)i * (double)i;
    return total;
}