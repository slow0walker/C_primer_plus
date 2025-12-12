#include <stdio.h>

#define CSIZE 4
#define SCORES 3

struct name
{
    char first[20];
    char last[20];
};
struct student
{
    struct name student_name;
    float scores[SCORES];
    float average;
};

void get_info(struct student students[], int size);
void compute_average(struct student students[], int size);
void display_info(const struct student *students, int size);
void display_class_average(const struct student *students, int size);

int main(void)
{
    struct student students[CSIZE];

    get_info(students, CSIZE);
    compute_average(students, CSIZE);
    display_info(students, CSIZE);
    display_class_average(students, CSIZE);

    return 0;
}

void get_info(struct student students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter first name of student %d: ", i + 1);
        scanf("%19s", students[i].student_name.first);
        printf("Enter last name of student %d: ", i + 1);
        scanf("%19s", students[i].student_name.last);
        printf("Enter %d scores for %s %s:\n", SCORES, students[i].student_name.first, students[i].student_name.last);
        for (int j = 0; j < SCORES; j++)
        {
            printf("Score %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
        }
    }
}

void compute_average(struct student students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < SCORES; j++)
        {
            sum += students[i].scores[j];
        }
        students[i].average = sum / SCORES;
    }
}

void display_info(const struct student *students, int size)
{
    printf("\nStudent Information:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s %s\n", students[i].student_name.first, students[i].student_name.last);
        printf("Scores: ");
        for (int j = 0; j < SCORES; j++)
        {
            printf("%.2f ", students[i].scores[j]);
        }
        printf("\nAverage: %.2f\n\n", students[i].average);
    }
}

void display_class_average(const struct student *students, int size)
{
    float total = 0.0;
    for (int i = 0; i < size; i++)
    {
        total += students[i].average;
    }
    printf("Class Average: %.2f\n", total / size);
}
