#include "2.h"
#include <stdlib.h>

void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

bool ListIsEmpty(const List *plist)
{
    return plist->head == NULL;
}

bool ListIsFull(const List *plist)
{
    Node *pt = (Node *)malloc(sizeof(Node));
    if (!pt)
        return true;
    free(pt);
    return false;
}

unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    for (Node *p = plist->head; p; p = p->next)
        count++;
    return count;
}

bool AddItem(Item item, List *plist)
{
    Node *pnew = (Node *)malloc(sizeof(Node));
    if (!pnew)
        return false;
    pnew->item = item;
    pnew->next = NULL;

    if (plist->head == NULL)
    {
        plist->head = plist->end = pnew;
    }
    else
    {
        plist->end->next = pnew;
        plist->end = pnew;
    }
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    for (Node *p = plist->head; p; p = p->next)
        pfun(p->item);
}

void EmptyTheList(List *plist)
{
    Node *psave;
    while (plist->head)
    {
        psave = plist->head->next;
        free(plist->head);
        plist->head = psave;
    }
    plist->end = NULL;
}
