#include <stdio.h>

int main() {
    char first_name[50];
    char last_name[50];

    printf("Please enter your first name: ");
    scanf("%s", first_name);

    printf("Please enter your last name: ");
    scanf("%s", last_name);

    printf("%s, %s\n", last_name, first_name);

    return 0;
}