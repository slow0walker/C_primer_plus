#include <stdio.h>
#include <limits.h>   
#include <float.h>    

int main() {
    // 整数溢出
    int int_overflow = INT_MAX + 1;
    printf("Integer overflow (INT_MAX + 1): %d\n", int_overflow);

    // 浮点上溢
    float float_overflow = FLT_MAX * 2;
    printf("Float overflow: %f\n", float_overflow);

    // 浮点下溢
    float float_underflow = FLT_MIN / 2;
    printf("Float underflow: %f\n", float_underflow);

    return 0;
}