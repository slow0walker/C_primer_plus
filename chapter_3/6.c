#include <stdio.h>

int main() {
    float quarts;
    const float GRAMS_PER_QUART = 950;
    const double MASS_PER_MOLECULE = 3.0e-23;
    
    printf("Enter amount of water in quarts: ");
    scanf("%f", &quarts);
    
    double grams = quarts * GRAMS_PER_QUART;
    double molecules = grams / MASS_PER_MOLECULE;
    printf("Number of molecules: %.2e\n", molecules);
    
    return 0;
}