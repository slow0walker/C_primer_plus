#include <stdio.h>

int main(void) {
    int category;
    double income, tax;

    while (1) {
        printf("Enter tax category (1-4) or 0 to quit:\n");
        printf("1) Single\n2) Head of Household\n3) Married, Joint\n4) Married, Separate\n");
        scanf("%d", &category);

        if (category == 0)
            break;

        printf("Enter taxable income: ");
        scanf("%lf", &income);

        double base, limit;

        switch (category) {
            case 1: limit = 17850; break;
            case 2: limit = 23900; break;
            case 3: limit = 29750; break;
            case 4: limit = 14875; break;
            default:
                printf("Invalid category!\n");
                continue;
        }

        if (income <= limit)
            tax = 0.15 * income;
        else
            tax = 0.15 * limit + 0.28 * (income - limit);

        printf("Tax owed = %.2f\n", tax);
    }

    return 0;
}
