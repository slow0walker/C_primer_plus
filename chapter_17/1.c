#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

typedef struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
} Film;

static char *s_gets(char *st, int n)
{
    char *ret = fgets(st, n, stdin);
    if (!ret)
        return NULL;
    char *p = strchr(st, '\n');
    if (p)
        *p = '\0';
    else
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }
    }
    return ret;
}

static void show_forward(const Film *head)
{
    puts("\nMovies in original order:");
    for (const Film *p = head; p; p = p->next)
        printf("Rating: %d  Title: %s\n", p->rating, p->title);
}

static void show_reverse_rec(const Film *node)
{
    if (!node)
        return;
    show_reverse_rec(node->next);
    printf("Rating: %d  Title: %s\n", node->rating, node->title);
}

static void free_list(Film *head)
{
    while (head)
    {
        Film *tmp = head->next;
        free(head);
        head = tmp;
    }
}

int main(void)
{
    Film *head = NULL, *tail = NULL;
    char input[TSIZE];

    puts("Enter first movie title (empty line to stop):");
    while (s_gets(input, TSIZE) && input[0] != '\0')
    {
        Film *node = (Film *)malloc(sizeof(Film));
        if (!node)
        {
            puts("Out of memory.");
            free_list(head);
            return 1;
        }
        strcpy(node->title, input);

        puts("Enter rating (0-10):");
        if (scanf("%d", &node->rating) != 1)
        {
            free(node);
            break;
        }
        while (getchar() != '\n')
        {
        } // clear line

        node->next = NULL;
        if (!head)
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }

        puts("Enter next movie title (empty line to stop):");
    }

    if (!head)
        puts("No data entered.");
    else
    {
        show_forward(head);
        puts("\nMovies in reverse order:");
        show_reverse_rec(head);
    }

    free_list(head);
    return 0;
}
