#include <stdio.h>
#include <string.h>

enum paytype
{
    HOURLY,
    PIECEWORKER,
    COMMISSIONAL,
    SALARIED
};

union paydata
{
    struct
    {
        float hours, rate;
    } hourly;
    struct
    {
        int pieces;
        float piece_rate;
    } pieceworker;
    struct
    {
        float sales, rate;
    } comm;
    struct
    {
        float salary;
    } salaried;
};

typedef struct
{
    char name[40];
    enum paytype kind;
    union paydata data;
} employee;

/* function prototypes */
void show_employee(const employee *e);
float compute_pay(const employee *e);

int main(void)
{
    /* Test employees */
    employee staff[] = {
        {"Tom Hourly", HOURLY, .data.hourly = {40, 20.0}},
        {"Alice Piece", PIECEWORKER, .data.pieceworker = {300, 0.50}},
        {"Bob Sales", COMMISSIONAL, .data.comm = {20000, 0.05}},
        {"Cindy Salary", SALARIED, .data.salaried = {8000}}};

    int n = sizeof(staff) / sizeof(staff[0]);

    for (int i = 0; i < n; i++)
        show_employee(&staff[i]);

    return 0;
}

/* -------- Show info + calculated pay -------- */
void show_employee(const employee *e)
{
    printf("\nEmployee: %s\n", e->name);

    switch (e->kind)
    {
    case HOURLY:
        printf("Type: Hourly\n");
        printf("Hours = %.1f, Rate = %.2f\n",
               e->data.hourly.hours, e->data.hourly.rate);
        break;

    case PIECEWORKER:
        printf("Type: Piece Worker\n");
        printf("Pieces = %d, Rate = %.2f\n",
               e->data.pieceworker.pieces,
               e->data.pieceworker.piece_rate);
        break;

    case COMMISSIONAL:
        printf("Type: Commission\n");
        printf("Sales = %.2f, Rate = %.2f\n",
               e->data.comm.sales, e->data.comm.rate);
        break;

    case SALARIED:
        printf("Type: Salaried\n");
        printf("Salary = %.2f\n", e->data.salaried.salary);
        break;
    }

    printf("Calculated Pay = %.2f\n", compute_pay(e));
}

/* -------- Compute pay using union data -------- */
float compute_pay(const employee *e)
{
    switch (e->kind)
    {
    case HOURLY:
        return e->data.hourly.hours * e->data.hourly.rate;

    case PIECEWORKER:
        return e->data.pieceworker.pieces * e->data.pieceworker.piece_rate;

    case COMMISSIONAL:
        return e->data.comm.sales * e->data.comm.rate;

    case SALARIED:
        return e->data.salaried.salary;

    default:
        return 0.0f;
    }
}
