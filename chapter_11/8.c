#include <stdio.h>

char *string_in(const char *s1, const char *s2)
{
    if (*s2 == '\0')
        return (char *)s1;

    while (*s1 != '\0')
    {
        const char *p1 = s1;
        const char *p2 = s2;
        if (*p1 == *p2 && *p2 != '\0')
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
            return (char *)s1;
        s1++;
    }
    return NULL;
}
int main(void)
{
    char big[80];
    char small[40];
    char *p;

    printf("Big string: ");
    fgets(big, sizeof big, stdin);
    printf("Small string: ");
    fgets(small, sizeof small, stdin);

    p = string_in(big, small);
    if (p)
        printf("Found at position %ld\n", p - big);
    else
        printf("Not found.\n");
    return 0;
}