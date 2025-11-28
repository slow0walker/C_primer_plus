#include <stdio.h>

void Temperatures(double fahrenheit);

int main()
{
    double fahr;
    printf("Enter a temperature in Fahrenheit: ");
    
    while(scanf("%lf", &fahr) == 1)
    {
        Temperatures(fahr);
        printf("Enter a temperature in Fahrenheit (Enter q or non-numeric to quit): ");
    }
    return 0;
}

void Temperatures(double fahenheit)
{
    double celsius,kelvin;
    celsius = (5.0/9.0) * (fahenheit - 32.0);
    kelvin = celsius + 273.16;
    printf("Fahrenheit: %.2f  Celsius: %.2f  Kelvin: %.2f\n", fahenheit, celsius, kelvin);
}