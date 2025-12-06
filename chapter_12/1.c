#include <stdio.h>
void critic(void);
static int units = 0;
int main()
{

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        critic();
    printf("Exactly!\n");
    return 0;
}
void critic(void)
{
    printf("Try again!\n");
    scanf("%d", &units);
}
