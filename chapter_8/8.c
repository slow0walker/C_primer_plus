#include <stdio.h>
#include <ctype.h>

char show_menu(void)
{
    char choice;
    printf("*******************************\n");
    printf("a. add             s. subtract\n");
    printf("m. multiply        d. divide\n");
    printf("q. quit\n");
    printf("*******************************\n");
    scanf(" %c", &choice);
    return choice;
}

float get_number(void)
{
    float num;
    int res;
    while ((res = scanf("%f", &num)) != 1)
    {
        while (getchar() != '\n')
            ; // 清除输入缓冲区
        printf("Invalid input. Please enter a number: ");
    }
    return num;
}

int main()
{
    char choice;
    float num1, num2, result;
    while ((choice = show_menu()) != 'q')
    {
        if (choice != 'a' && choice != 's' && choice != 'm' && choice != 'd')
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter first number: ");
        num1 = get_number();
        printf("Enter second number: ");
        num2 = get_number();

        if (choice == 'd' && num2 == 0)
        {
            printf("Error: Division by zero is not allowed, enter a non-zero divisor.\n");
            num2 = get_number();
        }

        switch (choice)
        {
        case 'a':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case 's':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case 'm':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case 'd':
            result = num1 / num2;
            printf("Result: %.2f\n", result);
            break;
        default:
            break;
        }
    }
    printf("Exiting the program. Goodbye!\n");
    return 0;
}