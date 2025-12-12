#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
struct month
{
    char name[20];
    char abbrev[4];
    int days;
    int month_number;
};

static struct month months[12] =
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

void get_input(char *month_name, int *day, int *year);
bool is_leap(int year);
bool all_digits(const char *str);
int str_casecmp(const char *s1, const char *s2);
bool input_valid(const char *month_name, int day, int year);
int get_month_index(const char *month_name);
int days_until_month(const char *month_name, int year, int day);

int main()
{
    int day, year;
    char month_name[20];
    int month_index;
    int total_days;

    get_input(month_name, &day, &year);
    /*
    month_index = get_month_index(month_name);
    if (month_index == -1)
    {
        fprintf(stderr, "Invalid month name.\n");
        exit(EXIT_FAILURE);
    }
    if (is_leap(year))
        months[1].days = 29;
    else
        months[1].days = 28;

    if (day < 1 || day > months[month_index].days)
    {
        fprintf(stderr, "Invalid day for the given month.\n");
        exit(EXIT_FAILURE);
    }

    total_days = days_until_month(month_name, year, day);
    */

    if (is_leap(year))
        months[1].days = 29;
    else
        months[1].days = 28;

    if (!input_valid(month_name, day, year))
    {
        fprintf(stderr, "Invalid date input.\n");
        exit(EXIT_FAILURE);
    }

    total_days = days_until_month(month_name, year, day);
    printf("From the beginning of the year to %s %d, %d, there are %d days.\n", month_name, day, year, total_days);
    return 0;
}

// get input from user
void get_input(char *month_name, int *day, int *year)
{
    printf("Enter year:");
    if (scanf("%d", year) != 1 || *year < 0)
    {
        fprintf(stderr, "Invalid year input.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter month name(number,name,or abbrev): ");
    scanf("%19s", month_name);

    printf("Enter day: ");
    if (scanf("%d", day) != 1)
    {
        fprintf(stderr, "Invalid day input.\n");
        exit(EXIT_FAILURE);
    }
}

// validate user input
bool input_valid(const char *month_name, int day, int year)
{
    int month_index = get_month_index(month_name);
    if (month_index == -1)
        return false;
    if (day < 1 || day > months[month_index].days)
        return false;
    return true;
}

// check if year is leap year
bool is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// check if string contains all digits
bool all_digits(const char *str)
{
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return false;
        str++;
    }
    return true;
}

// case insensitive string comparison
int str_casecmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        char c1 = (unsigned char)tolower((unsigned char)*s1);
        char c2 = (unsigned char)tolower((unsigned char)*s2);
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// get month index from month name/abbrev/number
int get_month_index(const char *month_name)
{
    if (all_digits(month_name))
    {
        int month_num = atoi(month_name);
        if (month_num >= 1 && month_num <= 12)
            return month_num - 1;
        else
            return -1;
    }
    for (int i = 0; i < 12; i++)
    {
        if (str_casecmp(month_name, months[i].name) == 0 || str_casecmp(month_name, months[i].abbrev) == 0)
            return i;
    }
    return -1;
}

// calculate days until given month and day
int days_until_month(const char *month_name, int year, int day)
{
    int total_days = 0;
    int month_index = get_month_index(month_name);
    for (int i = 0; i < month_index; i++)
    {
        total_days += months[i].days;
    }
    total_days += day;
    return total_days;
}