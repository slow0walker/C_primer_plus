#include <stdio.h>
#include "hotel.h"

int menu(void)
{
    int code, status;
    printf("%s\n", START);
    printf("Enter the number corresponding to the hotel desired:\n");
    printf("1) Fairfield Arms      2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza   4) The Stockton\n");
    printf("5) Quit\n");
    printf("%s\n", START);

    while ((status = scanf("%d", &code)) != 1 || code < 1 || code > QUIT)
    {
        if (status != 1)
            while (getchar() != '\n')
                continue;
        printf("Please enter a number between 1 and %d: ", QUIT);
    }
    return code;
}

int getnights(void)
{
    int nights, status;
    printf("How many nights will you be staying? ");

    while ((status = scanf("%d", &nights)) != 1 || nights < 1)
    {
        if (status != 1)
            while (getchar() != '\n')
                continue;
        printf("Please enter a positive integer: ");
    }
    return nights;
}

void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
    {
        total += rate * factor;
    }
    printf("The total price for %d nights is $%.2f\n", nights, total);
}