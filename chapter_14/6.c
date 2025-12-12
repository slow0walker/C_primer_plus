#include <stdio.h>
#include <string.h>

#define SIZE 19

struct player
{
    int number;
    char firstname[SIZE + 1];
    char lastname[SIZE + 1];
    int at_bats;
    int hits;
    int walks;
    int rbis;
    float average;
};

void init_team(struct player team[], int size);
void print_team(const struct player team[], int size);
void print_totals(const struct player team[], int size);

int main()
{
    struct player team[SIZE];
    init_team(team, SIZE);

    int num, atb, hit, walk, rbi;
    char fname[SIZE + 1], lname[SIZE + 1];

    printf("Reading softball data from input .\n");
    while (scanf("%d %s %s %d %d %d %d",
                 &num, fname, lname, &atb, &hit, &walk, &rbi) == 7)
    {
        struct player *p = &team[num];

        if (p->number == -1)
        {
            p->number = num;
            strcpy(p->firstname, fname);
            strcpy(p->lastname, lname);
        }
        p->at_bats += atb;
        p->hits += hit;
        p->walks += walk;
        p->rbis += rbi;
    }

    for (int i = 0; i < SIZE; i++)
    {
        if (team[i].at_bats > 0)
            team[i].average = (float)team[i].hits / team[i].at_bats;
    }

    print_team(team, SIZE);
    print_totals(team, SIZE);

    return 0;
}

void init_team(struct player team[], int size)
{
    for (int i = 0; i < size; i++)
    {
        team[i].number = -1;
        team[i].firstname[0] = '\0';
        team[i].lastname[0] = '\0';
        team[i].at_bats = 0;
        team[i].hits = 0;
        team[i].walks = 0;
        team[i].rbis = 0;
        team[i].average = 0.0;
    }
}

void print_team(const struct player team[], int size)
{
    printf("\n%-5s %-15s %-15s %-8s %-6s %-6s %-6s %-8s\n",
           "Num", "First Name", "Last Name", "At Bats", "Hits", "Walks", "RBIs", "Average");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++)
    {
        if (team[i].number != -1)
        {
            printf("%-5d %-15s %-15s %-8d %-6d %-6d %-6d %-8.3f\n",
                   team[i].number,
                   team[i].firstname,
                   team[i].lastname,
                   team[i].at_bats,
                   team[i].hits,
                   team[i].walks,
                   team[i].rbis,
                   team[i].average);
        }
    }
}

void print_totals(const struct player team[], int size)
{
    int total_at_bats = 0;
    int total_hits = 0;
    int total_walks = 0;
    int total_rbis = 0;

    for (int i = 0; i < size; i++)
    {
        if (team[i].number != -1)
        {
            total_at_bats += team[i].at_bats;
            total_hits += team[i].hits;
            total_walks += team[i].walks;
            total_rbis += team[i].rbis;
        }
    }

    float overall_average = (total_at_bats > 0) ? (float)total_hits / total_at_bats : 0.0;

    printf("-------------------------------------------------------------------------------\n");
    printf("%-20s %-8d %-6d %-6d %-6d %-8.3f\n",
           "Totals:",
           total_at_bats,
           total_hits,
           total_walks,
           total_rbis,
           overall_average);
}