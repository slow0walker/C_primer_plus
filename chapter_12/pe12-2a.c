#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0; // 0=metric, 1=US
static double distance;
static double fuel;

void set_mode(int new_mode)
{
    if (new_mode == 0 || new_mode == 1)
        mode = new_mode;
    else
        printf("Invalid mode specified. Mode %d(%s) used.\n", mode, (mode == 1 ? "US" : "metric"));
}

void get_info(void)
{
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

void show_info(void)
{
    if (mode == 0) // meric
    {
        if (distance > 0)
        {
            double consumption = (fuel / distance) * 100.0;
            printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
        }
        else
        {
            printf("Distance must be greater than zero for calculation.\n");
        }
    }
    else // us
    {
        if (fuel > 0)
        {
            double consumption = distance / fuel;
            printf("Fuel consumption is %.2f miles per gallon.\n", consumption);
        }
        else
        {
            printf("Fuel consumed must be greater than zero for calculation.\n");
        }
    }
}