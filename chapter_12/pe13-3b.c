#include <stdio.h>
#include "pe13-3a.h"
int main()
{
    int input_mode;
    int current_mode = 0;
    double distance = 0.0;
    double fuel = 0.0;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    while (scanf("%d", &input_mode) && input_mode >= 0)
    {
        current_mode = set_mode(input_mode);
        get_info(current_mode, &distance, &fuel);
        show_info(current_mode, distance, fuel);
        printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}