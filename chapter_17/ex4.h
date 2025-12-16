#ifndef H
#define H

#include <stdbool.h>

typedef struct item
{
    long arrive;
    int processtime;
} Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int items;
    int qsize;
} Queue;

void InitializeQueue(Queue *pq, int qsize);
bool QueueIsEmpty(const Queue *pq);
bool QueueIsFull(const Queue *pq);
int QueueItemCount(const Queue *pq);
bool EnQueue(Item item, Queue *pq);
bool DeQueue(Item *pitem, Queue *pq);
void EmptyQueue(Queue *pq);

#endif
