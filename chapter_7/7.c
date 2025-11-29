#include <stdio.h>

#define RATE 10.00
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void) {
    double hours, gross, tax, net;

    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours);

    if (hours > 40)
        gross = 40 * RATE + (hours - 40) * RATE * OVERTIME;
    else
        gross = hours * RATE;

    if (gross <= BREAK1)
        tax = gross * RATE1;
    else if (gross <= BREAK1 + BREAK2)
        tax = BREAK1 * RATE1 + (gross - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + BREAK2 * RATE2 + (gross - BREAK1 - BREAK2) * RATE3;

    net = gross - tax;

    printf("Gross Pay: %.2f\nTax: %.2f\nNet Pay: %.2f\n", gross, tax, net);

    return 0;
}
