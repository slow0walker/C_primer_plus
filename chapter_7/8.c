#include <stdio.h>

#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20
#define OVERTIME 1.5
#define BREAK1 300
#define BREAK2 150
#define TAX1 0.15
#define TAX2 0.20
#define TAX3 0.25

double compute_tax(double gross) {
    if (gross <= BREAK1)
        return gross * TAX1;
    else if (gross <= BREAK1 + BREAK2)
        return BREAK1 * TAX1 + (gross - BREAK1) * TAX2;
    else
        return BREAK1 * TAX1 + BREAK2 * TAX2 + (gross - BREAK1 - BREAK2) * TAX3;
}

int main(void) {
    int choice;
    double rate = 0, hours;

    while (1) {
        printf("*****************************************\n");
        printf("Enter the number corresponding to pay rate or action:\n");
        printf("1) $8.75/hr         2) $9.33/hr\n");
        printf("3) $10.00/hr        4) $11.20/hr\n");
        printf("5) quit\n");
        printf("*****************************************\n");

        scanf("%d", &choice);

        if (choice == 5)
            break;

        switch (choice) {
            case 1: rate = RATE1; break;
            case 2: rate = RATE2; break;
            case 3: rate = RATE3; break;
            case 4: rate = RATE4; break;
            default:
                printf("Invalid choice, try again.\n");
                continue;
        }

        printf("Enter hours worked: ");
        scanf("%lf", &hours);

        double gross;
        if (hours > 40)
            gross = 40 * rate + (hours - 40) * rate * OVERTIME;
        else
            gross = hours * rate;

        double tax = compute_tax(gross);
        double net = gross - tax;

        printf("Gross: %.2f  Tax: %.2f  Net: %.2f\n", gross, tax, net);
    }

    return 0;
}
