#include <stdio.h>

int main() {
    float inches;
    printf("Enter your height in inches: ");
    scanf("%f", &inches);
    
    float cm = inches * 2.54;
    printf("Your height in centimeters: %.2f\n", cm);
    
    return 0;
}