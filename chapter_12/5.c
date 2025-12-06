#include <stdio.h>
#include <stdlib.h> //for rand() and srand()
#include <time.h>   //for time()

#define SIZE 100
#define RANGE 10

void generate_random_array(int arr[], int size);
void sort_array(int arr[], int size);
void print_array(int arr[], int size, int per_line);

int main()
{
    int numbers[SIZE];
    srand((unsigned int)time(NULL));
    generate_random_array(numbers, SIZE);
    printf("--- Original Array (%d random numbers from 1 to %d) ---\n", SIZE, RANGE);
    print_array(numbers, SIZE, 10);
    sort_array(numbers, SIZE);
    printf("\n--- Sorted Array (%d random numbers from 1 to %d) ---\n", SIZE, RANGE);
    print_array(numbers, SIZE, 10);
    return 0;
}

void generate_random_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % RANGE + 1;
    }
}

void sort_array(int arr[], int size)
{
    int max_index;
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        max_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }
        if (max_index != i)
        {
            temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}
void print_array(int arr[], int size, int per_line)
{
    for (int i = 0; i < size; i++)
    {
        printf("%-2d ", arr[i]);
        if ((i + 1) % per_line == 0)
            printf("\n");
    }
}