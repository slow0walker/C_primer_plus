#include <stdio.h>

int main()
{
    double daphne = 100.0;
    double deirdre = 100.0;
    int year = 0;
    const double daphne_rate = 0.10;
    const double deirdre_rate = 0.05;
    
    while (deirdre <= daphne) {
        daphne += 10.0;// Daphne adds $10 each year
        deirdre += deirdre * deirdre_rate;// Deirdre's investment grows by 5%
        year++;
    }

    printf("After %d years, Deirdre's investment will exceed Daphne's.\n", year);
    printf("Daphne's investment: %.2f\n", daphne);
    printf("Deirdre's investment: %.2f\n", deirdre);

    return 0;
}