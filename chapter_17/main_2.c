#include <stdio.h>
#include <string.h>
#include "2.h"

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

static void showmovie(Item item)
{
    printf("Rating: %d  Title: %s\n", item.rating, item.title);
}

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);

    puts("Enter first movie title (empty line to stop):");
    while (s_gets(temp.title, TSIZE) && temp.title[0] != '\0')
    {
        puts("Enter rating (0-10):");
        if (scanf("%d", &temp.rating) != 1)
            break;
        while (getchar() != '\n')
        {
        }

        if (!AddItem(temp, &movies))
        {
            puts("Problem allocating memory.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    if (ListIsEmpty(&movies))
        puts("No movies entered.");
    else
    {
        puts("\nHere is the movie list:");
        Traverse(&movies, showmovie);
        printf("Total movies: %u\n", ListItemCount(&movies));
    }

    EmptyTheList(&movies);
    return 0;
}
