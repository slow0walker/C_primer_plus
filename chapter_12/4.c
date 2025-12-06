#include <stdio.h>
int count_calls(void);

int main()
{
    printf("count_calls() called %d times\n", count_calls());
    printf("count_calls() called %d times\n", count_calls());
    printf("count_calls() called %d times\n", count_calls());
    return 0;
}
int count_calls(void)
{
    static int count = 0;
    count++;
    return count;
}