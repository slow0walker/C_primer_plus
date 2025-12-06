#include <stdio.h>
#include <stdlib.h>
int *make_array(int size, int value);
void show_array(const int *arr, int size);

int main()
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements:");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value:");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements:(<1 to quit)");
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int size, int value)
{
    int *pa;
    pa = (int *)malloc(size * sizeof(int));
    if (pa == NULL)
        fprintf(stderr, "Memory allocation failed.\n");
    int i = 0;
    for (i = 0; i < size; i++)
    {
        pa[i] = value;
    }
    return pa;
}

void show_array(const int *arr, int size)
{
    const int num = 8;
    int i;
    for (i = 0; i < size; i++)
    {
        if (i % num == 0)
            printf("\n");
        printf("%3d", arr[i]);
    }
    printf("\n");
}