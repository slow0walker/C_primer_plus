#include <stdio.h>

int main() {
    float volume;
    printf("Enter volume in cups: ");
    scanf("%f", &volume);
    
    float pints = volume / 2;
    float ounces = volume * 8;
    float tablespoons = ounces * 2;
    float teaspoons = tablespoons * 3;
    
    printf("Equivalent: %.2f pints\n", pints);
    printf("            %.2f ounces\n", ounces);
    printf("            %.2f tablespoons\n", tablespoons);
    printf("            %.2f teaspoons\n", teaspoons);

    return 0;
}