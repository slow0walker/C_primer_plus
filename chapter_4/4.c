#include <stdio.h>

int main() {
    float height_in;
    char name[50];
    printf("Enter your height in inches: ");
    scanf("%f", &height_in);
    printf("Enter your name: ");
    scanf("%s", name);
    
    float height_ft = height_in / 12.0;
    printf("%s, you are %.3f feet tall\n", name, height_ft);
    
    return 0;
}