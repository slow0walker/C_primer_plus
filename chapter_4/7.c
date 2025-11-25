#include <stdio.h>

int main() {
    double d = 1.0 / 3.0;
    float f = 1.0 / 3.0;
    
    // 输出double
    printf("double: 4位小数: %.4f, 12位小数: %.12f, 16位小数: %.16f\n", d, d, d);
    // 输出float
    printf("float: 4位小数: %.4f, 12位小数: %.12f, 16位小数: %.16f\n", f, f, f);
    
    return 0;
}