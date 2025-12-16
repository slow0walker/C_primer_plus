#include "ex4.h"
#include <stdlib.h>

void InitializeQueue(Queue *pq, int qsize)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
    pq->qsize = qsize;
}

bool QueueIsEmpty(const Queue *pq) { return pq->items == 0; }
bool QueueIsFull(const Queue *pq) { return pq->items >= pq->qsize; }
int QueueItemCount(const Queue *pq) { return pq->items; }

bool EnQueue(Item item, Queue *pq)
{
    if (QueueIsFull(pq))
        return false;
    Node *pnew = (Node *)malloc(sizeof(Node));
    if (!pnew)
        return false;
    pnew->item = item;
    pnew->next = NULL;

    if (QueueIsEmpty(pq))
        pq->front = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
    if (QueueIsEmpty(pq))
        return false;
    Node *pt = pq->front;
    *pitem = pt->item;
    pq->front = pt->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}

void EmptyQueue(Queue *pq)
{
    Item dummy;
    while (DeQueue(&dummy, pq))
    {
    }
}
