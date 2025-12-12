#include <stdio.h>
#include <ctype.h>

void func1(void);
void func2(void);
void func3(void);
void quit(void);

int main(void)
{
    char choice;

    /* 函数指针数组 */
    void (*funcs[])(void) = {func1, func2, func3, quit};

    printf("Menu:\n");
    printf("a) Run function 1\n");
    printf("b) Run function 2\n");
    printf("c) Run function 3\n");
    printf("q) Quit\n");

    while (1)
    {
        printf("\nEnter choice: ");
        choice = getchar();
        while (getchar() != '\n')
            continue; /* 清理输入缓冲区 */

        choice = tolower(choice);

        if (choice == 'q')
        {
            funcs[3](); // quit
            break;
        }
        else if (choice >= 'a' && choice <= 'c')
        {
            int index = choice - 'a';
            funcs[index]();
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

/* ---------- 菜单功能函数 ---------- */

void func1(void)
{
    printf("Function 1 executed.\n");
}

void func2(void)
{
    printf("Function 2 executed.\n");
}

void func3(void)
{
    printf("Function 3 executed.\n");
}

void quit(void)
{
    printf("Program exited.\n");
}
