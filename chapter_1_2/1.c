#include <stdio.h>
#include "add.h"

int main() {
    int x = 5;
    int y = 10;
    int result = add(x, y);
    printf("The sum of %d and %d is %d\n", x, y, result);
    return 0;
}