#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void read_books(struct book library[], int *count);
char *s_gets(char *st, int n);
void show_books(const struct book library[], int count);
void sort_books_by_title(struct book library[], int count);
void sort_books_by_value(struct book library[], int count);

int main()
{
    struct book library[MAXBKS];
    int count = 0;
    read_books(library, &count);

    if (count > 0)
    {

        printf("\nBooks in the order entered:\n");
        show_books(library, count);

        printf("\nBooks sorted by title:\n");
        sort_books_by_title(library, count);
        show_books(library, count);

        printf("\nBooks sorted by value:\n");
        sort_books_by_value(library, count);
        show_books(library, count);
    }
    else
    {
        printf("No books entered.\n");
    }
    return 0;
}

// get book data from user
void read_books(struct book library[], int *count)
{
    int i = 0;
    printf("Enter book title (empty line to stop):\n");
    while (i < MAXBKS && s_gets(library[i].title, MAXTITL) != NULL && library[i].title[0] != '\0')
    {
        printf("Enter author:\n");
        s_gets(library[i].author, MAXAUTL);
        printf("Enter value:\n");
        scanf("%f", &library[i].value);
        while (getchar() != '\n')
            continue; // clear input buffer
        i++;
        if (i < MAXBKS)
            printf("Enter the next book title (empty line to stop):\n");
    }
    *count = i;
}

// safe string input
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

// display book data
void show_books(const struct book library[], int count)
{
    printf("Here is the list of your books:\n");
    for (int index = 0; index < count; index++)
    {
        printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
}

// sort books by title
void sort_books_by_title(struct book library[], int count)
{
    struct book temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(library[i].title, library[j].title) > 0)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
}

// sort books by increasing value
void sort_books_by_value(struct book library[], int count)
{
    struct book temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (library[i].value > library[j].value)
            {
                temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }
}