#include <stdio.h>

int main() {
    char first_name[50];

    printf("Please enter your first name: ");
    scanf("%s", first_name);

    printf("\"%s\"\n", first_name);

    printf("\"%20s\"\n", first_name);

    printf("\"%-20s\"\n", first_name);

    
    return 0;
}