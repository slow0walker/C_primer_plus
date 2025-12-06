#include <stdio.h>
#include <stdlib.h> //for rand() and srand()
#include <time.h>   //for time()

#define TOTAL 1000
#define MAX_VALUE 10

int main()
{
    int counts[MAX_VALUE + 1] = {0};
    int num = 0; // different seed

    for (num = 1; num <= 10; num++)
    {
        srand((unsigned int)time(NULL));
        for (int i = 0; i < TOTAL; i++)
        {
            counts[rand() % MAX_VALUE + 1]++;
        }
        printf("Seed %d\n", num);
        for (int i = 1; i <= 10; i++)
        {
            printf("%2d:  %3d\n", i, counts[i]);
        }
    }

    return 0;
}