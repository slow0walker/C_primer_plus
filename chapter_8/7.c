#include <stdio.h>

#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20

char show_menu(void)
{
    char choice;
    printf("*****************************************************************\n");
    printf("Enter the letter corresponding to the desired pay rate or action:\n");
    printf("a) $%.2f/hr                         b) $%.2f/hr\n", RATE1, RATE2);
    printf("c) $%.2f/hr                         d) $%.2f/hr\n", RATE3, RATE4);
    printf("q) quit\n");
    printf("*****************************************************************\n");
    scanf(" %c", &choice);
    return choice;
}
int main()
{
    char choice;
    double rate;
    while ((choice = show_menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            rate = RATE1;
            break;
        case 'b':
            rate = RATE2;
            break;
        case 'c':
            rate = RATE3;
            break;
        case 'd':
            rate = RATE4;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        printf("You selected a pay rate of $%.2f/hr\n", rate);
    }
    printf("Exiting the program. Goodbye!\n");
    return 0;
}