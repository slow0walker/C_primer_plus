#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(int sides)
{
    return rand() % sides + 1;
}

int main(void)
{
    int sets, dice, sides;
    srand((unsigned)time(NULL));

    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides, &dice);

        printf("Here are %d sets of %d %d-sided throws.\n",
               sets, dice, sides);

        for (int i = 0; i < sets; i++)
        {
            int sum = 0;
            for (int j = 0; j < dice; j++)
                sum += roll(sides);
            printf("%4d", sum);
            if ((i + 1) % 10 == 0)
                putchar('\n');
        }
        putchar('\n');
        printf("How many sets? Enter q to stop: ");
    }
    return 0;
}
