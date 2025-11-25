#include <stdio.h>

int main() {
    int age;
    const double SEC_PER_YEAR = 3.156e7;
    printf("Enter your age in years: ");
    scanf("%d", &age);
    
    double seconds = age * SEC_PER_YEAR;
    printf("You are about %.2e seconds old.\n", seconds);
    return 0;
}