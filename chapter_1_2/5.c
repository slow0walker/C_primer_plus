#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void br() {
    printf("Brazil, Russia");
}

void ic() {
    printf("India, China");
}

int main() {
    br();
    printf(", ");
    ic();
    printf("\n");

    ic();
    printf("\n");

    br();
    printf("\n");

    return 0;
}