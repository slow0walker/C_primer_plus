#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEATS 12
#define NAMELEN 20
#define FILENAME "seats.dat"

struct seat
{
    int id;       // seat number
    int assigned; // 0 = empty, 1 = taken
    char first[NAMELEN];
    char last[NAMELEN];
};

/* function prototypes */
void load(struct seat arr[], int n);
void save(const struct seat arr[], int n);
char menu(void);
void show_empty(const struct seat arr[], int n);
void show_assigned(const struct seat arr[], int n);
void assign_seat(struct seat arr[], int n);
void delete_assignment(struct seat arr[], int n);

int main(void)
{
    struct seat plane[SEATS];
    load(plane, SEATS);

    char choice;
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            show_empty(plane, SEATS);
            break;
        case 'b':
            show_assigned(plane, SEATS);
            break;
        case 'c':
            assign_seat(plane, SEATS);
            break;
        case 'd':
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

/* -------------------- Load seat file -------------------- */
void load(struct seat arr[], int n)
{
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
    {
        // File doesn't exist → init fresh data
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

        // handle "" as empty string
        if (strcmp(arr[i].first, "\"\"") == 0)
            strcpy(arr[i].first, "");
        if (strcmp(arr[i].last, "\"\"") == 0)
            strcpy(arr[i].last, "");
    }

    fclose(fp);
}

/* -------------------- Save seat file -------------------- */
void save(const struct seat arr[], int n)
{
    FILE *fp = fopen(FILENAME, "w");
    if (!fp)
    {
        printf("ERROR: cannot save file!\n");
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

/* -------------------- Menu -------------------- */
char menu(void)
{
    printf("\nMenu:\n");
    printf("a) Show empty seats\n");
    printf("b) Show assigned seats\n");
    printf("c) Assign a seat\n");
    printf("d) Delete a seat assignment\n");
    printf("q) Quit\n");
    printf("Enter option: ");

    char ch;
    while ((ch = getchar()) == '\n')
        ; // skip newline
    while (getchar() != '\n')
        ; // flush line
    return ch;
}

/* -------------------- Functions -------------------- */

void show_empty(const struct seat arr[], int n)
{
    printf("Empty seats: ");
    for (int i = 0; i < n; i++)
        if (!arr[i].assigned)
            printf("%d ", arr[i].id);

    printf("\n");
}

void show_assigned(const struct seat arr[], int n)
{
    printf("Assigned seats:\n");
    for (int i = 0; i < n; i++)
        if (arr[i].assigned)
            printf("Seat %2d: %s %s\n",
                   arr[i].id, arr[i].first, arr[i].last);
}

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
    while (getchar() != '\n')
        ;

    arr[id - 1].assigned = 1;
}

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
