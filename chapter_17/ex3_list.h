#ifndef EX03_LIST_H
#define EX03_LIST_H

#include <stdbool.h>

#define TSIZE 45
#define MAXSIZE 100

typedef struct film_item
{
    char title[TSIZE];
    int rating;
} Item;

typedef struct list
{
    Item entries[MAXSIZE]; /* array of items */
    int items;             /* number of items in list */
} List;

void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);
void Traverse(const List *plist, void (*pfun)(Item item));
void EmptyTheList(List *plist);

#endif
