#include <stdio.h>
#define CM_PER_FOOT 30.48
#define CM_PER_INCH 2.54
int main()
{
    double height_cm,inches,reminder_cm;
    int feet;
    printf("Enter a height in centimeters: ");
    scanf("%lf",&height_cm);
    while(height_cm > 0)
    {
        feet = (int)(height_cm / CM_PER_FOOT);
        reminder_cm = height_cm - (feet * CM_PER_FOOT);
        inches = reminder_cm / CM_PER_INCH;
        printf("%.1f cm is %d feet and %.1f inches\n",height_cm,feet,inches);
        printf("Enter a height in centimeters (<= 0 to quit):)");
        scanf("%lf",&height_cm);
    }
    printf("Bye!\n");
    return 0;
}