#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex4.h"

static int newcustomer(double x)
{
    /* average x minutes/customer -> probability 1/x each minute */
    return (rand() * x / (double)RAND_MAX) < 1.0;
}

int main(void)
{
    Queue line1, line2;
    Item temp;
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long line_wait = 0;

    int wait_time1 = 0, wait_time2 = 0; /* remaining service time */
    Item cur1 = {0, 0}, cur2 = {0, 0};
    int has1 = 0, has2 = 0;

    int hours;
    double perhour;
    double min_per_cust;

    puts("Double booth simulation (two queues, two servers).");
    printf("Enter max size of each queue: ");
    int qs;
    if (scanf("%d", &qs) != 1 || qs <= 0)
        return 1;

    InitializeQueue(&line1, qs);
    InitializeQueue(&line2, qs);

    printf("Enter number of simulation hours: ");
    if (scanf("%d", &hours) != 1 || hours <= 0)
        return 1;

    printf("Enter average customers per hour: ");
    if (scanf("%lf", &perhour) != 1 || perhour <= 0)
        return 1;

    min_per_cust = 60.0 / perhour;
    cyclelimit = (long)hours * 60;

    srand((unsigned)time(NULL));

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {

        if (newcustomer(min_per_cust))
        {
            customers++;
            temp.arrive = cycle;
            temp.processtime = rand() % 3 + 1;

            int c1 = QueueItemCount(&line1);
            int c2 = QueueItemCount(&line2);

            Queue *chosen = (c1 <= c2) ? &line1 : &line2;

            if (QueueIsFull(chosen))
            {

                Queue *other = (chosen == &line1) ? &line2 : &line1;
                if (!QueueIsFull(other))
                {
                    EnQueue(temp, other);
                }
                else
                {
                    turnaways++;
                }
            }
            else
            {
                EnQueue(temp, chosen);
            }
        }

        if (!has1 && !QueueIsEmpty(&line1))
        {
            DeQueue(&cur1, &line1);
            has1 = 1;
            wait_time1 = cur1.processtime;
            line_wait += (cycle - cur1.arrive);
            served++;
        }

        if (!has2 && !QueueIsEmpty(&line2))
        {
            DeQueue(&cur2, &line2);
            has2 = 1;
            wait_time2 = cur2.processtime;
            line_wait += (cycle - cur2.arrive);
            served++;
        }

        if (has1)
        {
            wait_time1--;
            if (wait_time1 <= 0)
                has1 = 0;
        }
        if (has2)
        {
            wait_time2--;
            if (wait_time2 <= 0)
                has2 = 0;
        }

        sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);
    }

    if (customers > 0)
    {
        printf("\ncustomers accepted: %ld\n", customers - turnaways);
        printf("customers served:   %ld\n", served);
        printf("turnaways:          %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
        printf("average wait time:  %.2f minutes\n",
               served ? (double)line_wait / served : 0.0);
    }
    else
    {
        puts("No customers!");
    }

    EmptyQueue(&line1);
    EmptyQueue(&line2);
    return 0;
}
