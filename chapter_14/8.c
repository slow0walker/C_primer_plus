#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEATS 12
#define NAMELEN 20
#define FILENAME "seats.dat"

struct seat
{
    int id;
    int assigned;
    char first[NAMELEN];
    char last[NAMELEN];
};

/* -------- function prototypes -------- */
void load(struct seat arr[], int n);
void save(const struct seat arr[], int n);
char menu(void);
void show_empty_count(const struct seat arr[], int n);
void show_empty_list(const struct seat arr[], int n);
void show_assigned_alpha(const struct seat arr[], int n);
void assign_seat(struct seat arr[], int n);
void delete_assignment(struct seat arr[], int n);

/* comparison for sorting */
int cmp_alpha(const void *a, const void *b);

int main(void)
{
    struct seat plane[SEATS];

    load(plane, SEATS);

    char choice;
    while ((choice = menu()) != 'f')
    {
        switch (choice)
        {
        case 'a':
            show_empty_count(plane, SEATS);
            break;
        case 'b':
            show_empty_list(plane, SEATS);
            break;
        case 'c':
            show_assigned_alpha(plane, SEATS);
            break;
        case 'd':
            assign_seat(plane, SEATS);
            break;
        case 'e':
            delete_assignment(plane, SEATS);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    save(plane, SEATS);
    printf("Data saved. Bye!\n");

    return 0;
}

/* ---------------- load file ---------------- */
void load(struct seat arr[], int n)
{
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i].id = i + 1;
            arr[i].assigned = 0;
            strcpy(arr[i].first, "");
            strcpy(arr[i].last, "");
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d %d %s %s",
               &arr[i].id, &arr[i].assigned,
               arr[i].first, arr[i].last);

        if (strcmp(arr[i].first, "\"\"") == 0)
            strcpy(arr[i].first, "");
        if (strcmp(arr[i].last, "\"\"") == 0)
            strcpy(arr[i].last, "");
    }

    fclose(fp);
}

/* ---------------- save file ---------------- */
void save(const struct seat arr[], int n)
{
    FILE *fp = fopen(FILENAME, "w");
    if (!fp)
    {
        printf("Cannot write file!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d %d %s %s\n",
                arr[i].id,
                arr[i].assigned,
                arr[i].first[0] ? arr[i].first : "\"\"",
                arr[i].last[0] ? arr[i].last : "\"\"");
    }

    fclose(fp);
}

/* ---------------- menu ---------------- */
char menu(void)
{
    printf("\nMenu:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show list of assigned seats (alphabetical order)\n");
    printf("d) Assign a customer to a seat\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
    printf("Enter choice: ");

    char ch;
    while ((ch = getchar()) == '\n')
        ;
    while (getchar() != '\n')
        ;
    return ch;
}

/* -------------- a: empty count -------------- */
void show_empty_count(const struct seat arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!arr[i].assigned)
            count++;

    printf("Number of empty seats: %d\n", count);
}

/* -------------- b: empty seats list -------------- */
void show_empty_list(const struct seat arr[], int n)
{
    printf("Empty seats: ");
    for (int i = 0; i < n; i++)
        if (!arr[i].assigned)
            printf("%d ", arr[i].id);

    printf("\n");
}

/* -------- c: assigned seats alphabetical -------- */

struct seat temp[SEATS];

int cmp_alpha(const void *a, const void *b)
{
    const struct seat *sa = (const struct seat *)a;
    const struct seat *sb = (const struct seat *)b;

    /* if one is empty */
    if (!sa->assigned && !sb->assigned)
        return 0;
    if (!sa->assigned)
        return 1;
    if (!sb->assigned)
        return -1;

    int cmp_last = strcmp(sa->last, sb->last);
    if (cmp_last != 0)
        return cmp_last;

    return strcmp(sa->first, sb->first);
}

void show_assigned_alpha(const struct seat arr[], int n)
{
    memcpy(temp, arr, sizeof(struct seat) * n);

    qsort(temp, n, sizeof(struct seat), cmp_alpha);

    printf("Assigned seats (alphabetical):\n");
    for (int i = 0; i < n; i++)
        if (temp[i].assigned)
            printf("Seat %2d: %s %s\n", temp[i].id, temp[i].first, temp[i].last);
}

/* -------------- d: assign seat -------------- */
void assign_seat(struct seat arr[], int n)
{
    int id;
    printf("Enter seat number to assign (1–12): ");
    scanf("%d", &id);
    while (getchar() != '\n')
        ;

    if (id < 1 || id > n || arr[id - 1].assigned)
    {
        printf("Seat unavailable.\n");
        return;
    }

    printf("Enter first name: ");
    scanf("%19s", arr[id - 1].first);

    printf("Enter last name: ");
    scanf("%19s", arr[id - 1].last);

    arr[id - 1].assigned = 1;
    printf("Seat %d assigned.\n", id);
}

/* -------------- e: delete assignment -------------- */
void delete_assignment(struct seat arr[], int n)
{
    int id;
    printf("Enter seat number to delete (1–12): ");
    scanf("%d", &id);
    while (getchar() != '\n')
        ;

    if (id < 1 || id > n || !arr[id - 1].assigned)
    {
        printf("Seat not assigned.\n");
        return;
    }

    arr[id - 1].assigned = 0;
    strcpy(arr[id - 1].first, "");
    strcpy(arr[id - 1].last, "");

    printf("Reservation canceled.\n");
}
