#include <stdio.h>

int binsearch(const int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return 1;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main(void)
{
    int a[] = {1, 3, 5, 7, 9, 12, 20, 31};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int x;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');

    printf("Enter integer to seek: ");
    if (scanf("%d", &x) != 1)
        return 1;

    printf("%d\n", binsearch(a, n, x));
    return 0;
}
