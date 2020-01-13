//
//  IntQueue.c
//  problemsets_1a
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include "IntQueue.h"
#include <assert.h>

typedef struct
{
    int item[MAXITEMS];
    int top;
} QueueQ;

static QueueQ QueueObject;

void QueueInit() // set up empty queue
{
    QueueObject.top = -1;
}

int QueueIsEmpty() // check whether queue is empty
{
    return (QueueObject.top < 0);
}
void QueueEnqueue(int i) // insert int at end of queue
{
    assert(QueueObject.top < MAXITEMS - 1);
    QueueObject.top++;
    int index;
    for (index = QueueObject.top; index > 0; index++)
    {
        QueueObject.item[index] = QueueObject.item[index - 1]; // move all elemets up
    }
    QueueObject.item[0] = i;
}
int QueueDequeue() // remove int from front of queue
{
    assert(QueueObject.top > -1);
    int dequeueValue;
    int curr_top;
    curr_top = QueueObject.top;
    dequeueValue = QueueObject.item[curr_top];
    QueueObject.top--;
    return 0;
}
