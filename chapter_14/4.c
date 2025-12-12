#include <stdio.h>
#include <string.h>
#define LEN 20

struct names
{
    char first[LEN];
    char middle[LEN];
    char last[LEN];
};

struct person
{
    struct names name;
    char ssn[12];
};

void show_by_pointer(const struct person *p);
void show_by_value(struct person p);

int main()
{
    struct person people[5] = {
        {{"Flossie", "Mildred", "Dribble"}, "302039823"},
        {{"John", "", "Smith"}, "123456789"},
        {{"Alice", "Beatrice", "Johnson"}, "567890123"},
        {{"Bob", "", "Brown"}, "990011223"},
        {{"Cindy", "Q", "Adams"}, "445566778"}};

    printf("=== Part (a): Passing pointer ===\n");
    for (int i = 0; i < 5; i++)
        show_by_pointer(&people[i]);

    printf("\n=== Part (b): Passing structure by value ===\n");
    for (int i = 0; i < 5; i++)
        show_by_value(people[i]);

    return 0;
}

void show_by_pointer(const struct person *p)
{
    if (strlen(p->name.middle) > 0)
        printf("%s, %s %c. -- %s\n", p->name.last, p->name.first, p->name.middle[0], p->ssn);
    else
        printf("%s, %s -- %s\n", p->name.last, p->name.first, p->ssn);
}

void show_by_value(struct person p)
{
    if (strlen(p.name.middle) > 0)
        printf("%s, %s %c. -- %s\n", p.name.last, p.name.first, p.name.middle[0], p.ssn);
    else
        printf("%s, %s -- %s\n", p.name.last, p.name.first, p.ssn);
}