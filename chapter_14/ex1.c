#include <stdio.h>
struct Bad
{
    char c;
    double d;
    int i;
};
struct good
{
    double d;
    int i;
    char c;
};

int main()
{
    printf("Size of Bad struct: %zu\n", sizeof(struct Bad));
    printf("Size of good struct: %zu\n", sizeof(struct good));
    return 0;
}
