#include <stdio.h>

#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09

double shipping(double weight) {
    if (weight <= 0)
        return 0;
    else if (weight <= 5)
        return 6.50;
    else if (weight <= 20)
        return 14.00;
    else
        return 14.00 + 0.50 * (weight - 20);
}

int main(void) {
    char choice;
    double a = 0, b = 0, c = 0;
    double w;

    while (1) {
        printf("Enter a (artichokes), b (beets), c (carrots), q (quit): ");
        scanf(" %c", &choice);

        if (choice == 'q')
            break;

        printf("Enter pounds: ");
        scanf("%lf", &w);

        switch (choice) {
            case 'a': a += w; break;
            case 'b': b += w; break;
            case 'c': c += w; break;
            default:
                printf("Invalid choice.\n");
        }
    }

    double ca = a * ARTICHOKE;
    double cb = b * BEET;
    double cc = c * CARROT;

    double total_weight = a + b + c;
    double subtotal = ca + cb + cc;

    double discount = subtotal > 100 ? subtotal * 0.05 : 0;
    double ship = shipping(total_weight);

    double total = subtotal - discount + ship;

    printf("\nOrder summary:\n");
    printf("Artichokes: %.2f lbs = $%.2f\n", a, ca);
    printf("Beets     : %.2f lbs = $%.2f\n", b, cb);
    printf("Carrots   : %.2f lbs = $%.2f\n", c, cc);
    printf("Subtotal        : $%.2f\n", subtotal);
    printf("Discount        : $%.2f\n", discount);
    printf("Shipping        : $%.2f\n", ship);
    printf("TOTAL           : $%.2f\n", total);

    return 0;
}
