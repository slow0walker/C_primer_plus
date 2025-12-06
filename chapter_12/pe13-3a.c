#include <stdio.h>
#include "pe13-3a.h"
int set_mode(int new_mode)
{
    if (new_mode == 0 || new_mode == 1)
    {
        return new_mode;
    }
    else
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        return 1;
    }
}

void get_info(int mode, double *dist, double *fuel)
{
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", dist);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", dist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel);
    }
}

void show_info(int mode, double dist, double fuel)
{
    if (mode == 0)
    {
        if (dist > 0)
        {
            double consumption = (fuel / dist) * 100.0;
            printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
        }
        else
        {
            printf("Distance must be greater than zero for calculation.\n");
        }
    }
    else
    {
        if (fuel > 0)
        {
            double consumption = dist / fuel;
            printf("Fuel consumption is %.2f miles per gallon.\n", consumption);
        }
        else
        {
            printf("Fuel consumed must be greater than zero for calculation.\n");
        }
    }
}