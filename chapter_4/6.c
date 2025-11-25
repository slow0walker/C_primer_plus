#include <stdio.h>
#include <string.h> 

int main() {
    char first[50], last[50];
    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);
    
    int len_first = strlen(first);
    int len_last = strlen(last);
    
    printf("%s %s\n", first, last);
    printf("%*d %*d\n", len_first, len_first, len_last, len_last);
    
    printf("%s %s\n", first, last);
    printf("%-*d %-*d\n", len_first, len_first, len_last, len_last);
    
    return 0;
}