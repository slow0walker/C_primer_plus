#include <stdio.h>

int main()
{
    printf("This program computes moduli.\n");
    int operand1, operand2;

    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &operand2);

    printf("Now enter the first operand: ");
    scanf("%d", &operand1);
    while(operand1 >0)
    {
        int modulus = operand1 % operand2;
        printf("%d %% %d is %d\n", operand1, operand2, modulus);
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d", &operand1);
    }
    
    return 0;
}