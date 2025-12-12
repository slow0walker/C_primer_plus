#include <stdio.h>
#include <string.h>
struct month
{
    char name[20];
    char abbrev[4];
    int days;
    int month_number;
};

const struct month months[12] =
    {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"November", "Nov", 30, 11},
        {"December", "Dec", 31, 12}};

int days(char *month_name);

int main()
{
    char month_name[20];
    printf("Enter month name: ");
    scanf("%19s", month_name);
    int num_days = days(month_name);
    if (num_days != -1)
    {
        printf("from the beginning of the year to %s, there are %d days.\n", month_name, num_days);
    }
    else
    {
        printf("Invalid month name.\n");
    }
    return 0;
}

int days(char *month_name)
{
    int total_days = 0;
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(month_name, months[i].name) == 0)
        {
            total_days += months[i].days;
            return total_days;
        }
        total_days += months[i].days;
    }
    return -1;
}