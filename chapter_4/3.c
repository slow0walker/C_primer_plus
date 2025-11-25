#include <stdio.h>

int main() {
    float num;
    printf("Enter a floating-point number: ");
    scanf("%f", &num);
    
    printf("a. The input is %.1f or %.1e\n", num, num);
    printf("b. The input is %+.3f or %.3e\n", num, num);
    
    return 0;
}