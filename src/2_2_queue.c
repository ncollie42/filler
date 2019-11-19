#include "h_functions.h"

queue *initQueue()
{
    queue *tmp;

    tmp = malloc(sizeof(queue));
    tmp->first = NULL;
    tmp->last = NULL;

    return tmp;
}

bool isQueueEmpty(queue *q)
{
    return (!q->first);
}

void addQueue(queue *q, cordinate cord) // change int x and y to cordinate
{
    node *new;

    new = newNode(cord.x, cord.y);
    if (isQueueEmpty(q))
        q->first = new;
    else
        q->last->next = new;
    q->last = new;
}

cordinate deQueue(queue *q)
{
    node *tmp;
    cordinate cord;

    tmp = q->first;
    cord = tmp->cord;
    q->first = q->first->next;
    if (isQueueEmpty(q))
        q->last = NULL;
    free(tmp);
    return cord;
}

node *newNode(int x, int y)
{
    node *tmp;

    tmp = malloc(sizeof(node));
    tmp->cord.x = x;
    tmp->cord.y = y;
    tmp->next = NULL;
    return tmp;
}